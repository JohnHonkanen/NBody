#pragma once
#include "Physics.h"
#include "Body.h"
#include "Quad.h";
#include <iostream>
#include <vector>
#define MAX_DEPTH 30

using namespace std;

const int numberOfPoints = 30;
const float STEP = 2 * M_PI / numberOfPoints;
const double maxSize = SOLAR_MASS * 10 + 1e20;

class BarnesHutTree {
public:
	BarnesHutTree(Quad* q, unsigned int depth);
	virtual ~BarnesHutTree();
	bool isExternal(BarnesHutTree* t);
	void insert(Body* b);
	void updateForce(Body* b, int &colliding);
	void draw();
	void clearTree();
private:
	vector<Body*> bodies;
	unsigned int depth;
	bool hasBody = false;
	double totalMass = 0;
	double cmx, cmy;
	Quad* quad;
	BarnesHutTree* NW;
	BarnesHutTree* NE;
	BarnesHutTree* SW;
	BarnesHutTree* SE;
};