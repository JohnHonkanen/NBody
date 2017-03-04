#include "Body.h"

Body::Body()
{
}

Body::Body(dvec2 p, dvec2 v, dvec2 a, double m, double r, vec3 c)
{
	this->p0 = p, this->p1 = p;
	this->v0 = v, this->v1 = v;
	this->a0 = v, this->a1 = a;
	this->ta = dvec2(0);
	this->mass = m;
	this->radius = r;
	this->color = c;
}

Body::~Body()
{
}
/*
	Calculate the forces affecting our particle, and add it to our velcoity (Verlett method);
	@param b Body
	@param dt deltaTime
*/
void Body::calculateForce(Body b)
{
	dvec2 op = b.getP1(); //Other Body's Position
	double dx = op.x - this->p1.x;
	double dy = op.y - this->p1.y;
	double dist = sqrt(dx*dx+dy*dy);
	//Calculate Acceleration. Can ignore mass of own body.
	double A = (GRAV_CONST*b.getMass()) / (dist*dist + EPS*EPS);
	this->ta += dvec2(A * dx, A * dy);
}

void Body::verlettStep(double dt)
{
	//Calculate position + 1
	double p1x = p0.x + (dt*v0.x) + (0.5f * dt*dt * a0.x);
	double p1y = p0.y + (dt*v0.y) + (0.5f * dt*dt * a0.y);
	dvec2 position = dvec2(p1x, p1y);
	this->p1 = position;

	//Calculate v+½
	double vhalfx = v0.x + (0.5*dt*a0.x);
	double vhalfy = v0.y + (0.5*dt*a0.y);
	//Compute ai+1
	double a1x = this->ta.x * dt;
	double a1y = this->ta.y * dt;
	this->a1 = dvec2(a1x, a1y);
	//Compute v+1
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
	this->verlettStep(dt);
	this->p0 = this->p1;
	this->a0 = this->a1;
	this->v0 = this->v1;
}
void Body::resetForce()
{
	this->ta = dvec2(0);
}
/*
	Renders using our renderer
*/
void Body::render(Renderer * r)
{
	r->renderCircle(dvec3(this->p0.x, this->p0.y, 0), this->radius, 30, this->color);
}

bool Body::checkCollision(Body b)
{
	dvec2 op = b.getP0(); //Other Body's Position
	double dx = op.x - this->p0.x;
	double dy = op.y - this->p0.y;
	double dist = sqrt(dx*dx + dy*dy);
	if (dist < (this->radius + b.getRadius()))
		return true;
	return false;
}

void Body::add(Body b)
{
	this->mass += b.getMass();
	this->radius += b.getRadius();
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

double Body::getRadius()
{
	return this->radius;
}

vec3 Body::getColor()
{
	return this->color;
}
