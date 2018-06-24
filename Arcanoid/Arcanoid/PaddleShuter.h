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

