#include "BallMultipler.h"
#include "Game.h"
#include "Ball.h"
#include <cmath>
#include <stdio.h>

BallMultipler::BallMultipler(Game * ga, float x,float  y) : Bonus()
{
	name = "BallMultipler";
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
	obj.move(0, 1000);
	std::list<std::list<Ball>::iterator> ballWskList;

	for (auto it = game->ballManager->ballList.begin(); it != game->ballManager->ballList.end(); it++) {

		ballWskList.push_back(it);
	}
	for (auto it = ballWskList.begin(); it != ballWskList.end(); it++) {

		auto wsk = *it;
		float x = wsk->direction.x;
		float y = wsk->direction.y;
		sf::Vector2f newDirection{ -(x * cos(alfa) - y * sin(alfa)), -(x * sin(alfa) + y * cos(alfa)) };
		game->ballManager->respawnBall(game, wsk->ball.getPosition().x, wsk->ball.getPosition().y, newDirection);
	}

}

void BallMultipler::stopAction()
{
}
