#pragma once
#include "stdafx.h"

class Game;
class Slab;

class SlabMenager
{
public:
	SlabMenager(Game * ga);
	~SlabMenager() = default;
	void generateNewLvl();
	void update();
	std::list<Slab> slabList;
	int rowCount;
	float topDistance{ 150.0f };
	float slabSpace{ 5.0f };
	sf::Vector2f checkColision(sf::CircleShape &ball);
	mutable std::list<Slab>::iterator it;
private:
	Game * game;
	int i = 0;
};

