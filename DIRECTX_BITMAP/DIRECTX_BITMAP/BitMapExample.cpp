#include "BitMapExample.h"

HRESULT BitMapExample::Initailize(HINSTANCE hInstance, LPCWSTR title, UINT width, UINT height)
{
    D2DFrameWork::Initialize(hInstance, title, width, height);

    mspBackBuffer = std::make_unique<UINT8[]>(BITMAP_WIDTH * BITMAP_HEIGHT* BITMAP_BYTECOUNT);

    HRESULT hr;

	hr = mspRenderTarget->CreateBitmap(
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
}
