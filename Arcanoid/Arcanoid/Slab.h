#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

class Slab
{
public:
	friend class SlabMenager;
	Slab(float argX, float argY, int live);
	~Slab();
	sf::RectangleShape slab;
	void update();
	void Draw(sf::RenderWindow & window);
	void removeLive();
	sf::Color color3{ 93, 244, 56 };  //{ 101, 244, 66 };
	sf::Color color2{ 190, 244, 65 };
	sf::Color color1{ 244, 97, 65 };
	float getHeight();
	float getWidth();
	int live;
private:
	float width{ 65 };
	float height{ 20 };
	sf::Text liveCount;
	sf::Font font;
};

