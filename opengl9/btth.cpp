#include "glut.h"

void DrawCoordinate()
{

    glDisable(GL_LIGHTING);
    glBegin(GL_LINES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(10.0, 0.0, 0.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, 10.0, 0.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, 0.0, 10.0);
    glEnd();

    glEnable(GL_LIGHTING);
}

void DrawMatban()
{
    glPushMatrix();
    glTranslatef(6, 5, 8);
    glScalef(6, 0.5, 8);
    glutSolidCube(2.0);
    glPopMatrix();
}
void Drawchanban(float x, float z) {
    glPushMatrix();
    glTranslatef(x, 2.05, z);
    glScalef(1, 5, 1);
    glutSolidCube(1);
    glPopMatrix();
}

void Draw4chanban() {
    Drawchanban(11.5, 15.5);
    Drawchanban(0.5, 0.5);
    Drawchanban(11.5, 0.5);
    Drawchanban(0.5, 15.5);
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key) {
    case '1':
        glEnable(GL_LIGHT0);
        break;
    case '2':
        glEnable(GL_LIGHT1);
        break;
    case '3':
        glDisable(GL_LIGHT0);
        break;
    case '4':
        glDisable(GL_LIGHT1);
        break;
    case 'f':
        glDisable(GL_LIGHT0);
        glDisable(GL_LIGHT1);
        break;
    default:
        break;
    }

    glutPostRedisplay();
}

void Display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    GLfloat light_post1[] = { 0.5, 0.2, 0.0, 0.0 };
    GLfloat light_post2[] = { -0.5, 1.0, 1.0, 0.0 };

    GLfloat ambient1[] = { 1.0, 0.0, 0.0, 0.0 };
    GLfloat diffuse1[] = { 1.0, 0.5, 0.5, 1.0 };
    GLfloat specular1[] = { 1.0, 0.5, 0.5, 1.0 };

    GLfloat ambient2[] = { 0.2, 0.0, 0.0, 0.0 };
    GLfloat diffuse2[] = { 0.5, 0.5, 0.5, 1.0 };
    GLfloat specular2[] = { 0,8, 0.5, 0.5, 1.0 };

    glLightfv(GL_LIGHT0, GL_POSITION, light_post1);
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient1);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse1);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular1);

    glLightfv(GL_LIGHT1, GL_POSITION, light_post2);
    glLightfv(GL_LIGHT1, GL_AMBIENT, ambient2);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuse2);
    glLightfv(GL_LIGHT1, GL_SPECULAR, specular2);

    glEnable(GL_LIGHTING);

    //glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, 1.0, 1.0, 10.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(25.0, 8.0, 25.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    glColor3f(0.0, 0.0, 0.0);
    glutSolidTeapot(1.0);

    DrawCoordinate();
    glColor3f(1.0, 0.0, 0.0);

    glColor3f(1.0, 0.0, 1.0);
    DrawMatban();
    Draw4chanban();

    glPushMatrix();
    glTranslatef(0, 6.5, 0);
    glutSolidTeapot(2);
    glPopMatrix();

    // Đặt vị trí của quả bóng
    glPushMatrix();
    glTranslatef(6, 6.5, 8);
    glutSolidSphere(1, 100, 100);
    glPopMatrix();

   glEnd();
   glFlush();
   glutSwapBuffers();
   glutKeyboardFunc(keyboard);
}

void Reshape(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (GLfloat)width / (GLfloat)height, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void Init()
{
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
}

void main()
{
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Tô màu bóng 3D");
    glClearColor(0.0, 0.0, 0.0, 1.0);
    Init();
    glutReshapeFunc(Reshape);
    glutDisplayFunc(Display);

    glutMainLoop();
}
