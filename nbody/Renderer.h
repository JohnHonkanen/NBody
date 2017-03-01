#pragma once
#include <glm/glm.hpp>
class Renderer
{
public:
	Renderer() {};
	virtual ~Renderer() {};
	virtual void renderCircle(glm::vec3 pos, int numPoints) = 0;
	virtual void init() = 0;
private:

};

Renderer::Renderer()
{
}

Renderer::~Renderer()
{
}
