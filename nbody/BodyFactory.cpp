/*

Name: John Honkanen

Student ID: B00291253

I declare that the following code was produced by John Honkanen (B00291253), Adam Stanton (B00266256) and Kyle Pearce (B00287219) as a group assignment for the IPM module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

This file was created by John Honkanen (B00291253) and Adam Stanton (B00266256).
*/

#include "BodyFactory.h"

BodyFactory::BodyFactory()
{
}

BodyFactory::~BodyFactory()
{
}

Body BodyFactory::createBody(dvec2 p, dvec2 v, dvec2 a, double m, double r, vec3 c)
{
	return Body(p,v,a,m,r,c);
}

Body BodyFactory::createBlackHole(dvec2 p, double m, double r, vec3 c)
{
	Body blackHole = createBody(p, vec2(0), vec2(0), m, r, c);
	blackHole.staticBody = true;
	return blackHole;
}

Body BodyFactory::createBlackHole(dvec2 p, double m)
{
	Body blackHole = createBody(p, vec2(0), vec2(0), m, 0.01, vec3(0));
	blackHole.staticBody = true;
	return blackHole;
}

Body BodyFactory::createRepulsor(dvec2 p, double m)
{
	return createBlackHole(p, -m);
}

Body BodyFactory::createRepulsor(dvec2 p, double m, double r, vec3 c)
{
	return createBlackHole(p, -m, r , c);
}
