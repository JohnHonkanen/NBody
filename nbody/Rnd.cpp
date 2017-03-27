/*

Name:

Student ID:

I declare that the following code was produced by John Honkanen (B00291253), Adam Stanton (B00266256) and Kyle Pearce (B00287219) as a group assignment for the IPM module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

This file was created by Adam Stanton (B00266256) and  John Honkanen (B00291253).
*/

#include "Rnd.h"

//Returns a random float, generated between rangemin and rangemax.
double rnd(double rangemin, double rangemax)			
{
	double f = (double)rand() / RAND_MAX;
	return f * (rangemax - rangemin) + rangemin;
}

// Returns a random int, generated between rangemin and rangemax.
int irnd(int rangemin, int rangemax)			
{
	int f = (int)rand() / RAND_MAX;
	return f * (rangemax - rangemin) + rangemin;
}


double exponent(double lambda) {
	return -log(1 - rnd(0, 1)) / lambda;
}
