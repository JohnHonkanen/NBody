/*

Name:

Student ID:

I declare that the following code was produced by John Honkanen (B00291253), Adam Stanton (B00266256) and Kyle Pearce (B00287219) as a group assignment for the IPM module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

This file was created by John Honkanen (B00291253), Adam Stanton (B00266256) and Kyle Pearce (B00287219).
*/
#pragma once
#include "SDLRenderer.h"
#include <SDL.h>
#include <GL/glew.h>
#include <vector>
#include <iostream>
#include <stack>;
#include "Simulation.h"
#include "BarnesHutTree.h"
#include "Body.h"
#include "BodyFactory.h"

using namespace std;

class BarnesHutSim :
	public Simulation
{
private:
	void render(Renderer *r);
	void update();
	bool pollEvents(SDL_Event e, Renderer *r);
	void generateBody();
	vector<Body> bodies;
	stack <int> colBodies;
	double dt;
	BarnesHutTree *tree;
	Quad *quad;
	BodyFactory factory;
	dvec2 mouse;
	bool keypressed;
	Body mouseBody;
	double simHeight, simWidth;
	double multiplier;
	double spawnBodies;
public:
	BarnesHutSim();
	virtual ~BarnesHutSim();
	void init();
	void run(Renderer *r);
	void pollInputs(SDL_Event e);
};

