#pragma once
#include "stdafx.h"

class Player;
class SlabMenager;
class BonusMenager;
class BallMenager;
class Ball;

class Game
{
public:
	friend class SlabMenager;
	friend class BonusMenager;
	friend class BallManager;
	friend class Slab;
	Game();
	~Game();
	void run();
	sf::VideoMode windowMode{ 540, 640 };
	Player* player;
	SlabMenager *slabMenager;
	BonusMenager *bonusMenager;
	BallManager* ballManager;
	sf::Font font;
private:
	int playerPoints{ 0 };
	int lvlCounter{ 1 };
	sf::Text lvlText;
	void refreshTextCounter();
	sf::RenderWindow window{ windowMode, "Arcanoid", sf::Style::Default };
	sf::Clock gameClock;
	float DeltaTime{ 1 / 60.0f };
};

