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

void BarnesHutTree::insert(int key,Body *b)
{
	if (this->hasBody == false || depth > MAX_DEPTH) {
		this->bodies.insert(pair<int, Body*>(key, b));
		this->hasBody = true;
	}
	else if (this->isExternal(this) == false) {
		double tMass = this->totalMass + b->getMass();
		this->cmx = (this->cmx * this->totalMass + b->getP0().x* b->getMass()) / tMass;
		this->cmy = (this->cmy * this->totalMass + b->getP0().y* b->getMass()) / tMass;
		this->totalMass = tMass;
		this->bodies.insert(pair<int, Body*>(key, b));

		if (depth < MAX_DEPTH) {
			Quad *northWest = this->quad->NW();
			if (northWest->contains(b->getP0().x, b->getP0().y)) {
				if (this->NW == nullptr) {
					this->NW = new BarnesHutTree(northWest, depth + 1);
				}
				this->NW->insert(key,b);
			}
			else {
				Quad *northEast = this->quad->NE();
				if (northEast->contains(b->getP0().x, b->getP0().y)) {
					if (this->NE == nullptr) {
						this->NE = new BarnesHutTree(northEast, depth + 1);
					}
					this->NE->insert(key,b);
				}
				else {
					Quad *southEast = this->quad->SE();
					if (southEast->contains(b->getP0().x, b->getP0().y)) {
						if (this->SE == nullptr) {
							this->SE = new BarnesHutTree(southEast, depth + 1);
						}
						this->SE->insert(key,b);
					}
					else {
						Quad *southWest = this->quad->SW();
						if (this->SW == nullptr) {
							this->SW = new BarnesHutTree(southWest, depth + 1);
						}
						this->SW->insert(key,b);
					}
				}
			}
		}
	}
	else if (this->isExternal(this)) {
		map<int, Body*>::iterator it = this->bodies.begin();
		if (depth < MAX_DEPTH) {
			Quad *northWest = this->quad->NW();
			if (northWest->contains(it->second->getP0().x, it->second->getP0().y)) {
				if (this->NW == nullptr) {
					this->NW = new BarnesHutTree(northWest, depth + 1);
				}
				this->NW->insert(it->first, it->second);
			}
			else {
				Quad *northEast = this->quad->NE();
				if (northEast->contains(it->second->getP0().x, it->second->getP0().y)) {
					if (this->NE == nullptr) {
						this->NE = new BarnesHutTree(northEast, depth + 1);
					}
					this->NE->insert(it->first, it->second);
				}
				else {
					Quad *southEast = this->quad->SE();
					if (southEast->contains(it->second->getP0().x, it->second->getP0().y)) {
						if (this->SE == nullptr) {
							this->SE = new BarnesHutTree(southEast, depth + 1);
						}
						this->SE->insert(it->first, it->second);
					}
					else {
						Quad *southWest = this->quad->SW();
						if (this->SW == nullptr) {
							this->SW = new BarnesHutTree(southWest, depth + 1);
						}
						this->SW->insert(it->first, it->second);

					}
				}
			}
			this->insert(key, b);
		}
	}
}

void BarnesHutTree::updateForce(int i, Body *body, stack<int> &colBodies, vector<Body> &tb)
{
	
	Body *iB = body;
	if (this->isExternal(this)) {


		for (map<int,Body*>::iterator it = this->bodies.begin(); it != this->bodies.end(); it++) {
			/*
				Check Forces, Check Collision, Add to colliding Bodies
			*/
			int key = it->first;
			if (i != key) {
				Body *jB = &tb[key];
				iB->calculateForce(*jB);

				if (iB->checkCollision(*jB)) {
					if (iB->getMass() >= jB->getMass()) {
						colBodies.push(key);
						iB->add(*jB);
						iB->inelasticCollision(*jB);

					}

				}
			}
		}
	}
	else if (this->quad->getLength() / this->checkDistance(this->cmx, this->cmy, *iB) < 2.0) {
		/*
			Check Forces using Center of Mass
		*/
		Body cmb = Body(dvec2(this->cmx, this->cmy), dvec2(0), dvec2(0), this->totalMass, 0 , dvec3(0));
		iB->calculateForce(cmb);
	}
	else {
		if (this->NW != nullptr)
			this->NW->updateForce(i, body, colBodies, tb);
		if (this->SW != nullptr)
			this->SW->updateForce(i, body, colBodies, tb);
		if (this->SE != nullptr)
			this->SE->updateForce(i, body, colBodies, tb);
		if (this->NE != nullptr)
			this->NE->updateForce(i, body, colBodies, tb);
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
	if(this->bodies.size() > 0)
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

double BarnesHutTree::checkDistance(Body a, Body b)
{
	double dx = b.getP0().x - a.getP0().x;
	double dy = b.getP0().y - a.getP0().y;
	return sqrt(dx*dx + dy*dy);
}

double BarnesHutTree::checkDistance(double cmx, double cmy, Body a)
{
	double dx = cmx - a.getP0().x;
	double dy = cmy - a.getP0().y;
	return sqrt(dx*dx + dy*dy);
}
