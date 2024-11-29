#include "glut.h"
#include <cmath>

// Biến để lưu trữ hướng nhìn của camera
float eyeX = 25.0;
float eyeY = 8.0;
float eyeZ = 25.0;

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
    case 'w':
        // Điều chỉnh hướng nhìn lên trên
        eyeY += 1.0;
        break;
    case 's':
        // Điều chỉnh hướng nhìn xuống dưới
        eyeY -= 1.0;
        break;
    case 'a':
        // Điều chỉnh hướng nhìn sang trái
        eyeX -= 1.0;
        break;
    case 'd':
        // Điều chỉnh hướng nhìn sang phải
        eyeX += 1.0;
        break;
    }

    glutPostRedisplay();
}

void Display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);

    // Thiết lập spot light 0
    GLfloat light_post0[] = { 0.5, 0.0, 0.5, 0.0 };
    GLfloat ambient0[] = { 0.0, 0.2, 0.2, 0.0 };
    GLfloat diffuse0[] = { 0.8, 0.1, 0.2, 1.0 };
    GLfloat specular0[] = { 0.8, 0.2, 0.2, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, light_post0);
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient0);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse0);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular0);

    // Thiết lập spot light 1
    GLfloat light_post1[] = { 0.0, 1.0, 0.0, 1.0 };
    glLightfv(GL_LIGHT1, GL_POSITION, light_post1);
    GLfloat ambient1[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat diffuse1[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat specular1[] = { 1.0,1.0, 1.0, 1.0 };
    glLightfv(GL_LIGHT1, GL_AMBIENT, ambient1);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuse1);
    glLightfv(GL_LIGHT1, GL_SPECULAR, specular1);

    // Thiết lập ma trận projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, 1.0, 1.0, 100.0);

    // Thiết lập ma trận modelview
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(eyeX, eyeY, eyeZ, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    // Vẽ các đối tượng
    glColor3f(0.0, 0.0, 0.0);
    glutSolidTeapot(1.0);
    DrawCoordinate();
    glutSwapBuffers();
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
    glEnable(GL_LIGHT1);
    glEnable(GL_COLOR_MATERIAL);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Tô màu bóng 3D");

    glutDisplayFunc(Display);
    glutReshapeFunc(Reshape);
    glutKeyboardFunc(keyboard); // Đăng ký hàm xử lý sự kiện bàn phím

    glClearColor(0.0, 0.0, 0.0, 1.0);
    Init();

    glutMainLoop();
    return 0;
}
