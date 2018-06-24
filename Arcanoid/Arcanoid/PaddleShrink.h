#pragma once
#include "stdafx.h"

class Game;
class Bonus;

class PaddleShrink :
	public virtual Bonus
{
public:
	PaddleShrink(Game* ga, float x, float  y);
	virtual ~PaddleShrink() = default;
	void action(float DeltaTime);
	void startAction();
	void stopAction();
};

