/*

Name:

Student ID:

I declare that the following code was produced by John Honkanen (B00291253), Adam Stanton (B00266256) and Kyle Pearce (B00287219) as a group assignment for the IPM module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

This file was created by John Honkanen (B00291253), Based on : http://www.cs.princeton.edu/courses/archive/fall03/cs126/checklist/barnes-hut.html Quad Template.
*/

#include "Quad.h"

Quad::Quad()
{
}

Quad::Quad(double xmid, double ymid, double length)
{
	this->xmid = xmid;
	this->ymid = ymid;
	this->length = length;
}

Quad::~Quad()
{
}

double Quad::getLength()
{
	return this->length;
}

bool Quad::contains(double xmid, double ymid)
{
	if ((xmid <= this->xmid + this->length / 2.0) && (xmid >= this->xmid - this->length / 2.0) &&
		(ymid <= this->ymid + this->length / 2.0) && (ymid >= this->ymid - this->length / 2.0))
	{
		return true;
	}

	return false;
}

Quad *Quad::NW()
{
	Quad* newQuad = new Quad(this->xmid - this->length / 4.0, this->ymid + this->length / 4.0, this->length / 2.0);
	return newQuad;
}

Quad * Quad::NE()
{
	Quad* newQuad = new Quad(this->xmid + this->length / 4.0, this->ymid + this->length / 4.0, this->length / 2.0);
	return newQuad;
}

Quad * Quad::SW()
{
	Quad* newQuad = new Quad(this->xmid - this->length / 4.0, this->ymid - this->length / 4.0, this->length / 2.0);
	return newQuad;
}

Quad * Quad::SE()
{
	Quad* newQuad = new Quad(this->xmid + this->length / 4.0, this->ymid - this->length / 4.0, this->length / 2.0);
	return newQuad;
}

void Quad::draw()
{
	glBegin(GL_LINES);
	glVertex3d(this->xmid - length / 2.0, this->ymid, 0.0);
	glVertex3d(this->xmid + length / 2.0, this->ymid, 0.0);

	glVertex3d(this->xmid, this->ymid - length / 2.0, 0.0);
	glVertex3d(this->xmid, this->ymid + length / 2.0, 0.0);
	glEnd();
}
