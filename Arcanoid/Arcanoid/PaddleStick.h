#pragma once
#include "stdafx.h"

class Game;
class Bonus;

class PaddleStick :
	public virtual Bonus
{
public:
	PaddleStick(Game* ga, float x, float  y);
	virtual ~PaddleStick() = default;
	void action(float DeltaTime);
	void startAction();
	void stopAction();
};

