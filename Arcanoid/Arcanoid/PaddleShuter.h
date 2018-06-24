#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "Bonus.h"

class Game;

class PaddleShuter :
	public virtual Bonus
{
public:
	PaddleShuter(Game* ga, float x, float  y);
	virtual ~PaddleShuter() = default;
	void action(float DeltaTime);
	void startAction();
	void stopAction();
};

