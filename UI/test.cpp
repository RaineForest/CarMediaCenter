
// compile with: g++ -L/usr/lib/i386-linux-gnu -o test test.cpp -lglut -lGLU -lGL

#include <GL/freeglut.h>
#include <stdio.h>
#include "UIUtil.hpp"
#include <math.h>

using namespace UI;

UI_Point2_t* shape;
int sides = 0;
void setShape(int ngon, float rot, float rad) {
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

static void InitGL() {
	glShadeModel(GL_SMOOTH);

	setShape(6, 0.0f, 0.25f);
}

static void display() {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClearStencil(0.0f);
	glClear(GL_COLOR_BUFFER_BIT|GL_STENCIL_BUFFER_BIT);

	glPushMatrix();
		glClear(GL_STENCIL_BUFFER_BIT);
		//move to location
		glTranslatef(0.0, 0.0, 0.0);
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
			glVertex2f(shape[i].x, shape[i].y);
		}
		glEnd();
		//turn color and depth back on
		glColorMask(GL_TRUE,GL_TRUE,GL_TRUE,GL_TRUE);
		glDepthMask(GL_TRUE);
		//set new stencil function
		glStencilFunc(GL_EQUAL, 1, 0x01);

		//do the stuff
		glColor3f(0.0f, 1.0f, 0.0f);
		glBegin(GL_QUADS);
			glVertex2f(-0.5f, -0.5f);
			glVertex2f(0.5f, -0.5f);
			glVertex2f(0.5f, 0.5f);
			glVertex2f(-0.5f, 0.5f);
		glEnd();

		//turn off stencil write
		glStencilMask(0x00);
		//turn off stencil test
		glDisable(GL_STENCIL_TEST);
	glPopMatrix();

	glPushMatrix();
		glClear(GL_STENCIL_BUFFER_BIT);
		//move to location
		glTranslatef(.425f, .25f, 0.0);
		//turn on stencil test
		glEnable(GL_STENCIL_TEST);
		//prepare the stencil
		glStencilFunc(GL_ALWAYS, 2, 0x02);
		glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
		glStencilMask(0x02);
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
		glStencilFunc(GL_EQUAL, 2, 0x02);

		//do the stuff
		glColor3f(0.0f, 0.0f, 1.0f);
		glBegin(GL_QUADS);
			glVertex2f(-0.5f, -0.5f);
			glVertex2f(0.5f, -0.5f);
			glVertex2f(0.5f, 0.5f);
			glVertex2f(-0.5f, 0.5f);
		glEnd();

		//turn off stencil write
		glStencilMask(0x00);
		//turn off stencil test
		glDisable(GL_STENCIL_TEST);
	glPopMatrix();

	glPushMatrix();
		glClear(GL_STENCIL_BUFFER_BIT);
		//move to location
		glTranslatef(0.0f, .5f, 0.0);
		//turn on stencil test
		glEnable(GL_STENCIL_TEST);
		//prepare the stencil
		glStencilFunc(GL_ALWAYS, 3, 0x03);
		glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
		glStencilMask(0x03);
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
		glStencilFunc(GL_EQUAL, 3, 0x03);

		//do the stuff
		glColor3f(1.0f, 0.0f, 0.0f);
		glBegin(GL_QUADS);
			glVertex2f(-0.5f, -0.5f);
			glVertex2f(0.5f, -0.5f);
			glVertex2f(0.5f, 0.5f);
			glVertex2f(-0.5f, 0.5f);
		glEnd();

		//turn off stencil write
		glStencilMask(0x00);
		//turn off stencil test
		glDisable(GL_STENCIL_TEST);
	glPopMatrix();

	glutSwapBuffers();
}

static void reshape(GLint width, GLint height) {
	if (height == 0) {
		height = 1;
	}
	GLfloat aspectRatio = (GLfloat) width / (GLfloat) height;

	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION); //switch to modify perspective
	glLoadIdentity();
	if(width >= height) { //landscape
		gluOrtho2D(-1.0 * aspectRatio, 1.0 * aspectRatio, -1.0, 1.0);
	} else { //portrait
		gluOrtho2D(-1.0, 1.0, -1.0 / aspectRatio, 1.0 / aspectRatio);
	}

	glMatrixMode(GL_MODELVIEW);
}

static void keyCallback(unsigned char key, int x, int y) {
	printf("key: %c x: %d y: %d\n", (char)key, x, y);
}

static void clickCallback(int button, int state, int x, int y) {
	printf("button: %d state: %d x: %d y: %d\n", button, state, x, y);

}

static void moveCallback(int x, int y) {
	printf("x: %d y: %d\n", x, y);
}

static void idleCallback() {

}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA|GLUT_STENCIL);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Window's Title");

	InitGL();

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyCallback);
	glutMouseFunc(clickCallback);
	glutMotionFunc(moveCallback);
	glutIdleFunc(idleCallback);

	glutMainLoop();
	return 0;
}
