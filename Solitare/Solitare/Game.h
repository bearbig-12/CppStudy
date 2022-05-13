#pragma once
#include "Card.h"
#include <list>
namespace Solitare
{
	class Game
	{
		const int BOARD_COLUM = 8;
		const int BOARD_ROW = 5;
		const Gdiplus::RectF mCountRect{ 885.0f, 60.0f, 120.0f,30.0f };
	private:
		std::unique_ptr<Gdiplus::Image> mBackGround;
		std::list<Card> mDeck;
		int mFlipCounter;
		HWND mHwnd;

		Card* mpSelectedCard{};

	public:
		void Init(HWND hwnd);
		void Release();

		void Draw(Gdiplus::Graphics& graphics);
		void OnClick(int mouseX, int mouseY);
	private:
		void CreateCards();
	};

}


