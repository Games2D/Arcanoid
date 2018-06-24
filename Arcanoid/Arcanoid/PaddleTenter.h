#pragma once
#include "stdafx.h"

class Game;
class Bonus;

class PaddleTenter :
	public virtual Bonus
{
public:
	PaddleTenter(Game* ga, float x, float  y);
	virtual ~PaddleTenter() = default;
	void action(float DeltaTime);
	void startAction();
	void stopAction();
};

