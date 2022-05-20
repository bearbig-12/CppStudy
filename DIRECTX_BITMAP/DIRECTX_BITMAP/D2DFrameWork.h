#pragma once

#include <d2d1.h>
#include <wrl/client.h>
#include <exception>
#include <sstream>

class com_exception : public std::exception
{
private:
	HRESULT mResult;
public:
	com_exception(HRESULT hr) : mResult{ hr } {}
	virtual const char* what() const override
	{
		/*static char buf[128];

		sprintf_s(buf, 128, "Failure with HRESULT of 0X%08X", mResult);

		return buf;*/

		std::stringstream ss;
		ss << "Failure with Code : " << mResult << std::endl;
		return ss.str().c_str();
	}

};
// inline 
//		����: ȣ�⽺���� ������� �ʾƼ� ����
//		����: �ڵ� �����

// ����/����
//	inline void f()
//	{
//	}
// 
//	����� ����
//	void f();
//  inline void f();

// Ŭ������ ��� .h�� ����
inline void ThrowIfFailed(HRESULT hr)
{
	if (FAILED(hr))
	{
		throw com_exception(hr);
	}
}

class D2DFrameWork
{
private:
	const LPCWSTR WND_CLASS_NAME{ L"MyD2DWindowClass" };

protected:
	HWND mHwnd{};
	Microsoft::WRL::ComPtr<ID2D1Factory> mspD2DFactory{};
	Microsoft::WRL::ComPtr<ID2D1HwndRenderTarget> mspRenderTarget{};

protected:
	HRESULT InitWindow(HINSTANCE hInstance, LPCWSTR title,
		UINT width, UINT height);		// ������ �ʱ�ȭ �Լ�.

	HRESULT InitD2D();
	virtual HRESULT CreateDeviceResources();

public:
	virtual HRESULT Initialize(HINSTANCE hInstance,
		LPCWSTR title = L"MyFrameWork",
		UINT width = 1024,
		UINT height = 768);
	virtual void Release();
	virtual int GameLoop();
	virtual void Render();

	static void ShowErrorMsg(LPCWSTR msg, LPCWSTR title = L"Error");

public:
	static LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam);

};

