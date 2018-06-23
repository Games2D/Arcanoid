#pragma once
#include "stdafx.h"

class Player;
class SlabMenager;

class Game
{
public:
	friend class SlabMenager;
	Game();
	~Game();
	void run();
	sf::VideoMode windowMode{ 540, 640 };
	Player* player;
	SlabMenager *slabMenager;
private:
	sf::RenderWindow window{ windowMode, "Arcanoid", sf::Style::Default };
	sf::Clock gameClock;
	float DeltaTime{ 1 / 60.0f };
};

