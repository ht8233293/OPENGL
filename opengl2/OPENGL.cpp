#include "glut.h"

void draw_bookcase_with_books() {
    // Vẽ tủ sách
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.6, 0.4); // Màu nâu
    glVertex3f(-2, -1, -0.5);
    glVertex3f(2, -1, -0.5);
    glVertex3f(2, 1, -0.5);
    glVertex3f(-2, 1, -0.5);
    glEnd();

    // Vẽ sách
    glColor3f(0.0, 0.5, 1.0); // Màu xanh lam
    glPushMatrix();
    glTranslatef(-1.5, -0.5, 0);
    glScalef(0.4, 0.1, 0.4);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.5, 0.0, 0);
    glScalef(0.4, 0.1, 0.4);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.5, 0.5, 0);
    glScalef(0.4, 0.1, 0.4);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.5, -0.5, 0);
    glScalef(0.4, 0.1, 0.4);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.5, 0.0, 0);
    glScalef(0.4, 0.1, 0.4);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.5, 0.5, 0);
    glScalef(0.4, 0.1, 0.4);
    glutSolidCube(1);
    glPopMatrix();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(5, 5, 5, 0, 0, 0, 0, 1, 0);

    draw_bookcase_with_books();

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
    glutCreateWindow("Bookcase with Books");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    init();
    glutMainLoop();
    return 0;
}
