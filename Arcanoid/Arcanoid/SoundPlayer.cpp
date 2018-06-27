#include "SoundPlayer.h"
#include <iostream>  
#include <windows.h>
#include <fstream>
#include <string>



void SoundPlayer::run()
{
	std::string x{ "" };
	loadMusicFileNames();

	while (true) {

		for (auto record = musicList.begin(); record != musicList.end(); record++) {

			x = "music\\" + record->name + ".wav";
			PlaySound(TEXT(x.c_str()), NULL, SND_ASYNC);
			waveOutSetVolume(0, 858993459);
			Sleep(record->timeInSec * 1000);

			PlaySound(NULL, 0, 0);
			Sleep(timeBetweenMusicInSec * 1000);
		}
	}
	
}

void SoundPlayer::loadMusicFileNames()
{
	std::fstream settings;
	settings.open("music\\music_settings.txt", std::ios::in);

	if (settings.good() == false) { //oznacza ze plik nie istnieje 

		std::cout << "Settings load error" << std::endl;
	}
	else {


		std::string x;
		std::string name, sec;
		int second;

		while (!settings.eof()) {

			getline(settings, x);

			bool nameReading = true;
			name = "";
			sec = "";
			for (int i = 0; i < x.length(); i++) {

				if (x[i] == ',') {

					nameReading = false;
					continue;
				}

				if (nameReading) {

					name += x[i];
				}
				else {
					
					if(x[i] != ' ')
						sec += x[i];
				}
			}
			musicList.push_back(MusicRecord{ name, atoi(sec.c_str()) });
		}
		settings.close();
	}
}
