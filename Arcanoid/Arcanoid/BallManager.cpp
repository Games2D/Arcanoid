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

void BallManager::respawnBall()
{
	Ball ball(game, game->windowMode.width / 2, game->player->getYposition() - 100, sf::Vector2f{ 0, -1 });

	ballList.push_back(ball);
}

void BallManager::clearList()
{
	ballList.clear();
}
