/*

Name: John Honkanen

Student ID: B00291253

I declare that the following code was produced by John Honkanen (B00291253), Adam Stanton (B00266256) and Kyle Pearce (B00287219) as a group assignment for the IPM module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

This file was created by John Honkanen (B00291253), Adam Stanton (B00266256) and Kyle Pearce (B00287219).
*/

#pragma once
#define _USE_MATH_DEFINES
#include "Body.h"
#include "Quad.h";
#include <iostream>
#include <map>
#include <stack>;
#include <vector>;
#define MAX_DEPTH 15

using namespace std;

const int numberOfPoints = 30;
const float STEP = 2 * M_PI / numberOfPoints;

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