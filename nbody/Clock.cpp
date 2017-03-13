Skip to content
This repository
Search
Pull requests
Issues
Gist
@JohnHonkanen
Sign out
Unwatch 2
Star 1
Fork 0 JohnHonkanen / penguine
Code  Issues 0  Pull requests 0  Projects 0  Wiki  Pulse  Graphs  Settings
Branch : master Find file Copy pathpenguine / Engine / Clock.cpp
	308dded  a day ago
	@JohnHonkanen JohnHonkanen Added Clock
	1 contributor
	RawBlameHistory
	53 lines(39 sloc)  678 Bytes
#include "Clock.h"



	Clock::Clock()
{
}


Clock::~Clock()
{
}

void Clock::startClock()
{
	Clock::startTime = clock();
}

void Clock::updateClock()
{
	Clock::millisecondPassed = (clock() - Clock::startTime); // 
}

double Clock::getMilliseconds()
{
	return Clock::millisecondPassed;
}

double Clock::getSeconds()
{
	return Clock::millisecondPassed / CLOCKS_PER_SEC;
}

void Clock::resetClock()
{
	Clock::startClock();
}

void Clock::setDelay(double milliseconds)
{
	millisecondToDelay = milliseconds;
}

void Clock::setDelayInSeconds(int seconds)
{
	Clock::setDelay((double)seconds * 1000);
}

bool Clock::alarm()
{
	return (Clock::millisecondPassed >= millisecondToDelay);
}
Contact GitHub API Training Shop Blog About
© 2017 GitHub, Inc.Terms Privacy Security Status Help