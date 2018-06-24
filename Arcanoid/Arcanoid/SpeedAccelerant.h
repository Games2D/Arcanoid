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
	virtual ~SpeedAccelerant() = default;
	void action(float DeltaTime);
	void startAction();
	void stopAction();
};

