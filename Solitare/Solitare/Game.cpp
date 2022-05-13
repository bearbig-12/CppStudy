#include "Game.h"
#include <string>
#include <random>
#include <vector>

namespace Solitare
{
	void Game::Init(HWND hwnd)
	{
		mHwnd = hwnd;
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
		Card* pCard{};

		for (auto& card : mDeck)
		{
			if (card.CheckCliked(mouseX, mouseY))
			{
				//TODO : Å¬¸¯Ã³¸®
				pCard = &card;
				break;
			}
		}

		if (pCard != nullptr)
		{
			mFlipCounter++;
			RECT rect{
				static_cast<LONG>(mCountRect.GetLeft()),
				static_cast<LONG>(mCountRect.GetTop()),
				static_cast<LONG>(mCountRect.GetRight()),
				static_cast<LONG>(mCountRect.GetBottom())
			};
			InvalidateRect(mHwnd, &rect, false);
		}

		if (mpSelectedCard == nullptr)
		{
			mpSelectedCard = pCard;
		}
		else
		{
			if (pCard == mpSelectedCard)
			{
				return;
			}
			if (pCard->GetType() == mpSelectedCard->GetType())
			{
				UpdateWindow(mHwnd);
				Sleep(500);

				pCard->Invalidate();
				mpSelectedCard->Invalidate();

				mDeck.remove_if([&](Card& card) {
					return (card.GetIndex() == mpSelectedCard->GetIndex() ||
						card.GetIndex() == pCard->GetIndex());
					});

				mpSelectedCard = nullptr;
			}
			else
			{
				UpdateWindow(mHwnd);
				Sleep(500);				
				pCard->Click_Turn(false);
				mpSelectedCard->Click_Turn(false);

				mpSelectedCard = nullptr;
			}
		}
	}

	void Game::CreateCards()
	{

		std::vector<Type> types;
		while (types.size() < static_cast<size_t>(BOARD_COLUM * BOARD_ROW))
		{
			int temp = types.size() % 6;


			switch (temp)
			{
			case 0:
				types.push_back(Type::Bear);
				types.push_back(Type::Bear);
				break;
			case 2:
				types.push_back(Type::Wolf);
				types.push_back(Type::Dragon);
				break;
			case 4:
				types.push_back(Type::Bear);
				types.push_back(Type::Bear);
				break;
			default:
				break;
			}
		}

		std::random_device rd;
		std::mt19937 gen(rd());
		std::shuffle(types.begin(), types.end(), gen);

		int index{};
		int posX{ 15 }, posY{ 10 };

		for (int x = 0; x < BOARD_COLUM; ++x)
		{
			posY = 10;
			for (int y = 0; y < BOARD_ROW; ++y)
			{
				mDeck.push_back(Card(mHwnd, index ,types[index++], posX, posY));

				posY += 140 + 10;
			}
			posX += 100 + 10;

		}

		//TODO Ä«µå ¼¯±â
	/*	mDeck.push_back(Solitare::Card(mHwnd, Type::Bear, 0, 0));
		mDeck.push_back(Solitare::Card(mHwnd, Type::Wolf, 120, 0));
		mDeck.push_back(Solitare::Card(mHwnd, Type::Dragon, 240, 0));*/

	}

}