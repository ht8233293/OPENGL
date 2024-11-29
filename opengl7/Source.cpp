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

void drawBackWall() {
    glColor3f(0.5, 0.1, 0.1);
    glBegin(GL_QUADS);//chế độ vẽ tứ giác
    glVertex3f(0.0, 0.0, -2.0);
    glVertex3f(7.0, 0.0, -2.0);
    glVertex3f(7.0, 7.0, -2.0);
    glVertex3f(0.0, 7.0, -2.0);
    glEnd();
}

void Display()
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    gluLookAt(5.0, 5.0, 15.0, 0.0, 0.0, 0.0, 0.0, 5.0, 0.0);

    // glPushMatrix();
    DrawCoordinate();

    glColor3f(1.0, 1.0, 1.0);
    drawBackWall();
    glutSolidTeapot(3.0);
    //glPopMatrix();

    glFlush();
}

void ReShape(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    float ratio = (float)width / (float)height;
    gluPerspective(45.0, ratio, 1, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

void Init()
{
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    glEnable(GL_DEPTH_TEST);
    //vị trí nguồn sáng
    GLfloat light_pos[] = { 4.0, 4.0, 4.0, 10.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, light_pos);



    //Thiết lập màu môi trường của vật liệu
    GLfloat ambient[] = { 1.0, 0.0,0.0, -1.0 };
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
    //Thiết lập độ khuyếch tán màu
    GLfloat diff_use[] = { 0.5, 0.0, 0.0, 1.0 };
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff_use);
    //Thiết lập độ phản chiếu
    GLfloat specular[] = { 1.0, 0.0, 0.0, 0.0 };
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
    //Thiết lập độ lớn cho specular
    GLfloat shininess = 30.0f;
    glMateriali(GL_FRONT, GL_SHININESS, shininess);
}

void main()
{
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Tô màu bóng 3D");

    Init();
    glutReshapeFunc(ReShape);
    glutDisplayFunc(Display);

    glutMainLoop();

}