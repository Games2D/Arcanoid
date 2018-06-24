#pragma once
#include "stdafx.h"

class Game;
class Bonus;

class SpeedAccelerant :
	public virtual Bonus
{
public:
	SpeedAccelerant(Game* ga, float x, float  y);
	virtual ~SpeedAccelerant() = default;
	void action(float DeltaTime);
	void startAction();
	void stopAction();
};

