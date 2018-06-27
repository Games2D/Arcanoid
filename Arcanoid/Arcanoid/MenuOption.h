#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

class Game;

class MenuOption
{
public:
	friend class Menu;
	MenuOption(Game* ga, float xPositionWindowCenter, float yPosition, std::string na);
	~MenuOption();
	std::string name;
	void update();
	void Draw(sf::RenderWindow & window);
	bool pressed();
private:
	bool presed{ false };
	bool clickDetection();
	sf::Text NAME;
	float toTopDistance;
	float width{ 180};
	float height{ 46 };
	sf::Color background{ 6, 31, 71 };
	sf::Color backgroundHover{ 7, 40, 94 };
	sf::Color outlineColor{ 1, 6, 15 };
	sf::RectangleShape rectangle{ sf::Vector2f{ width, height } };
	Game* game;
};

