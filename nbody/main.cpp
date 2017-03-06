#include "SDLRenderer.h"
#include "BarnesHutSim.h"
#include "ThreeBody.h"
int main(int argc, char *argv[])
{
	SDLRenderer renderer;
	renderer.init();
	BarnesHutSim sim;
	sim.run(&renderer);
	renderer.destroy();
	return 0;
}