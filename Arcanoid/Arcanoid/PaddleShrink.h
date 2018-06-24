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
	virtual ~PaddleShrink() = default;
	void action(float DeltaTime);
	void startAction();
	void stopAction();
};

