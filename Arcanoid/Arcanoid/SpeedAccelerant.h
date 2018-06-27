#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "Bonus.h"

class Game;

class SpeedAccelerant :
	public virtual Bonus
{
public:
	SpeedAccelerant(Game* ga, float x, float  y);
	virtual ~SpeedAccelerant();
	void action(float DeltaTime);
	void startAction();
	void stopAction();
private:
	float velocityBonus{ 130 };
};

