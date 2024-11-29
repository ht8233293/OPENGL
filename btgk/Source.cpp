#include "glut.h"

void init() {
    glClearColor(0.3, 0.3, 0.3, 0.3);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    glMatrixMode(GL_PROJECTION);
    gluPerspective(80.0, 800.0 / 600.0, 1.0, 100.0);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
}

/**void initLight() {
    // Vị trí nguồn sáng
    GLfloat light_pos1[] = { -15.0, 5.0, 1.0, 10.0 };
    GLfloat light_pos2[] = { 0, 14.0, 0, 1.0 };

    // Thiết lập màu môi trường
    GLfloat ambient1[] = { 1.0, 0.91, 0.81, 1.0 };
    GLfloat ambient2[] = { 1.0, 0.91, 0.81, 1.0 };

    // Thiết lập màu khuyết tán
    GLfloat diff_use1[] = { 1.0, 0.91, 0.81, 1.0 };
    GLfloat diff_use2[] = { 1.0, 0.91, 0.81, 1.0 };

    // Thiết lập màu phản chiếu
    GLfloat specular1[] = { 1.0, 0.91, 0.81, 1.0 };
    GLfloat specular2[] = { 1.0, 0.91, 0.81, 1.0 };

    // Thiết lập độ phản chiếu
    GLfloat shininess1 = 100.0f;
    GLfloat shininess2 = 1.0f;

    glLightfv(GL_LIGHT0, GL_POSITION, light_pos1);
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient1);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diff_use1);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular1);

    glLightfv(GL_LIGHT1, GL_POSITION, light_pos2);
    glLightfv(GL_LIGHT1, GL_AMBIENT, ambient2);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, diff_use2);
    glLightfv(GL_LIGHT1, GL_SPECULAR, specular2);

    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);

    // Thiết lập góc cắt của ánh sáng
    GLfloat spotCutoff = 50.0;
    glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, spotCutoff);

    // Hướng chiếu sáng
    GLfloat light_dir[3] = { 0, -1.0, 0 };
    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, light_dir);
    glEnable(GL_LIGHT1);



}**/

void reShape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    float ratio = (float)width / (float)height;
    gluPerspective(45.0, ratio, 1, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

void drawBackWall() {
    // Thiết lập smooth shading
    glShadeModel(GL_SMOOTH);

    // Vẽ các mặt phẳng tạo thành tường phía sau
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5); // Màu xám

    // Mặt phẳng x - y
    glNormal3f(0.0, 0.0, 1.0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(10.0, 0.0, 0.0);
    glVertex3f(10.0, 5.0, 0.0);
    glVertex3f(0.0, 5.0, 0.0);

    // Mặt phẳng y - z
    glNormal3f(-1.0, 0.0, 0.0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, 0.0, 15.0);
    glVertex3f(0.0, 5.0, 15.0);
    glVertex3f(0.0, 5.0, 0.0);

    // Mặt phẳng x - z (top)
    glNormal3f(0.0, 1.0, 0.0);
    glVertex3f(0.0, 5.0, 0.0);
    glVertex3f(15.0, 5.0, 0.0);
    glVertex3f(15.0, 5.0, 15.0);
    glVertex3f(0.0, 5.0, 15.0);

    // Mặt phẳng x - z (bottom)
    glNormal3f(0.0, -1.0, 0.0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(15.0, 0.0, 0.0);
    glVertex3f(15.0, 0.0, 15.0);
    glVertex3f(0.0, 0.0, 15.0);
    glEnd();
}

void drawSofa() {
    // Vẽ sofa
    glColor3f(1.0, 0.5, 0.5); // Màu đỏ hồng

    // Ghế ngồi
    glPushMatrix();
    glTranslatef(5.0, 0.0, 5.0); // Di chuyển sofa đến vị trí mong muốn
    glScalef(3.0, 0.5, 0.91);      // Kích thước sofa
    glutSolidCube(2.0);           // Vẽ sofa dưới dạng hình lập phương
    glPopMatrix();



    // Tựa ghế
    glColor3f(1.0, 0.5, 0.5); // Màu đỏ hồng
    glPushMatrix();
    glTranslatef(5.0, 0.7, 5.7); // Di chuyển tựa ghế đến vị trí mong muốn
    glScalef(3.0, 0.5, 0.2);      // Kích thước tựa ghế
    glutSolidCube(2.0);           // Vẽ tựa ghế dưới dạng hình lập phương
    glPopMatrix();
}


void drawLamp() {
    // Vẽ đèn trang trí
    glColor3f(0.8, 0.8, 0.2); // Màu vàng
    glPushMatrix();
    glTranslatef(0.0, 14.0, 0.0); // Di chuyển đèn đến vị trí mong muốn
    glutSolidSphere(0.5, 10, 10);  // Vẽ đèn dưới dạng hình cầu
    glPopMatrix();
}
void drawCeilingLamp() {
    // Vẽ đèn trần
    glColor3f(1.0, 1.0, 0.0); // Màu vàng cho đèn
    glPushMatrix();
    glTranslatef(4.5, 4.9, 3.5); // Di chuyển đèn đến vị trí trên trần
    glutSolidSphere(0.5, 20, 20);  // Vẽ đèn dưới dạng hình cầu
    glPopMatrix();
}


/**void drawChair() {
    // Vẽ ghế
    glColor3f(0.9, 0.1, 0.6); // Màu nâu cho ghế

    // Mặt ngồi ghế
    glPushMatrix();
    glTranslatef(10.05, 0.7, 6.75); // Di chuyển mặt ngồi ghế đến vị trí mong muốn
    glScalef(1.8, 0.1, 0.9);        // Kích thước của mặt ngồi ghế (chiều dài, chiều cao, chiều rộng)
    glutSolidCube(1.0);             // Vẽ mặt ngồi ghế dưới dạng hình lập phương
    glPopMatrix();

    // Chân ghế (bên trái)
    glPushMatrix();
    glTranslatef(10.1, 0.35, 6.75); // Di chuyển chân ghế bên trái đến vị trí mong muốn
    glScalef(0.1, 0.7, 0.9);         // Kích thước của chân ghế bên trái (chiều dài, chiều cao, chiều rộng)
    glutSolidCube(1.0);              // Vẽ chân ghế bên trái dưới dạng hình lập phương
    glPopMatrix();

    // Chân ghế (bên phải)
    glPushMatrix();
    glTranslatef(10.95, 0.35, 6.75); // Di chuyển chân ghế bên phải đến vị trí mong muốn
    glScalef(0.1, 0.7, 0.9);          // Kích thước của chân ghế bên phải (chiều dài, chiều cao, chiều rộng)
    glutSolidCube(1.0);               // Vẽ chân ghế bên phải dưới dạng hình lập phương
    glPopMatrix();
}**/



/**void drawTV() {
    // Vẽ TV
    glColor3f(0.1, 0.1, 0.1); // Màu đen cho TV

    // Màn hình TV
    glPushMatrix();
    glTranslatef(5.0, 7.0, 14.0); // Di chuyển màn hình TV đến vị trí mong muốn
    glScalef(2.0, 1.0, 0.1);      // Kích thước của màn hình TV (chiều dài, chiều cao, chiều rộng)
    glutSolidCube(1.0);           // Vẽ màn hình TV dưới dạng hình lập phương
    glPopMatrix();

    // Thân TV
    glPushMatrix();
    glTranslatef(5.0, 5.0, 14.0); // Di chuyển thân TV đến vị trí mong muốn
    glScalef(2.5, 2.0, 0.2);      // Kích thước của thân TV (chiều dài, chiều cao, chiều rộng)
    glutSolidCube(1.0);           // Vẽ thân TV dưới dạng hình lập phương
    glPopMatrix();
}**/


/**void drawTable() {
    // Vẽ bàn
    glColor3f(0.5, 0.35, 0.05); // Màu nâu cho bàn

    // Mặt bàn
    // Vẽ mặt bàn dưới dạng hình lập phương
    glPushMatrix();
    glTranslatef(10.0, 1.0, 8.0); // Di chuyển mặt bàn đến vị trí mong muốn
    glScalef(2.0, 0.1, 1.0);      // Kích thước của mặt bàn (chiều dài, chiều cao, chiều rộng)
    glutSolidCube(1.0);           // Vẽ mặt bàn dưới dạng hình lập phương
    glPopMatrix();

    // Vẽ 4 chân bàn
    glColor3f(0.6, 0.4, 0.2); // Màu nâu cho chân bàn

    // Chân bàn 1
    glPushMatrix();
    glTranslatef(9.5, 0.0, 7.5); // Di chuyển chân bàn đến vị trí mong muốn
    glScalef(0.1, 2.0, 0.1);     // Kích thước của chân bàn (chiều dài, chiều cao, chiều rộng)
    glutSolidCube(1.0);          // Vẽ chân bàn dưới dạng hình lập phương
    glPopMatrix();

    // Chân bàn 2
    glPushMatrix();
    glTranslatef(9.5, 0.0, 8.45); // Di chuyển chân bàn đến vị trí mong muốn
    glScalef(0.1, 1.95, 0.1);     // Kích thước của chân bàn (chiều dài, chiều cao, chiều rộng)
    glutSolidCube(1.0);          // Vẽ chân bàn dưới dạng hình lập phương
    glPopMatrix();

    // Chân bàn 3
    glPushMatrix();
    glTranslatef(10.5, 0.0, 7.5); // Di chuyển chân bàn đến vị trí mong muốn
    glScalef(0.1, 2.0, 0.1);      // Kích thước của chân bàn (chiều dài, chiều cao, chiều rộng)
    glutSolidCube(1.0);           // Vẽ chân bàn dưới dạng hình lập phương
    glPopMatrix();

    // Chân bàn 4
    glPushMatrix();
    glTranslatef(10.5, 0.0, 8.45); // Di chuyển chân bàn đến vị trí mong muốn
    glScalef(0.1, 1.95, 0.1);      // Kích thước của chân bàn (chiều dài, chiều cao, chiều rộng)
    glutSolidCube(1.0);           // Vẽ chân bàn dưới dạng hình lập phương
    glPopMatrix();
}**/



/**void drawCarpet() {
    // Vẽ thảm
    glColor3f(1.0, 0.0, 0.0); // Màu xám cho thảm

    // Mặt thảm
    glBegin(GL_QUADS);
    glVertex3f(10.0, 0.0, 10.0);  // Đỉnh trái dưới
    glVertex3f(5.0, 0.01, 10.0); // Đỉnh phải dưới
    glVertex3f(5.0, 0.01, 2.0); // Đỉnh phải trên
    glVertex3f(10.0, 0.0, 2.0); // Đỉnh trái trên
    glEnd();
}**/

void drawPictureFrame() {
    // Vẽ khung ảnh
    glColor3f(0.8, 0.6, 0.4); // Màu nâu cho khung ảnh
    // Vẽ mặt trước của khung ảnh
    glBegin(GL_QUADS);
    glVertex3f(2.0, 2.0, 0.1);  // Đỉnh trái
    glVertex3f(3.0, 2.0, 0.1);  // Đỉnh phải
    glVertex3f(3.0, 3.0, 0.1);  // Đỉnh dưới phải
    glVertex3f(2.0, 3.0, 0.1);  // Đỉnh dưới trái
    glEnd();

    // Vẽ các cạnh của khung ảnh
    glColor3f(0.0, 0.0, 0.0); // Màu đen cho đường viền
    glLineWidth(2.0); // Độ dày của đường viền

    glBegin(GL_LINE_LOOP);
    glVertex3f(2.0, 2.0, 0.1);  // Đỉnh trái
    glVertex3f(3.0, 2.0, 0.1);  // Đỉnh phải
    glVertex3f(3.0, 3.0, 0.1);  // Đỉnh dưới phải
    glVertex3f(2.0, 3.0, 0.1);  // Đỉnh dưới trái
    glEnd();


}

void disPlay() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(15.0, 3.0, 10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    drawBackWall();      // Vẽ tường phía sau
    drawCeilingLamp();
   // drawSofa();          // Vẽ sofa
    drawLamp();          // Vẽ đèn
  //  drawChair();         // Vẽ ghế
   // drawTable();         // Vẽ bàn
    //drawCarpet();        // Vẽ thảm
    drawPictureFrame();  // Vẽ khung ảnh
    drawLamp();
    glFlush();
    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1000, 1000);
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH) - 1000) / 2, (glutGet(GLUT_SCREEN_HEIGHT) - 1000) / 2);
    glutCreateWindow("Living Room");
    init();
    //initLight();
    glutReshapeFunc(reShape);
    glutDisplayFunc(disPlay);
    glutMainLoop();
    return 0;
}
