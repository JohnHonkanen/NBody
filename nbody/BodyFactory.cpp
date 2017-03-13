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
	return createBody(p, vec2(0), vec2(0), m, r, c);
}

Body BodyFactory::createBlackHole(dvec2 p, double m)
{
	return createBody(p,vec2(0), vec2(0), m, 0.01, vec3(0));
}

Body BodyFactory::createRepulsor(dvec2 p, double m)
{
	return createBlackHole(p, -m);
}

Body BodyFactory::createRepulsor(dvec2 p, double m, double r, vec3 c)
{
	return createBlackHole(p, -m, r , c);
}
