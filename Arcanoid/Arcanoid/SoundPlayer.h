#pragma once
#include <list>
#include "MusicRecord.h"

class MusicRecord;

class SoundPlayer
{
public:
	SoundPlayer() = default;
	~SoundPlayer() = default;
	void run();
	void loadMusicFileNames();
	std::list<MusicRecord> musicList;
private:
	int timeBetweenMusicInSec{ 1 };
};

