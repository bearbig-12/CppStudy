#include "BitmapManager.h"
#include "ComException.h"
#pragma comment (lib, "WindowsCodecs.lib")

using namespace Microsoft::WRL;



HRESULT BitmapManager::Initialize(ID2D1HwndRenderTarget* pRT)
{
    if (pRT == nullptr)
    {
        return E_FAIL;
    }

    mpRenderTarget = pRT;

    HRESULT hr = CoCreateInstance(CLSID_WICImagingFactory,
        nullptr,
        CLSCTX_INPROC_SERVER,
        IID_PPV_ARGS(mspWICFactory.GetAddressOf())
        );
    ThrowIfFailed(hr, "Can not init COM");

    return hr;
}

void BitmapManager::Release()
{
    for (auto& bitmap : mBitmapResources)
    {
        bitmap.second.Reset();
    }

    mBitmapResources.clear();
    mspWICFactory.Reset();
}


HRESULT BitmapManager::LoadWICBitmap(std::wstring filename, ID2D1Bitmap** ppBitmap)
{
	auto pWICFactory{ mspWICFactory.Get() };
	if (pWICFactory == nullptr)
	{
		return E_FAIL;
	}

	// 1. 디코더를 생성

	Microsoft::WRL::ComPtr<IWICBitmapDecoder> bitmapDecoder;

	HRESULT hr;


	hr = pWICFactory->CreateDecoderFromFilename(
		filename.c_str(),
		nullptr,
		GENERIC_READ,
		WICDecodeMetadataCacheOnLoad,
		bitmapDecoder.GetAddressOf()
	);
	ThrowIfFailed(hr);




	// 2. 프레임 선택
	Microsoft::WRL::ComPtr<IWICBitmapFrameDecode> frame;
	hr = bitmapDecoder->GetFrame(0, frame.GetAddressOf());
	ThrowIfFailed(hr);




	// 3. Format Converter - 우리가 원하는 BGRA8888
	Microsoft::WRL::ComPtr<IWICFormatConverter> converter;
	hr = pWICFactory->CreateFormatConverter(converter.GetAddressOf());
	ThrowIfFailed(hr);



	hr = converter->Initialize(
		frame.Get(),
		GUID_WICPixelFormat32bppPBGRA,
		WICBitmapDitherTypeNone,
		nullptr,
		0,				//threshold
		WICBitmapPaletteTypeCustom
	);
	ThrowIfFailed(hr);



	// 4.  픽셀 배열

	hr = mpRenderTarget->CreateBitmapFromWicBitmap(
		converter.Get(),
		ppBitmap
	);
	ThrowIfFailed(hr);


	return S_OK;
}

ID2D1Bitmap* BitmapManager::LoadBitmap(std::wstring filename)
{
	if (mspWICFactory == nullptr)
	{
		return nullptr;
	}

	auto result = mBitmapResources.insert({filename, nullptr});

	if (result.second == true)
	{
		auto spBitmap = ComPtr<ID2D1Bitmap>();
		LoadWICBitmap(filename, spBitmap.GetAddressOf());

		result.first->second = spBitmap;
	}

		
    return result.first->second.Get();
}
