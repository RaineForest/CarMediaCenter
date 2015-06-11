
#include "Button.hpp"

#define _USE_MATH_DEFINES
#include <cmath>

namespace UI {

Button::Button() {
	shape = nullptr;
	location = {0.0f, 0.0f};
	sides = 0;

	draw = [](){};
	update = [](float dt){};
	action = [](Event e){};
}

Button::~Button() {
	delete[] shape;
	shape = nullptr;
}

void Button::Draw() {
	UI_Point2_t* shape = this->getShape();
	int sides = this->getNumSides();
	UI_Point2_t scale = this->Polygonal::getSize();
	glPushMatrix();
		//turn on stencil test
		glEnable(GL_STENCIL_TEST);
		//prepare the stencil
		glStencilFunc(GL_ALWAYS, 1, 0x01);
		glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
		glStencilMask(0x01);
		//don't write to color or depth
		glColorMask(GL_FALSE,GL_FALSE,GL_FALSE,GL_FALSE);
		glDepthMask(GL_FALSE);
		//draw the stencil area
		glBegin(GL_POLYGON);
		for(int i = 0; i < sides; i++) {
			glVertex2f(shape[i].x*scale.x, shape[i].y*scale.y);
		}
		glEnd();
		//turn color and depth back on
		glColorMask(GL_TRUE,GL_TRUE,GL_TRUE,GL_TRUE);
		glDepthMask(GL_TRUE);
		//set new stencil function
		glStencilFunc(GL_EQUAL, 1, 0x01);

		//do the stuff
		glScalef(scale.x, scale.y, 1.0f);
		draw();
		
		//turn off stencil write
		glStencilMask(~0);
		//turn off stencil test
		glDisable(GL_STENCIL_TEST);
	glPopMatrix();
}

void Button::Update(float dt) {
	update(dt);
}

void Button::Action(Event e) {
	//TODO: on-click animation?
	//spawn thread? - no called from thread
	action(e);
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

BtnDrawFunc btnColor(float r, float g, float b, float a) {
	return [r, g, b, a]() {
		glColor4f(r, g, b, a);
		glBegin(GL_QUADS);
			glVertex2f(-1.0f, -1.0f);
			glVertex2f(1.0f, -1.0f);
			glVertex2f(1.0f, 1.0f);
			glVertex2f(-1.0f, 1.0f);
		glEnd();
	};
}

BtnDrawFunc btnCenterText(char* str) {
	return [str]() {
		//TODO: actually implement
	};
}

} //end namespace UI

