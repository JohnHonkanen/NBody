/*

Name:

Student ID:

I declare that the following code was produced by John Honkanen (B00291253), Adam Stanton (B00266256) and Kyle Pearce (B00287219) as a group assignment for the IPM module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

This file was created by John Honkanen (B00291253), Based on : http://www.cs.princeton.edu/courses/archive/fall03/cs126/checklist/barnes-hut.html Quad Template.
*/

#pragma once
#include <iostream>
#include <GL\glew.h>
class Quad
{
public:
	Quad();
	Quad(double xmid, double ymid, double length);
	virtual ~Quad();
	double getLength();
	bool contains(double xmid, double ymid);
	Quad *NW();
	Quad *NE();
	Quad *SW();
	Quad *SE();
	void draw();

private:
	double xmid;
	double ymid;
	double length;


};