#include "D2DFrameWork.h"
#include <sstream>

#pragma comment (lib, "d2d1.lib")


HRESULT D2DFrameWork::InitWindow(HINSTANCE hInstance, LPCWSTR title, UINT width, UINT height)
{
	WNDCLASSEX wc;

	ZeroMemory(&wc, sizeof(WNDCLASSEX));

	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpszClassName = WND_CLASS_NAME;
	wc.hInstance = hInstance;
	wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.lpfnWndProc = D2DFrameWork::WndProc;

	if (RegisterClassEx(&wc) == false)
	{
		D2DFrameWork::ShowErrorMsg(L"Failed to Create Register");
		return 0;
	}



	RECT wr = { 0, 0, static_cast<LONG>(width), static_cast<LONG>(height) };					// ������ ����
	AdjustWindowRect(&wr, WS_OVERLAPPEDWINDOW, false);

	mHwnd = CreateWindowEx(
		NULL,
		WND_CLASS_NAME,
		title,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		wr.right - wr.left, wr.bottom - wr.top,
		NULL,
		NULL,
		hInstance,
		NULL
	);

	if (mHwnd == NULL)
	{
		D2DFrameWork::ShowErrorMsg(L"Failed to Create Window");
		return 0;
	}

	SetWindowLongPtr(mHwnd, GWLP_USERDATA,
		reinterpret_cast<LONG_PTR>(this));					//������ ���� �����͸� �ο�

	return S_OK;
}

HRESULT D2DFrameWork::InitD2D()
{
	HRESULT hr = D2D1CreateFactory(
		D2D1_FACTORY_TYPE_SINGLE_THREADED,
		mspD2DFactory.GetAddressOf());
	if (FAILED(hr))
	{
		ShowErrorMsg(L"Failed to Create D2D Factory");
		return hr;
	}
	hr = CreateDeviceResources();
	ThrowIfFailed(hr);

	return hr;
}

HRESULT D2DFrameWork::CreateDeviceResources()
{
	RECT wr;

	GetClientRect(mHwnd, &wr);		// �������� Ŭ���̾�Ʈ ��Ʈ(��ܹ� ���� �����ϰ� ���� �׸��� ������)
	HRESULT hr = mspD2DFactory->CreateHwndRenderTarget(
		D2D1::RenderTargetProperties(),
		D2D1::HwndRenderTargetProperties(
			mHwnd,
			D2D1::SizeU(wr.right - wr.left, wr.bottom - wr.top)),
		mspRenderTarget.GetAddressOf()
	);

	return hr;
}



HRESULT D2DFrameWork::Initialize(HINSTANCE hInstance, LPCWSTR title, UINT width, UINT height)
{
	HRESULT hr;


	hr = InitWindow(hInstance, title, width, height);
	ThrowIfFailed(hr);

	hr = InitD2D();
	ThrowIfFailed(hr);

	ShowWindow(mHwnd, SW_SHOW);
	UpdateWindow(mHwnd);

	return hr;
}

void D2DFrameWork::Release()
{
}

int D2DFrameWork::GameLoop()
{
	MSG msg;
	while (true)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
			if (msg.message == WM_QUIT)
			{
				break;
			}
		}
		else
		{
			Render();
		}
	}
	return static_cast<int>(msg.wParam);
}

void D2DFrameWork::Render()
{
	HRESULT hr;
	mspRenderTarget->BeginDraw();
	mspRenderTarget->Clear(D2D1::ColorF(0.0f, 0.2f, 0.4f, 1.0f));	// r g b a

	//TODO: �׸���


	hr = mspRenderTarget->EndDraw();
	if (hr == D2DERR_RECREATE_TARGET)
	{
		CreateDeviceResources();
	}
}

void D2DFrameWork::ShowErrorMsg(LPCWSTR msg, LPCWSTR title)
{



	OutputDebugString(msg);

	MessageBox(nullptr, msg,
		title, MB_OK | MB_ICONEXCLAMATION);
}

LRESULT D2DFrameWork::WndProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam)
{
	D2DFrameWork* pFrameWork =
		reinterpret_cast<D2DFrameWork*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));

	switch (message)
	{
	case WM_CLOSE:
		DestroyWindow(hwnd);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hwnd, message, wparam, lparam);
		break;
	}

	return 0;
}
