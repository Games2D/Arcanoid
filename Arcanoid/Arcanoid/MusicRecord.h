#pragma once
#include <iostream>

class MusicRecord
{
public:
	MusicRecord(std::string x, int timeInsec);
	~MusicRecord() = default;
	std::string name;
	int timeInSec;
};

