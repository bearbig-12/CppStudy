#include "Game.h"

namespace Solitare
{
	void Game::Init()
	{
		mBackGround = std::make_unique<Gdiplus::Image>(L"data/bg_blank.png");

		CreateCards();
	}

	void Game::Release()
	{
		mDeck.clear();
		mBackGround.reset();
	}

	void Game::Draw(Gdiplus::Graphics& graphics)
	{
		//BackGround Draw
		graphics.DrawImage(mBackGround.get(), 0, 0,
			mBackGround->GetWidth(), mBackGround->GetHeight());

		//Card Draw
		for (auto& card : mDeck)
		{
			card.Draw(graphics);
		}

		Gdiplus::PointF pos(895.0f, 20.0f);

		Gdiplus::SolidBrush brush(Gdiplus::Color(255, 79, 64));
		Gdiplus::Font font(L"¸¼Àº °íµñ", 20);

		graphics.DrawString(L"Å¬¸¯ ¼ö : ", -1, &font, pos, &brush);
	}

	void Game::OnClick(int mouseX, int mouseY)
	{
	}

	void Game::CreateCards()
	{
	}

}