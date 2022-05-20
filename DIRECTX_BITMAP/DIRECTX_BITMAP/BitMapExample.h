#pragma once
#include "D2DFrameWork.h"

const int BITMAP_WIDTH{ 1024 };
const int BITMAP_HEIGHT{ 768 };
const int BITMAP_BYTECOUNT{};

class BitMapExample : public D2DFrameWork
{
private:
	Microsoft::WRL::ComPtr<ID2D1Bitmap> mspFrameBitmap{};
	std::unique_ptr<UINT8[]>			mspBackBuffer;

public:
	virtual HRESULT Initailize(HINSTANCE hInstance, LPCWSTR title = L"D2D Bitmap EX",
		UINT width = 1024, UINT height = 768);
	virtual void Render() override;
};

