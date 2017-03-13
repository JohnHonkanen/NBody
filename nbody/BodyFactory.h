#pragma once
#include <SDL.h>
#include <glew.h>
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