#include "PaddleTenter.h"
#include "Game.h"


PaddleTenter::PaddleTenter(Game * ga, float x, float  y) : Bonus()
{
	game = ga;
	texture.loadFromFile("PaddleTenter.png");
	obj.setTexture(texture);
	obj.setOrigin(obj.getLocalBounds().width / 2, obj.getLocalBounds().height / 2);
	obj.setPosition(x, y);
}

void PaddleTenter::action(float DeltaTime)
{
}

void PaddleTenter::startAction()
{
}

void PaddleTenter::stopAction()
{
}

