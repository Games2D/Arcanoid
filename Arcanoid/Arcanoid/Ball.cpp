#include "Ball.h"
#include "Game.h"
#include "Slab.h"

Ball::Ball(Game * ga, float argX, float argY)
{
	game = ga;

	ball.setRadius(radius);
	ball.setPosition(argX, argY);
	ball.setFillColor(color);
	ball.setOrigin(radius, radius);
}

Ball::Ball(Game * ga, float argX, float argY, sf::Vector2f dir)
{
	game = ga;

	ball.setRadius(radius);
	ball.setPosition(argX, argY);
	ball.setFillColor(color);
	ball.setOrigin(radius, radius);
	direction.x = dir.x;
	direction.y = dir.y;
}

void Ball::update(const float &DeltaTime)
{
	if (ball.getPosition().x + radius >= game->windowMode.width)  //odbicia od œciany prawej
		direction.x *= -1;
	if (ball.getPosition().x - radius <= 0)                         //odbicia od œciany lewej
		direction.x *= -1;
	if (ball.getPosition().y + radius >= game->windowMode.height) {//odbicia od œciany dolnej

	}
	if (ball.getPosition().y - radius <= 0)                         //odbicia od œciany górnej
		direction.y *= -1;

	if (ball.getGlobalBounds().intersects(game->player->getGlobalBounds())) {

		velocityBonus = (game->player->getXposition() - game->player->xPositionOneSecBefore);
		velocityBonus = -velocityBonus;
		float y = velocityBonus / (velocityBonus - 10);

		sf::Vector2f paddleStrangth{ y, 0 };

		sf::Vector2f paddleDirectionVector(paddleStrangth.x, 0);
		direction = direction + paddleDirectionVector;
		direction.y *= -1;

		velocityBonus *= 1.5;
		if (velocityBonus < 0)
			velocityBonus = -velocityBonus;

		//normalizacja kierunku 
		float vectorLength = sqrt(direction.x * direction.x + direction.y * direction.y);
		if (vectorLength != 0) {
			direction.x = direction.x / vectorLength;
		}
	}

	checkColisionWitchSlab();

	ball.move(direction * (velocity + velocityBonus) * DeltaTime);
}

void Ball::Draw(sf::RenderWindow & window)
{
	window.draw(ball);
}

void Ball::checkColisionWitchSlab()
{

	sf::Vector2f slabColided = game->slabMenager->checkColision(ball);
	Slab exampleSlab(0, 0, 1);
	if (slabColided != sf::Vector2f{ 0.0f, 0.0f }) {

		sf::Vector2f ballPos = ball.getPosition();

		if (ballPos.x < slabColided.x &&
			ballPos.y > slabColided.y - exampleSlab.getHeight() / 2 &&
			ballPos.y < slabColided.y + exampleSlab.getHeight() / 2) { //odbicie od lewej strony

			direction.x *= -1;
		}
		else if (ballPos.x >= slabColided.x &&
			ballPos.y > slabColided.y - exampleSlab.getHeight() / 2 &&
			ballPos.y < slabColided.y + exampleSlab.getHeight() / 2) { //odbicie o prawej strony

			direction.x *= -1;
		}
		else if (ballPos.y <= slabColided.y &&
			ballPos.x > slabColided.x - exampleSlab.getWidth() / 2 &&
			ballPos.x < slabColided.x + exampleSlab.getWidth() / 2) { // odbicie od góry

			direction.y *= -1;
		}
		else if (ballPos.y >= slabColided.y &&
			ballPos.x > slabColided.x - exampleSlab.getWidth() / 2 &&
			ballPos.x < slabColided.x + exampleSlab.getWidth() / 2) { // odbicie od do³u

			direction.y *= -1;
        }
	}
}
