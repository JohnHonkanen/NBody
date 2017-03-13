#pragma once
#include "SDLRenderer.h"
#include <SDL.h>
#include <glew.h>
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
public:
	BarnesHutSim();
	virtual ~BarnesHutSim();
	void init();
	void run(Renderer *r);
	void pollInputs(SDL_Event e);
};

