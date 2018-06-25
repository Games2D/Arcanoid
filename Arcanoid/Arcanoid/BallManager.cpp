#include "BallManager.h"
#include <iterator>
#include <string>
#include "Game.h"
#include "Ball.h"

BallManager::BallManager(Game* ga)
{
	game = ga;
}

void BallManager::update(float DeltaTime) 
{
	for (auto it = ballList.begin(); it != ballList.end(); it++) { //update kulki / kulek

		it->update(DeltaTime);
		it->Draw(game->window);
	}
}

void BallManager::Draw()
{
	for (auto it = ballList.begin(); it != ballList.end(); it++) { //update kulki / kulek

		it->Draw(game->window);
	}
}

void BallManager::respawnBall()
{
	respawnBall(game, game->windowMode.width / 2, game->player->getYposition() - 100, sf::Vector2f{ 0, -1 });
}

void BallManager::respawnBall(Game * game, float argX, float argY, sf::Vector2f direction)
{
	Ball ball(game, argX, argY, direction);

	ballList.push_back(ball);
}

void BallManager::clearList()
{
	ballList.clear();
}

void BallManager::setSticky()
{
	isStic = true;

	for (auto it = ballList.begin(); it != ballList.end(); it++) { //update kulki / kulek

		it->sticky = true;
	}
}

void BallManager::setUnSticky()
{
	isStic = false;

	for (auto it = ballList.begin(); it != ballList.end(); it++) { //update kulki / kulek

		it->sticky = false;
		it->stick = false;
	}
}

bool BallManager::isSticky()
{
	return isStic;
}

void BallManager::speedAccelerate(float velocityBonus)
{
	for (auto it = ballList.begin(); it != ballList.end(); it++) { //update kulki / kulek

		it->speedAccelerate(velocityBonus);
	}
}
