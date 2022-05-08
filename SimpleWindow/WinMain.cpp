#include <Windows.h>
#include <sstream>
// HINSTANCE : Handle(pointer) of INSTANCE
// LPSTR : Long Pointer to NULL - Terminated STRing

// MessageBox
//			HWND hwnd				: Handle(pointer) of Window 부모윈도우
//			LPCWSTR lpText			: Long Pointer Constant Wide STRing 본문
//			LPCWSTR lpCaption		: 제목
//			UINT uType				: Unsinged Integer 스타일


	//	1. 윈도우 클래스 등록

	//	2. 윈도우 만들기 (1번의 윈도우 클래스)

	//	3. 윈도우 메시지 루프 처리

	//	4. 윈도우 프로시져(procedure) 작성

const wchar_t gClassName[] = L"MyWindowClass";

// 윈도우 프로시져에 대한선언
//		HWND : 메시지를 받은 윈도우
//		UINT : message 종류
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
	
	//MessageBox(nullptr, L"HelloWorld", L"SimpleWorld", MB_ICONEXCLAMATION | MB_OK);

	// 윈도우 클래스
	WNDCLASSEX wc;
	ZeroMemory(&wc, sizeof(WNDCLASSEX));
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpszClassName = gClassName;
	wc.hInstance = hInstance;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = reinterpret_cast<HBRUSH>(COLOR_WINDOW);
	wc.lpfnWndProc = WindowProc;
	wc.cbSize = sizeof(WNDCLASSEX);

	// 윈도우 클래스 등록 (OS에)
	if (!RegisterClassEx(&wc))	//등록이 실패 했을때
	{
		MessageBox(nullptr, L"Failed To Register Window Class!!", L"ERROR", MB_OK);
		return 0;
	}

	// 클래스로 부터 윈도우 생성 - 등록된 클래스로부터 만들어지기에 무조건 클래스가 등록되어 있어야 함.
	HWND hwnd;

	hwnd = CreateWindowEx(
		0,
		gClassName,
		L"SimpleWindow App",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		640,
		480,
		NULL,
		NULL,
		hInstance,
		NULL
	);
	//WS_OVERLAPPEDWINDOW - 다른 윈도우 창과 겹치는걸 허용? 해주는 기능

	if (!hwnd)
	{
		MessageBox(nullptr, L"Failed To Create Window!!", L"ERROR", MB_OK);
		return 0;
	}
	ShowWindow(hwnd, nShowCmd);
	UpdateWindow(hwnd);

	// 메시지 루프 - 코드패턴 외워두기

	MSG msg;
	while (GetMessage(&msg, 0,0,0))
	{
		TranslateMessage(&msg);
		DispatchMessageW(&msg);
	}

	return (int)msg.wParam;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	// 윈도우에서 무슨일이 벌어졌는지 알려줌
	switch (message)
	{
	case WM_KEYDOWN:
	{
		std::stringstream ss;
		if (wParam == VK_SPACE) // 스페이스 누를때만 출력
		{
			ss << "Virtual Key : " << wParam << ", Extra : " << lParam << std::endl;
			OutputDebugStringA(ss.str().c_str());
		}
		
		break;
	}
	case WM_LBUTTONDOWN:
	{
		int x = LOWORD(lParam);	// x좌표
		int y = HIWORD(lParam);	// y좌표

		// 문자열
		std::stringstream ss;
		ss << "x : " << x << "  " << "y : " << y << std::endl;

		//MessageBoxA(hwnd, ss.str().c_str(), "Message Test", MB_OK);	// MessageBoxA 아스키 버젼 , MessageBoxW 와이드 버젼
		OutputDebugStringA(ss.str().c_str());
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
