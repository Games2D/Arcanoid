#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <list>
#include <iterator>
#include "Game.h"
#include "Bonus.h"
#include "BallMultipler.h"
#include "PaddleShrink.h"
#include "PaddleShuter.h"
#include "PaddleStick.h"
#include "PaddleTenter.h"
#include "SpeedAccelerant.h"

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

class BonusMenager
{
public:
	BonusMenager(Game * ga);
	~BonusMenager() = default;
	void update(float DeltaTime);
	void addBonus(float x, float y);
	void checkColision(sf::RectangleShape paddle);
private:
	Game * game;
	mutable std::list<Bonus*> bonusList;
};

