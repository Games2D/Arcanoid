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
	Ball newBall1(game, game->player->paddle.getPosition().x, game->player->paddleTopDistance - 50, sf::Vector2f{ 1.0f, -1.0f });
	Ball newBall2(game, game->player->paddle.getPosition().x, game->player->paddleTopDistance - 50, sf::Vector2f{ -1.0f, -1.0f });
	/*game->ballList.push_back(newBall1);
	game->ballList.push_back(newBall2);*/
}

void BallMultipler::stopAction()
{
}
