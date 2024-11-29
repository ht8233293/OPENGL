
00:20
00 : 02
00 : 33
00 : 39
01 : 00

#define GL_SILENCE_DEPRECATION

#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include "glut.h"
#endif
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

GLboolean redFlag = true, switchOne = false, switchTwo = false, switchLamp = false, amb1 = true, diff1 = true, spec1 = true, amb2 = true, diff2 = true, spec2 = true, amb3 = true, diff3 = true, spec3 = true;
double windowHeight = 800, windowWidth = 600;
double eyeX = 7.0, eyeY = 2.0, eyeZ = 15.0, refX = 0, refY = 0, refZ = 0;
double theta = 180.0, y = 1.36, z = 7.97888;

static GLfloat v_cube[8][3] =
{
    {0.0, 0.0, 0.0}, // Dinh 0
    {0.0, 0.0, 3.0}, // Dinh 1
    {3.0, 0.0, 3.0}, // Dinh 2
    {3.0, 0.0, 0.0}, // Dinh 3
    {0.0, 3.0, 0.0}, // Dinh 4
    {0.0, 3.0, 3.0}, // Dinh 5
    {3.0, 3.0, 3.0}, // Dinh 6
    {3.0, 3.0, 0.0}  // Dinh 7
};

static GLubyte quadIndices[6][4] =
{
    {0, 1, 2, 3}, // Day
    {4, 5, 6, 7}, // Mat tren
    {5, 1, 2, 6}, // Mat truoc
    {0, 4, 7, 3}, // Mat sau (chieu kim dong ho)
    {2, 3, 7, 6}, // Mat phai
    {1, 5, 4, 0}  // Mat trai (chieu kim dong ho)
};

static void getNormal3p
(GLfloat x1, GLfloat y1, GLfloat z1, GLfloat x2, GLfloat y2, GLfloat z2, GLfloat x3, GLfloat y3, GLfloat z3)
{
    GLfloat Ux, Uy, Uz, Vx, Vy, Vz, Nx, Ny, Nz;

    Ux = x2 - x1; // Tinh vector U
    Uy = y2 - y1; // Tinh vector U
    Uz = z2 - z1; // Tinh vector U

    Vx = x3 - x1; // Tinh vector V
    Vy = y3 - y1; // Tinh vector V
    Vz = z3 - z1; // Tinh vector V

    Nx = Uy * Vz - Uz * Vy; // Tinh thanh phan x cua vector phap tuyen
    Ny = Uz * Vx - Ux * Vz; // Tinh thanh phan y cua vector phap tuyen
    Nz = Ux * Vy - Uy * Vx; // Tinh thanh phan z cua vector phap tuyen

    glNormal3f(Nx, Ny, Nz); // Thiet lap vector phap tuyen cho doi tuong
}

void drawCube()
{
    glBegin(GL_QUADS);
    for (GLint i = 0; i < 6; i++)
    {
        getNormal3p(v_cube[quadIndices[i][0]][0], v_cube[quadIndices[i][0]][1], v_cube[quadIndices[i][0]][2],
            v_cube[quadIndices[i][1]][0], v_cube[quadIndices[i][1]][1], v_cube[quadIndices[i][1]][2],
            v_cube[quadIndices[i][2]][0], v_cube[quadIndices[i][2]][1], v_cube[quadIndices[i][2]][2]); // Tinh vector phap tuyen cho mat dang ve
        glVertex3fv(&v_cube[quadIndices[i][0]][0]); // Ve dinh 1
        glVertex3fv(&v_cube[quadIndices[i][1]][0]); // Ve dinh 2
        glVertex3fv(&v_cube[quadIndices[i][2]][0]); // Ve dinh 3
        glVertex3fv(&v_cube[quadIndices[i][3]][0]); // Ve dinh 4
    }
    glEnd();
}


void drawCube1(GLfloat difX, GLfloat difY, GLfloat difZ, GLfloat ambX = 0, GLfloat ambY = 0, GLfloat ambZ = 0, GLfloat shine = 50)
{
    GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat mat_ambient[] = { ambX, ambY, ambZ, 1.0 };
    GLfloat mat_diffuse[] = { difX, difY, difZ, 1.0 };
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = { shine };

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);

    glBegin(GL_QUADS);

    for (GLint i = 0; i < 6; i++)
    {
        getNormal3p(v_cube[quadIndices[i][0]][0], v_cube[quadIndices[i][0]][1], v_cube[quadIndices[i][0]][2],
            v_cube[quadIndices[i][1]][0], v_cube[quadIndices[i][1]][1], v_cube[quadIndices[i][1]][2],
            v_cube[quadIndices[i][2]][0], v_cube[quadIndices[i][2]][1], v_cube[quadIndices[i][2]][2]);
        glVertex3fv(&v_cube[quadIndices[i][0]][0]);
        glVertex3fv(&v_cube[quadIndices[i][1]][0]);
        glVertex3fv(&v_cube[quadIndices[i][2]][0]);
        glVertex3fv(&v_cube[quadIndices[i][3]][0]);
    }
    glEnd();
}

static GLfloat v_trapezoid[8][3] =
{
    {0.0, 0.0, 0.0}, //0
    {0.0, 0.0, 3.0}, //1
    {3.0, 0.0, 3.0}, //2
    {3.0, 0.0, 0.0}, //3
    {0.5, 3.0, 0.5}, //4
    {0.5, 3.0, 2.5}, //5
    {2.5, 3.0, 2.5}, //6
    {2.5, 3.0, 0.5}  //7
};

static GLubyte TquadIndices[6][4] =
{
    {0, 1, 2, 3}, //bottom
    {4, 5, 6, 7}, //top
    {5, 1, 2, 6}, //front
    {0, 4, 7, 3}, // back is clockwise
    {2, 3, 7, 6}, //right
    {1, 5, 4, 0}  //left is clockwise
};

static GLfloat v_pyramid[5][3] =
{
    {0.0, 0.0, 0.0},
    {0.0, 0.0, 2.0},
    {2.0, 0.0, 2.0},
    {2.0, 0.0, 0.0},
    {1.0, 4.0, 1.0}
};

static GLubyte p_Indices[4][3] =
{
    {4, 1, 2},
    {4, 2, 3},
    {4, 3, 0},
    {4, 0, 1}
};

static GLubyte PquadIndices[1][4] =
{
    {0, 3, 2, 1}
};

void drawpyramid(GLfloat difX, GLfloat difY, GLfloat difZ, GLfloat ambX, GLfloat ambY, GLfloat ambZ, GLfloat shine)
{
    GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 }; // Không có vat lieu
    GLfloat mat_ambient[] = { ambX, ambY, ambZ, 1.0 }; // Mau vat lieu phan xa tu moi truong xung quanh
    GLfloat mat_diffuse[] = { difX, difY, difZ, 1.0 }; // Mau vat lieu phan xa tu nguon sang
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 }; // Mau vat lieu phan xa tu nguon sang manh
    GLfloat mat_shininess[] = { shine }; // Do bong cua vat lieu

    // Dat cac thuoc tinh vat lieu
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

    // Ve hinh tam giac
    glBegin(GL_TRIANGLES);
    for (GLint i = 0; i < 4; i++)
    {
        getNormal3p(v_pyramid[p_Indices[i][0]][0], v_pyramid[p_Indices[i][0]][1], v_pyramid[p_Indices[i][0]][2],
            v_pyramid[p_Indices[i][1]][0], v_pyramid[p_Indices[i][1]][1], v_pyramid[p_Indices[i][1]][2],
            v_pyramid[p_Indices[i][2]][0], v_pyramid[p_Indices[i][2]][1], v_pyramid[p_Indices[i][2]][2]);
        glVertex3fv(&v_pyramid[p_Indices[i][0]][0]);
        glVertex3fv(&v_pyramid[p_Indices[i][1]][0]);
        glVertex3fv(&v_pyramid[p_Indices[i][2]][0]);
    }
    glEnd();

    // Ve hinh tu giac
    glBegin(GL_QUADS);
    for (GLint i = 0; i < 1; i++)
    {
        getNormal3p(v_pyramid[PquadIndices[i][0]][0], v_pyramid[PquadIndices[i][0]][1], v_pyramid[PquadIndices[i][0]][2],
            v_pyramid[PquadIndices[i][1]][0], v_pyramid[PquadIndices[i][1]][1], v_pyramid[PquadIndices[i][1]][2],
            v_pyramid[PquadIndices[i][2]][0], v_pyramid[PquadIndices[i][2]][1], v_pyramid[PquadIndices[i][2]][2]);
        glVertex3fv(&v_pyramid[PquadIndices[i][0]][0]);
        glVertex3fv(&v_pyramid[PquadIndices[i][1]][0]);
        glVertex3fv(&v_pyramid[PquadIndices[i][2]][0]);
        glVertex3fv(&v_pyramid[PquadIndices[i][3]][0]);
    }
    glEnd();
}

void drawSphere(GLfloat difX, GLfloat difY, GLfloat difZ, GLfloat ambX, GLfloat ambY, GLfloat ambZ, GLfloat shine = 90)
{
    GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat mat_ambient[] = { ambX, ambY, ambZ, 1.0 };
    GLfloat mat_diffuse[] = { difX, difY, difZ, 1.0 };
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = { shine };

    // Dat cac thuoc tinh vat lieu
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

    // Ve hinh cau
    glutSolidSphere(3.0, 20, 16);
}

void drawTrapezoid(GLfloat difX, GLfloat difY, GLfloat difZ, GLfloat ambX, GLfloat ambY, GLfloat ambZ, GLfloat shine = 50)
{
    GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat mat_ambient[] = { ambX, ambY, ambZ, 1.0 };
    GLfloat mat_diffuse[] = { difX, difY, difZ, 1.0 };
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_emission[] = { difX, difY, difZ, 0.0 };
    GLfloat mat_shininess[] = { shine };

    // Dat cac thuoc tinh vat lieu
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

    // Kiem tra trang thai cua den
    if (switchLamp == true) {
        glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
    }
    else {
        glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
    }

    // Ve hinh thang
    glBegin(GL_QUADS);
    for (GLint i = 0; i < 6; i++)
    {
        getNormal3p(v_trapezoid[TquadIndices[i][0]][0], v_trapezoid[TquadIndices[i][0]][1], v_trapezoid[TquadIndices[i][0]][2],
            v_trapezoid[TquadIndices[i][1]][0], v_trapezoid[TquadIndices[i][1]][1], v_trapezoid[TquadIndices[i][1]][2],
            v_trapezoid[TquadIndices[i][2]][0], v_trapezoid[TquadIndices[i][2]][1], v_trapezoid[TquadIndices[i][2]][2]);

        glVertex3fv(&v_trapezoid[TquadIndices[i][0]][0]);
        glVertex3fv(&v_trapezoid[TquadIndices[i][1]][0]);
        glVertex3fv(&v_trapezoid[TquadIndices[i][2]][0]);
        glVertex3fv(&v_trapezoid[TquadIndices[i][3]][0]);
    }
    glEnd();
}



void room()
{
    // Tuong ben phai
    glPushMatrix();
    glTranslatef(-1.5, -1, .5);
    glScalef(5, 2, 0.1);
    drawCube1(1, 0.5, 0.3, 0.4, 0.7, 0.6);
    glPopMatrix();

    // Tuong ben trai
    glPushMatrix();
    glTranslatef(-4.5, -1, 0);
    glScalef(1, 2, 5);
    drawCube1(1, 0.5, 0.3, 0.4, 0.7, 0.6);
    glPopMatrix();

    // Tuong ben canh tuong phai
    glPushMatrix();
    glTranslatef(8, -1, 0);
    glScalef(0.2, 2, 5);
    drawCube1(1, 0.8, 0.7, 0.5, 0.4, 0.35);
    glPopMatrix();

    // Tran nha
    glPushMatrix();
    glTranslatef(-2, 5.1, 0);
    glScalef(5, 0.1, 7);
    drawCube1(1.0, 0.9, 0.8, 0.5, 0.45, 0.4);
    glPopMatrix();

    // San nha
    glPushMatrix();
    glScalef(5, 0.1, 7);
    glTranslatef(-1, -5, 0);
    drawCube1(0.5, 0.1, 0.0, 0.25, 0.05, 0);
    glPopMatrix();
}

void desk1() {
    // Ban lam viec
    glPushMatrix();
    glTranslatef(-1.5, 1, 2); // Vi tri cua ban
    glScalef(0.6, 0.1, 0.9); // Kich thuoc cua ban (dai, day, rong)
    drawCube1(0.5, 0.3, 0.1); // Ve ban su dung ham drawCube voi mau va kich thuoc dinh
    glPopMatrix();

    // Chan ban
    // Chan truoc ben trai
    glPushMatrix();
    glTranslatef(-1.5, -3.5, 4.39);
    glScalef(0.1, 1.5, 0.1);
    drawCube1(0.3, 0.3, 0.1);
    glPopMatrix();

    // Chan truoc ben phai
    glPushMatrix();
    glTranslatef(0, -3.5, 4.39);
    glScalef(0.1, 1.5, 0.1);
    drawCube1(0.3, 0.3, 0.1);
    glPopMatrix();

    // Chan sau ben trai
    glPushMatrix();
    glTranslatef(-1.5, -3.3, 2);
    glScalef(0.1, 1.5, 0.1);
    drawCube1(0.3, 0.3, 0.1);
    glPopMatrix();

    // Chan sau ben phai
    glPushMatrix();
    glTranslatef(0, -3.3, 2);
    glScalef(0.1, 1.5, 0.1);
    drawCube1(0.3, 0.3, 0.1);
    glPopMatrix();
}

void drawStudyChair() {
    // Ghe lam viec
    // Ghe ngoi
    glPushMatrix();
    glTranslatef(0.5, 0.5, 2.7); // Vi tri cua ghe
    glScalef(0.3, 0.05, 0.5); // Kich thuoc cua ghe (dai, day, rong)
    drawCube1(0.4, 0.4, 0.4); // Ve ghe su dung ham drawCube voi mau va kich thuoc dinh
    glPopMatrix();

    // Do dai cua phan tua lung
    glPushMatrix();
    glTranslatef(1.4, 0.5, 2.7); // Vi tri cua phan tua lung
    glRotatef(-90, 0, 1, 0);
    glScalef(0.49, 0.5, 0.05); // Kich thuoc cua phan tua lung (dai, cao, rong)
    drawCube1(1, 0.4, 0.4); // Ve phan tua lung su dung ham drawCube voi mau va kich thuoc dinh
    glPopMatrix();

    // Chan ghe
    glPushMatrix();
    glTranslatef(0.5, -3.9, 2.7);
    glScalef(0.05, 1.5, 0.1);
    drawCube1(0.3, 0.3, 0.1);
    glPopMatrix();

    // Chan ghe
    glPushMatrix();
    glTranslatef(1.25, -3.9, 2.7);
    glScalef(0.05, 1.5, 0.1);
    drawCube1(0.3, 0.3, 0.1);
    glPopMatrix();

    // Chan ghe
    glPushMatrix();
    glTranslatef(1.25, -3.9, 3.85);
    glScalef(0.05, 1.5, 0.1);
    drawCube1(0.3, 0.3, 0.1);
    glPopMatrix();

    // Chan ghe
    glPushMatrix();
    glTranslatef(0.5, -3.9, 3.85);
    glScalef(0.05, 1.5, 0.1);
    drawCube1(0.3, 0.3, 0.1);
    glPopMatrix();
}



void computer() {
    // Thung may
    glPushMatrix();
    glColor3f(0.5, 0.5, 0.5); // Mau cua thung may
    glTranslatef(-1.5, 1, 2); // Vi tri cua thung may
    glScalef(0.2, 0.4, 0.1); // Kich thuoc cua thung may (dai, cao, rong)
    drawCube1(1.0, 0.8, 0.6); // Ve thung may su dung ham drawCube voi mau va kich thuoc dinh
    glPopMatrix();

    // Man hinh
    glPushMatrix();
    glColor3f(0.3, 0.3, 0.8); // Mau cua man hinh
    glRotatef(90, 0, 1, 0);
    glTranslatef(-4.1, 1.5, -1.3); // Vi tri cua man hinh
    glScalef(0.5, 0.4, 0.02); // Kich thuoc cua man hinh (dai, cao, rong)
    drawCube1(0.5, 0.5, 0.5); // Ve man hinh su dung ham drawCube voi mau va kich thuoc dinh
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.3, 0.3, 0.8);
    glRotatef(90, 0, 1, 0);
    glTranslatef(-3.4, 1.2, -1.3); // Vi tri cua man hinh
    glScalef(0.02, 0.15, 0.02); // Kich thuoc cua man hinh (dai, cao, rong)
    drawCube1(0.5, 0.5, 0.5); // Ve man hinh su dung ham drawCube voi mau va kich thuoc dinh
    glPopMatrix();


    glPushMatrix();
    glColor3f(0.3, 0.3, 0.8);
    glRotatef(90, 0, 1, 0);
    glTranslatef(-3.5, 1.3, -1.4); // Vi tri cua man hinh
    glScalef(0.1, 0.01, 0.1); // Kich thuoc cua man hinh (dai, cao, rong)
    drawCube1(0.5, 0.5, 0.5); // Ve man hinh su dung ham drawCube voi mau va kich thuoc dinh
    glPopMatrix();

    // Ban phim
    glPushMatrix();
    glColor3f(0.2, 0.2, 0.2); // Mau cua ban phim
    glRotatef(90, 0, 1, 0);
    glTranslatef(-3.9, 1.2, -1); // Vi tri cua ban phim
    glScalef(0.3, 0.05, 0.15); // Kich thuoc cua ban phim (dai, cao, rong)
    drawCube1(1.0, 0.1, 0.4); // Ve ban phim su dung ham drawCube voi mau va kich thuoc dinh
    glPopMatrix();

    // Chuot
    glPushMatrix();
    glColor3f(0.2, 0.2, 0.2); // Mau cua chuot
    glTranslatef(-0.7, 1.3, 2.5); // Vi tri cua chuot
    glScalef(0.09, 0.02, 0.07); // Kich thuoc cua chuot (dai, cao, rong)
    drawCube1(0.5, 0.5, 0.5); // Ve chuot su dung ham drawCube voi mau va kich thuoc dinh
    glPopMatrix();
}

// Ham ve tranh anh
void picture() {
    // Buc tranh
    glPushMatrix();
    glTranslatef(3.5, 1.5, 0.8); // Vi tri cua buc tranh (phai nam phia tren khung tranh)
    glScalef(0.7, 0.5, 0.05); // Kich thuoc cua buc tranh (dai, cao, rong)
    drawCube1(0, 0, 0); // Ve buc tranh su dung ham drawCube voi mau va kich thuoc dinh
    glPopMatrix();

    glColor3f(1.0, 1.0, 1.0);
    glPushMatrix();
    glTranslatef(4, 2, 0.98); // Dieu chinh vi tri cua logo (tinh tu goc tren ben trai cua buc tranh)
    glRotatef(90, 0, 1, 0); // Xoay logo neu can
    glScalef(0.001, 0.02, 0.25); // Kich thuoc cua logo
    drawCube1(1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 10); // Ve logo
    glPopMatrix();

    // Logo Linkin Park thu hai
    glColor3f(1.0, 1.0, 1.0);
    glPushMatrix();
    glTranslatef(4, 2, 0.98); // Dieu chinh vi tri cua logo (tinh tu goc tren ben trai cua buc tranh)
    glRotatef(90, 0, 1, 0); // Xoay logo neu can
    glScalef(0.001, 0.28, 0.02); // Kich thuoc cua logo
    drawCube1(1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 10); // Ve logo
    glPopMatrix();
}


// Ham ve ban hoc 
void desk2() {

    glPushMatrix();
    glTranslatef(2, -0.5, 6.5);

    // Be mat ban
    glPushMatrix();
    glTranslatef(-1.5, 1, 2); // Vi tri cua ban
    glScalef(0.6, 0.08, 0.9); // Kich thuoc cua ban (chieu dai, do day, chieu rong)
    drawCube1(0.5, 0.3, 0.1); // Su dung ham drawCube1 de ve ban
    glPopMatrix();

    // Chan ban
    // Chan truoc ben trai
    glPushMatrix();
    glTranslatef(-1.5, -3.5, 4.39);
    glScalef(0.1, 1.5, 0.1);
    drawCube1(0.3, 0.3, 0.1);
    glPopMatrix();

    // Chan truoc ben phai
    glPushMatrix();
    glTranslatef(0, -3.5, 4.39);
    glScalef(0.1, 1.5, 0.1);
    drawCube1(0.3, 0.3, 0.1);
    glPopMatrix();

    // Chan sau ben trai 
    glPushMatrix();
    glTranslatef(-1.5, -3.3, 2);
    glScalef(0.1, 1.5, 0.1);
    drawCube1(0.3, 0.3, 0.1);
    glPopMatrix();

    // Chan sau ben phai
    glPushMatrix();
    glTranslatef(0, -3.3, 2);
    glScalef(0.1, 1.5, 0.1);
    drawCube1(0.3, 0.3, 0.1);
    glPopMatrix();
    glPopMatrix();
}

// Ham ve gia do TV

void drawTVStand() {
    // Khung TV
    glColor3f(0.5, 0.3, 0.2); // Mau nau
    glPushMatrix();
    glTranslatef(2, 0.9, -2.5); // Vi tri cua khung TV
    glScalef(1.3, 0.2, 0.1); // Kich thuoc cua khung TV
    drawCube1(0.5, 0.3, 0.2, 0.5, 0.3, 0.2); // Ve khung TV
    glPopMatrix();

    // TV
    glColor3f(0.1, 0.1, 0.1); // Mau den
    glPushMatrix();
    glTranslatef(2.5, 1.5, -2.3); // Vi tri TV
    glScalef(1, 0.6, 0.01); // Kich thuoc TV
    drawCube1(0.1, 0.1, 0.1, 0.1, 0.1, 0.1); // Ve TV
    glPopMatrix();
}

// Ham ve TV

void tv() {
    glPushMatrix();
    glTranslatef(10, -1.2, 13);
    glRotatef(90, 0, 1, 0);
    drawTVStand();
    glPopMatrix();
}

// Ham ve sofa

void sofa()
{

    glPushMatrix();
    glScalef(0.1, 0.5, 0.9);
    glTranslatef(-14, -0.5, 9.2);
    drawCube1(0.5, 0.2, 0.2, 0.25, 0.1, 0.1);
    glPopMatrix();

    glPushMatrix();
    glScalef(0.3, 0.2, 0.9); //1, 0.2, 0.9
    glTranslatef(-3.75, -1, 9.2);
    drawCube1(0.824, 0.706, 0.549, 0.412, 0.353, 0.2745);
    glPopMatrix();

}



// Ham ve tham
void carpet() {
    glPushMatrix();
    glColor3f(0.5, 0.5, 0.5);
    glTranslatef(0, -0.2, 6.3);
    glScalef(2, 0.01, 2);
    drawCube1(0.5, 0.5, 0.5);
    glPopMatrix();
}


// Ham ve dong ho

void clock()
{
    // Than dong ho
    glColor3f(0.545, 0.271, 0.075);
    glPushMatrix();
    glTranslatef(-0.9, 1.8, 7.87);
    //glRotatef(22, 0,0,1);
    glScalef(0.08, 0.25, 0.1);
    drawCube1(0.545, 0.271, 0.075, 0.271, 0.1335, 0.0375, 50);
    glPopMatrix();

    // Than dong ho mau trang
    glPushMatrix();
    glTranslatef(-0.83, 1.9, 7.9);
    //glRotatef(22, 0,0,1);
    glScalef(0.06, 0.2, 0.08);
    drawCube1(1.000, 0.894, 0.710, 1.000, 0.894, 0.710);
    glPopMatrix();

    // Kim gio
    glPushMatrix();
    glTranslatef(-0.65, 2.18, 8.01);
    glRotatef(45, 1, 0, 0);
    glScalef(0.0001, 0.01, 0.04);
    drawCube1(0, 0, 0, 0, 0, 0);
    glPopMatrix();

    // Kim phut
    glPushMatrix();
    glTranslatef(-0.65, 2.18, 8.01);
    glRotatef(90, 1, 0, 0);
    glScalef(0.0001, 0.012, 0.08);
    drawCube1(0, 0, 0, 0, 0, 0);
    glPopMatrix();

}

// Ham ve dong ho 1

void clock1() {
    glPushMatrix();
    glTranslatef(10, 1, 2);
    glRotatef(270, 0, 1, 0);
    clock();
    glPopMatrix();
}

// Ham ve sach

void drawBook() {
    // Mat truoc cua sach
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.2, 0.2); // Mau cua bia sach
    glVertex3f(-0.2, 0.0, 0.0); // Diem duoi ben trai
    glVertex3f(0.2, 0.0, 0.0);  // Diem duoi ben phai
    glVertex3f(0.2, 0.4, 0.2);  // Diem tren ben phai
    glVertex3f(-0.2, 0.4, 0.2); // Diem tren ben trai
    glEnd();

    // Mat sau cua sach
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.2, 0.2); // Mau cua bia sach
    glVertex3f(-0.1, 0.0, -0.02); // Diem duoi ben trai
    glVertex3f(0.1, 0.0, -0.02);  // Diem duoi ben phai
    glVertex3f(0.1, 0.2, -0.02);  // Diem tren ben phai
    glVertex3f(-0.1, 0.2, -0.02); // Diem tren ben trai
    glEnd();

    // Lung sach
    glBegin(GL_QUADS);
    glColor3f(0.2, 0.2, 0.6); // Mau cua duong gap sach
    glVertex3f(-0.1, 0.0, 0.0);  // Diem duoi ben trai
    glVertex3f(-0.1, 0.0, -0.02); // Diem duoi ben phai
    glVertex3f(-0.1, 0.2, -0.02); // Diem tren ben phai
    glVertex3f(-0.1, 0.2, 0.0);  // Diem tren ben trai
    glEnd();
}

// Ham ve tu quan ao

void cupboard()
{
    //Tu quan ao/Almari ************************************************************

        //Tu quan ao
    glPushMatrix();
    glTranslatef(4, 0, 4.4);
    glScalef(0.5, 1, 0.5);
    drawCube1(0.5, 0.2, 0.2, 0.3, 0.1, 0.1);
    glPopMatrix();

    //Thanh doc 1 cua tu quan ao
    glPushMatrix();
    glTranslatef(4, 1, 5.9);
    glScalef(0.25, 0.01, 0.0001);
    drawCube1(0.2, 0.1, 0.1, 0.1, 0.05, 0.05);
    glPopMatrix();

    //Thanh doc 2 cua tu quan ao
    glPushMatrix();
    glTranslatef(4, 0.5, 5.9);
    glScalef(0.25, 0.01, 0.0001);
    drawCube1(0.2, 0.1, 0.1, 0.1, 0.05, 0.05);
    glPopMatrix();

    //Thanh doc cuoi cung cua tu quan ao
    glPushMatrix();
    glTranslatef(4, 0, 5.9);
    glScalef(0.5, 0.01, 0.0001);
    drawCube1(0.2, 0.1, 0.1, 0.1, 0.05, 0.05);
    glPopMatrix();

    //Thanh ngang cuoi cung cua tu quan ao
    glPushMatrix();
    glTranslatef(5.5, 0, 5.9);
    glScalef(0.01, 1, 0.0001);
    drawCube1(0.2, 0.1, 0.1, 0.1, 0.05, 0.05);
    glPopMatrix();

    //Thanh ngang ben phai cua tu quan ao
    glPushMatrix();
    glTranslatef(4.75, 0, 5.9);
    glScalef(0.01, 1, 0.0001);
    drawCube1(0.2, 0.1, 0.1, 0.1, 0.05, 0.05);
    glPopMatrix();

    //Thanh ngang ben trai cua tu quan ao
    glPushMatrix();
    glTranslatef(4, 0, 5.9);
    glScalef(0.01, 1, 0.0001);
    drawCube1(0.2, 0.1, 0.1, 0.1, 0.05, 0.05);
    glPopMatrix();

    //Tay nam ben phai cua tu quan ao
    glPushMatrix();
    glTranslatef(5, 1.4, 5.9);
    glScalef(0.02, 0.18, 0.01);
    drawCube1(0.2, 0.1, 0.1, 0.1, 0.05, 0.05);
    glPopMatrix();

    //Tay nam ben trai cua tu quan ao
    glPushMatrix();
    glTranslatef(4.5, 1.4, 5.9);
    glScalef(0.02, 0.18, 0.01);
    drawCube1(0.2, 0.1, 0.1, 0.1, 0.05, 0.05);
    glPopMatrix();

    //Tay nam ngan keo 1 cua tu quan ao
    glPushMatrix();
    glTranslatef(4.3, 0.7, 5.9);
    glScalef(0.05, 0.02, 0.01);
    drawCube1(0.2, 0.1, 0.1, 0.1, 0.05, 0.05);
    glPopMatrix();

    //Tay nam ngan keo 2 cua tu quan ao
    glPushMatrix();
    glTranslatef(4.3, 0.25, 5.9);
    glScalef(0.05, 0.02, 0.01);
    drawCube1(0.2, 0.1, 0.1, 0.1, 0.05, 0.05);
    glPopMatrix();
}

// Ham ve tu quan ao 1

void cupboard1() {
    glPushMatrix();
    glTranslatef(13, -0.2, -2);
    glRotatef(270, 0, 1, 0);
    cupboard();
    glPopMatrix();
}


// Ham wallshelf() ve ke tuong va sach tren ke

void wallshelf()
{
    //Wall Shelf **********************************************
    // Ve ke tuong

    // Ke tuong mot
    glPushMatrix();
    glTranslatef(1.5, 2.7, 0.9);
    glScalef(0.4, 0.03, 0.2);
    drawCube1(0.2, 0.1, 0.1, 0.1, 0.05, 0.05);
    glPopMatrix();

    // Ke tuong hai
    glPushMatrix();
    glTranslatef(1, 2.3, 0.9);
    glScalef(0.4, 0.03, 0.2);
    drawCube1(0.2, 0.1, 0.1, 0.1, 0.05, 0.05);
    glPopMatrix();

    // Ke tuong ba
    glPushMatrix();
    glTranslatef(0.5, 1.9, 0.9);
    glScalef(0.4, 0.03, 0.2);
    drawCube1(0.2, 0.1, 0.1, 0.1, 0.05, 0.05);
    glPopMatrix();

    // Ke tuong bon
    glPushMatrix();
    glTranslatef(1, 1.5, 0.9);
    glScalef(0.4, 0.03, 0.2);
    drawCube1(0.2, 0.1, 0.1, 0.1, 0.05, 0.05);
    glPopMatrix();

    // Ke tuong nam
    glPushMatrix();
    glTranslatef(1.5, 1.1, 0.9);
    glScalef(0.4, 0.03, 0.2);
    drawCube1(0.2, 0.1, 0.1, 0.1, 0.05, 0.05);
    glPopMatrix();

    // Ve sach tren ke

    // Sach tren ke mot
    glPushMatrix();
    glTranslatef(1.5, 2.7, 0.9);
    glTranslatef(0.0, 0.02, -0.05); // Dich chuyen cho vi tri sach tren ke
    drawBook(); // Ham ve mot cuon sach
    glPopMatrix();

    // Sach tren ke hai
    glPushMatrix();
    glTranslatef(1, 2.3, 0.9);
    glTranslatef(0.0, 0.02, -0.05); // Dich chuyen cho vi tri sach tren ke
    drawBook(); // Ham ve mot cuon sach
    glPopMatrix();

    // Sach tren ke ba
    glPushMatrix();
    glTranslatef(0.5, 1.9, 0.9);
    glTranslatef(0.0, 0.02, -0.05); // Dich chuyen cho vi tri sach tren ke
    drawBook(); // Ham ve mot cuon sach
    glPopMatrix();

    // Sach tren ke bon
    glPushMatrix();
    glTranslatef(1, 1.5, 0.9);
    glTranslatef(0.0, 0.02, -0.05); // Dich chuyen cho vi tri sach tren ke
    drawBook(); // Ham ve mot cuon sach
    glPopMatrix();

    // Sach tren ke nam
    glPushMatrix();
    glTranslatef(1.5, 1.1, 0.9);
    glTranslatef(0.0, 0.02, -0.05); // Dich chuyen cho vi tri sach tren ke
    drawBook(); // Ham ve mot cuon sach
    glPopMatrix();
}

// Ham lamp() ve den

void lamp()
{
    // Co so cua den
    glPushMatrix();
    glTranslatef(.6, 0.5, 8.95);
    glScalef(0.07, 0.02, 0.07);
    drawCube1(0, 0, 1, 0, 0, 0.5);
    glPopMatrix();

    // Chan den
    glColor3f(1, 0, 0);
    glPushMatrix();
    glTranslatef(.7, 0.35, 9.05);
    glScalef(0.01, 0.2, 0.01);
    drawCube1(1, 0, 0, 0.5, 0.0, 0.0);
    glPopMatrix();

    // Man den
    glColor3f(0.000, 0.000, 0.545);
    glPushMatrix();
    glTranslatef(.6, 0.9, 8.9);
    glScalef(0.08, 0.09, 0.08);
    drawTrapezoid(0.000, 0.000, 0.545, 0, 0, 0.2725);
    //drawCube1(0.000, 0.000, 0.545,  0,0,0.2725);
    glPopMatrix();
}

// Ham lamp1() ve den 1

void lamp1() {
    glPushMatrix();
    glTranslatef(-1.9, 0.8, -4.5);
    lamp();
    glPopMatrix();
}




// Ham window() ve cua so
void window()
{
    // Cua so ********************************************
    // Cua so mau trang
    glPushMatrix();
    glTranslatef(-0.9, 1, 8.9);
    glScalef(0.0001, .6, .3);
    drawCube1(1.0, 1.0, 1.0, 0.05, 0.05, 0.05);
    glPopMatrix();

    // Goc phai duoi cua so
    glPushMatrix();
    glTranslatef(-0.9, 1, 8.9);
    glScalef(0.04, 0.6, 0.0001);
    drawCube1(0.8, 0.6, 0.4, 0.4, 0.3, 0.2);
    glPopMatrix();

    // Goc trai duoi cua so
    glPushMatrix();
    glTranslatef(-0.9, 1, 9.8);
    glScalef(0.04, 0.6, 0.0001);
    drawCube1(0.8, 0.6, 0.4, 0.4, 0.3, 0.2);
    glPopMatrix();

    // Goc tren cua so
    glPushMatrix();
    glTranslatef(-0.7, 2.7, 8.9);
    glScalef(0.0001, 0.05, 0.4);
    drawCube1(0.7, 0.6, 0.5, 0.35, 0.3, 0.25);
    glPopMatrix();

    // Goc duoi cua so
    glPushMatrix();
    glTranslatef(-0.8, 1.02, 8.9);
    glScalef(0.0001, 0.02, 0.34);
    drawCube1(0.7, 0.6, 0.5, 0.35, 0.3, 0.25);
    glPopMatrix();

    // Thanh doc cua so 1
    glPushMatrix();
    glTranslatef(-0.87, 2.1, 8.9);
    glScalef(0.0001, 0.02, 0.3);
    drawCube1(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 5);
    glPopMatrix();

    // Thanh doc cua so 2
    glPushMatrix();
    glTranslatef(-0.87, 1.6, 8.9);
    glScalef(0.0001, 0.02, 0.3);
    drawCube1(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 5);
    glPopMatrix();

    // Thanh ngang cua so
    glPushMatrix();
    glTranslatef(-0.87, 1, 9.3);
    glScalef(0.0001, 0.6, 0.02);
    drawCube1(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 5);
    glPopMatrix();
}

// Ham window1() ve cua so 1
void window1() {
    glPushMatrix();
    glTranslatef(-0.5, 0.5, 0);
    window();
    glPopMatrix();
}

// Ham lightBulb1() ve bong den thu nhat
void lightBulb1()
{
    // Khai bao cac thong so vat lieu
    GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat mat_diffuse[] = { 1.000, 0.843, 0.000, 1.0 };
    GLfloat high_shininess[] = { 100.0 };
    GLfloat mat_emission[] = { 1.000, 1,1, 0.0 };

    glPushMatrix();
    glTranslatef(5, 5, 8);
    glScalef(0.2, 0.2, 0.2);
    glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    // Kiem tra trang thai cua cong tac 1
    if (switchOne == true) {
        glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission); // Phat ra anh sang
    }
    else {
        glMaterialfv(GL_FRONT, GL_EMISSION, no_mat); // Khong phat ra anh sang
    }

    glutSolidSphere(1.0, 16, 16);
    glPopMatrix();
}



// Ham lightBulb2() ve bong den thu hai
void lightBulb2()
{
    // Khai bao cac thong so vat lieu
    GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat mat_ambient[] = { 0.7, 0.7, 0.7, 1.0 };
    GLfloat mat_diffuse[] = { 1.000, 0.843, 0.000, 1.0 };
    GLfloat high_shininess[] = { 100.0 };
    GLfloat mat_emission[] = { 1,1,1, 1.0 };

    // Dua ma tran hien tai vao stack
    glPushMatrix();
    // Dich chuyen toa do hien tai
    glTranslatef(0, 5, 8);
    // Thay doi ti le kich thuoc doi tuong
    glScalef(0.2, 0.2, 0.2);
    // Thiet lap vat lieu cho mat truoc cua cac hinh hoc
    glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
    // Kiem tra trang thai cua cong tac 2
    if (switchTwo == true) {
        glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission); // Phat ra anh sang
    }
    else {
        glMaterialfv(GL_FRONT, GL_EMISSION, no_mat); // Khong phat ra anh sang
    }
    // Ve mot hinh cau
    glutSolidSphere(1.0, 16, 16);
    // Dua ma tran da luu tru tu stack ra
    glPopMatrix();
}

// Ham lightBulb3() ve bong den thu ba
void lightBulb3()
{
    // Khai bao cac thong so vat lieu
    GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat mat_diffuse[] = { 1.000, 0.843, 0.000, 1.0 };
    GLfloat high_shininess[] = { 100.0 };
    GLfloat mat_emission[] = { 1,1,1, 1.0 };

    // Dua ma tran hien tai vao stack
    glPushMatrix();
    // Dich chuyen toa do hien tai
    glTranslatef(0.7, 1.5, 9.0);
    // Thay doi ti le kich thuoc doi tuong
    glScalef(0.2, 0.2, 0.2);
    // Thiet lap vat lieu cho mat truoc cua cac hinh hoc
    glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
    // Kiem tra trang thai cua cong tac den
    if (switchLamp == true) {
        glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission); // Phat ra anh sang
    }
    else {
        glMaterialfv(GL_FRONT, GL_EMISSION, no_mat); // Khong phat ra anh sang
    }
    // Ve mot hinh cau
    glutSolidSphere(1.0, 16, 16);
    // Dua ma tran da luu tru tu stack ra
    glPopMatrix();
}


void lightOne()
{
    // Luu trang thai hien tai cua ma tran
    glPushMatrix();

    // Mang mau khong co anh sang
    GLfloat no_light[] = { 0.0, 0.0, 0.0, 1.0 };

    // Mang mau anh sang moi truong
    GLfloat light_ambient[] = { 0.5, 0.5, 0.5, 1.0 };

    // Mang mau anh sang khuech tan
    GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };

    // Mang mau anh sang phan xa
    GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };

    // Vi tri cua nguon sang
    GLfloat light_position[] = { 5.0, 5.0, 8.0, 1.0 }; //5 5 10

    // Bat nguon sang
// glEnable( GL_LIGHT0);

    // Kiem tra va cai dat mau anh sang moi truong
    if (amb1 == true) { glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient); }
    else { glLightfv(GL_LIGHT0, GL_AMBIENT, no_light); }

    // Kiem tra va cai dat mau anh sang khuech tan
    if (diff1 == true) { glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse); }
    else { glLightfv(GL_LIGHT0, GL_DIFFUSE, no_light); }

    // Kiem tra va cai dat mau anh sang phan xa
    if (spec1 == true) { glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular); }
    else { glLightfv(GL_LIGHT0, GL_SPECULAR, no_light); }

    // Cai dat vi tri cua nguon sang
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    // Khoi phuc trang thai truoc do cua ma tran
    glPopMatrix();
}


void lightTwo()
{
    // Luu trang thai hien tai cua ma tran
    glPushMatrix();

    // Mang mau khong co anh sang
    GLfloat no_light[] = { 0.0, 0.0, 0.0, 1.0 };

    // Mang mau anh sang moi truong
    GLfloat light_ambient[] = { 0.5, 0.5, 0.5, 1.0 };

    // Mang mau anh sang khuech tan
    GLfloat light_diffuse[] = { 1.0, 1.0, 0.9, 1.0 };

    // Mang mau anh sang phan xa
    GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };

    // Vi tri cua nguon sang
    GLfloat light_position[] = { 0.0, 5.0, 8.0, 1.0 };

    // Bat nguon sang
    // glEnable(GL_LIGHT1);

    // Kiem tra va cai dat mau anh sang moi truong
    if (amb2 == true) { glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient); }
    else { glLightfv(GL_LIGHT1, GL_AMBIENT, no_light); }

    // Kiem tra va cai dat mau anh sang khuech tan
    if (diff2 == true) { glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse); }
    else { glLightfv(GL_LIGHT1, GL_DIFFUSE, no_light); }

    // Kiem tra va cai dat mau anh sang phan xa
    if (spec2 == true) { glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular); }
    else { glLightfv(GL_LIGHT1, GL_SPECULAR, no_light); }

    // Cai dat vi tri cua nguon sang
    glLightfv(GL_LIGHT1, GL_POSITION, light_position);

    // Khoi phuc trang thai truoc do cua ma tran
    glPopMatrix();
}

void display(void)
{
    // Xoa bo dem mau va bo dem sau
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Chuyen sang che do chieu phoi canh
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, 1, 1, 100);

    // Chuyen sang che do chieu mo hinh
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(eyeX, eyeY, eyeZ, refX, refY, refZ, 0, 1, 0); //7,2,15, 0,0,0, 0,1,0

    // Bat anh sang
    glEnable(GL_LIGHTING);
    // Ve anh sang mot
    lightOne();
    // Ve anh sang hai
    lightTwo();
    // Ve phong
    room();
    // Ve ban 1
    desk1();
    // Ve ban 2
    desk2();
    // Ve ghe hoc
    drawStudyChair();
    // Ve buc tranh 
    picture();
    // Ve may tinh 
    computer();
    // Ve TV
    tv();
    // Ve sofa
    sofa();
    // Ve tham 
    carpet();
    // Ve dong ho 1
    clock1();
    // Ve den dung 1
    lamp1();
    // Ve tu do
    cupboard1();
    // Ve ke do
    wallshelf();
    // Ve cua so 
    window1();
    // Ve bong den 1
    lightBulb1();
    // Ve bong den 2
    lightBulb2();
    // Tat anh sang
    glDisable(GL_LIGHTING);
    // Lam sach cac lenh doi trong bo nho
    glFlush();
    // Hoan doi buffer
    glutSwapBuffers();
}

void myKeyboardFunc(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'w': // di chuyen diem Eye len theo truc Y
        eyeY += 1.0;
        break;
    case 's': // di chuyen diem Eye xuong theo truc Y
        eyeY -= 1.0;
        break;
    case 'a': // di chuyen diem Eye sang trai theo truc X
        eyeX -= 1.0;
        break;
    case 'd': // di chuyen diem Eye sang phai theo truc X
        eyeX += 1.0;
        break;
    case 'o':  // thu nho
        eyeZ += 1;
        break;
    case 'i': // phong to
        eyeZ -= 1;
        break;
    case 'q': // quay ve vi tri mac dinh cua diem Eye va diem tham chieu
        eyeX = 7.0; eyeY = 2.0; eyeZ = 15.0;
        refX = 0.0; refY = 0.0; refZ = 0.0;
        break;
    case 'j': // di chuyen diem tham chieu len theo truc Y
        refY += 1.0;
        break;
    case 'n': // di chuyen diem tham chieu xuong theo truc Y
        refY -= 1.0;
        break;
    case 'b': // di chuyen diem tham chieu sang trai theo truc X
        refX -= 1.0;
        break;
    case 'm': // di chuyen diem tham chieu sang phai theo truc X
        refX += 1.0;
        break;
    case 'k':  // di chuyen diem tham chieu xa khoi man hinh/ theo truc Z
        refZ += 1;
        break;
    case 'l': // di chuyen diem tham chieu gan man hinh/ theo truc Z
        refZ -= 1;
        break;
    case '1': // bat va tat den mot
        if (switchOne == false)
        {
            switchOne = true; amb1 = true; diff1 = true; spec1 = true;
            glEnable(GL_LIGHT0); break;
        }
        else if (switchOne == true)
        {
            switchOne = false; amb1 = false; diff1 = false; spec1 = false; glDisable(GL_LIGHT0); break;
        }
    case '2': // bat va tat den hai
        if (switchTwo == false)
        {
            switchTwo = true; amb2 = true; diff2 = true; spec2 = true;
            glEnable(GL_LIGHT1); break;
        }
        else if (switchTwo == true)
        {
            switchTwo = false; amb2 = false; diff2 = false; spec2 = false;
            glDisable(GL_LIGHT1); break;
        }
    case '3': // bat va tat den chieu
        if (switchLamp == false)
        {
            switchLamp = true; amb3 = true; diff3 = true; spec3 = true;
            glEnable(GL_LIGHT2); break;
        }
        else if (switchLamp == true)
        {
            switchLamp = false; amb3 = false; diff3 = false; spec3 = false;
            glDisable(GL_LIGHT2); break;
        }
    case '4': // bat va tat anh sang moi truong mot
        if (amb1 == false) { amb1 = true; break; }
        else { amb1 = false; break; }
    case '5': // bat va tat anh sang khuech tan mot
        if (diff1 == false) { diff1 = true; break; }
        else { diff1 = false; break; }
    case '6': // bat va tat anh sang phan xa mot
        if (spec1 == false) { spec1 = true; break; }
        else { spec1 = false; break; }
    case '7': // bat va tat anh sang moi truong hai
        if (amb2 == false) { amb2 = true; break; }
        else { amb2 = false; break; }
    case '8': // bat va tat anh sang khuech tan hai
        if (diff2 == false) { diff2 = true; break; }
        else { diff2 = false; break; }
    case '9': // bat va tat anh sang phan xa hai
        if (spec2 == false) { spec2 = true; break; }
        else { spec2 = false; break; }
    case 'e': // bat va tat anh sang moi truong cua den chieu
        if (amb3 == false) { amb3 = true; break; }
        else { amb3 = false; break; }
    case 'r': // bat va tat anh sang khuech tan cua den chieu
        if (diff3 == false) { diff3 = true; break; }
        else { diff3 = false; break; }
    case 't': // bat va tat anh sang phan xa cua den chieu
        if (spec3 == false) { spec3 = true; break; }
        else { spec3 = false; break; }
    case 27:    // phim Escape
        exit(1);
    }

    glutPostRedisplay();
}


void fullScreen(int w, int h)
{
    if (h == 0)
        h = 1;
    float ratio = (GLfloat)w / (GLfloat)h;

    //Set the perspective coordinate system
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glViewport(0, 0, w, h);
    gluPerspective(60, ratio, 1, 500);
    //glFrustum(-2.5,2.5,-2.5,2.5, ratio, 200);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    std::cout << "De di chuyen diem Eye:" << std::endl;
    std::cout << "w: len" << std::endl;
    std::cout << "s: xuong" << std::endl;
    std::cout << "a: trai" << std::endl;
    std::cout << "d: phai" << std::endl;
    std::cout << "i: phong to" << std::endl;
    std::cout << "o: thu nho" << std::endl;
    std::cout << "      " << std::endl;
    std::cout << "De di chuyen diem Camera:" << std::endl;
    std::cout << "j: len" << std::endl;
    std::cout << "n: xuong" << std::endl;
    std::cout << "b: trai" << std::endl;
    std::cout << "m: phai" << std::endl;
    std::cout << "l: di chuyen gan hon" << std::endl;
    std::cout << "k: di chuyen xa hon" << std::endl;
    std::cout << "      " << std::endl;
    std::cout << "Nhan q de quay ve vi tri mac dinh" << std::endl;
    std::cout << "      " << std::endl;
    std::cout << "Den sang:" << std::endl;
    std::cout << "Nguon sang 1 [den ben phai tren man hinh]:" << std::endl;
    std::cout << "1: bat/tat den mot" << std::endl;
    std::cout << "4: bat/tat anh sang moi truong mot" << std::endl;
    std::cout << "5: bat/tat anh sang khuech tan mot" << std::endl;
    std::cout << "6: bat/tat anh sang phan xa mot" << std::endl;
    std::cout << "      " << std::endl;
    std::cout << "Nguon sang 2 [den ben trai tren man hinh]:" << std::endl;
    std::cout << "2: bat/tat den hai" << std::endl;
    std::cout << "7: bat/tat anh sang moi truong hai" << std::endl;
    std::cout << "8: bat/tat anh sang khuech tan hai" << std::endl;
    std::cout << "9: bat/tat anh sang phan xa hai" << std::endl;
    std::cout << "      " << std::endl;
    std::cout << "Den chieu (den chop):" << std::endl;
    std::cout << "3: bat/tat den chieu" << std::endl;
    std::cout << "e: bat/tat anh sang moi truong cua den chieu" << std::endl;
    std::cout << "r: bat/tat anh sang khuech tan cua den chieu" << std::endl;
    std::cout << "t: bat/tat anh sang phan xa cua den chieu" << std::endl;
    std::cout << "      " << std::endl;
    std::cout << "____________________" << std::endl;



    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    glutInitWindowPosition(100, 100);
    glutInitWindowSize(windowHeight, windowWidth);
    glutCreateWindow("Phong hoc");

    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);

    glutReshapeFunc(fullScreen);
    glutDisplayFunc(display);
    glutKeyboardFunc(myKeyboardFunc);
    glutMainLoop();

    return 0;
}
lấy đồ vật từ code sang code kia đc k hoặc ngược lại
làm thế lâu lắm
xem làm ntn để láy đc thì lấy
tại cần bàn vs ghế
code kia có ổ cứng vs bàn phím, chuột, bàn ghế
đầy đủ các vật t cần
#include"glut.h"
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

void initialize(void);  // Khởi tạo các cài đặt

void display(void);  // Hàm hiển thị, tại đây chúng ta thực hiện toàn bộ việc vẽ

void reshape(int w, int h);  // Hàm thay đổi kích thước cửa sổ

void keyboard(unsigned char key, int x, int y);  // Hàm phản hồi khi nhấn phím từ bàn phím

void idle(void);  // Hàm idle, điều khiển hoạt ảnh

void setLight0(bool flag);  // Thiết lập ánh sáng 0
void setLight1(bool flag);  // Thiết lập ánh sáng 1
void setLight2(bool flag);  // Thiết lập ánh sáng 2



//Khai báo biến toàn cục 

// Định nghĩa các thông số của nguồn sáng 0
GLfloat light_pos0[] = { 0, 25, -10, 1 };  // Vị trí của nguồn sáng
GLfloat light_dir0[] = { 0, -1, 0 };       // Hướng của nguồn sáng
GLfloat light_cutoff0 = 45;                // Góc cắt của nguồn sáng
GLfloat light_amb0[] = { 0.2, 0.2, 0.2, 1.0 };  // Màu ánh sáng môi trường
GLfloat light_dif0[] = { 0.4, 0.4, 0.4, 1.0 };  // Màu sắc khi chiếu sáng lên bề mặt
GLfloat light_spc0[] = { 1.0, 1.0, 1.0, 1.0 };  // Màu sắc phản chiếu từ bề mặt

// Định nghĩa các thông số của nguồn sáng 1
GLfloat light_pos1[] = { 10, 10, 10, 1 };    // Vị trí của nguồn sáng
GLfloat light_dir1[] = { 0, -1, -1 };        // Hướng của nguồn sáng
GLfloat light_cutoff1 = 20;                  // Góc cắt của nguồn sáng
GLfloat light_amb1[] = { 0.1, 0.3, 0.1, 1.0 };  // Màu ánh sáng môi trường
GLfloat light_dif1[] = { 0.1, 0.7, 0.1, 1.0 };  // Màu sắc khi chiếu sáng lên bề mặt
GLfloat light_spc1[] = { 1.0, 1.0, 1.0, 1.0 };  // Màu sắc phản chiếu từ bề mặt

// Định nghĩa các thông số của nguồn sáng 2
GLfloat light_pos2[] = { 0, 10, -10, 1 };    // Vị trí của nguồn sáng
GLfloat light_dir2[] = { 0, -1, 0 };         // Hướng của nguồn sáng
GLfloat light_cutoff2 = 50;                  // Góc cắt của nguồn sáng
GLfloat light_amb2[] = { 0.2, 0.15, 0, 1.0 };  // Màu ánh sáng môi trường
GLfloat light_dif2[] = { 0.8, 0.75, 0, 1.0 };  // Màu sắc khi chiếu sáng lên bề mặt
GLfloat light_spc2[] = { 1.0, 1.0, 0, 1.0 };  // Màu sắc phản chiếu từ bề mặt



bool RoomLight = true;  // Ánh sáng phòng
bool Computer = false;  // Máy tính

bool ChristmasTree = false;  // Cây thông Noel
int ChristmasTreeAng = 0;  // Góc quay của cây thông Noel
bool ChristmasTreeLight = false;  // Ánh sáng của cây thông Noel
bool ChristmasTreeJumpUp = true;  // Trạng thái nhảy của cây thông Noel
float ChristmasTreeJumpDis = 0;  // Khoảng cách nhảy của cây thông Noel

bool CeilingLight = false;  // Đèn trần


void setLight0(bool flag)   // Thiết lập ánh sáng 0
{
    //glLightfv(Tên nguồn sáng, Loại, Giá trị) 
    glLightfv(GL_LIGHT0, GL_POSITION, light_pos0);  // Vị trí nguồn sáng
    glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, light_dir0);  // Hướng ánh sáng dạng spot
    glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, light_cutoff0);  // Góc cắt ánh sáng dạng spot

    glLightfv(GL_LIGHT0, GL_AMBIENT, light_amb0);  // Ánh sáng môi trường
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_dif0);  // Ánh sáng phản xạ khuếch tán
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_spc0);  // Ánh sáng phản xạ gương

    if (flag)
        glEnable(GL_LIGHT0);  // Bật nguồn sáng
    else
        glDisable(GL_LIGHT0);  // Tắt nguồn sáng
}

void setLight1(bool flag)   // Thiết lập ánh sáng 1
{
    glLightfv(GL_LIGHT1, GL_POSITION, light_pos1);  // Vị trí nguồn sáng
    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, light_dir1);  // Hướng ánh sáng dạng spot
    glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, light_cutoff1);  // Góc cắt ánh sáng dạng spot

    glLightfv(GL_LIGHT1, GL_AMBIENT, light_amb1);  // Ánh sáng môi trường
    glLightfv(GL_LIGHT1, GL_DIFFUSE, light_dif1);  // Ánh sáng phản xạ khuếch tán
    glLightfv(GL_LIGHT1, GL_SPECULAR, light_spc1);  // Ánh sáng phản xạ gương

    if (flag)
        glEnable(GL_LIGHT1);  // Bật nguồn sáng
    else
        glDisable(GL_LIGHT1);  // Tắt nguồn sáng
}


void setLight2(bool flag)  // Thiết lập ánh sáng 2
{
    glLightfv(GL_LIGHT2, GL_POSITION, light_pos2);  // Vị trí nguồn sáng
    glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, light_dir2);  // Hướng ánh sáng dạng spot
    glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, light_cutoff2);  // Góc cắt ánh sáng dạng spot

    glLightfv(GL_LIGHT2, GL_AMBIENT, light_amb2);  // Ánh sáng môi trường
    glLightfv(GL_LIGHT2, GL_DIFFUSE, light_dif2);  // Ánh sáng phản xạ khuếch tán
    glLightfv(GL_LIGHT2, GL_SPECULAR, light_spc2);  // Ánh sáng phản xạ gương

    if (flag)
        glEnable(GL_LIGHT2);  // Bật nguồn sáng
    else
        glDisable(GL_LIGHT2);  // Tắt nguồn sáng
}

void initialize(void) // Khởi tạo cài đặt
{
    glEnable(GL_DEPTH_TEST);  // Bật kiểm tra độ sâu
    glEnable(GL_COLOR_MATERIAL);  // Bật vật liệu màu
    glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);  // Mô hình ánh sáng kép

    glEnable(GL_NORMALIZE);  // Chuẩn hóa vector pháp tuyến
    glEnable(GL_LIGHTING);  // Bật ánh sáng
    glEnable(GL_LIGHT0);  // Bật nguồn sáng 0
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);  // Xóa bộ đệm độ sâu và bộ đệm màu
}


void display(void) // Here's Where We Do All The Drawing
{

    // Thiết lập nguồn sáng cho căn phòng
    setLight0(RoomLight); // Thiết lập nguồn sáng 0 dựa trên trạng thái của biến RoomLight
    setLight1(ChristmasTreeLight); // Thiết lập nguồn sáng 1 dựa trên trạng thái của biến ChristmasTreeLight
    setLight2(CeilingLight); // Thiết lập nguồn sáng 2 dựa trên trạng thái của biến CeilingLight

    // Xóa bộ đệm độ sâu và bộ đệm màu để chuẩn bị cho việc vẽ mới
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

    // Chuyển sang chế độ ma trận GL_MODELVIEW và thiết lập ma trận hiện tại thành ma trận đơn vị
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Thiết lập màu sắc cho vật liệu sử dụng trong vẽ
    GLfloat matBlack[] = { 0, 0, 0, 1 };
    GLfloat matWhite[] = { 1, 1, 1, 1 };
    GLfloat matPink[] = { 1, 0.8, 0.2, 1 };
    GLfloat matBrown[] = { 1, 0.6, 0.3, 1 };
    GLfloat matYellowGreen[] = { 0.5, 1, 0.5, 1 };
    GLfloat matRed[] = { 1, 0, 0, 1 };
    GLfloat matGreen[] = { 0, 1, 0, 1 };
    GLfloat matBlue[] = { 0, 0, 1, 1 };
    GLfloat matSkyBlue[] = { 0.5, 1, 1, 1 };
    GLfloat matYellow[] = { 1, 1, 0, 1 };
    GLfloat matGold[] = { 0.4, 0.3, 0.1, 1 };
    GLfloat matShininess[] = { 50 };

    // Phạm vi không gian của căn phòng:
    // - Tọa độ x từ 10 đến -10
    // - Tọa độ y từ 10 đến -10
    // - Tọa độ z từ 0 đến -20


    // Vẽ màu sắc cho các mặt tường
// Tường phía sau
    glColor3f(0.6, 1, 1);
    glMaterialfv(GL_FRONT, GL_AMBIENT, matSkyBlue); // Màu ánh sáng môi trường
    glMaterialfv(GL_FRONT, GL_DIFFUSE, matSkyBlue); // Màu phản xạ khu vực
    glMaterialfv(GL_FRONT, GL_SPECULAR, matSkyBlue); // Màu phản xạ gương
    glMaterialfv(GL_FRONT, GL_SHININESS, matShininess); // Bậc bóng
    glMaterialfv(GL_FRONT, GL_EMISSION, matBlack); // Màu phát xạ (đen)
    glBegin(GL_QUADS);
    glVertex3f(10, 10, -20); // Đỉnh phải trên
    glVertex3f(-10, 10, -20); // Đỉnh trái trên
    glVertex3f(-10, -10, -20); // Đỉnh trái dưới
    glVertex3f(10, -10, -20); // Đỉnh phải dưới
    glEnd();

    // Tường phía trên
    glColor3f(0.9, 0.8, 0.7);
    glMaterialfv(GL_FRONT, GL_AMBIENT, matWhite); // Màu ánh sáng môi trường
    glMaterialfv(GL_FRONT, GL_DIFFUSE, matWhite); // Màu phản xạ khu vực
    glMaterialfv(GL_FRONT, GL_SPECULAR, matWhite); // Màu phản xạ gương
    glMaterialfv(GL_FRONT, GL_SHININESS, matShininess); // Bậc bóng
    glMaterialfv(GL_FRONT, GL_EMISSION, matBlack); // Màu phát xạ (đen)
    glBegin(GL_QUADS);
    glVertex3f(10, 10, -20); // Đỉnh phải trên
    glVertex3f(10, 10, 0); // Đỉnh phải dưới
    glVertex3f(-10, 10, 0); // Đỉnh trái dưới
    glVertex3f(-10, 10, -20); // Đỉnh trái trên
    glEnd();

    // Tường bên trái
    glColor3f(0.6, 1, 1);
    glMaterialfv(GL_FRONT, GL_AMBIENT, matSkyBlue); // Màu ánh sáng môi trường
    glMaterialfv(GL_FRONT, GL_DIFFUSE, matSkyBlue); // Màu phản xạ khu vực
    glMaterialfv(GL_FRONT, GL_SPECULAR, matSkyBlue); // Màu phản xạ gương
    glMaterialfv(GL_FRONT, GL_SHININESS, matShininess); // Bậc bóng
    glMaterialfv(GL_FRONT, GL_EMISSION, matBlack); // Màu phát xạ (đen)
    glBegin(GL_QUADS);
    glVertex3f(-10, 10, -20); // Đỉnh trái trên
    glVertex3f(-10, 10, 0); // Đỉnh trái dưới
    glVertex3f(-10, -10, 0); // Đỉnh trái dưới
    glVertex3f(-10, -10, -20); // Đỉnh trái trên
    glEnd();
    // Tường dưới cùng
    glColor3f(0.5, 0.45, 0.33);
    glMaterialfv(GL_FRONT, GL_AMBIENT, matBlue); // Màu ánh sáng môi trường
    glMaterialfv(GL_FRONT, GL_DIFFUSE, matBlue); // Màu phản xạ khu vực
    glMaterialfv(GL_FRONT, GL_SPECULAR, matBlack); // Màu phản xạ gương
    glMaterialfv(GL_FRONT, GL_SHININESS, matShininess); // Bậc bóng
    glMaterialfv(GL_FRONT, GL_EMISSION, matBlack); // Màu phát xạ (đen)
    glBegin(GL_QUADS);
    glVertex3f(-10, -10, -20); // Đỉnh trái dưới
    glVertex3f(-10, -10, 0); // Đỉnh trái trên
    glVertex3f(10, -10, 0); // Đỉnh phải trên
    glVertex3f(10, -10, -20); // Đỉnh phải dưới
    glEnd();

    // Tường bên phải
    glColor3f(0.6, 1, 1);
    glMaterialfv(GL_FRONT, GL_AMBIENT, matSkyBlue); // Màu ánh sáng môi trường
    glMaterialfv(GL_FRONT, GL_DIFFUSE, matSkyBlue); // Màu phản xạ khu vực
    glMaterialfv(GL_FRONT, GL_SPECULAR, matSkyBlue); // Màu phản xạ gương
    glMaterialfv(GL_FRONT, GL_SHININESS, matShininess); // Bậc bóng
    glMaterialfv(GL_FRONT, GL_EMISSION, matBlack); // Màu phát xạ (đen)
    glBegin(GL_QUADS);
    glVertex3f(10, -10, -20); // Đỉnh phải dưới
    glVertex3f(10, -10, 0); // Đỉnh phải trên
    glVertex3f(10, 10, 0); // Đỉnh phải trên
    glVertex3f(10, 10, -20); // Đỉnh phải dưới
    glEnd();

    // Vẽ phần đứng của tủ sách
    glPushMatrix();
    glColor3f(0.4, 0.2, 0); // Màu nâu
    glTranslatef(0, -4, 0); // Di chuyển xuống dưới để nó không chạm vào sàn
    glScalef(2, 8, 0.5); // Kích thước của phần đứng
    glutSolidCube(1);
    glPopMatrix();

    // Vẽ kệ sách trên
    glPushMatrix();
    glColor3f(0.6, 0.4, 0.2); // Màu nâu đậm
    glTranslatef(0, -1, 0); // Di chuyển lên trên một chút
    glScalef(2.2, 0.5, 0.5); // Kích thước của kệ sách
    glutSolidCube(1);
    glPopMatrix();

    // Vẽ các giá sách
    glPushMatrix();
    glColor3f(0.6, 0.4, 0.2); // Màu nâu đậm
    for (int i = 0; i < 4; ++i) {
        glTranslatef(0, -1.5, 0); // Di chuyển xuống dưới để vẽ giá sách mới
        glPushMatrix();
        glTranslatef(-0.8, 0, 0); // Di chuyển sang trái một chút
        glScalef(0.2, 4, 0.5); // Kích thước của giá sách
        glutSolidCube(1);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(0.0, 0, 0); // Di chuyển sang phải một chút
        glScalef(0.2, 4, 0.5); // Kích thước của giá sách
        glutSolidCube(1);
        glPopMatrix();
    }**/



        // Cabin - Tủ
        glColor3f(0.6, 0.3, 0.1);
    glMaterialfv(GL_FRONT, GL_AMBIENT, matBrown); // Màu ánh sáng môi trường
    glMaterialfv(GL_FRONT, GL_DIFFUSE, matBrown); // Màu phản xạ khu vực
    glMaterialfv(GL_FRONT, GL_SPECULAR, matBrown); // Màu phản xạ gương
    glMaterialfv(GL_FRONT, GL_SHININESS, matShininess); // Bậc bóng
    glMaterialfv(GL_FRONT, GL_EMISSION, matGold); // Màu phát xạ (vàng)

    glPushMatrix();
    glTranslatef(6, -10, -18); // Di chuyển đến vị trí của tủ
    glScalef(8, 10, 4); // Thay đổi kích thước để vẽ thành hình hộp chữ nhật
    glutSolidCube(1); // Vẽ tủ
    glPopMatrix(); // Kết thúc phần tủ**/



    // Máy tính
// Phần dưới
    glColor3f(0, 0, 0); // Màu đen
    glPushMatrix();
    glTranslatef(6, -5, -18); // Di chuyển đến vị trí đáy máy tính
    glRotatef(0, 0, 1, 0); // Xoay (hiện tại không có xoay)
    glScalef(1, 0.1, 0.8); // Thay đổi kích thước để vẽ thành hình hộp chữ nhật (chiều dài, chiều cao, chiều rộng)
    glutSolidCube(1); // Vẽ hình hộp chữ nhật
    glPopMatrix(); // Kết thúc phần đáy máy tính

    // Cổ máy
    glPushMatrix();
    glTranslatef(6, -4.9, -18); // Di chuyển đến vị trí của cổ máy tính
    glRotatef(0, 0, 1, 0); // Xoay (hiện tại không có xoay)
    glScalef(0.1, 0.8, 0.1); // Thay đổi kích thước để vẽ thành hình hộp chữ nhật (chiều dài, chiều cao, chiều rộng)
    glutSolidCube(1); // Vẽ hình hộp chữ nhật
    glPopMatrix(); // Kết thúc phần cổ máy tính

    // Màn hình
    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_AMBIENT, matYellow); // Màu ánh sáng môi trường
    glMaterialfv(GL_FRONT, GL_DIFFUSE, matYellow); // Màu phản xạ khu vực
    glMaterialfv(GL_FRONT, GL_SPECULAR, matWhite); // Màu phản xạ gương
    glMaterialfv(GL_FRONT, GL_SHININESS, matShininess); // Bậc bóng
    glMaterialfv(GL_FRONT, GL_EMISSION, matBlack); // Màu phát xạ (đen)
    if (Computer) glMaterialfv(GL_FRONT, GL_EMISSION, matBlue); // Nếu máy tính được bật, sử dụng màu xanh lá cây
    glTranslatef(6, -3.6, -18); // Di chuyển đến vị trí của màn hình
    glRotatef(0, 0, 1, 0); // Xoay (hiện tại không có xoay)
    glScalef(3, 1.8, 0.1); // Thay đổi kích thước để vẽ thành hình hộp chữ nhật (chiều dài, chiều cao, chiều rộng)
    glutSolidCube(1); // Vẽ hình hộp chữ nhật
    glPopMatrix(); // Kết thúc phần màn hình

    // Bàn làm việc màu nâu
    glColor3f(0.6, 0.3, 0.1); // Đặt màu là màu nâu
    glBegin(GL_POLYGON);
    glVertex2f(-0.8, -0.6); // Góc dưới bên trái
    glVertex2f(-0.8, -0.5); // Góc trên bên trái
    glVertex2f(0.8, -0.5); // Góc trên bên phải
    glVertex2f(0.8, -0.6); // Góc dưới bên phải
    glEnd();**/
        glColor3f(1, 0.6, 0.3);
    glMaterialfv(GL_FRONT, GL_AMBIENT, matBrown); // Màu ánh sáng môi trường
    glMaterialfv(GL_FRONT, GL_DIFFUSE, matBrown); // Màu phản xạ khu vực
    glMaterialfv(GL_FRONT, GL_SPECULAR, matWhite); // Màu phản xạ gương
    glMaterialfv(GL_FRONT, GL_SHININESS, matShininess); // Bậc bóng
    glMaterialfv(GL_FRONT, GL_EMISSION, matBlack); // Màu phát xạ (đen)

    glPushMatrix();
    glTranslatef(8, -4.5, -6); // Di chuyển đến vị trí của bàn làm việc
    glScalef(4, 1, 12); // Thay đổi kích thước để vẽ thành hình hộp chữ nhật (chiều dài, chiều cao, chiều rộng)
    glutSolidCube(1); // Vẽ hình hộp chữ nhật
    glPopMatrix(); // Kết thúc phần bàn làm việc

    glPushMatrix();
    glTranslatef(9.5, -7, -6); // Di chuyển đến vị trí của bàn làm việc
    glScalef(1, 6, 12); // Thay đổi kích thước để vẽ thành hình hộp chữ nhật (chiều dài, chiều cao, chiều rộng)
    glutSolidCube(1); // Vẽ hình hộp chữ nhật
    glPopMatrix(); // Kết thúc phần bàn làm việc**/





    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, -10, -19.99);

    glPushMatrix(); // Đèn trần
    glColor3f(1, 1, 0); // Màu vàng
    glMaterialfv(GL_FRONT, GL_AMBIENT, matYellow); // Màu ánh sáng môi trường
    glMaterialfv(GL_FRONT, GL_DIFFUSE, matYellow); // Màu phản xạ khu vực
    glMaterialfv(GL_FRONT, GL_SPECULAR, matWhite); // Màu phản xạ gương
    glMaterialfv(GL_FRONT, GL_SHININESS, matShininess); // Bậc bóng
    glMaterialfv(GL_FRONT, GL_EMISSION, matBlack); // Màu phát xạ (đen)
    if (CeilingLight) glMaterialfv(GL_FRONT, GL_EMISSION, matYellow); // Nếu đèn trần được bật, sử dụng màu vàng
    glTranslatef(0, 9.0, -10); // Di chuyển đến vị trí của đèn trần
    glRotatef(270, 1, 0, 0); // Xoay (270 độ theo trục x)
    glutSolidCone(1, 1, 16, 16); // Vẽ hình nón
    glPopMatrix();

    // TODO: Thêm hoạt cảnh ở đây

    glFlush(); // Xả bộ đệm
    glutSwapBuffers(); // Hoán đổi các bộ đệm


}

void reshape(int w, int h) // Định hình lại kích thước cửa sổ
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(65, (GLfloat)w / (GLfloat)h, 1.0, 100.0);

    // Góc nhìn cá nhân (x1,y1,z1) nhìn vào (x2,y2,z2) trục (x,y,z)
    gluLookAt(0.0, 0.0, 15, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

void keyboard(unsigned char key, int x, int y) // Phản ứng sự kiện bàn phím
{
    switch (key)
    {

    case'\033': // Nhấn 'esc' để thoát
        exit(0);
        break;

    case'1': // Ánh sáng phòng
        RoomLight = !RoomLight;
        printf("Nhấn phím '1'.\n");
        break;
    case'2': // Ánh sáng trần nhà
        CeilingLight = !CeilingLight;
        printf("Nhấn phím '2'.\n");
        break;
    case'3': // Ánh sáng cây Giáng Sinh
        ChristmasTreeLight = !ChristmasTreeLight;
        if (!ChristmasTreeLight) ChristmasTreeJumpDis = 0;
        printf("Nhấn phím '3'.\n");
        break;
    case'4': // Hoạt động của cây Giáng Sinh
        ChristmasTree = !ChristmasTree;
        if (!ChristmasTree) ChristmasTreeJumpDis = 0;
        printf("Nhấn phím '4'.\n");
        break;
    case'6': // Máy tính
        Computer = !Computer;
        printf("Nhấn phím '6'.\n");
        break;
    }
}


void idle(void) // Điều khiển hoạt hình
{
    if (ChristmasTree) {
        if (!ChristmasTreeLight)
            ChristmasTreeAng = ++ChristmasTreeAng % 360;   // Xoay cây Giáng Sinh
        else {
            if (ChristmasTreeJumpUp) {
                ChristmasTreeJumpDis += 0.1;              // Nhảy của cây Giáng Sinh
                if (ChristmasTreeJumpDis >= 1) ChristmasTreeJumpUp = false;
            }
            else {
                ChristmasTreeJumpDis -= 0.1;
                if (ChristmasTreeJumpDis <= 0) ChristmasTreeJumpUp = true;
            }
        }
    }
    Sleep(10);
    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    // Khởi tạo thư viện GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);

    // Tạo cửa sổ
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("PHÒNG 3D");

    // Khởi tạo cài đặt
    initialize();

    // Tạo phản ứng sự kiện
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutIdleFunc(idle);

    // Vào vòng lặp chính của cửa sổ
    glutMainLoop();

}
.
