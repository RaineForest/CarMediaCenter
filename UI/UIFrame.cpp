
#include <GL/freeglut.h>
#include "UIFrame.hpp"

namespace UI {

UIFrame::UIFrame(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("CarMediaCenter");

	//initialization stuff
	glShadeModel(GL_SMOOTH);

	glutDisplayFunc(Draw);
	glutReshapeFunc([](GLint width, GLint height) {
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
	});
	//glutKeyboardFunc(keyCallback);
	//glutMouseFunc(clickCallback);
	//glutMotionFunc(moveCallback);
	//glutIdleFunc(idleCallback);

	glutMainLoop();
}

}

