#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

class Game;
class Interface
{
public:
	Interface(Game* ga);
	~Interface() = default;
	void update();
	void Draw(sf::RenderWindow & window);
	float getHeight();
private: 
	float partucularTranslate;
	void updateScorText();
	void updateLvlText();
	sf::Sprite background;
	float width;
	float height{ 200 };
	float topGlobalPosition;
	sf::Texture backgroundTexture;
	sf::Texture ballMultiplerTexture;
	sf::Texture paddleShrinkTexture;
	sf::Texture paddleTenterTexture;
	sf::Texture speedAccelerantTexture;
	sf::Texture paddleStickTexture;
	sf::Texture paddleShuterTexture;
	sf::Sprite ballMultipler;
	sf::Sprite paddleShrink;
	sf::Sprite paddleTenter;
	sf::Sprite speedAccelerant;
	sf::Sprite paddleStick;
	sf::Sprite paddleShuter;
	sf::Font font;
	sf::Text scor;
	sf::Text lvl;
	sf::Text bonus;
	sf::Text scorValue;
	sf::Text lvlValue;
	float margin{ 30 };
	Game * game;
};

