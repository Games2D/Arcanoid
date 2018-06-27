#include <cstdlib>
#include <thread>
#include "Game.h"
#include "SoundPlayer.h"


void musicThread()
{
	SoundPlayer soundManager;

	soundManager.run();
}

int main()
{
	srand(time(NULL));

	std::thread MUSIC(musicThread);
	Game game;

	game.run();

	MUSIC.detach();
	return 0;
}