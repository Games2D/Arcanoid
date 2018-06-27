#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "Bonus.h"

class Game;

class BallMultipler :
	public virtual Bonus
{
public:
	BallMultipler(Game* ga, float x, float  y);
	virtual ~BallMultipler();
	void action(float DeltaTime);
	void startAction();
	void stopAction();
private: 
	float alfa{ 10.0f }; //k¹t odchylenia
};

