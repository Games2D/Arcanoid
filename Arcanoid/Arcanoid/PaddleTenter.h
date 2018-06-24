#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "Bonus.h"

class Game;

class PaddleTenter :
	public virtual Bonus
{
public:
	PaddleTenter(Game* ga, float x, float  y);
	virtual ~PaddleTenter() = default;
	void action(float DeltaTime);
	void startAction();
	void stopAction();
};

