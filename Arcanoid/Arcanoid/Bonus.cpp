#include "Bonus.h"

void Bonus::update(float DeltaTime)
{
	if (visibilyty) {

		moveVector += gravity;
		obj.move(moveVector);
	}
	else action(DeltaTime);
}

void Bonus::Draw(sf::RenderWindow & window)
{
	if(visibilyty)
		window.draw(obj);
}

void Bonus::startAction()
{
}

void Bonus::stopAction()
{
}

bool Bonus::getDestroyStatus()
{
	return destructionStatus;
}
