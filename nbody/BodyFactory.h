/*

Name:

Student ID:

I declare that the following code was produced by John Honkanen (B00291253), Adam Stanton (B00266256) and Kyle Pearce (B00287219) as a group assignment for the IPM module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

This file was created by John Honkanen (B00291253) and Adam Stanton (B00266256).
*/
#pragma once
#include <SDL.h>
#include <GL/glew.h>
#include <vector>
#include <iostream>
#include <stack>;
#include "Simulation.h"
#include "BarnesHutTree.h"
#include "Body.h"

class BodyFactory {
public:
	BodyFactory();
	~BodyFactory();

	Body createBody(dvec2 p, dvec2 v, dvec2 a, double m, double r, vec3 c);
	Body createBlackHole(dvec2 p, double m);
	Body createBlackHole(dvec2 p, double m, double r, vec3 c);
	Body createRepulsor(dvec2 p, double m);
	Body createRepulsor(dvec2 p, double m, double r, vec3 c);
};