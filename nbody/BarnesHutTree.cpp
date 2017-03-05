/*
#include "BarnesHutTree.h"

BarnesHutTree::BarnesHutTree(Quad * q)
{
	this->quad = q;
	this->body = nullptr;
	this->NW = nullptr;
	this->NE = nullptr;
	this->SW = nullptr;
	this->SE = nullptr;
}

BarnesHutTree::~BarnesHutTree()
{
}

bool BarnesHutTree::isExternal(BarnesHutTree * t)
{
	if ((t->NW == nullptr) && (t->NE == nullptr) && (t->SW == nullptr) && (t->SE == nullptr))
		return true;
	return false;
}

void BarnesHutTree::insert(Body *b)
{
	if (this->body == nullptr) {
		this->totalMass = b->getMass();
		this->cmx = b->getP0().x;
		this->cmy = b->getP0().y;
		this->body = b;
	}
	else if (this->isExternal(this) == false) {
		double tMass = this->totalMass + b->getMass();
		this->cmx = (this->cmx * this->totalMass + b->getP0().x* b->getMass()) / tMass;
		this->cmy = (this->cmy * this->totalMass + b->getP0().x* b->getMass()) / tMass;
		this->totalMass = tMass;
		//this->body = placeHolder;

		Quad *northWest = this->quad->NW();
		if (northWest->contains(b->getP0().x, b->getP0().y)) {
			if (this->NW == nullptr) {
				this->NW = new BarnesHutTree(northWest);
			}
			this->NW->insert(b);
		}
		else {
			Quad *northEast = this->quad->SW();
			if (northWest->contains(b->getP0().x, b->getP0().y)) {
				if (this->NE == nullptr) {
					this->NE = new BarnesHutTree(northEast);
				}
				this->NE->insert(b);
			}
			else {
				Quad *southEast = this->quad->SE();
				if (southEast->contains(b->getP0().x, b->getP0().y)) {
					if (this->SE == nullptr) {
						this->SE = new BarnesHutTree(southEast);
					}
					this->SE->insert(b);
				}
				else {
					Quad *southWest = this->quad->SW();
					if (this->SW == nullptr) {
						this->SW = new BarnesHutTree(southWest);
					}
					this->SW->insert(b);
				}
			}
		}
	}
	else if (this->isExternal(this)) {
		Body * c = this->body;
		Quad *northWest = this->quad->NW();
		if (northWest->contains(c->getP0().x, b->getP0().y)) {
			if (this->NW == nullptr) {
				this->NW = new BarnesHutTree(northWest);
			}
			this->NW->insert(c);
		}
		else {
			Quad *northEast = this->quad->NE();
			if (northEast->contains(c->getP0().x, b->getP0().y)) {
				if (this->NE == nullptr) {
					this->NE = new BarnesHutTree(northEast);
				}
				this->NE->insert(c);
			}
			else {
				Quad *southEast = this->quad->SE();
				if (southEast->contains(c->getP0().x, b->getP0().y)) {
					if (this->SE == nullptr) {
						this->SE = new BarnesHutTree(southEast);
					}
					this->SE->insert(c);
				}
				else {
					Quad *southWest = this->quad->SW();
					if (this->SW == nullptr) {
						this->SW = new BarnesHutTree(southWest);
					}
					this->SW->insert(c);

				}
			}
		}
		this->insert(b);
	}
}

void BarnesHutTree::updateForce(Body* b)
{
	if (this->isExternal(this)) {

		double dx = this->cmx - (b->getP0().x);
		double dy = this->cmy - (b->getP0().y);
		double distance = sqrt(dx*dx + dy*dy);
		double A = (GRAV_CONST * b->getMass()) / ((distance*distance) + (EPS*EPS));

		if (this->body != b) {

			b->addAcc((A*dx / distance), (A*dy / distance));

		}
		else if (this->quad->getLength() / (distance, (b->getP0().x), (b->getP0().y)) < 2.0) {

			double dx = this->cmx - (b->getP0().x);
			double dy = this->cmy - (b->getP0().y);
			double dist = sqrt(dx*dx + dy*dy);
			A = (GRAV_CONST * b->getMass()) / ((distance*distance) + (EPS*EPS));
			b->addAcc((A*dx / distance), (A*dy / distance));

		}
		else {
			if (this->NW != nullptr)
				this->NW->updateForce(b);
			if (this->SW != nullptr)
				this->SW->updateForce(b);
			if (this->SE != nullptr)
				this->SE->updateForce(b);
			if (this->NE != nullptr)
				this->NE->updateForce(b);
		}
	}
}

void BarnesHutTree::draw()
{
	this->quad->draw();
	if (this->NW != nullptr)
		this->NW->draw();
	if (this->SW != nullptr)
		this->SW->draw();
	if (this->SE != nullptr)
		this->SE->draw();
	if (this->NE != nullptr)
		this->NE->draw();
}

void BarnesHutTree::clearTree()
{
	if (this->NW != nullptr)
		delete this->NW;
	if (this->SW != nullptr)
		delete this->SW;
	if (this->SE != nullptr)
		delete this->SE;
	if (this->NE != nullptr)
		delete this->NE;

	delete this->quad;
	delete this;
}
*/
#include "BarnesHutTree.h"

BarnesHutTree::BarnesHutTree(Quad * q, unsigned int depth)
{
	this->quad = q;
	this->NW = nullptr;
	this->NE = nullptr;
	this->SW = nullptr;
	this->SE = nullptr;
	this->depth = depth;
}

BarnesHutTree::~BarnesHutTree()
{
}

bool BarnesHutTree::isExternal(BarnesHutTree * t)
{
	if ((t->NW == nullptr) && (t->NE == nullptr) && (t->SW == nullptr) && (t->SE == nullptr))
		return true;
	return false;
}

void BarnesHutTree::insert(Body *b)
{
	if (this->hasBody == false) {
		this->totalMass = b->getMass();
		this->cmx = b->getP0().x;
		this->cmy = b->getP0().y;
		this->bodies.push_back(b);
		this->hasBody = true;
	}
	else if (this->isExternal(this) == false) {
		double tMass = this->totalMass + b->getMass();
		this->cmx = (this->cmx * this->totalMass + b->getP0().x* b->getMass()) / tMass;
		this->cmy = (this->cmy * this->totalMass + b->getP0().y* b->getMass()) / tMass;
		this->totalMass = tMass;
		this->bodies.push_back(b);

		if (depth < MAX_DEPTH) {
			Quad *northWest = this->quad->NW();
			if (northWest->contains(b->getP0().x, b->getP0().y)) {
				if (this->NW == nullptr) {
					this->NW = new BarnesHutTree(northWest, depth + 1);
				}
				this->NW->insert(b);
			}
			else {
				Quad *northEast = this->quad->NE();
				if (northEast->contains(b->getP0().x, b->getP0().y)) {
					if (this->NE == nullptr) {
						this->NE = new BarnesHutTree(northEast, depth + 1);
					}
					this->NE->insert(b);
				}
				else {
					Quad *southEast = this->quad->SE();
					if (southEast->contains(b->getP0().x, b->getP0().y)) {
						if (this->SE == nullptr) {
							this->SE = new BarnesHutTree(southEast, depth + 1);
						}
						this->SE->insert(b);
					}
					else {
						Quad *southWest = this->quad->SW();
						if (this->SW == nullptr) {
							this->SW = new BarnesHutTree(southWest, depth + 1);
						}
						this->SW->insert(b);
					}
				}
			}
		}
	}
	else if (this->isExternal(this)) {
		Body * c = this->bodies[0];
		if (depth < MAX_DEPTH) {
			Quad *northWest = this->quad->NW();
			if (northWest->contains(c->getP0().x, c->getP0().y)) {
				if (this->NW == nullptr) {
					this->NW = new BarnesHutTree(northWest, depth + 1);
				}
				this->NW->insert(c);
			}
			else {
				Quad *northEast = this->quad->NE();
				if (northEast->contains(c->getP0().x, c->getP0().y)) {
					if (this->NE == nullptr) {
						this->NE = new BarnesHutTree(northEast, depth + 1);
					}
					this->NE->insert(c);
				}
				else {
					Quad *southEast = this->quad->SE();
					if (southEast->contains(c->getP0().x, c->getP0().y)) {
						if (this->SE == nullptr) {
							this->SE = new BarnesHutTree(southEast, depth + 1);
						}
						this->SE->insert(c);
					}
					else {
						Quad *southWest = this->quad->SW();
						if (this->SW == nullptr) {
							this->SW = new BarnesHutTree(southWest, depth + 1);
						}
						this->SW->insert(c);

					}
				}
			}
			this->insert(b);
		}
	}
}

void BarnesHutTree::updateForce(Body* b, int &colliding)
{
	if (b == nullptr)
		return;

	//maybe idek
	double dx = this->cmx - (b->getP0().x);
	double dy = this->cmy - (b->getP0().y);
	double distance = sqrt(dx*dx + dy*dy);
	double A = (GRAV_CONST * b->getMass()) / ((distance*distance) + (EPS*EPS));
	//maybeidek

	if (this->isExternal(this)) {

		for (unsigned int i = 0; i < this->bodies.size(); i++) {
			if (this->bodies[i] != b && this->bodies[i] != nullptr) {
				if (b->checkCollision(*this->bodies[i])) {
					this->bodies[i]->addMass(b->getMass());
					//this->bodies[i]->calculateRadius();
					colliding = 1;
					//cout << "colliding";
				}
				else {
					//b->addForce(this->bodies[i]->py, this->bodies[i]->py, this->bodies[i]->mass);
					b->addAcc((A*dx / distance), (A*dy / distance));
				}

			}
		}
	}
	else if (this->quad->getLength() / (distance, (b->getP0().x), (b->getP0().y)) < 2.0) {
		b->addAcc((A*dx / distance), (A*dy / distance));
	}
	else {
		if (this->NW != nullptr)
			this->NW->updateForce(b, colliding);
		if (this->SW != nullptr)
			this->SW->updateForce(b, colliding);
		if (this->SE != nullptr)
			this->SE->updateForce(b, colliding);
		if (this->NE != nullptr)
			this->NE->updateForce(b, colliding);
	}
}

void BarnesHutTree::draw()
{
	this->quad->draw();
	if (this->NW != nullptr)
		this->NW->draw();
	if (this->SW != nullptr)
		this->SW->draw();
	if (this->SE != nullptr)
		this->SE->draw();
	if (this->NE != nullptr)
		this->NE->draw();
}

void BarnesHutTree::clearTree()
{
	this->bodies.clear();
	if (this->NW != nullptr)
		delete this->NW;
	if (this->SW != nullptr)
		delete this->SW;
	if (this->SE != nullptr)
		delete this->SE;
	if (this->NE != nullptr)
		delete this->NE;

	delete this->quad;
	delete this;
}