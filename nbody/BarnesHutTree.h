#pragma once
#include "Physics.h"
#include "Body.h"
#include "Quad.h";
#include <iostream>
#include <map>
#include <stack>;
#include <vector>;
#define MAX_DEPTH 30

using namespace std;

const int numberOfPoints = 30;
const float STEP = 2 * M_PI / numberOfPoints;
const double maxSize = SOLAR_MASS * 10 + 1e20;

class BarnesHutTree {
public:
	BarnesHutTree() {};
	BarnesHutTree(Quad* q, unsigned int depth);
	virtual ~BarnesHutTree();
	bool isExternal(BarnesHutTree* t);
	void insert(int key, Body *b);
	void updateForce(int i, Body *body, stack<int> &colBodies, vector<Body> &tb);
	void draw();
	void clearTree();
	double checkDistance(Body a, Body b);
	double checkDistance(double cmx, double cmy, Body a);
private:
	map<int,Body*> bodies;
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