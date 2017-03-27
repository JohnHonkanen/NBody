/*

Name:

Student ID:

I declare that the following code was produced by John Honkanen (B00291253), Adam Stanton (B00266256) and Kyle Pearce (B00287219) as a group assignment for the IPM module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

This file was created by John Honkanen (B00291253) and Kyle Pearce (B00287219).
*/

#include "Physics.h"
Physics::Physics()
{
}


Physics::~Physics()
{
}
double Physics::calculateForce(dvec2 p1, dvec2 p2, double mass, double mass2)
{
	double dist = distanceBetween(p1, p2); // Distance between 2 particle
	double force = GRAV_CONST * (mass * mass2) / ((dist*dist) + (EPS*EPS)); // Calculate Strength/Length of the gravity
	return force;
}
/**
Get the distance of particle p2 from particle p1
@param p1 Particle 1 position
@param p2 Particle 2 position
@return float Distance from p1 to p2
**/
double Physics::distanceBetween(dvec2 p1, dvec2 p2)
{
	double dx = p2.x - p1.x; // Difference between p2 x and p1 x
	double dy = p2.y - p1.y; // Difference between p2 y and p1 y
	return sqrt(dx*dx + dy*dy); // Pythagaros of the difference
}
/**
Get the angle in radians to particle p2 from particle 1
@param p1 Particle 1 position
@param p2 Particle 2 position
@return float Angle from p1 to p2 in radians
**/
float Physics::angleBetween(dvec2 p1, dvec2 p2)
{
	double dx = p2.x - p1.x; // Difference between p2 x and p1 x
	double dy = p2.y - p1.y; // Difference between p2 y and p1 y
	return atan(dy, dx); // Arc tangeant to get the angle between the two;
}
double Physics::circularOrbit(double px, double py)
{
	double r2 = sqrt(px*px + py*py);
	double numerator = (GRAV_CONST)*SOLAR_MASS*1e6;
	return sqrt(numerator / r2);
}
/*
returns Length of a vector, in relation to local origin
*/
double Physics::getLengthOf(dvec2 p)
{
	return sqrt(p.x*p.x + p.y*p.y);
}
/*
returns Angle of a vector, in relation to local origin
*/
float Physics::getAngleOf(dvec2 p)
{
	return atan(p.x, p.y);
}
/*
Set the angle of a vector
*/
void Physics::setAngleOf(dvec2 & p, float angle)
{
	float length = getLengthOf(p);
	p.x = cos(angle) * length;
	p.y = sin(angle) * length;
}
/*
Set the magnitude/length of a vector
*/
void Physics::setLengthOf(dvec2 & p, float length)
{
	float angle = getAngleOf(p);
	p.x = cos(angle) * length;
	p.y = sin(angle) * length;
}
