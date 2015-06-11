
#include "UIHierarchy.hpp"

#define _USE_MATH_DEFINES
#include <cmath>

namespace UI {

///////////Placeable/////////////////

Placeable::Placeable() {
	location ={ 0.0f, 0.0f };
}
	
UI_Point2_t Placeable::getLocation() {
	return this->location;
}

void Placeable::setLocation(GLfloat x, GLfloat y) {
	this->location = {x, y};
}

void Placeable::setLocation(UI_Point2_t* loc) {
	this->location = *loc;
}

/////////////Sizeable///////////////

Sizeable::Sizeable() {
	scale = {0.0f, 0.0f};
}

UI_Point2_t Sizeable::getSize() {
	return this->scale;
}

void Sizeable::setSize(float x, float y) {
	this->scale.x = x;
	this->scale.y = y;
}

////////////Polygonal///////////////

Polygonal::Polygonal() {
	shape = nullptr;
	sides = 0;
}

Polygonal::~Polygonal() {
	delete[] shape;
	shape = nullptr;
	sides = 0;
}

UI_Point2_t* Polygonal::getShape() {
	return shape;
}

int Polygonal::getNumSides() {
	return sides;
}

void Polygonal::setShape(GLfloat* xvals, GLfloat* yvals, int n) {
	if(n < 3) {
		return;
	}
	shape = new UI_Point2_t [n];
	sides = n;

	for(int i = 0; i < n; i++) {
		shape[i] = {xvals[i], yvals[i]};
	}
}

void Polygonal::setShape(UI_Point2_t* points, int n) {
	if(n < 3) {
		return;
	}
	shape = new UI_Point2_t [n];
	sides = n;

	for(int i = 0; i < n; i++) {
		shape[i] = points[i];
	}
}

void Polygonal::setShape(int ngon, float rot, float rad) {
	if(ngon < 3) {
		return;
	}
	shape = new UI_Point2_t [ngon];
	sides = ngon;
	const float angle = M_PI * 2.0 / (float)ngon;

	for(int i = 0; i < ngon; i++) {
		shape[i] = {rad*cosf(angle*i + rot), rad*sinf(angle*i + rot)};
	}
}

////////////Container//////////////

void Container::Draw() {
	for(unsigned int i = 0; i < this->components.size(); i++) {
		this->components[i]->Draw();
	}
}

void Container::add(Component* c) {
	components.push_back(c);
}

Component* Container::remove(Component* c) {
	for(unsigned int i = 0; i < components.size(); i++) {
		if(c == components[i]) {
			components.erase(components.begin()+i);
			return c;
		}
	}
	return nullptr;
}

Component* Container::remove(int index) {
	Component* c = components[index];
	components.erase(components.begin()+index);
	return c;
}

std::vector<Component*> Container::removeAll() {
	std::vector<Component*> ret = components;
	components.clear();
	return ret;
}

}

