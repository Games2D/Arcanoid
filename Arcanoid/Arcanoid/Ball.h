#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "Game.h"

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

class Ball
{
public:
	Ball(Game * ga, float argX, float argY);
	Ball(Game * ga, float argX, float argY, sf::Vector2f dir);
	~Ball() = default;

	sf::Color color{ 255, 255, 255 };
	sf::CircleShape ball;
	void update(const float &DeltaTime);
	void Draw(sf::RenderWindow & window);
	float velocity{ 365 };
	float velocityBonus{ 0 };
	sf::Vector2f direction{ 1.0f, -1.0f};
private:
	void checkColisionWitchSlab();
	float radius{ 7 };
	Game * game;
};

