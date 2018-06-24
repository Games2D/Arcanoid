#pragma once
#include "stdafx.h"
#include "Bonus.h"

class Game;


class BallMultipler :
	public Bonus
{
public:
	BallMultipler(Game* ga);
	~BallMultipler();
	void action(float DeltaTime);
	void startAction();
	void stopAction();
};

