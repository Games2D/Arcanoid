#include "BonusMenager.h"
#include <iterator>
#include <iostream>
#include "Game.h"
#include "Bonus.h"
#include "BallMultipler.h"
#include "PaddleShrink.h"
#include "PaddleShuter.h"
#include "PaddleStick.h"
#include "PaddleTenter.h"
#include "SpeedAccelerant.h"


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
		else 		
			wsk++;
	}
}

void BonusMenager::Draw()
{
	for (auto wsk = bonusList.begin(); wsk != bonusList.end(); wsk++) {

		auto it = *wsk;
		it->Draw(game->window);
	}
}

void BonusMenager::addBonus(float x, float y)
{
	int bonusNum = (std::rand() % 6) + 1;
	Bonus* wsk = nullptr;

	switch (bonusNum) {
	case 1: wsk = new BallMultipler(game, x, y);
		break;
	case 2: wsk = new PaddleShrink(game, x, y);
		break;
	//case 3: wsk = new PaddleShuter(game, x, y);
	//	break;
	case 4: wsk = new PaddleStick(game, x, y);
		break;
	case 5: wsk = new PaddleTenter(game, x, y);
		break;
	case 6: wsk = new SpeedAccelerant(game, x, y);
		break;
	}

	if (wsk != nullptr)
		bonusList.push_back(wsk);
}

void BonusMenager::checkColision(sf::RectangleShape paddle)
{
	Bonus* it;
	for (auto wsk = bonusList.begin(); wsk != bonusList.end(); wsk++) {

		it = *wsk;
		if (paddle.getGlobalBounds().intersects(it->obj.getGlobalBounds())) {

			it->startAction();
			it->visibilyty = false;
			it->obj.move(0, 1000);
		}
	}
}

int* BonusMenager::activeBonus()
{
	int* returnedTab = new int[6];
	for (int i = 0; i < 6; i++) {

		returnedTab[i] = 0;
	}

	for (auto wsk = bonusList.begin(); wsk != bonusList.end(); wsk++) {

		auto it = *wsk;

		if(!it->visibilyty) // je¿eli jest aktywny
			if (it->name == "BallMultipler" && returnedTab[0] != 1) {

				returnedTab[0] = 1;
			}
			else if (it->name == "PaddleShrink" && returnedTab[1] != 1) {

				returnedTab[1] = 1;
			}
			else if (it->name == "PaddleStick" && returnedTab[2] != 1) {

				returnedTab[2] = 1;
			}
			else if (it->name == "PaddleTenter" && returnedTab[3] != 1) {

				returnedTab[3] = 1;
			}
			else if (it->name == "PaddleShuter" && returnedTab[4] != 1) {

				returnedTab[4] = 1;
			}
			else if (it->name == "SpeedAccelerant" && returnedTab[5] != 1) {

				returnedTab[5] = 1;
			}
	}
	return returnedTab;
}

