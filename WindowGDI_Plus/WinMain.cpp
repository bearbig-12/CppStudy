#include <Windows.h>
#include <sstream>
#include <gdiplus.h>

#pragma comment (lib, "Gdiplus.lib")

// HINSTANCE : Handle(pointer) of INSTANCE
// LPSTR : Long Pointer to NULL - Terminated STRing

// MessageBox
//			HWND hwnd				: Handle(pointer) of Window �θ�������
//			LPCWSTR lpText			: Long Pointer Constant Wide STRing ����
//			LPCWSTR lpCaption		: ����
//			UINT uType				: Unsinged Integer ��Ÿ��


	//	1. ������ Ŭ���� ���

	//	2. ������ ����� (1���� ������ Ŭ����)

	//	3. ������ �޽��� ���� ó��

	//	4. ������ ���ν���(procedure) �ۼ�

const wchar_t gClassName[] = L"MyWindowClass";

// ������ ���ν����� ���Ѽ���
//		HWND : �޽����� ���� ������
//		UINT : message ����
//		WPARAM : Word Parameter
//		LPARAM : Long Parameter
LRESULT CALLBACK WindowProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nShowCmd
)
{
	Gdiplus::GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR token;

	GdiplusStartup(&token, &gdiplusStartupInput, nullptr);
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

	// Ŭ������ ���� ������ ���� - ��ϵ� Ŭ�����κ��� ��������⿡ ������ Ŭ������ ��ϵǾ� �־�� ��.
	HWND hwnd;
	RECT rect{ 0,0,640,480 };
	AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

	hwnd = CreateWindowEx(
		0,
		gClassName,
		L"SimpleWindow App",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		rect.right-rect.left,
		rect.bottom-rect.top,
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
	PAINTSTRUCT ps; // WM_PAINT�� PAINTSTRUCT�� ������ ����Ѵ�.

	HDC hdc = BeginPaint(hwnd, &ps);
	Gdiplus::Graphics graphics(hdc);
	/*Gdiplus::Pen pen(Gdiplus::Color(255, 0, 0, 255));
	graphics.DrawRectangle(&pen, 0, 0, 100, 100);*/

	Gdiplus::Image image(L"isaac.png");
	
	/*graphics.DrawImage(&image, 0, 0, 
		ps.rcPaint.right - ps.rcPaint.left,
		ps.rcPaint.bottom - ps.rcPaint.top);*/
	graphics.DrawImage(&image, 0, 0, image.GetWidth(), image.GetHeight()); // ���� �״��

	EndPaint(hwnd, &ps);
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	// �����쿡�� �������� ���������� �˷���
	switch (message)
	{
		//case WM_ERASEBKGND:	// ������ ����� ����� ���.
		//	break;
	case WM_PAINT:
	{
		OnPaint(hwnd);
		break;
	}
	case WM_KEYDOWN:
	{
		std::stringstream ss;
		if (wParam == VK_SPACE) // �����̽� �������� ���
		{
			ss << "Virtual Key : " << wParam << ", Extra : " << lParam << std::endl;
			OutputDebugStringA(ss.str().c_str());
		}

		break;
	}
	case WM_LBUTTONDOWN:
	{
		//int x = LOWORD(lParam);	// x��ǥ
		//int y = HIWORD(lParam);	// y��ǥ

		//// ���ڿ�
		//std::stringstream ss;
		//ss << "x : " << x << "  " << "y : " << y << std::endl;

		////MessageBoxA(hwnd, ss.str().c_str(), "Message Test", MB_OK);	// MessageBoxA �ƽ�Ű ���� , MessageBoxW ���̵� ����
		//OutputDebugStringA(ss.str().c_str());

		HDC hdc;
		hdc = GetDC(hwnd);	//Device Context�� �����ͷ� �޾ƿ�.

		Rectangle(hdc, 0, 0, 100, 100);

		ReleaseDC(hwnd, hdc);	// �������̱� ������ Release �ʿ�


		break;
	}

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