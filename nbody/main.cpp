/*

Name: John Honkanen

Student ID: B00291253

I declare that the following code was produced by John Honkanen (B00291253), Adam Stanton (B00266256) and Kyle Pearce (B00287219) as a group assignment for the IPM module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

This file was created by John Honkanen (B00291253) and Adam Stanton (B00266256).
*/

#include "SDLRenderer.h"
#include "BarnesHutSim.h"
#include "ThreeBody.h"
int main(int argc, char *argv[])
{
	printf("Welcome to the Nbody 1500 Simulation \n \n ");
	printf("Press the following keys for the following effects: \n 1) Spawn Black Hole. \n 2) Spawn Repulsor. \n 3) Spawn Single Body. \n 4) Spawn 1000 Bodies. \n 5)Draw Quad Tree \n");
	SDLRenderer renderer;
	renderer.init();
	BarnesHutSim sim;
	sim.run(&renderer);
	renderer.destroy();
	return 0;
}