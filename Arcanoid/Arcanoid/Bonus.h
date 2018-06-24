#pragma once
#include "stdafx.h"

class Game;

class Bonus
{
public:
	friend class BonusMenager;
	Bonus() = default;
	~Bonus() = default;
	sf::Sprite obj;
	sf::Texture texture;
	sf::Vector2f gravity{ 0.0f, 20 };
	sf::Vector2f moveVector{ 0.0f, -50.0f };
	void update(float DetlaTime);
	void Draw(sf::RenderWindow & window);
	virtual void startAction() = 0;
	virtual void stopAction() = 0;
	bool getDestroyStatus();
private:
	float destructionTimer{ 4 };
	bool visibilyty = true;
	bool destructionStatus{ false };

	virtual void action(float DeltaTime) = 0;
	Game* game;
};

