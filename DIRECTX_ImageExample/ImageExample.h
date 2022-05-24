#pragma once
#include "D2DFrameWork.h"
#include <vector>
#include <wincodec.h>

class ImageExample : public D2DFrameWork
{
private:
	Microsoft::WRL::ComPtr<ID2D1Bitmap> mspBitmap;

public:
	virtual HRESULT Initialize(HINSTANCE hInstance,
		LPCWSTR title = L"BMP FILE EXMAPLE",
		UINT width = 1024,
		UINT height = 768) override;
	void Render() override;

	HRESULT LoadBMP(LPCWSTR filename, ID2D1Bitmap** ppbitmap);
protected:

};

