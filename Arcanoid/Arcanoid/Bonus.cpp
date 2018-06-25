#include "Bonus.h"
#include "Game.h"

Bonus::Bonus()
{
	gravity = sf::Vector2f{ 0.0f, 3 };
	moveVector = sf::Vector2f{ 0.0f, -300.0f };
	destructionTimer = float{ 4.0f };
	visibilyty = bool{ true };
	destructionStatus = bool{ false };
}

void Bonus::update(float DeltaTime)
{
	if (visibilyty) {

		if(moveVector.y < 1100 )
			moveVector += gravity;
		obj.move(moveVector * DeltaTime);
		if(obj.getPosition().y > game->windowMode.height) // je¿eli bonus przepad³
			destructionStatus = true;
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
