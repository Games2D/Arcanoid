#include "Menu.h"
#include "MenuOption.h"


Menu::Menu(Game* ga)
{
	game = ga;
	background.setFillColor(sf::Color{ 6, 14, 35, 170});
	background.setSize(sf::Vector2f{ (float)game->windowMode.width, (float)game->windowMode.height });
	background.setPosition(0, 0);

	pause.setFont(game->font);
	pause.setCharacterSize(90);
	pause.setString("PAUSE");
	pause.setPosition(game->windowMode.width / 2, game->windowMode.height / 4);
}

void Menu::run(float* framStart)
{
	sf::FloatRect textRect = pause.getLocalBounds();
	pause.setOrigin(textRect.left + textRect.width / 2.0f,
		textRect.top + textRect.height / 2.0f);

	sf::Event windowEvent;
	MenuOption resumeOption(game, game->windowMode.width / 2, game->windowMode.height / 2 - 20, "Resume");
	MenuOption exitOption(game, game->windowMode.width / 2, game->windowMode.height / 2 + 36, "Exit");
	bool menuIsOpen = true;
	while (menuIsOpen) {

		while (game->window.pollEvent(windowEvent)) {

			if (windowEvent.type == sf::Event::Closed) {

				game->window.close();
				menuIsOpen = false;
			}

			if (windowEvent.type == sf::Event::KeyPressed) {

				switch (windowEvent.key.code) {

				case sf::Keyboard::Escape: menuIsOpen = false;
					*framStart = game->gameClock.getElapsedTime().asSeconds();
					break;
				}
			}
		}

		//wykrywanie zda¿eñ przycisków
		if (resumeOption.pressed()) {

			menuIsOpen = false;
			*framStart = game->gameClock.getElapsedTime().asSeconds();
		}
		else if (exitOption.pressed()) {

			game->window.close();
			menuIsOpen = false;
		}

		//rysowanie t³a t³a
		game->window.clear(game->backgroundColor);
		game->player->Draw(game->window);
		game->ballManager->Draw();
		game->slabMenager->Draw();
		game->bonusMenager->Draw();
		game->gameInterface->Draw(game->window);

	    //rysowanie menu
		game->window.draw(background); 
		game->window.draw(pause);
		resumeOption.update();
		exitOption.update();

		game->window.display();
	}
}

void Menu::update(sf::Vector2i mousePos)
{
}

void Menu::Draw(sf::RenderWindow & window)
{
}
