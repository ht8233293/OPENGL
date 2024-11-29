#include "glut.h"

void draw_desk() {
    // Vẽ mặt bàn
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.35, 0.05); // Màu nâu đậm
    glVertex3f(-1.5, -0.1, 0.5);
    glVertex3f(1.5, -0.1, 0.5);
    glVertex3f(1.5, -0.1, -0.5);
    glVertex3f(-1.5, -0.1, -0.5);
    glEnd();

    // Vẽ chân bàn
    glBegin(GL_QUADS);
    glVertex3f(-1.4, -0.1, 0.4);
    glVertex3f(-1.3, -0.1, 0.4);
    glVertex3f(-1.3, -1.0, 0.4);
    glVertex3f(-1.4, -1.0, 0.4);

    glVertex3f(1.4, -0.1, 0.4);
    glVertex3f(1.3, -0.1, 0.4);
    glVertex3f(1.3, -1.0, 0.4);
    glVertex3f(1.4, -1.0, 0.4);

    glVertex3f(1.4, -0.1, -0.4);
    glVertex3f(1.3, -0.1, -0.4);
    glVertex3f(1.3, -1.0, -0.4);
    glVertex3f(1.4, -1.0, -0.4);

    glVertex3f(-1.4, -0.1, -0.4);
    glVertex3f(-1.3, -0.1, -0.4);
    glVertex3f(-1.3, -1.0, -0.4);
    glVertex3f(-1.4, -1.0, -0.4);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(5, 5, 5, 0, 0, 0, 0, 1, 0);

    draw_desk();

    glutSwapBuffers();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glEnable(GL_DEPTH_TEST);
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, (float)w / (float)h, 1, 100);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Desk");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    init();
    glutMainLoop();
    return 0;
}