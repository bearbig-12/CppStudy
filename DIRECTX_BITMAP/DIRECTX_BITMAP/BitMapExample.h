#pragma once
#include "D2DFrameWork.h"

const int BITMAP_WIDTH{ 1024 };
const int BITMAP_HEIGHT{ 768 };
const int BITMAP_BYTECOUNT{4};

class BitMapExample : public D2DFrameWork
{
private:
	Microsoft::WRL::ComPtr<ID2D1Bitmap> mspFrameBitmap{};
	std::unique_ptr<UINT8[]> mspBackBuffer{};
public:
	virtual HRESULT Initialize(HINSTANCE hInstance,
		LPCWSTR title = L"MyD2DFrameWork",
		UINT width = 1024,
		UINT height = 768);

	virtual void Render() override;

	void PresentBuffer();
	void DrawPixelToBuffer(int x, int y, D2D1::ColorF color);
	void ClearBuffer(D2D1::ColorF color);

	void DrawRectToBuffer(int width, int height,D2D1::ColorF color);
	void DrawCircleToBuffer(int x, int y, float radius, D2D1::ColorF color);
	void DrawLineToBuffer(int x1, int y1, int x2, int y2, D2D1::ColorF color);

};

