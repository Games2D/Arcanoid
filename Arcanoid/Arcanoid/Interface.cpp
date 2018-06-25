#include "Interface.h"
#include "Game.h"
#include "Bonus.h"
#include <iostream>
#include <string>
#include <sstream>

Interface::Interface(Game* ga)
{
	game = ga;
	topGlobalPosition = game->windowMode.height - height;
	width = game->windowMode.width;

	backgroundTexture.loadFromFile("backgroundInterface.png");
	ballMultiplerTexture.loadFromFile("BallMultipler.png");
	paddleShrinkTexture.loadFromFile("PaddleShrink.png");
	paddleTenterTexture.loadFromFile("PaddleTenter.png");
	speedAccelerantTexture.loadFromFile("SpeedAccelerant.png");
	paddleStickTexture.loadFromFile("PaddleStick.png");
	paddleShuterTexture.loadFromFile("PaddleShuter.png");

	background.setTexture(backgroundTexture);
	background.setPosition(game->windowMode.width / 2, topGlobalPosition);
	background.setOrigin(width / 2, 0);

	ballMultipler.setTexture(ballMultiplerTexture);
	paddleShrink.setTexture(paddleShrinkTexture);
	paddleTenter.setTexture(paddleTenterTexture);
	speedAccelerant.setTexture(speedAccelerantTexture);
	paddleStick.setTexture(paddleStickTexture);
	paddleShuter.setTexture(paddleShuterTexture);

	font.loadFromFile("Roboto-Medium.ttf");

	scor.setFont(font);
	scor.setCharacterSize(30);
	scor.setString("SCORE");
	scor.setPosition(sf::Vector2f{ margin,  topGlobalPosition  + margin});

	scorValue.setFont(font);
	scorValue.setCharacterSize(22);
	scorValue.setString("0");
	scorValue.setPosition(sf::Vector2f{ margin,  topGlobalPosition + 2 * margin + scor.getGlobalBounds().height });

	lvl.setFont(font);
	lvl.setCharacterSize(20);
	lvl.setString("LVL");
	lvl.setOrigin(lvl.getGlobalBounds().width / 2 - 5, -height / 2 - 15);
	lvl.setPosition(sf::Vector2f{ width / 2, topGlobalPosition });

	lvlValue.setFont(font);
	lvlValue.setCharacterSize(60);
	lvlValue.setString("1");
	lvlValue.setOrigin(lvlValue.getGlobalBounds().width / 2 + 5, 0 );
	lvlValue.setPosition(sf::Vector2f{ width / 2, topGlobalPosition + margin });

	bonus.setFont(font);
	bonus.setCharacterSize(30);
	bonus.setString("BONUS");
	bonus.setPosition(sf::Vector2f{ game->windowMode.width - margin - bonus.getGlobalBounds().width - 3,  topGlobalPosition + margin });

	partucularTranslate = ballMultipler.getGlobalBounds().width + 5;
}

void Interface::update()
{
	updateLvlText();
	updateScorText();

	int *returnedTab = game->bonusMenager->activeBonus();
	float translateDistance = margin;

	ballMultipler.setPosition(sf::Vector2f{ 2000, 2000 });
	paddleShrink.setPosition(sf::Vector2f{ 2000, 2000 });
	paddleStick.setPosition(sf::Vector2f{ 2000, 2000 });
	paddleTenter.setPosition(sf::Vector2f{ 2000, 2000 });
	paddleShuter.setPosition(sf::Vector2f{ 2000, 2000 });
	speedAccelerant.setPosition(sf::Vector2f{ 2000, 2000 });

	int i = 0;
	while (true) {

		float x = game->windowMode.width - translateDistance - partucularTranslate;
		float y = topGlobalPosition + 2 * margin + scor.getGlobalBounds().height;

		if (returnedTab[i] && i == 0) {

			ballMultipler.setPosition(sf::Vector2f{ x, y });
			translateDistance += partucularTranslate;
		}
		else if (returnedTab[i] && i == 1) {

			paddleShrink.setPosition(sf::Vector2f{ x, y });
			translateDistance += partucularTranslate;
		}
		else if (returnedTab[i] && i == 2) {

			paddleStick.setPosition(sf::Vector2f{ x, y });
			translateDistance += partucularTranslate;
		}
		else if (returnedTab[i] && i == 3) {

			paddleTenter.setPosition(sf::Vector2f{ x, y });
			translateDistance += partucularTranslate;
		}
		else if (returnedTab[i] && i == 4) {

			paddleShuter.setPosition(sf::Vector2f{ x, y });
			translateDistance += partucularTranslate;
		}
		else if (returnedTab[i] && i == 5) {

			speedAccelerant.setPosition(sf::Vector2f{ x, y });
			translateDistance += partucularTranslate;
		}

		if (i < 6)
			i++;
		else
			break;
	}
	delete returnedTab;
}

void Interface::Draw(sf::RenderWindow & window)
{
	window.draw(background);
	window.draw(scor);
	window.draw(lvl);
	window.draw(bonus);

	window.draw(scorValue);
	window.draw(lvlValue);

	window.draw(ballMultipler);
	window.draw(paddleShrink);
	window.draw(paddleStick);
	window.draw(paddleTenter);
	window.draw(paddleShuter);
	window.draw(speedAccelerant);
}

float Interface::getHeight()
{
	return height;
}

void Interface::updateScorText()
{
	std::ostringstream ss;
	ss << game->playerPoints;
	scorValue.setString(ss.str());
	ss.str("");
	ss.clear();
}

void Interface::updateLvlText()
{
	lvlValue.setString(game->lvlText.getString());
}
