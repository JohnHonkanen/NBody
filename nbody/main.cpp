#include "SDLRenderer.h"
int main(int argc, char *argv[])
{
	SDLRenderer renderer;
	renderer.init();
	std::cin.get();
	renderer.destroy();
	return 0;
}