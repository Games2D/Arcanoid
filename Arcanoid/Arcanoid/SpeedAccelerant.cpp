#include "SpeedAccelerant.h"
#include "Game.h"

SpeedAccelerant::SpeedAccelerant(Game * ga, float x, float  y) : Bonus()
{
	name = "SpeedAccelerant";
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
	game->ballManager->speedAccelerate(velocityBonus);
}

void SpeedAccelerant::stopAction()
{
	game->ballManager->speedAccelerate(-velocityBonus);
}
