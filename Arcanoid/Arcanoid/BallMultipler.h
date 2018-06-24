#pragma once
#include "stdafx.h"

class Game;
class Bonus;

class BallMultipler :
	public virtual Bonus
{
public:
	BallMultipler(Game* ga, float x, float  y);
	virtual ~BallMultipler() = default;
	void action(float DeltaTime);
	void startAction();
	void stopAction();
};

