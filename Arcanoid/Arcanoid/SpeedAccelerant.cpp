#include "SpeedAccelerant.h"




SpeedAccelerant::SpeedAccelerant(Game * ga, float x, float  y) : Bonus()
{
	game = ga;
	texture.loadFromFile("SpeedAccelerant.png");
	obj.setTexture(texture);
	obj.setOrigin(obj.getLocalBounds().width / 2, obj.getLocalBounds().height / 2);
	obj.setPosition(x, y);
}

void SpeedAccelerant::action(float DeltaTime)
{
}

void SpeedAccelerant::startAction()
{
}

void SpeedAccelerant::stopAction()
{
}
