#include "MusicRecord.h"



MusicRecord::MusicRecord(std::string x, int timeInsec)
{
	name = x;

	if(timeInsec != 0)
		timeInSec = timeInsec;
	else 
		timeInSec = 60;
}
