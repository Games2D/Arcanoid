#include "PaddleShuter.h"
#include "Game.h"


PaddleShuter::PaddleShuter(Game * ga, float x, float  y) : Bonus()
{
	game = ga;
	texture.loadFromFile("PaddleShuter.png");
	obj.setTexture(texture);
	obj.setOrigin(obj.getLocalBounds().width / 2, obj.getLocalBounds().height / 2);
	obj.setPosition(x, y);
}

void PaddleShuter::action(float DeltaTime)
{
}

void PaddleShuter::startAction()
{
}

void PaddleShuter::stopAction()
{
}

