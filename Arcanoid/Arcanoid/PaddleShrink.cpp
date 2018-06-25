#include "PaddleShrink.h"
#include "Game.h"


PaddleShrink::PaddleShrink(Game * ga, float x, float  y) : Bonus()
{
	name = "PaddleShrink";
	game = ga;
	texture.loadFromFile("PaddleShrink.png");
	obj.setTexture(texture);
	obj.setOrigin(obj.getLocalBounds().width / 2, obj.getLocalBounds().height / 2);
	obj.setPosition(x, y);
}

void PaddleShrink::action(float DeltaTime)
{
}

void PaddleShrink::startAction()
{
	refreshPaddleSize();

	shrinkSizeValue = paddleSizeActualy.x * shrinkLvl;
	shrinkOriginValue = paddleOriginActualy.x * shrinkLvl;

	game->player->paddle.setSize(sf::Vector2f{ paddleSizeActualy.x * ( 1 - shrinkLvl ), paddleSizeActualy.y });
	game->player->paddle.setOrigin(paddleOriginActualy.x * ( 1 - shrinkLvl ), paddleOriginActualy.y);
}

void PaddleShrink::stopAction()
{
	refreshPaddleSize();

	game->player->paddle.setSize(sf::Vector2f{ paddleSizeActualy.x + shrinkSizeValue, paddleSizeActualy.y });
	game->player->paddle.setOrigin(paddleOriginActualy.x + shrinkOriginValue, paddleOriginActualy.y);
}

void PaddleShrink::refreshPaddleSize()
{
	paddleSizeActualy = game->player->paddle.getSize();
	paddleOriginActualy = game->player->paddle.getOrigin();
}

