#pragma once
#include "stdafx.h"
#include "Bonus.h"

class Game;

class PaddleTenter :
	public Bonus
{
public:
	PaddleTenter(Game* ga);
	~PaddleTenter();
	void action(float DeltaTime);
	void startAction();
	void stopAction();
};

