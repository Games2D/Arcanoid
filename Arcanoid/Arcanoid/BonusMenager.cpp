#include "BonusMenager.h"



BonusMenager::BonusMenager(Game* ga)
{
	game = ga;
}

void BonusMenager::update(float DeltaTime)
{
	Bonus* it;
	for (auto wsk = bonusList.begin(); wsk != bonusList.end();) {

		it = *wsk;

		it->update(DeltaTime);
		it->Draw(game->window);
		if(it->getDestroyStatus()) 
			wsk = bonusList.erase(wsk);
	}
}

void BonusMenager::addBonus()
{
	int bonusNum = (std::rand() % 6) + 1;
	Bonus* wsk = nullptr;

	switch (bonusNum) {
	case 1: wsk = new BallMultipler(game);
		break;
	case 2: wsk = new PaddleShrink(game);
		break;
	case 3: wsk = new PaddleShuter(game);
		break;
	case 4: wsk = new PaddleStick(game);
		break;
	case 5: wsk = new PaddleTenter(game);
		break;
	case 6: wsk = new SpeedAccelerant(game);
		break;
	}

	if (wsk != nullptr)
		bonusList.push_back(wsk);
}

void BonusMenager::checkColision(sf::RectangleShape paddle)
{
	Bonus* it;
	for (auto wsk = bonusList.begin(); wsk != bonusList.end();) {

		it = *wsk;
		if (paddle.getGlobalBounds().intersects(it->obj.getGlobalBounds())) {

			it->startAction();
			it->visibilyty = false;
		}
		else {
			wsk++;
		}
	}
}

