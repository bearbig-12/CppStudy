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

	// 1. ���� ����
	std::ifstream file;
	file.open(filename, std::ios::binary);


	// 2. BIT MAP FILE HEADER �б�
	BITMAPFILEHEADER bfh;
	file.read(reinterpret_cast<char*>(&bfh), sizeof(BITMAPFILEHEADER));
	 
	// 3. BIT MAP INFO HEADER �б�
	BITMAPINFOHEADER bih;
	file.read(reinterpret_cast<char*>(&bih), sizeof(BITMAPINFOHEADER));

	if (bfh.bfType == 0x4D42) // bftype�� BMP Ÿ������ Ȯ���� �ʿ� �ϴ�. ������ bfType Ÿ���� ���ڿ��� �ƴϰ� ��Ʋ ������̴�.
	{						  // ���� 42D4�� BM�̹Ƿ� ��Ʋ ����ȿ� ���� ����� ��
		return E_FAIL;
	}							 
	if (bih.biBitCount != 32)
	{
		return E_FAIL;
	}

	// 4. bfoffBits  �� ��ŭ �ǳʶٱ�
	file.seekg(bfh.bfOffBits);
	// 5. �ȼ� ������ �б�
	std::vector<char> pPixels(bih.biSizeImage);
	file.read(&pPixels[0], bih.biSizeImage);
	// 6. 5�� �����ͷ� Bit map �����
	return S_OK;
}
