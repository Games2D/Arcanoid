#pragma once
#include "stdafx.h"
#include "Bonus.h"

class Game;

class SpeedAccelerant :
	public Bonus
{
public:
	SpeedAccelerant(Game* ga);
	~SpeedAccelerant();
	void action(float DeltaTime);
	void startAction();
	void stopAction();
};

