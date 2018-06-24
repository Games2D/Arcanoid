#pragma once
#include "stdafx.h"

class Game;
class Ball;

class BallManager
{
public:
	BallManager(Game* ga);
	~BallManager() = default;
	void update(float DeltaTime);
	void respawnBall();
	void clearList();
private:
	mutable std::list<Ball> ballList;
	Game* game;

};

