#pragma once
#include "stdafx.h"
#include "Bonus.h"

class Game;

class PaddleShrink :
	public Bonus
{
public:
	PaddleShrink(Game* ga);
	~PaddleShrink();
	void action(float DeltaTime);
	void startAction();
	void stopAction();
};

