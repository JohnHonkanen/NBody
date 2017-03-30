/*

Name: John Honkanen

Student ID: B00291253

I declare that the following code was produced by John Honkanen (B00291253), Adam Stanton (B00266256) and Kyle Pearce (B00287219) as a group assignment for the IPM module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

This file was created by John Honkanen (B00291253).
*/

#pragma once
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;
class Clock
{
private:
	clock_t startTime;
	double millisecondPassed;
	double millisecondToDelay;
public:
	Clock();
	virtual ~Clock();
	virtual void startClock();
	virtual void updateClock();
	virtual double getMilliseconds();
	virtual double getSeconds();
	virtual void resetClock();
	virtual void setDelay(double milliseconds);
	virtual void setDelayInSeconds(int seconds);
	virtual bool alarm();
};
