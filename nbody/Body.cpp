#include "Body.h"

Body::Body()
{
}

Body::~Body()
{
}
/*
	Calculate the forces affecting our particle, and add it to our velcoity (Verlett method);
	@param b Body
	@param dt deltaTime
*/
void Body::calculateForce(Body b, double dt)
{
	dvec2 op = b.getP1(); //Other Body's Position
	double dx = op.x - this->p1.x;
	double dy = op.y - this->p1.y;
	double dist = sqrt(dx*dx+dy*dy);
	//Calculate Acceleration. Can ignore mass of own body.
	double A = (GRAV_CONST*b.getMass()) / (dist*dist + EPS*EPS);

	//Calculate v+½
	double vhalfx = v0.x + (0.5*dt*a0.x);
	double vhalfy = v0.y + (0.5*dt*a0.y);
	//Compute ai+1
	double a1x = A * dt * dx;
	double a1y = A * dt * dy;
	this->a1 = dvec2(a1x, a1y);
	//Comput v+1
	double v1x = vhalfx + (0.5*dt*a1.x);
	double v1y = vhalfy + (0.5*dt*a1.y);
	this->v1 = dvec2(v1x, v1y);
}

/*
	Update our position and move forward (Verlett method);
	@param dt deltaTime
*/
void Body::update(double dt)
{
	//Calculate position + 1
	double p1x = p0.x + (dt*v0.x) + (0.5f * dt*dt * a0.x);
	double p1y = p0.y + (dt*v0.y) + (0.5f * dt*dt * a0.y);
	dvec2 position = dvec2(p1x, p1y);

	this->p0 = this->p1;
	this->p1 = position;

	this->a0 = this->a1;
	this->v0 = this->v1;
}
/*
	Renders using our renderer
*/
void Body::render(Renderer * r)
{
	r->renderCircle(dvec3(this->p0.x, this->p0.y, 0), this->mass, 30);
}
/*
	Get Current Position
*/
dvec2 Body::getP0()
{
	return this->p0;
}
/*
	Get Position at next step
*/
dvec2 Body::getP1()
{
	return this->p1;
}
/*
	Get Mass
*/
double Body::getMass()
{
	return this->mass;
}
