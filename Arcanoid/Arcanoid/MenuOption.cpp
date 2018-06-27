#include "MenuOption.h"
#include "Game.h"


MenuOption::MenuOption(Game* ga, float xPositionWindowCenter, float yPosition, std::string na)
{
	game = ga;
	name = na;
	NAME.setString(na);
	NAME.setPosition(xPositionWindowCenter, yPosition);
	NAME.setCharacterSize(30);
	NAME.setFont(game->font);

	toTopDistance = yPosition - height / 2;
	rectangle.setFillColor(background);
	rectangle.setPosition(sf::Vector2f{ xPositionWindowCenter, yPosition });
	rectangle.setOrigin(width / 2, height / 2);
	rectangle.setOutlineThickness(1);
	rectangle.setOutlineColor(outlineColor);
}


MenuOption::~MenuOption()
{
}

void MenuOption::update()
{
	NAME.setOrigin(NAME.getLocalBounds().left + NAME.getLocalBounds().width / 2.0f,
		NAME.getLocalBounds().top + NAME.getLocalBounds().height / 2.0f);

	Draw(game->window);
	if (clickDetection())
		presed = true;
}

void MenuOption::Draw(sf::RenderWindow & window)
{
	window.draw(rectangle);
	window.draw(NAME);
}

bool MenuOption::pressed()
{
	return presed;
}

bool MenuOption::clickDetection()
{
	float xWitchOriginLeft = rectangle.getPosition().x - width / 2;
	float yWitchOriginTop = rectangle.getPosition().y - height / 2;

	sf::Vector2i mousePos = sf::Mouse::getPosition(game->window);

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

		if (xWitchOriginLeft < mousePos.x
			&& xWitchOriginLeft + width > mousePos.x
			&& yWitchOriginTop < mousePos.y
			&& yWitchOriginTop + height > mousePos.y
			) {

			return true;
		}
	}
	if (xWitchOriginLeft < mousePos.x
		&& xWitchOriginLeft + width > mousePos.x
		&& yWitchOriginTop < mousePos.y
		&& yWitchOriginTop + height > mousePos.y
		) {

		rectangle.setFillColor(backgroundHover);
	}
	else {

		rectangle.setFillColor(background);
	}
	return false;
}
