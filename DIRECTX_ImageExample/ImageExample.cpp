#include "ImageExample.h"
#include <fstream>
#include <vector>

HRESULT ImageExample::Initialize(HINSTANCE hInstance, LPCWSTR title, UINT width, UINT height)
{
	D2DFrameWork::Initialize(hInstance, title, width, height);

	LoadBMP(L"Data/32.bmp", mspBitmap.GetAddressOf());

	return S_OK;
}

void ImageExample::Render()
{
	mspRenderTarget->BeginDraw();

	mspRenderTarget->Clear(D2D1::ColorF(D2D1::ColorF::LightSalmon));

	mspRenderTarget->DrawBitmap(mspBitmap.Get());

	mspRenderTarget->EndDraw();
}

HRESULT ImageExample::LoadBMP(LPCWSTR filename, ID2D1Bitmap** ppbitmap)
{

	// 1. 파일 열기
	std::ifstream file;
	file.open(filename, std::ios::binary);


	// 2. BIT MAP FILE HEADER 읽기
	BITMAPFILEHEADER bfh;
	file.read(reinterpret_cast<char*>(&bfh), sizeof(BITMAPFILEHEADER));
	 
	// 3. BIT MAP INFO HEADER 읽기
	BITMAPINFOHEADER bih;
	file.read(reinterpret_cast<char*>(&bih), sizeof(BITMAPINFOHEADER));

	if (bfh.bfType == 0x4D42) // bftype는 BMP 타입인지 확인이 필요 하다. 하지만 bfType 타입은 문자열이 아니고 리틀 엔디안이다.
	{						  // 따라서 42D4가 BM이므로 리틀 엔디안에 따라 뒤집어서 비교
		return E_FAIL;
	}							 
	if (bih.biBitCount != 32)
	{
		return E_FAIL;
	}

	// 4. bfoffBits  값 만큼 건너뛰기
	file.seekg(bfh.bfOffBits);
	// 5. 픽셀 데이터 읽기
	std::vector<char> pPixels(bih.biSizeImage);
	file.read(&pPixels[0], bih.biSizeImage);
	// 6. 5번 데이터로 Bit map 만들기
	return S_OK;
}
