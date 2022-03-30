#include "Point2D.h"
#include<iostream>
#include<cmath>

void Point2D::SetCoord(int x, int y)
{
	mX = x;
	mY = y;
}

float Point2D::GetDistance()
{
	int xDis = mX;
	int yDis = mY;
	return mDistance = sqrt(pow(xDis, 2) + pow(yDis,2));
}

void Point2D::PrintResult()
{
	std::cout << "(" << mX << " , " << mY << ")" << std::endl;
	std::cout << "Distance from (0 , 0) = " << mDistance << std::endl;
}