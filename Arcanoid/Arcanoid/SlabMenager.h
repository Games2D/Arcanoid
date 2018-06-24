#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <list>

class Slab;
class Game;

class SlabMenager
{
public:
	SlabMenager(Game * ga);
	~SlabMenager() = default;
	void generateNewLvl();
	void update(float DeltaTime);
	void addSlab(float argX, float argY, int live);
	int rowCount;
	float topDistance{ 150.0f };
	float slabSpace{ 5.0f };
	sf::Vector2f checkColision(sf::CircleShape &ball);
	mutable std::list<Slab>::iterator it;
private:
	int propability{ 5 }; //odwrócone prawdopodobieñstwo wydropienia bonusu
	std::list<Slab> slabList;
	Game * game;
	float respawnDelay{ 3.0f }; //inSec
	float deltaTimer{ 0.0f };
};

