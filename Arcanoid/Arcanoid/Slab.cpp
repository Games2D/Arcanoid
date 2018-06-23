#include "Slab.h"
#include "stdafx.h"

Slab::Slab(float argX, float argY, int live)
{
	this->live = live;

	slab.setOrigin(width / 2, height / 2);
	slab.setPosition(argX, argY);
	slab.setSize(sf::Vector2f(width, height));
	slab.setOutlineColor(sf::Color(28, 26, 26));
	slab.setOutlineThickness(2);

	//if (live == 3) {

	//	liveCount.setString("3");
	//	slab.setFillColor(color3);
	//}

	//else if (live == 2) {

	//	liveCount.setString("2");
	//	slab.setFillColor(color2);
	//}

	//else {

	//	liveCount.setString("1");
	//	slab.setFillColor(color1);
	//}


	font.loadFromFile("Roboto-Medium.ttf");
	liveCount.setFont(font);
	liveCount.setFillColor(sf::Color(28, 26, 26));
	liveCount.setCharacterSize(15);
	liveCount.setOrigin(liveCount.getLocalBounds().width / 2, height/2 );
	liveCount.setPosition(argX, argY);

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
	else {

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
}

float Slab::getHeight()
{
	return height;
}

float Slab::getWidth()
{
	return width;
}
