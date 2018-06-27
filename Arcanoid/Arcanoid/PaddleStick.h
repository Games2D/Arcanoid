#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "Bonus.h"

class Game;

class PaddleStick :
	public virtual Bonus
{
public:
	PaddleStick(Game* ga, float x, float  y);
	virtual ~PaddleStick();
	void action(float DeltaTime);
	void startAction();
	void stopAction();
	sf::Color playerColorBefore;
private:
	bool active;
};

