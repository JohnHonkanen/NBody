#include "BarnesHutSim.h"
#include "Rnd.h"


void BarnesHutSim::render(Renderer * r)
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glOrtho(-2000, 2000, -2000, 2000, 0.0f, 1.0f); // Reference system of our simulation
	glColor3f(0.5, 1.0, 1.0);

	for (int i = 0; i < bodies.size(); i++) {
		this->bodies[i].render(r);
	}

	tree->draw();
	r->swap();
}

void BarnesHutSim::update()
{
	tree->clearTree();

	this->quad = new Quad(0, 0, 2 * 4000);
	tree = new BarnesHutTree(this->quad, 0);

	for (int i = 0; i < this->bodies.size(); i++) {
		if (quad->contains(bodies[i].getP0().x, bodies[i].getP0().y)) {
			tree->insert(i, &this->bodies[i]);
		}
	}

	for (int i = 0; i < this->bodies.size(); i++) {
		this->bodies[i].resetForce();
		if (quad->contains(bodies[i].getP0().x, bodies[i].getP0().y)) {
			tree->updateForce(i, &this->bodies[i], this->colBodies, this->bodies);
			this->bodies[i].update(dt);
		}
	}

	while (!colBodies.empty()) {
		if (colBodies.top() < bodies.size())
		{
			bodies[colBodies.top()] = bodies.back();
			bodies.pop_back();

			//particleCount--;
		}
		colBodies.pop();
	}
}

bool BarnesHutSim::pollEvents(SDL_Event e)
{
	if (e.type == SDL_QUIT)
		return false;
	if (e.type == SDL_KEYDOWN)
	{
		// Can extend this to handle a wider range of keys
		switch (e.key.keysym.sym)
		{
		case SDLK_ESCAPE:
			return false;
		default:
			break;
		}
	}

	return true;
}

BarnesHutSim::BarnesHutSim()
{
	this->quad = new Quad(0, 0, 2 * 4000);
	tree = new BarnesHutTree(this->quad, 0);
}

BarnesHutSim::~BarnesHutSim()
{
}

void BarnesHutSim::init()
{
	dt = 1e4;
	bodies.push_back(Body(dvec2(500, 300), dvec2(0, 0), dvec2(0), 1, 10, vec3(1.0, 1.0, 1.0)));
	bodies.push_back(Body(dvec2(500, -500), dvec2(-0, 0), dvec2(0), 1, 10, vec3(0.0, 1.0, 1.0)));
	bodies.push_back(Body(dvec2(-500, 500), dvec2(0), dvec2(0), 1, 10, vec3(1.0, 0.0, 0.0)));
	bodies.push_back(Body(dvec2(0, 0), dvec2(0), dvec2(0), 1, 10, vec3(1.0, 0.0, 0.0)));
}

void BarnesHutSim::run(Renderer * r)
{
	SDL_Event e;
	this->init();
	bool running = true;
	while (running) {
		SDL_PollEvent(&e);
		running = this->pollEvents(e);
		this->update();
		this->render(r);
	}
}