#pragma once
#include "stdafx.h"
#include "Bonus.h"

class Game;

class PaddleShuter :
	public Bonus
{
public:
	PaddleShuter(Game* ga);
	~PaddleShuter();
	void action(float DeltaTime);
	void startAction();
	void stopAction();
};

