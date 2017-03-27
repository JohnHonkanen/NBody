/*

Name:

Student ID:

I declare that the following code was produced by John Honkanen (B00291253), Adam Stanton (B00266256) and Kyle Pearce (B00287219) as a group assignment for the IPM module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

This file was created by John Honkanen (B00291253).
*/

//Test Class used for 3 Body testing
#pragma once
#include <SDL.h>
#include <GL/glew.h>
#include <vector>
#include <stack>;
#include <iostream>
#include "Simulation.h"
#include "Body.h"

using namespace std;

class ThreeBody :
	public Simulation
{
private:
	void render(Renderer *r);
	void update();
	bool pollEvents(SDL_Event e);
	vector<Body> bodies;
	stack <int> colBodies;
	double dt;
public:
	ThreeBody();
	virtual ~ThreeBody();
	void init();
	void run(Renderer *r);
};
