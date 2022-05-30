#pragma once
#include <vector>
#include <memory>
#include "D2DFramework.h"
#include "Actor.h"
#include "ComException.h"
class ActorExample : public D2DFramework
{
	std::unique_ptr<Actor> mspBackground;
	std::vector<std::unique_ptr<Actor>> mspBug;

public:
	virtual HRESULT Initialize(HINSTANCE hInstance, LPCWSTR title = L"Actor Example", UINT width = 1024, UINT height = 768) override
	{
		HRESULT hr;
		hr = D2DFramework::Initialize(hInstance, title, width, height);
		ThrowIfFailed(hr);

		// �������� �ʱ�ȭ �ʿ��� ��
		mspBackground = std::make_unique<Actor>(this, L"Data/back1_1024.png", 0.0f, 0.0f);
		for (int i = 0; i < 20; ++i)
		{
			mspBug.push_back(std::make_unique<Actor>(this, L"Data/bug1_1.png", i * 20.0f, 100.0f));
		}

		return S_OK;
	}

	virtual void Release() override
	{
		// �������� ����� �����޸� ����
		for (auto& e : mspBug)
		{
			e.reset();
		}
		mspBackground.reset();

		D2DFramework::Release();
	}

	virtual void Render() override
	{
		HRESULT hr;

		mspRenderTarget->BeginDraw();
		mspRenderTarget->Clear(D2D1::ColorF(0.0f, 0.2f, 0.4f, 1.0f));

		// �������� �׸� ��
		mspBackground->Draw();
		for (auto& e : mspBug)
		{
			e->Draw();
		}

		hr = mspRenderTarget->EndDraw();
		if (hr == D2DERR_RECREATE_TARGET)
		{
			CreateDeviceResources();
		}
	}
};

