#pragma once
#include "Renderer.h"
#include "Physics.h"
class Simulation
{
public:
	Simulation() {};
	virtual~Simulation() {};
	virtual void init() = 0;
	virtual void run(Renderer *r) = 0;
private:
	virtual void render() = 0;
	virtual void update(Physics *p) = 0;

};
