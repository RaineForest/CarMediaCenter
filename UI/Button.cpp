
#include "Button.hpp"

#define _USE_MATH_DEFINES
#include <cmath>

namespace UI {

Button::Button() {
	shape = nullptr;
	location = {0.0f, 0.0f};
	sides = 0;
}

Button::~Button() {
	delete[] shape;
	shape = nullptr;
}

void Button::Draw() {
	glEnable(GL_STENCIL_TEST);
	//prepare the stencil
	glStencilFunc(GL_ALWAYS, 1, 0xFF);
	glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
	glStencilMask(0xFF);
	//don't write to color or depth
	glColorMask(GL_FALSE,GL_FALSE,GL_FALSE,GL_FALSE);
	glDepthMask(GL_FALSE);
	//draw the stencil area
	glBegin(GL_POLYGON);
	for(int i = 0; i < sides; i++) {
		glVertex2f(shape[i].x, shape[i].y);
	}
	glEnd();
	//turn color and depth back on
	glColorMask(GL_TRUE,GL_TRUE,GL_TRUE,GL_TRUE);
	glDepthMask(GL_TRUE);
	//set new stencil function
	glStencilFunc(GL_EQUAL, 1, 0xFF);
	//turn off stencil write
	glStencilMask(0x00);

	//do the stuff
	draw();
	
	glDisable(GL_STENCIL_TEST);
}

void Button::Update(float dt) {
	update(dt);
}

void Button::Action() {
	//TODO: on-click animation?
	//TODO: spawn thread?
	action();
}

UI_Point2_t Button::getLocation() {
	return location;
}

void Button::setLocation(GLfloat x, GLfloat y) {
	location = {x, y};
}

void Button::setLocation(UI_Point2_t* loc) {
	location = *loc;
}

void Button::setShape(GLfloat* xvals, GLfloat* yvals, int size) {
	if(size < 3) {
		return;
	}
	shape = new UI_Point2_t [size];
	sides = size;

	for(int i = 0; i < size; i++) {
		shape[i] = {xvals[i], yvals[i]};
	}
}

void Button::setShape(UI_Point2_t* points, int size) {
	if(size < 3) {
		return;
	}
	shape = new UI_Point2_t [size];
	sides = size;

	for(int i = 0; i < size; i++) {
		shape[i] = points[i];
	}
}

void Button::setShape(int ngon, float rot, float rad) {
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

void Button::setDraw(BtnDrawFunc func) {
	draw = func;
}

void Button::setUpdate(BtnUpdateFunc func) {
	update = func;
}

void Button::setAction(BtnActionFunc func) {
	action = func;
}

////////////////////////////////////////////////////////////////

BtnDrawFunc btnSolidColor(float r, float g, float b, float a = 1.0) {
	return [r, g, b, a]() {
		glClearColor(r, g, b, a);
	};
}

BtnDrawFunc btnCenterText(char* str) {
	return [str]() {
		//TODO: actually implement
	};
}

} //end namespace UI

