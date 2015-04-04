
// compile with: g++ -L/usr/lib/i386-linux-gnu -o test test.cpp -lglut -lGLU -lGL

#include <GL/freeglut.h>

static void dispfun() {
    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Window's Title");
    glutDisplayFunc(dispfun);
    glClearColor(0.0f, 1.0f, 0.0f, 0.0f);
    glutMainLoop();
    return 0;
}
