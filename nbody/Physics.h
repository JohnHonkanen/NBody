/*

Name:

Student ID:

I declare that the following code was produced by John Honkanen (B00291253), Adam Stanton (B00266256) and Kyle Pearce (B00287219) as a group assignment for the IPM module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

This file was created by John Honkanen (B00291253) and Kyle Pearce (B00287219).
*/

#pragma once
#define _USE_MATH_DEFINES
#include <glm\glm.hpp>
#include <iostream>
#include <limits>
using namespace glm;

const double static GRAV_CONST = 6.673E-11;
const double static SOLAR_MASS = 1.98892e30;
const double static EARTH_MASS = 5.972e24;
const double static EPS = DBL_EPSILON;
const double static UNIVERSE_RADIUS = 1e18;

class Physics
{
public:
	Physics();
	virtual ~Physics();
	static double calculateForce(dvec2 p1, dvec2 p2, double mass, double mass2);
	static double getLengthOf(dvec2 p);
	static float getAngleOf(dvec2 p);
	static void setAngleOf(dvec2 &p, float angle);
	static void setLengthOf(dvec2 &p, float length);
	static double distanceBetween(dvec2 p1, dvec2 p2);
	static float angleBetween(dvec2 p1, dvec2 p2);
	static double circularOrbit(double px, double py);
};

