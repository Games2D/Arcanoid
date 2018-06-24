#include "Player.h"


Player::Player()
{
	game = nullptr;
}

Player::Player(Game * ga, float argX)
{
	setPlayer(ga, argX);
}

void Player::setPlayer(Game * ga, float argX)
{
	game = ga;
	paddleTopDistance = game->windowMode.height - paddleBotomDistance;

	paddle.setPosition(argX, paddleTopDistance);
	paddle.setOrigin(width / 2, height / 2);
	paddle.setFillColor(color);
}

void Player::update(sf::Vector2i mousePos,float DeltaTime)
{
	if(mousePos.x - width / 2 > 0 
		&& mousePos.x + width / 2 < game->windowMode.width)
	paddle.setPosition(mousePos.x, paddleTopDistance);

	if (positionRefresher > 0.05) {
		positionRefresher = 0.0f;
		xPositionOneSecBefore = mousePos.x;
		
	}
	else {
		positionRefresher += DeltaTime;
	}
}

void Player::Draw(sf::RenderWindow & window)
{
	window.draw(paddle);
}

sf::FloatRect Player::getGlobalBounds()
{
	return paddle.getGlobalBounds();
}

float Player::getXposition()
{
	return paddle.getPosition().x;
}

float Player::getYposition()
{
	return paddle.getPosition().y;
}
