
#include <GL/freeglut.h>
#include "UIFrame.hpp"

namespace UI {

UIFrame* thisInstance;
static void drawCallback();
static void reshapeCallback(GLint width, GLint height);

UIFrame::UIFrame() {}

void UIFrame::show(int argc, char** argv, int width, int height, const char* title) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA|GLUT_STENCIL);
	glutInitWindowSize(width, height);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(title);

	//initialization stuff
	//glShadeModel(GL_SMOOTH);

	thisInstance = this;
	glutDisplayFunc(drawCallback);
	glutReshapeFunc(reshapeCallback);
	//glutKeyboardFunc(keyCallback);
	//glutMouseFunc(clickCallback);
	//glutMotionFunc(moveCallback);
	//glutIdleFunc(idleCallback);

	glutMainLoop();
}

static void drawCallback() {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClearStencil(0.0f);
	glClear(GL_COLOR_BUFFER_BIT|GL_STENCIL_BUFFER_BIT);

	thisInstance->Draw();

	glutSwapBuffers();
}

static void reshapeCallback(GLint width, GLint height) {
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

}

