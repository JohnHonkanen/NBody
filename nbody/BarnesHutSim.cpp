/*

Name:

Student ID:

I declare that the following code was produced by John Honkanen (B00291253), Adam Stanton (B00266256) and Kyle Pearce (B00287219) as a group assignment for the IPM module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

This file was created by John Honkanen (B00291253), Adam Stanton (B00266256) and Kyle Pearce (B00287219).
*/


#include "BarnesHutSim.h"
#include "Rnd.h"


void BarnesHutSim::render(Renderer * r)
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glOrtho(-simWidth*multiplier, simWidth*multiplier, -simHeight*multiplier, simHeight*multiplier, 0.0f, 1.0f); // Reference system of our simulation
	glColor3f(0.5, 1.0, 1.0);

	for (int i = 0; i < bodies.size(); i++) {
		this->bodies[i].render(r);
	}
	mouseBody.render(r);
	//tree->draw();
	r->swap();
}

void BarnesHutSim::update()
{
	tree->clearTree();

	this->quad = new Quad(0, 0, 4*multiplier * simWidth);
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
			this->bodies[i].clock.updateClock();
			if (!this->bodies[i].gravitate && this->bodies[i].clock.alarm())
			{
				this->bodies[i].gravitate = true;
				this->bodies[i].canEat = true;

			}
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

	mouseBody = Body(mouse, dvec2(0), dvec2(0), 1, 10, vec3(0.0f, 1.0f, 1.0f));
}

bool BarnesHutSim::pollEvents(SDL_Event e, Renderer *r)
{
	int mx;
	int my;
	SDL_GetMouseState(&mx, &my);
	float posX = mx * (simWidth*multiplier *2/dynamic_cast<SDLRenderer*>(r)->width) -simWidth*multiplier;
	float posY = simHeight * multiplier*2 - my * (simHeight*multiplier*2 / dynamic_cast<SDLRenderer*>(r)->height) -simHeight*multiplier;
	//std::cout << mx << " " << my << std::endl;
	mouse = dvec2(posX, posY);

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
	 

	if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
		pollInputs(e);
	return true;
}

void BarnesHutSim::generateBody()
{
	dvec2 p = dvec2(rnd(-simWidth *multiplier, simWidth*multiplier), rnd(-simHeight*multiplier, simHeight*multiplier));
	//dvec2 p = dvec2(0,0);
	double vBase = 0;
	dvec2 v = dvec2(rnd(-vBase, vBase), rnd(-vBase, vBase));
	dvec2 a = dvec2(rnd(-0, 0), rnd(-0, 0));

	double m = 1;
	double rad = 10;

	float r = 0.5f;
	float g = 0.4f;
	float b = 0.4f;

	vec3 c = vec3(r,g,b);
	Body body = Body(p, v, a, m, rad, c);
	body.canEat = false;
	body.gravitate = false;
	body.clock.startClock();
	body.clock.setDelay(10);
	return bodies.push_back(body);
}

BarnesHutSim::BarnesHutSim()
{
	simHeight = 4000;
	simWidth = 4000;
	this->quad = new Quad(0, 0, 4* multiplier * simWidth);
	tree = new BarnesHutTree(this->quad, 0);
	keypressed = false;
	mouseBody = Body(dvec2(0), dvec2(0), dvec2(0), 1, 10, vec3(0.0f, 1.0f, 1.0f));
	
}

BarnesHutSim::~BarnesHutSim()
{
}

void BarnesHutSim::init()
{
	dt = 4e3;
	multiplier = 4.0f;
	for (int i = 0; i < spawnBodies; i++)
	{
		generateBody();
	}
}

void BarnesHutSim::run(Renderer * r)
{
	srand(time(NULL));
	SDL_Event e;
	spawnBodies = 15000;
	this->init();
	bool running = true;
	while (running) {
		SDL_PollEvent(&e);
		running = this->pollEvents(e, r);
		this->update();
		this->render(r);
	}
}

void BarnesHutSim::pollInputs(SDL_Event e)
{

	switch (e.key.keysym.sym) {
	case SDLK_1:
		std::cout << "1" << std::endl;
		bodies.push_back(BarnesHutSim::factory.createBlackHole(mouse, 25000, 1.0f, vec3(0.1f)));
		break;
	case SDLK_2:
		bodies.push_back(BarnesHutSim::factory.createRepulsor(mouse, 10000, 20.0f, vec3(1.0f,0.0f,1.0f)));
		break;
	case SDLK_3:
		std::cout <<"Creating Body" << std::endl;
		bodies.push_back(BarnesHutSim::factory.createBody(mouse, dvec2(0), dvec2(0), 1, 10, vec3(1.0f,1.0f,1.0f)));
		break;
	case SDLK_4:
		spawnBodies = 1000;
		init();
		break;
	}
}
