/*

Name: John Honkanen

Student ID: B00291253

I declare that the following code was produced by John Honkanen (B00291253), Adam Stanton (B00266256) and Kyle Pearce (B00287219) as a group assignment for the IPM module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

This file was created by John Honkanen (B00291253).
*/


#include "Body.h"

Body::Body()
{
}
/*
@param p Position
@param v Velocity
@param a Acceleration
@param m Mass
@param r Radius
@param c Color
*/
Body::Body(dvec2 p, dvec2 v, dvec2 a, double m, double r, vec3 c)
{
	this->position = p;
	this->velocity = v;
	this->acceleration = v;
	this->force = dvec2(0);
	this->mass = m;
	this->radius = r;
	this->color = c;
	gravitate = true;
	staticBody = false;
	canEat = true;
}

Body::~Body()
{
}
/*
Calculate the forces affecting our particle, and add it to our velcoity (Verlett method);
Newton's Gravitational acceleration (Gravity, James Brown(1986), pg 12)
@param b Body
@param dt deltaTime
*/
void Body::calculateForce(Body b)
{
	if (gravitate) {
		dvec2 DeltaPos = normalize(b.getP0() - this->position);

		double distSqrd = dot(DeltaPos, DeltaPos);
		//Calculate Acceleration. Can ignore mass of own body.
		double A = (GRAV_CONST*b.getMass()) / (distSqrd + EPS*EPS);
		this->force += A * DeltaPos;
	}
}
/*
Verlett velocity solver for motion
@param dt timestep/delta time
*/
void Body::verlettStep(double dt)
{
	//Calculate position + 1
	this->position += dt * velocity+ 0.5f * dt * dt * acceleration;

	//Calculate v+�
	dvec2 vhalf = velocity + (0.5*dt*acceleration);
	//Compute ai+1
	this->acceleration = force *dt;

	//Compute v+1
	this->velocity = vhalf + (0.5*dt*acceleration);

}

/*
Update our position and move forward (Verlett method);
@param dt deltaTime
*/
void Body::update(double dt)
{
	if(!staticBody)
		this->verlettStep(dt);
}
/*
Resets temporary acceleration/force
*/
void Body::resetForce()
{
	this->force = dvec2(0);
}
/*
Renders using our renderer
*/
void Body::render(Renderer * r)
{
	r->renderCircle(dvec3(this->position.x, this->position.y, 0), this->radius, 30, this->color);
}
/*
Circle-circle Collision
@param Body to check
*/
bool Body::checkCollision(Body b)
{
	if (!canEat)
		return false;

	dvec2 op = b.getP0(); //Other Body's Position
	double dx = op.x - this->position.x;
	double dy = op.y - this->position.y;

	dvec2 deltaDist = b.getPosition() - this->position;
	double distSqrd = dot(deltaDist, deltaDist);
	double radiusSqrd = (this->radius + b.getRadius()) * (this->radius + b.getRadius());
	if (distSqrd < radiusSqrd)
		return true;
	return false;
}
/*
Calculates the inelastic Collision while maintaining momentum
The Law of Momentum Conservation (https://www.sciencetopia.net/physics/linear-momentum-principles)
@param Colliding Body
*/

void Body::inelasticCollision(Body b)
{
	//Momentum for this Body
	dvec2 thisMomentum = velocity * mass;
	//Momentum for other Body
	dvec2 otherMomentum = b.getCurrentVelocity() * b.getMass();

	//Total Mass
	double OneOvertotalMass = 1/(this->mass + b.getMass());

	//Final Velocity
	this->velocity = (thisMomentum + otherMomentum) * OneOvertotalMass;
}

/*
	Add mass and radius from the a body
	@param b Body
*/
void Body::add(Body b)
{
	this->mass += b.getMass();
	this->radius = sqrt((b.getRadius() *  b.getRadius()) + (this->radius * this->radius));
	if (this->color.g < 0.6) {
		this->color.g += 0.05;
	}
	else if (this->color.b < 1) {
		this->color.b += 0.05;
	}
	else if (this->color.r < 1) {
		this->color.r += 0.05;
	}
}


/*
*/
dvec2 Body::getP0()
{
	return this->position;
}
dvec2 Body::getPosition()
{
	return this->position;
}
/*
Get Mass
*/
double Body::getMass()
{
	return this->mass;
}
/*
Get Radius
*/
double Body::getRadius()
{
	return this->radius;
}
/*
Get Colour
*/
vec3 Body::getColor()
{
	return this->color;
}
/*
Get Current Acceleration

*/
dvec2 Body::getCurrentAccleration()
{
	return this->acceleration;
}

dvec2 Body::getCurrentVelocity()
{
	return this->velocity;
}
