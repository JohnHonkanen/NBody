#include "SDLRenderer.h"
#include "ThreeBody.h"
int main(int argc, char *argv[])
{
	SDLRenderer renderer;
	renderer.init();
	ThreeBody sim;
	sim.run(&renderer);
	renderer.destroy();
	return 0;
}