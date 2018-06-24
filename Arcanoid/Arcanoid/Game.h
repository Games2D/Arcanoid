#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "Player.h"
#include "BallManager.h"
#include "SlabMenager.h"
#include "BonusMenager.h"

class BallManager;
class BonusMenager;
class SlabMenager;
class Player;

class Game
{
public:
	friend class SlabMenager;
	friend class BonusMenager;
	friend class BallManager;
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

