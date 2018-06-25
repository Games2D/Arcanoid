#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "Player.h"
#include "BallManager.h"
#include "SlabMenager.h"
#include "BonusMenager.h"
#include "Interface.h"
#include "Menu.h"

class BallManager;
class BonusMenager;
class SlabMenager;
class Player;
class Interface;

class Game
{
public:
	friend class SlabMenager;
	friend class BonusMenager;
	friend class BallManager;
	friend class Menu;
	Game();
	~Game();
	void run();
	sf::VideoMode windowMode{ 540, 840 };
	Player* player;
	SlabMenager *slabMenager;
	BonusMenager *bonusMenager;
	BallManager* ballManager;
	Interface* gameInterface;
	Menu* menu;
	sf::Font font;
	sf::Text lvlText;
	int playerPoints{ 0 };
private:
	sf::Color backgroundColor{ 40, 40, 40 };
	int lvlCounter{ 1 };
	void refreshTextCounter();
	sf::RenderWindow window{ windowMode, "Arcanoid", sf::Style::Default };
	sf::Clock gameClock;
	float DeltaTime{ 1 / 60.0f };
};

