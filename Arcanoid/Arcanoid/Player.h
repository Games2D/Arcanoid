#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

class Game;

class Player
{
public:
	friend class BallMultipler;
	Player();
	Player(Game * ga, float argX);
	~Player() = default;
	void setPlayer(Game * ga, float argX);
	void update(sf::Vector2i mousePos, float DeltaTime);
	void Draw(sf::RenderWindow & window);
	sf::FloatRect getGlobalBounds();
	float getXposition();
	float getYposition();
	float xPositionOneSecBefore{ 0 };
	float positionRefresher{ 0 };
private:
	Game * game;
	float width{ 80 };
	float height{ 5 };
	float paddleBotomDistance{ 60 };
	float paddleTopDistance;
	sf::Color color{ 0,0,0 };
	sf::RectangleShape paddle{ sf::Vector2f{ width, height } };
};

