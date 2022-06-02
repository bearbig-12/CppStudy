#pragma once
#include "Actor.h"

class Bug : public Actor
{
	enum class Direction
	{
		UP,
		UP_RIGHT,
		RIGHT,
		DOWN_RIGHT,
		DOWN,
		DOWN_LEFT,
		LEFT,
		UP_LEFT,

		// 방향의 갯수.
		COUNT // 8
	};

	Direction mDirection;
	float mSteps;


public:
	Bug(D2DFramework* pFramework);

	virtual void Draw() override;
};

