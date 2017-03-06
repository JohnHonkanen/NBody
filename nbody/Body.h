#pragma once
#include <iostream>
#include <glm\glm.hpp>
#include "Renderer.h"
using namespace glm;
using namespace std;
class Body
{
public:
	Body();
	Body(dvec2 p, dvec2 v, dvec2 a, double m, double r, vec3 c);
	virtual ~Body();
	void calculateForce(Body b);
	void verlettStep(double dt);
	void update(double dt);
	void resetForce();
	void render(Renderer *r);
	bool checkCollision(Body b);
	void inelasticCollision(Body b);
	void add(Body b);
	dvec2 getP0();
	double getMass();
	double getRadius();
	vec3 getColor();
	dvec2 getCurrentAccleration();
	dvec2 getCurrentVelocity();
	double GRAV_CONST = 6.673E-11; //Gravity Constant
	double EPS = 1; //Damapener to avoid infinites
private:
	dvec2 position; //Positions
	dvec2 velocity; //Velocity
	dvec2 acceleration; //Acceleration
	dvec2 force; //Total Accleration (Force)
	double mass;
	double radius;
	vec3 color;

};