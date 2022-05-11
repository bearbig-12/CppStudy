#include "Card.h"
#include <string>

namespace Solitare
{
	Card::Card(Type type, int x, int y) :
		mX(x) , mY(y), mIsFront(false), mType(type)
	{
		std::wstring filename(L"Data/card_creature_");
		switch (type)
		{
		case Solitare::Type::Wolf:
			filename += L"wolf.png";
			break;
		case Solitare::Type::Dragon:
			filename += L"dragon.png";

			break;
		case Solitare::Type::Bear:
			filename += L"bear.png";

			break;
		default:
			break;
		}
		mFront = std::make_unique<Gdiplus::Image>(filename.c_str());
		mBack = std::make_unique<Gdiplus::Image>(L"Data/card_back_png");
	}
	bool Card::CheckCliked(int mouseX, int mouseY)
	{
		return false;
	}
	void Card::Click_Turn(bool isFront)
	{
		mIsFront = isFront;
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
}

