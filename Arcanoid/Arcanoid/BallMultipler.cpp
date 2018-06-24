#include "BallMultipler.h"



BallMultipler::BallMultipler(Game * ga, float x,float  y) : Bonus()
{
	game = ga;
	texture.loadFromFile("BallMultipler.png");
	obj.setTexture(texture);
	obj.setOrigin(obj.getLocalBounds().width / 2, obj.getLocalBounds().height / 2);
	obj.setPosition(x, y);
}

void BallMultipler::action(float DeltaTime)
{
}

void BallMultipler::startAction()
{
}

void BallMultipler::stopAction()
{
}
