#pragma once
#include <Windows.h>
#include <gdiplus.h>
#include <memory>

namespace Solitare
{
	enum class Type
	{
		Wolf,
		Dragon,
		Bear
	};
	class Card
	{
	
		std::unique_ptr<Gdiplus::Image> mBack;
		std::unique_ptr<Gdiplus::Image> mFront;

		int mX;
		int mY;
		bool mIsFront;
		Type mType;
	protected:
		Card(){ }
	public:
		Card(Type type, int x, int y);

		bool CheckCliked(int mouseX, int mouseY);
		void Click_Turn(bool isFront);
		void Draw(Gdiplus::Graphics& graphics);
	};

}

