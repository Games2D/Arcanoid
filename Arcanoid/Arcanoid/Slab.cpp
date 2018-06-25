#include "Slab.h"

Slab::Slab(float argX, float argY, int li)
{
	live = li;

	slab.setOrigin(width / 2, height / 2);
	slab.setPosition(argX, argY);
	slab.setSize(sf::Vector2f(width, height));
	slab.setOutlineColor(sf::Color(76, 76, 76)); //obwódka p³ytki
	slab.setOutlineThickness(2);

	font.loadFromFile("Roboto-Medium.ttf");
	liveCount.setFont(font);
	liveCount.setFillColor(sf::Color(40, 52, 94, 190));
	liveCount.setCharacterSize(14);
	liveCount.setOrigin((liveCount.getLocalBounds().width / 2 ) + 3, height/2 );
	liveCount.setPosition(argX, argY);

	update();
}

Slab::~Slab()
{
}

void Slab::update()
{
	if (live == 3) {

		liveCount.setString("3");
		slab.setFillColor(color3);
	}

	else if (live == 2) {

		liveCount.setString("2");
		slab.setFillColor(color2);
	}

	else if(live == 1) {

		liveCount.setString("1");
		slab.setFillColor(color1);
	}
	else if(live == 0){

		liveCount.setString("");
		slab.setFillColor(sf::Color::Transparent);
	}


}

void Slab::Draw(sf::RenderWindow & window)
{
	window.draw(slab);
	window.draw(liveCount);
}

void Slab::removeLive()
{
	live--;
	update();	
}

float Slab::getHeight()
{
	return height;
}

float Slab::getWidth()
{
	return width;
}
