#pragma once
#include "stdafx.h"

class Game;
class Bonus;

class PaddleShuter :
	public virtual Bonus
{
public:
	PaddleShuter(Game* ga, float x, float  y);
	virtual ~PaddleShuter() = default;
	void action(float DeltaTime);
	void startAction();
	void stopAction();
};

