#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <list>

class Bonus;
class Game;

class BonusMenager
{
public:
	BonusMenager(Game * ga);
	~BonusMenager() = default;
	void update(float DeltaTime);
	void addBonus(float x, float y);
	void checkColision(sf::RectangleShape paddle);
private:
	Game * game;
	mutable std::list<Bonus*> bonusList;
};

