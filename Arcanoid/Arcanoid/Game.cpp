#include "Game.h"

Game::Game()
{
	player = new Player(this, windowMode.width / 2);
	slabMenager = new SlabMenager(this);
	bonusMenager = new BonusMenager(this);
	ballManager = new BallManager(this);

	lvlText.setString("1");
    font.loadFromFile("Roboto-Medium.ttf");
	lvlText.setFont(font);
	lvlText.setCharacterSize(70);
	lvlText.setPosition(windowMode.width / 2, windowMode.height / 3);
	lvlText.setOrigin(lvlText.getGlobalBounds().width / 2 + 20, 0);
}

Game::~Game()
{
	delete player;
}

void Game::run()
{
	ballManager->respawnBall();

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
		

	
		player->update(mousePos, DeltaTime);
		player->Draw(window);

		ballManager->update(DeltaTime);
		slabMenager->update(DeltaTime);
		bonusMenager->update(DeltaTime);
		window.display();

		DeltaTime = gameClock.getElapsedTime().asSeconds() - framStart;
	}
}

void Game::refreshTextCounter()
{
	lvlCounter++;;

	std::ostringstream ss;
	ss << lvlCounter;
	lvlText.setString(ss.str());
	ss.str("");
	ss.clear();
}
