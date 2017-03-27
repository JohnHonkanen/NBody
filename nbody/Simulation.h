/*

Name:

Student ID:

I declare that the following code was produced by John Honkanen (B00291253), Adam Stanton (B00266256) and Kyle Pearce (B00287219) as a group assignment for the IPM module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

This file was created by John Honkanen (B00291253).
*/
#pragma once
#include "Renderer.h"
class Simulation
{
public:
	Simulation() {};
	virtual~Simulation() {};
	virtual void init() = 0;
	virtual void run(Renderer *r) = 0;
private:
	virtual void render(Renderer *r) = 0;
	virtual void update() = 0;

};
