#include "Game.h"
#include <string>
namespace Solitare
{
	void Game::Init()
	{
		mBackGround = std::make_unique<Gdiplus::Image>(L"Data/bg_blank.png");
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
		Gdiplus::SolidBrush brush(Gdiplus::Color(255, 79, 64));
		Gdiplus::Font font(L"¸¼Àº °íµñ", 20);
		Gdiplus::PointF pos(895.0f, 20.0f);

		graphics.DrawString(L"Å¬¸¯ ¼ö : ", -1, &font, pos, &brush);

		Gdiplus::StringFormat format;

		format.SetAlignment(Gdiplus::StringAlignmentCenter);
		format.SetLineAlignment(Gdiplus::StringAlignmentCenter);

		graphics.DrawString(
			std::to_wstring(mFlipCounter).c_str(),
			-1, &font, mCountRect, &format, &brush);
	}

	void Game::OnClick(int mouseX, int mouseY)
	{
		for (auto& card : mDeck)
		{
			if (card.CheckCliked(mouseX, mouseY))
			{
				//TODO : Å¬¸¯Ã³¸®
			}
		}
	}

	void Game::CreateCards()
	{
		//TODO Ä«µå ¼¯±â
		mDeck.push_back(Solitare::Card(Type::Bear, 0, 0));
		mDeck.push_back(Solitare::Card(Type::Wolf, 120, 0));
		mDeck.push_back(Solitare::Card(Type::Dragon, 240, 0));

	}

}