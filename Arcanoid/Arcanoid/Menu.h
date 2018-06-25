#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "Game.h"

class Game;

class Menu
{
public:
	Menu(Game* ga);
	~Menu() = default;
	void run(float* framStart);
	void update(sf::Vector2i mousePos);
	void Draw(sf::RenderWindow & window);
private:
	sf::RectangleShape background;
	bool display{ false };
	Game * game;
	sf::Text pause;
};

