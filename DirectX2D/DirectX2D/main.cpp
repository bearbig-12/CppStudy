#include <Windows.h>
#include <d2d1.h>

#pragma comment (lib, "d2d1.lib")

const wchar_t gClassName[]{ L"MyWindowClass" };



LRESULT CALLBACK WindowProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

// 0. D2D ���� ������
ID2D1Factory* gpD2DFactory{};
ID2D1HwndRenderTarget* gpRenderTarget{};

// 1. Direct2D Factory
// 2. RenderTarget Create
// 3. Render Draw
// 4. Release

int WINAPI WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nShowCmd
)
{
	// 1. D2D Factory �����
	HRESULT hr = D2D1CreateFactory(
		D2D1_FACTORY_TYPE_SINGLE_THREADED,
		&gpD2DFactory
	);

	if (FAILED(hr))	// ���� - SUCCEEDED(hr)

	{
		MessageBox(NULL, L"Failed to Create Factory", L"Error", MB_OK);
		return 0;
	}

	// ������ Ŭ����
	WNDCLASSEX wc;
	ZeroMemory(&wc, sizeof(WNDCLASSEX));
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpszClassName = gClassName;
	wc.hInstance = hInstance;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = reinterpret_cast<HBRUSH>(COLOR_WINDOW);
	wc.lpfnWndProc = WindowProc;
	wc.cbSize = sizeof(WNDCLASSEX);

	// ������ Ŭ���� ��� (OS��)
	if (!RegisterClassEx(&wc))	//����� ���� ������
	{
		MessageBox(nullptr, L"Failed To Register Window Class!!", L"ERROR", MB_OK);
		return 0;
	}

	RECT rc{ 0,0,1024, 768 };
	AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, FALSE);

	// Ŭ������ ���� ������ ���� - ��ϵ� Ŭ�����κ��� ��������⿡ ������ Ŭ������ ��ϵǾ� �־�� ��.
	HWND hwnd;

	hwnd = CreateWindowEx(
		NULL,
		gClassName,
		L"Direct2D",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		rc.right - rc.left,
		rc.bottom - rc.top,
		NULL,
		NULL,
		hInstance,
		NULL
	);
	//WS_OVERLAPPEDWINDOW - �ٸ� ������ â�� ��ġ�°� ���? ���ִ� ���

	if (!hwnd)
	{
		MessageBox(nullptr, L"Failed To Create Window!!", L"ERROR", MB_OK);
		return 0;
	}
	ShowWindow(hwnd, nShowCmd);
	UpdateWindow(hwnd);

	// �޽��� ���� - �ڵ����� �ܿ��α�

	MSG msg;
	while (GetMessage(&msg, 0, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessageW(&msg);
	}

	return (int)msg.wParam;
}

void OnPaint(HWND hwnd)
{
	HDC hdc;
	PAINTSTRUCT ps;

	hdc = BeginPaint(hwnd, &ps);

	EndPaint(hwnd, &ps);
}



LRESULT CALLBACK WindowProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_PAINT:
		OnPaint(hwnd);
		break;
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
