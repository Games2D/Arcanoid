#pragma once
#include "stdafx.h"

class Game;
class Bonus;

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

