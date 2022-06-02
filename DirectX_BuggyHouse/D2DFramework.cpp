#include <sstream>
#include "D2DFramework.h"
#include "BitmapManager.h"

#pragma comment (lib, "d2d1.lib")

HRESULT D2DFramework::InitWindow(HINSTANCE hInstance, LPCWSTR title, UINT width, UINT height)
{
	WNDCLASSEX wc;

	ZeroMemory(&wc, sizeof(WNDCLASSEX));
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpszClassName = WINDOW_CLASSNAME;
	wc.hInstance = hInstance;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.lpfnWndProc = WindowProc;
	wc.cbSize = sizeof(WNDCLASSEX);
	if (!RegisterClassEx(&wc))
	{
		MessageBox(NULL, L"Failed To Register!", L"Error", MB_OK);
		return 0;
	}

	RECT rc{ 0, 0, 
		static_cast<LONG>(width), static_cast<LONG>(height) };
	AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, FALSE);
	HWND hwnd = CreateWindowEx(
		NULL,
		WINDOW_CLASSNAME,
		title,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		rc.right - rc.left,
		rc.bottom - rc.top,
		NULL,
		NULL,
		hInstance,
		NULL
	);
	if (hwnd == NULL)
	{
		MessageBox(NULL, L"Failed To Create", L"Error", MB_OK);
		return 0;
	}

	mHwnd = hwnd;

	SetWindowLongPtr(mHwnd, GWLP_USERDATA, 
		reinterpret_cast<LONG_PTR>(this));

	return S_OK;
}

HRESULT D2DFramework::InitD2D(HWND hwnd)
{
	HRESULT hr;

	// 1. D2D Factory �����
	hr = D2D1CreateFactory(
		D2D1_FACTORY_TYPE_SINGLE_THREADED, mspD2DFactory.GetAddressOf()
	);

	ThrowIfFailed(hr);

	return CreateDeviceResources();
}

HRESULT D2DFramework::CreateDeviceResources()
{
	// 2. RenderTarget ����
	RECT rc;
	GetClientRect(mHwnd, &rc);
	HRESULT hr = mspD2DFactory->CreateHwndRenderTarget(
		D2D1::RenderTargetProperties(),
		D2D1::HwndRenderTargetProperties(
			mHwnd,
			D2D1::SizeU(rc.right - rc.left, rc.bottom - rc.top)
		),
		mspRenderTarget.GetAddressOf()
	);
	ThrowIfFailed(hr);

	return hr;
}

HRESULT D2DFramework::Initialize(HINSTANCE hInstance, LPCWSTR title, UINT width, UINT height)
{
	HRESULT hr;

	hr = CoInitialize(nullptr);
	ThrowIfFailed(hr);

	hr = InitWindow(hInstance, title, width, height);
	ThrowIfFailed(hr);

	hr = InitD2D(mHwnd);
	ThrowIfFailed(hr);

	hr = BitmapManager::Instance().Initialize(mspRenderTarget.Get());
	ThrowIfFailed(hr, "Failed to Initialize BitmapManager");

	ShowWindow(mHwnd, SW_SHOW);
	UpdateWindow(mHwnd);

	return hr;
}

void D2DFramework::Release()
{
	BitmapManager::Instance().Release();

	mspRenderTarget.Reset();
	mspD2DFactory.Reset();

	CoUninitialize();
}

void D2DFramework::Render()
{
	HRESULT hr;

	mspRenderTarget->BeginDraw();
	mspRenderTarget->Clear(D2D1::ColorF(0.0f, 0.2f, 0.4f, 1.0f));
	hr = mspRenderTarget->EndDraw();

	if (hr == D2DERR_RECREATE_TARGET)
	{
		CreateDeviceResources();
	}
}

int D2DFramework::GameLoop()
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

	Release();

	return static_cast<int>(msg.wParam);
}

void D2DFramework::ShowErrorMsg(LPCWSTR msg, HRESULT error, LPCWSTR title)
{
	std::wostringstream oss;

	oss << L"ERROR : " << error << std::endl;
	oss << msg;

	OutputDebugString(oss.str().c_str());
}

LRESULT CALLBACK D2DFramework::WindowProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	D2DFramework* pFramework = reinterpret_cast<D2DFramework*>
		(GetWindowLongPtr(hwnd, GWLP_USERDATA));

	switch (message)
	{
	case WM_CLOSE:
		DestroyWindow(hwnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}

	return 0;
}
