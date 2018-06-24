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

class Bonus
{
public:
	friend class BonusMenager;
	Bonus();
	virtual ~Bonus() = default;
	sf::Sprite obj;
	sf::Texture texture;
	sf::Vector2f gravity;
	sf::Vector2f moveVector;
	void update(float DetlaTime);
	void Draw(sf::RenderWindow & window);
	bool destTimer(float DeltaTime);
	bool getDestroyStatus();
	virtual void startAction() = 0;
	virtual void stopAction() = 0;
	virtual void action(float DeltaTime) = 0; // obs³uga tego co siê dzieje w trakcie akcji
protected:
	float destructionTimer;
	bool visibilyty;
	bool destructionStatus;
	Game* game;
};

