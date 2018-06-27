#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <list>

class Game;
class Ball;

class BallManager
{
public:
	friend class BallMultipler;
	friend class Game;
	BallManager(Game* ga);
	~BallManager() = default;
	void update(float DeltaTime); //update and draw
	void Draw();
	void respawnBall();
	void respawnBall(Game* game, float argX, float argY, sf::Vector2f direction);
	void clearList();
	void setSticky();
	void setUnSticky();
	bool isSticky();
	void speedAccelerate(float velocityBonus);
private:
	mutable std::list<Ball> ballList;
	Game* game;
	bool isStic{ false };
	bool isBallBellowPaddle(Ball w) const;
};

