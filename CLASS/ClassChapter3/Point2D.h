#pragma once
#include <iostream>

class Point2D
{
private:
	int mX;
	int	mY;
	float mDistance;
public:


	Point2D()
	{
		mX = 0;
		mY = 0;
		mDistance = 0;
	}
	~Point2D() {};

	void SetCoord(int x, int y);
	float GetDistance();
	void PrintResult();


};

