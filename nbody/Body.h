#pragma once
#include <glm\glm.hpp>
#include "Renderer.h"
using namespace glm;
class Body
{
public:
	Body();
	virtual ~Body();
	void calculateForce(Body b, double dt);
	void update(double dt);
	void render(Renderer *r);
	dvec2 getP0();
	dvec2 getP1();
	double getMass();
	
	const double GRAV_CONST = 6.673E-11; //Gravity Constant
	const double EPS = 3E4; //Damapener to avoid infinites
private:
	dvec2 p0, p1; //Positions
	dvec2 v0, v1; //Velocity
	dvec2 a0, a1; //Acceleration
	double mass;
	double radius;
	vec3 color;

};