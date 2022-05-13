#include "Card.h"
#include <string>

namespace Solitare
{
	Card::Card(HWND hwnd,int index, Type type, int x, int y) :
		mHwnd(hwnd), mIndex{index}, mType(type), mX(x), mY(y), mIsFront(false)
	{
		std::wstring filename;
		switch (type)
		{
		case Type::Wolf:
			filename = L"Data/card_creature_wolf.png";
			break;

		case Type::Dragon:
			filename = L"Data/card_creature_dragon.png";
			break;

		case Type::Bear:
			filename = L"Data/card_creature_bear.png";
			break;

		default:
			break;
		}
		mFront = std::make_unique<Gdiplus::Image>(filename.c_str());
		mBack = std::make_unique<Gdiplus::Image>(L"Data/card_back.png");
	}
	bool Card::CheckCliked(int mouseX, int mouseY)
	{
		if (mouseX >= mX && mouseX <= mX + mBack->GetWidth() &&
			mouseY >= mY && mouseY <= mY + mBack->GetHeight())
		{
			Click_Turn(!mIsFront);
			return true;
		}
		return false;
	}
	void Card::Click_Turn(bool isFront)
	{
		mIsFront = isFront;
		Invalidate();
	}
	void Card::Draw(Gdiplus::Graphics& graphics)
	{
		if (mIsFront)
		{
			graphics.DrawImage(mFront.get(), mX, mY, mFront->GetWidth(), mFront->GetHeight());
		}
		else
		{
			graphics.DrawImage(mBack.get(), mX, mY, mBack->GetWidth(), mBack->GetHeight());

		}
	}
	void Card::Invalidate()
	{
		RECT rct{
			mX,mY,
			static_cast<LONG>(mX + mFront->GetWidth()),
			static_cast<LONG>(mY + mFront->GetHeight())
		};
		InvalidateRect(mHwnd, &rct, false);
	}
}

