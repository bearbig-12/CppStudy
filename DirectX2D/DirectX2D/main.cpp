#include <Windows.h>
#include <d2d1.h>

#pragma comment (lib, "d2d1.lib")

const wchar_t gClassName[]{ L"MyWindowClass" };



LRESULT CALLBACK WindowProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

// 0. D2D 전역 변수들
ID2D1Factory* gpD2DFactory{};
ID2D1HwndRenderTarget* gpRenderTarget{};
ID2D1SolidColorBrush* gpBrush{};
ID2D1RadialGradientBrush* gpRadialBrush{};

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

	RECT rc{ 0,0,1024, 768 };
	AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, FALSE);

	// 클래스로 부터 윈도우 생성 - 등록된 클래스로부터 만들어지기에 무조건 클래스가 등록되어 있어야 함.
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
	//WS_OVERLAPPEDWINDOW - 다른 윈도우 창과 겹치는걸 허용? 해주는 기능

	if (!hwnd)
	{
		MessageBox(nullptr, L"Failed To Create Window!!", L"ERROR", MB_OK);
		return 0;
	}


	// 1. D2D Factory 만들기
	HRESULT hr = D2D1CreateFactory(
		D2D1_FACTORY_TYPE_SINGLE_THREADED,
		&gpD2DFactory
	);

	if (FAILED(hr))	// 성공 - SUCCEEDED(hr)

	{
		MessageBox(NULL, L"Failed to Create Factory", L"Error", MB_OK);
		return 0;
	}

	// 2. RenderTarget 생성

	hr = gpD2DFactory->CreateHwndRenderTarget(
		D2D1::RenderTargetProperties(),
		D2D1::HwndRenderTargetProperties
		(
			hwnd,
			D2D1::SizeU(rc.right - rc.left, rc.bottom - rc.top)
		),
		&gpRenderTarget
	);
	if (FAILED(hr))
	{
		MessageBox(NULL, L"Faile to Create D2D Render Target!", L"Error", MB_OK);
		return 0;
	}
	
	hr = gpRenderTarget->CreateSolidColorBrush(
		D2D1::ColorF(D2D1::ColorF::DeepPink),
		&gpBrush
	);

	// 그라데이션
	ID2D1GradientStopCollection* pGradientStop;
	D2D1_GRADIENT_STOP gradientStops[2];
	gradientStops[0].color = D2D1::ColorF(D2D1::ColorF::Yellow);
	gradientStops[0].position = 0.0f;
	gradientStops[1].color = D2D1::ColorF(D2D1::ColorF::Crimson);
	gradientStops[1].position = 1.0f;


	hr = gpRenderTarget->CreateGradientStopCollection(
		gradientStops,
		2,
		&pGradientStop
	);
	hr = gpRenderTarget->CreateRadialGradientBrush(
		D2D1::RadialGradientBrushProperties(
			D2D1::Point2F(50.0f,150.0f),
			D2D1::Point2F(0.0f,0.0f),
			50.0f, 50.0f
		),
		pGradientStop,
		&gpRadialBrush
	);

	ShowWindow(hwnd, nShowCmd);
	UpdateWindow(hwnd);

	// 메시지 루프 - 코드패턴 외워두기

	MSG msg;
	while (GetMessage(&msg, 0, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessageW(&msg);
	}
	
	// 4. 해제
	if (gpRadialBrush)
	{
		gpRadialBrush->Release();
		gpRadialBrush = nullptr;
	}
	if (gpBrush)
	{
		gpBrush->Release();
		gpBrush = nullptr;
	}
	if (gpRenderTarget != nullptr)
	{
		gpRenderTarget->Release();
		gpRenderTarget = nullptr;
	}
	if (gpD2DFactory)
	{
		gpD2DFactory->Release();
		gpD2DFactory = nullptr;
	}


	return (int)msg.wParam;
}

void OnPaint(HWND hwnd)
{
	HDC hdc;
	PAINTSTRUCT ps;

	// 3 그리기
	gpRenderTarget->BeginDraw();
	gpRenderTarget->Clear(D2D1::ColorF(0.0f, 0.2f, 0.4f, 1.0f));

	
	gpBrush->SetOpacity(1.0f);
	gpBrush->SetColor(D2D1::ColorF(D2D1::ColorF::Aquamarine));
	gpRenderTarget->FillRectangle(
		D2D1::RectF(0.0f,0.0f,100.0f,100.0f),
		gpBrush
	);

	gpBrush->SetOpacity(0.5f);
	gpBrush->SetColor(D2D1::ColorF(D2D1::ColorF::LightYellow));
	gpRenderTarget->FillRectangle(
		D2D1::RectF(50.0f, 50.0f, 150.0f, 150.0f),
		gpBrush
	);
	
	gpRenderTarget->FillEllipse(
		D2D1::Ellipse(D2D1::Point2F(50.0f,150.0f),50.0f,50.0f),
		gpRadialBrush
	);

	gpRenderTarget->EndDraw();

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
