#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "Game.h"
#include "Bonus.h"

class Bonus;
class Ball;
class BallMenager;
class MallMultipler;
class BonusMenager;
class Game;
class PaddleShrink;
class PaddleShuter;
class PaddleStick;
class PaddleTenter;
class Player;
class Slab;
class SlabMenager;
class SpeedAccelerant;

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

