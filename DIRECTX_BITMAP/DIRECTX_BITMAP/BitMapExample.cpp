#include "BitMapExample.h"

HRESULT BitMapExample::Initialize(HINSTANCE hInstance, LPCWSTR title, UINT width, UINT height)
{
    D2DFrameWork::Initialize(hInstance, title, width, height);

	//가상 BackBuffer
    mspBackBuffer = std::make_unique<UINT8[]>(
		BITMAP_WIDTH * BITMAP_HEIGHT* BITMAP_BYTECOUNT
		);

  

	// 가상 FrameBuffer
	HRESULT hr = mspRenderTarget->CreateBitmap(
		D2D1::SizeU(BITMAP_WIDTH, BITMAP_HEIGHT),
		D2D1::BitmapProperties(
			D2D1::PixelFormat(DXGI_FORMAT_R8G8B8A8_UNORM, D2D1_ALPHA_MODE_IGNORE)
		),
		mspFrameBitmap.GetAddressOf()
	);

    ThrowIfFailed(hr);

    return hr;
}

void BitMapExample::Render()
{
	mspRenderTarget->BeginDraw();
	mspRenderTarget->Clear(D2D1::ColorF(0.0f, 0.2f, 0.4f, 1.0f));

	//DrawPixelToBuffer(10, 10, D2D1::ColorF::White);
	//ClearBuffer(D2D1::ColorF::Yellow);
	DrawRectToBuffer(100, 50,  D2D1::ColorF::Yellow);
	DrawCircleToBuffer(500, 500, 50.0f, D2D1::ColorF::Crimson);
	PresentBuffer();

	mspRenderTarget->DrawBitmap(mspFrameBitmap.Get());

	mspRenderTarget->EndDraw();
}

void BitMapExample::PresentBuffer()
{
	mspFrameBitmap->CopyFromMemory(nullptr, mspBackBuffer.get(),
		BITMAP_WIDTH * BITMAP_BYTECOUNT);
}

void BitMapExample::DrawPixelToBuffer(int x, int y, D2D1::ColorF color)
{
	int pitch = BITMAP_WIDTH * BITMAP_BYTECOUNT;
	int index = pitch * y + x * BITMAP_BYTECOUNT;

	mspBackBuffer[index ] = static_cast<UINT8>(color.r * 255);
	mspBackBuffer[index+1] = static_cast<UINT8>(color.g * 255);
	mspBackBuffer[index+2] = static_cast<UINT8>(color.b * 255);
	mspBackBuffer[index+3] = static_cast<UINT8>(color.a * 255);

}

void BitMapExample::ClearBuffer(D2D1::ColorF color)
{
	UINT8* temp = &mspBackBuffer[0];

	for (int pixel = 0; pixel < BITMAP_WIDTH * BITMAP_HEIGHT; ++pixel)
	{
		// 0.0f ~ 1.0f
		// 0 ~ 255
		*(temp) = static_cast<UINT8>(color.r * 255);
		*(temp + 1) = static_cast<UINT8>(color.g * 255);
		*(temp + 2) = static_cast<UINT8>(color.b * 255);
		*(temp + 3) = static_cast<UINT8>(color.a * 255);

		temp += BITMAP_BYTECOUNT;
	}
}

void BitMapExample::DrawRectToBuffer( int width, int height, D2D1::ColorF color)
{
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			DrawPixelToBuffer(width + j, height + i, color);
		}
	}
}

void BitMapExample::DrawCircleToBuffer(int x, int y, float radius, D2D1::ColorF color)
{
	for (int i = 0; i < 360; ++i)
	{
		auto radian = (i * (3.141592 / 180));
		int _x = (cos(radian) * radius) + x;
		int _y = (sin(radian) * radius) + y;
		DrawPixelToBuffer(_x, _y, color);
	}
}

void BitMapExample::DrawLineToBuffer(int x1, int y1, int x2, int y2, D2D1::ColorF color)
{
	float _x = stati
}

