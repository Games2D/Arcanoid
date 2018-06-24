#include "Bonus.h"
#include "Game.h"

Bonus::Bonus()
{
	gravity = sf::Vector2f{ 0.0f, 20 };
	moveVector = sf::Vector2f{ 0.0f, -50.0f };
	destructionTimer = float{ 4.0f };
	visibilyty = bool{ true };
	destructionStatus = bool{ false };
}

void Bonus::update(float DeltaTime)
{
	if (visibilyty) {

		moveVector += gravity;
		obj.move(moveVector);
	}
	else {

		action(DeltaTime);
		if (destTimer(DeltaTime)) {

			destructionStatus = true;
			stopAction();
		}
	}
}

void Bonus::Draw(sf::RenderWindow & window)
{
	if(visibilyty)
		window.draw(obj);
}

bool Bonus::destTimer(float DeltaTime)
{
	if(destructionTimer > 0) {

		destructionTimer -= DeltaTime;
		return false;
	}
	return true;
}

bool Bonus::getDestroyStatus()
{
	return destructionStatus;
}
