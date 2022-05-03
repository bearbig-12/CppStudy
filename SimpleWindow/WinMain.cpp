#include <Windows.h>

// HINSTANCE : Handle(pointer) of INSTANCE
// LPSTR : Long Pointer to NULL - Terminated STRing

int WINAPI WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nShowCmd
)
{
	MessageBox(nullptr, L"HelloWorld", L"SimpleWorld", MB_ICONEXCLAMATION | MB_OK);

	return 0;
}