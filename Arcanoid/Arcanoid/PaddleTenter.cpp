#include "PaddleTenter.h"
#include "Game.h"


PaddleTenter::PaddleTenter(Game * ga, float x, float  y) : Bonus()
{
	name = "PaddleTenter";
	game = ga;
	texture.loadFromFile("PaddleTenter.png");
	obj.setTexture(texture);
	obj.setOrigin(obj.getLocalBounds().width / 2, obj.getLocalBounds().height / 2);
	obj.setPosition(x, y);
}

PaddleTenter::~PaddleTenter()
{
	stopAction();
}

void PaddleTenter::action(float DeltaTime)
{
}

void PaddleTenter::startAction()
{
	refreshPaddleSize();

	tenterSizeValue = paddleSizeActualy.x * tenterLvl;
	tenterOriginValue = paddleOriginActualy.x * tenterLvl;

	game->player->paddle.setSize(sf::Vector2f{ paddleSizeActualy.x * (1 + tenterLvl), paddleSizeActualy.y });
	game->player->paddle.setOrigin(paddleOriginActualy.x * (1 + tenterLvl), paddleOriginActualy.y);
}

void PaddleTenter::stopAction()
{
	refreshPaddleSize();

	game->player->paddle.setSize(sf::Vector2f{ paddleSizeActualy.x - tenterSizeValue, paddleSizeActualy.y });
	game->player->paddle.setOrigin(paddleOriginActualy.x - tenterOriginValue, paddleOriginActualy.y);
}

void PaddleTenter::refreshPaddleSize()
{
	paddleSizeActualy = game->player->paddle.getSize();
	paddleOriginActualy = game->player->paddle.getOrigin();
}

