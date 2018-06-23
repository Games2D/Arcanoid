#include "SlabMenager.h"
#include "stdafx.h"

SlabMenager::SlabMenager(Game * ga)
{
	game = ga;
	generateNewLvl();
}

void SlabMenager::generateNewLvl()
{
	float center = game->windowMode.width / 2;
	float toCenterDistance = 0;
	float fromTopDistance = topDistance;
	Slab exampleSlab(0, 0, 1);
	float pointDistanceHorizontal = slabSpace + exampleSlab.getWidth();
	float pointDistanceVertical = slabSpace + exampleSlab.getHeight();
	Slab* newSlab = nullptr;

	srand(time(NULL));
	rowCount = (std::rand() % 6) + 2;

	for (int i = 0; i < rowCount; i++) {

		while (true) {

			if (center + toCenterDistance + exampleSlab.getWidth() > game->windowMode.width)
				break;
			int slabType = (std::rand() % 4);
			toCenterDistance += pointDistanceHorizontal;
			
			if (slabType != 0) {

				newSlab = new Slab(center + toCenterDistance, fromTopDistance, slabType);
				slabList.push_back(*newSlab);

				newSlab = new Slab(center - toCenterDistance, fromTopDistance, slabType);
				slabList.push_back(*newSlab);
			}
			

		}

		toCenterDistance = 0;
		fromTopDistance += exampleSlab.getHeight() + slabSpace;
	}
}

void SlabMenager::update()
{

	if (slabList.empty())
		int x = 0;

	for (it = slabList.begin(); it != slabList.end(); it++) {

		if (it->live > 0) {
			it->update();
			it->Draw(game->window);

		}
	}
}

sf::Vector2f SlabMenager::checkColision(sf::CircleShape & ball)
{
	for (it = slabList.begin(); it != slabList.end(); it++) {

		if (ball.getGlobalBounds().intersects(it->slab.getGlobalBounds())) {

			sf::Vector2f slabPosPom = it->slab.getPosition();

			it->removeLive();

			if (it->live < 1)
				slabList.erase(it);

			return slabPosPom;
		}
	}
}
