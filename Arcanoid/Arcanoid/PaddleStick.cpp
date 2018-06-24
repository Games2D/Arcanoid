#include "PaddleStick.h"


PaddleStick::PaddleStick(Game * ga, float x, float  y) : Bonus()
{
	game = ga;
	texture.loadFromFile("PaddleStick.png");
	obj.setTexture(texture);
	obj.setOrigin(obj.getLocalBounds().width / 2, obj.getLocalBounds().height / 2);
	obj.setPosition(x, y);
}

void PaddleStick::action(float DeltaTime)
{
}

void PaddleStick::startAction()
{
}

void PaddleStick::stopAction()
{
}
