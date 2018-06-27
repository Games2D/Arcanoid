#include "PaddleStick.h"
#include "Game.h"

PaddleStick::PaddleStick(Game * ga, float x, float  y) : Bonus()
{
	name = "PaddleStick";
	game = ga;
	texture.loadFromFile("PaddleStick.png");
	obj.setTexture(texture);
	obj.setOrigin(obj.getLocalBounds().width / 2, obj.getLocalBounds().height / 2);
	obj.setPosition(x, y);
}

PaddleStick::~PaddleStick()
{
	stopAction();
}

void PaddleStick::action(float DeltaTime)
{
}

void PaddleStick::startAction()
{
	if (!game->ballManager->isSticky()) {

		active = true;
		game->ballManager->setSticky();
		playerColorBefore = game->player->paddle.getFillColor();
		game->player->paddle.setFillColor(sf::Color::Green);
	}
	else
		active = false;
	
}

void PaddleStick::stopAction()
{
	if (active) {

		game->ballManager->setUnSticky();
		game->player->paddle.setFillColor(playerColorBefore);
	}

}
