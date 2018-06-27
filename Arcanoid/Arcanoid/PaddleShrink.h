#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "Bonus.h"

class Game;

class PaddleShrink :
	public virtual Bonus
{
public:
	PaddleShrink(Game* ga, float x, float  y);
	virtual ~PaddleShrink();
	void action(float DeltaTime);
	void startAction();
	void stopAction();
private:
	void refreshPaddleSize();
	sf::Vector2f paddleSizeActualy;
	sf::Vector2f paddleOriginActualy;
	float shrinkLvl{ 0.3f };
	float shrinkSizeValue{ 0.0f };
	float shrinkOriginValue{ 0.0f };
};

