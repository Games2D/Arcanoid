#include "Game.h"
#include "stdafx.h"

using namespace std;

Game::Game()
{
	player = new Player(this, windowMode.width / 2);
	slabMenager = new SlabMenager(this);
}

Game::~Game()
{
	delete player;
}

void Game::run()
{
	Ball ball(this, 100.0f, 100.0f);
	list<Ball> ballList;
	ballList.push_back(ball);
	SlabMenager slabMenager(this);

	while (window.isOpen()) {

		float framStart = gameClock.getElapsedTime().asSeconds();
		sf::Vector2i mousePos = sf::Mouse::getPosition(window);

		sf::Event windowEvent;
		while (window.pollEvent(windowEvent)) {

			if (windowEvent.type == sf::Event::Closed) {

				window.close();
			}

			if (windowEvent.type == sf::Event::KeyPressed) {

				switch (windowEvent.key.code) {

				case sf::Keyboard::Escape: window.close();
					break;
				}
			}
		}

		window.clear(sf::Color(40, 40, 40));         //ustawianie t³a
		
		for (auto it = ballList.begin(); it != ballList.end(); it++) { //update kulki / kulek

			it->update(DeltaTime);
			it->Draw(window);
		}
	
		player->update(mousePos, DeltaTime);
		player->Draw(window);

		slabMenager.update();
		window.display();

		DeltaTime = gameClock.getElapsedTime().asSeconds() - framStart;
	}
}
