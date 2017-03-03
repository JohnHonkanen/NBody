#pragma once
#include <glm/glm.hpp>
class Renderer
{
public:
	Renderer() {};
	virtual ~Renderer() {};
	virtual void renderCircle(glm::dvec3 pos, double radius, int numPoints) = 0;
	virtual void init() = 0;
private:

};

Renderer::Renderer()
{
}

Renderer::~Renderer()
{
}
