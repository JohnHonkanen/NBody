/*

Name:

Student ID:

I declare that the following code was produced by John Honkanen (B00291253), Adam Stanton (B00266256) and Kyle Pearce (B00287219) as a group assignment for the IPM module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

This file was created by John Honkanen (B00291253).
*/

#pragma once
#include <SDL.h>
#include <GL/glew.h>
#include <iostream>
#include "Renderer.h"
class SDLRenderer :
	public Renderer
{
private:
	SDL_GLContext glContext;
	SDL_Window *window;
	SDL_Window *setup(SDL_GLContext &context);
public:
	SDLRenderer();
	virtual ~SDLRenderer();
	void init();
	void renderCircle(glm::dvec3 pos, double radius, int numPoints, glm::vec3 color);
	void swap();
	void destroy();

	float width, height;
};

