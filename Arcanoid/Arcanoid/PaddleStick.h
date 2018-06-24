#pragma once
#include "stdafx.h"
#include "Bonus.h"

class Game;

class PaddleStick :
	public Bonus
{
public:
	PaddleStick(Game* ga);
	~PaddleStick();
	void action(float DeltaTime);
	void startAction();
	void stopAction();
};

