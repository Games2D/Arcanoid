#include "PaddleShrink.h"



PaddleShrink::PaddleShrink(Game * ga, float x, float  y) : Bonus()
{
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
}

void PaddleShrink::stopAction()
{
}

