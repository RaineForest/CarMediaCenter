
// compile with: g++ -L/usr/lib/i386-linux-gnu -o test test.cpp -lglut -lGLU -lGL

#include <GL/freeglut.h>

static void InitGL() {
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glShadeModel(GL_SMOOTH);
}

static void display() {
	glClear(GL_COLOR_BUFFER_BIT);
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
	switch(key) {
		default:
			break;
	}
}

static void clickCallback(int button, int state, int x, int y) {

}

static void moveCallback(int x, int y) {

}

static void idleCallback() {

}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA);
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
