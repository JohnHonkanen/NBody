#pragma once
#include <SDL.h>
#include <glew.h>
#include <vector>
#include <iostream>
#include "Simulation.h"
#include "Body.h"

using namespace std;

class BarnesHutSim :
	public Simulation
{
private:
	void render(Renderer *r);
	void update();
	bool pollEvents(SDL_Event e);
	vector<Body> bodies;
	double dt;
public:
	BarnesHutSim();
	virtual ~BarnesHutSim();
	void init();
	void run(Renderer *r);
};
