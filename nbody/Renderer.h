/*

Name: John Honkanen

Student ID: B00291253

I declare that the following code was produced by John Honkanen (B00291253), Adam Stanton (B00266256) and Kyle Pearce (B00287219) as a group assignment for the IPM module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

This file was created by John Honkanen (B00291253).
*/
#pragma once
#include <glm/glm.hpp>
class Renderer
{
public:
	Renderer() {};
	virtual ~Renderer() {};
	virtual void renderCircle(glm::dvec3 pos, double radius, int numPoints, glm::vec3 color) = 0;
	virtual void swap() = 0;
	virtual void init() = 0;
	virtual void destroy() = 0;
private:

};
