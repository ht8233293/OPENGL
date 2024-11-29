#include "glut.h"
//#include "math.h"

int startX, startY;
float angleX = 0;
float angleY = 0;
bool isDragging = false;
bool isZoomMode = false;
bool isDoorOpen = false;

void init() {
	glClearColor(0.3, 0.3, 0.3, 0.3);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(80.0, 800.0 / 600.0, 1.0, 100.0);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
}

void mouseButton(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		startX = x;
		startY = y;
		isDragging = true;
	}
	else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
		isDragging = false;
	}
}

void mouseMotion(int x, int y) {
	if (isDragging) {
		int deltaX = x - startX;
		int deltaY = y - startY;
		angleX += deltaX * 0.1;
		angleY += deltaY * 0.1;
		startX = x;
		startY = y;
		glutPostRedisplay();
	}
}


void initLight() {

	// vi tri nguon sang
	//GLfloat light_pos1[] = { 5.0, 5.0, 1.0, 0.0 };
	GLfloat light_pos1[] = { 0.0, 0.0, -15.0, 0.5 };
	//GLfloat light_pos2[] = { 0, 14.0, 0.0, 1.0 };
	GLfloat light_pos2[] = { 0.0, 15.0, 5.0, 0.5 };


	// thiet lap mau moi truong
	GLfloat ambient1[] = { 0.5, 0.5, 0.5, 0.0 };
	GLfloat ambient2[] = { 0.7, 0.7, 0.4, 0.0 };

	// thiet lap do khuyech tan mau
	GLfloat diff_use1[] = { 1.0, 0.91, 0.81, 1.0 };
	GLfloat diff_use2[] = { 0.5, 0.91, 0.81, 1.0 };

	// thiet lap do phan chieu
	GLfloat specular1[] = { 1.0, 0.91, 0.81, 1.0 };
	GLfloat specular2[] = { 0.5, 0.91, 0.81, 1.0 };

	// thiet lap specular phan xa
	GLfloat shininess2 = 1.0f;
	glMateriali(GL_FRONT, GL_SHININESS, shininess2);

	glLightfv(GL_LIGHT0, GL_POSITION, light_pos1);
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient1);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diff_use1);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular1);


	glLightfv(GL_LIGHT1, GL_POSITION, light_pos2);
	glLightfv(GL_LIGHT1, GL_AMBIENT, ambient2);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, diff_use2);
	glLightfv(GL_LIGHT1, GL_SPECULAR, specular2);

	glEnable(GL_LIGHTING);
	//glEnable(GL_LIGHT1);
	//glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);


	// 
	GLfloat spotCutoff = 30.0;
	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, spotCutoff);

	// huong chieu san
	GLfloat light_dir[3] = { 0, -1.0, -2.0 };
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, light_dir); // -1 chieu xuong
	glEnable(GL_LIGHT1);
}



void keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case '1':
		glDisable(GL_LIGHT1);
		break;
	case '2':
		glEnable(GL_LIGHT1);
		break;

	}
	glutPostRedisplay();

}
void reShape(int width, int height) {
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	float ratio = (float)width / (float)height;
	gluPerspective(45.0, ratio, 1, 100.0);
	glMatrixMode(GL_MODELVIEW);
}
void DrawTV() {
	glPushMatrix();
	glTranslatef(2, 2.5, 4);

	glColor3f(0.0, 0.0, 0.0);
	glPushMatrix();
	glTranslatef(0.0, 0.0, 0.0);
	glScalef(3.0, 1.3, 0.05);
	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(0.0, 0.0, 0.0);
	glPushMatrix();
	glTranslatef(0.0, -0.8, 0.0);
	glScalef(0.45, 0.5, 0.025);
	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(0.6, 0.6, 0.6);
	glPushMatrix();
	glTranslatef(0.0, -1.6, 0.0);
	glScalef(2.2, 1.4, 1.2);
	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(0.6, 0.6, 0.6);
	glPushMatrix();
	glTranslatef(0.0, -0.89, 0.0);
	glScalef(1.5, 0.0, 0.5);
	glutSolidSphere(0.5, 50, 20);
	glPopMatrix();
	glPopMatrix();
}
void DrawCoodinate2D() {
	//x
	glColor3f(1, 0, 0);
	glBegin(GL_LINES);
	glVertex3f(100, 0, 0);
	glVertex3f(-100, 0, 0);
	glEnd();

	//y
	glColor3f(0, 1, 0);
	glBegin(GL_LINES);
	glVertex3f(0, 100, 0);
	glVertex3f(0, -100, 0);
	glEnd();
}
void DrawCoodinate3D() {
	glDisable(GL_LIGHTING);
	DrawCoodinate2D();

	glColor3f(0, 0, 1);
	glBegin(GL_LINES);
	glVertex3f(0, 0, 100);
	glVertex3f(0, 0, -100);
	glEnd();

	glEnable(GL_LIGHTING);
}
void DrawRoomWall() {
	glColor3f(0.5, 0.5, 0.5);

	//san
	glPushMatrix();
	glScalef(10, 0.5f, 10);
	glutSolidCube(1);
	glPopMatrix();

	//tuong phai
	glPushMatrix();
	glTranslatef(0.0, 4.75, -5);
	glScalef(10, 10, 0.5f);
	glutSolidCube(1);
	glPopMatrix();

	//tuong trai
	glPushMatrix();
	glTranslatef(-5, 4.75, 0.0);
	glScalef(0.5, 10, 10);
	glutSolidCube(1);
	glPopMatrix();

}
void DrawBook() {
	glColor3f(1, 1, 1);
	// khối trang sách
	glPushMatrix();
	glScalef(0.7, 0.7, 0.2);
	glutSolidCube(1);
	glPopMatrix();

	//bia1
	glPushMatrix();
	glColor3f(0.78, 0.63, 0.51); // Màu xám
	glTranslatef(0, 0, 0.1);
	glScalef(0.8, 0.8, 0.05);
	glutSolidCube(1);
	glPopMatrix();

	//bia2
	glPushMatrix();
	glTranslatef(0, 0, -0.1);
	glScalef(0.8, 0.8, 0.05);
	glutSolidCube(1);
	glPopMatrix();

	//bia3 mat truoc
	glPushMatrix();
	glTranslatef(0.4, 0, 0);
	glScalef(0.05, 0.8, 0.25);
	glutSolidCube(1);
	glPopMatrix();
}
void DrawBookWithY(float y) {
	float start = -1.2;
	float end = 1.2;

	float delta = start;
	for (int i = 0; i <= (end - start) / 0.3f; i++) {
		glPushMatrix();
		glTranslatef(0, y, delta);
		DrawBook();
		glPopMatrix();
		delta += 0.3f;
	}
}
void DrawBookCase() {

	//glEnable(GL_LIGHTING);
	GLfloat light_pos[] = { 5.0, 3.0, 2.0, 1.0 };
	glLightfv(GL_LIGHT2, GL_POSITION, light_pos);

	//Thiết lập màu môi trường của vật liệu
	GLfloat ambient[] = { 0.0, 0.0, 1.0, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
	//Thiết lập độ khuyếch tán màu
	GLfloat diff_use[] = { 1, 1, 1, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff_use);
	//Thiết lập độ phản chiếu
	GLfloat specular[] = { 1.0, 1.0, 1.0, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
	//Thiết lập độ lớn cho specular
	GLfloat shininess = 30.0f;
	glMateriali(GL_FRONT, GL_SHININESS, shininess);

	glPushMatrix();
	glTranslatef(-4, 0.7, 3);
	glColor3f(0.7, 0.5, 0.3);
	//san1
	glPushMatrix();
	glScalef(1, 0.2, 2.7);
	glutSolidCube(1);
	glPopMatrix();

	//san2
	glPushMatrix();
	glTranslatef(0, 1.7, 0);
	glScalef(1, 0.2, 2.7);
	glutSolidCube(1);
	glPopMatrix();

	//san3
	glPushMatrix();
	glTranslatef(0, 3.2, 0);
	glScalef(1, 0.2, 2.7);
	glutSolidCube(1);
	glPopMatrix();

	//san3
	glPushMatrix();
	glTranslatef(0, 4.7, 0);
	glScalef(1, 0.2, 2.7);
	glutSolidCube(1);
	glPopMatrix();

	// canh trai
	glPushMatrix();
	glTranslatef(0, 2.2, 1.4);
	glScalef(1, 5.2, 0.2);
	glutSolidCube(1);
	glPopMatrix();

	// canh trai
	glPushMatrix();
	glTranslatef(0, 2.2, -1.4);
	glScalef(1, 5.2, 0.2);
	glutSolidCube(1);
	glPopMatrix();

	DrawBookWithY(0.5);
	DrawBookWithY(2.2);
	DrawBookWithY(3.7);

	glPopMatrix();
}
void DrawChairLeg(float x, float z) {
	glPushMatrix();
	glTranslated(x, -0.1, z); // Dịch chuyển theo tọa độ x và z
	glScalef(0.15, 0.4, 0.15); // Scale chiều rộng và chiều sâu
	glutSolidCube(1);
	glPopMatrix();
	glEnd();
}
void DrawSofa1() {
	glPushMatrix();
	glTranslatef(-4.1, 0.5, -5);

	glColor3f(0.6, 0.6, 0.6);
	glPushMatrix();
	glTranslatef(0.6, 0.1, 5.0);
	glScalef(2.0, 0.1, 2.0);
	glutSolidCube(1);
	glPopMatrix();

	glColor3f(1.0, 1.0, 1.0);
	glPushMatrix();
	glTranslatef(0.6, 0.4, 5.0);
	glScalef(2.0, 0.5, 2.0);
	glutSolidCube(1);
	glPopMatrix();

	glColor3f(1.0, 1.0, 1.0);
	glPushMatrix();
	glTranslatef(-0.15, 1.2, 5.0);
	glScalef(0.5, 2.0, 2.0);
	glutSolidCube(1);
	glPopMatrix();

	glColor3f(0.2, 0.2, 0.2);
	glPushMatrix();
	glTranslatef(0.6, 0.87, 6.12);
	glScalef(2.0, 1.5, 0.25);
	glutSolidCube(1);
	glPopMatrix();

	glColor3f(0.2, 0.2, 0.2);
	glPushMatrix();
	glTranslatef(0.6, 0.87, 3.88);
	glScalef(2.0, 1.5, 0.25);
	glutSolidCube(1);
	glPopMatrix();

	DrawChairLeg(1.4, 4.2);
	DrawChairLeg(1.4, 5.8);
	DrawChairLeg(-0.2, 4.2);
	DrawChairLeg(-0.2, 5.8);

	glPopMatrix();
	glEnd();
}
void drawSofa3() {
	glPushMatrix();
	glTranslatef(1.8, -0.2, 0.2);


	glColor3f(0.6, 0.6, 0.6);
	glPushMatrix();
	glTranslatef(0, 0.5, 0);
	glScalef(6.0, 0.1, 2.0);
	glutSolidCube(1);
	glPopMatrix();

	glColor3f(0.1, 0.1, 0.1);
	glPushMatrix();
	glTranslatef(0, 0.8, 0);
	glScalef(6.0, 0.5, 2.0);
	glutSolidCube(1);
	glPopMatrix();

	glColor3f(0.1, 0.1, 0.1);
	glPushMatrix();
	glTranslatef(0, 1.55, -0.75);
	glScalef(6.0, 2.0, 0.5);
	glutSolidCube(1);
	glPopMatrix();

	glColor3f(0.2, 0.2, 0.2);
	glPushMatrix();
	glTranslatef(-3.1, 1.2, 0);
	glScalef(0.20, 1.5, 2.0);
	glutSolidCube(1);
	glPopMatrix();

	glColor3f(0.2, 0.2, 0.2);
	glPushMatrix();
	glTranslatef(3.1, 1.2, 0);
	glScalef(0.20, 1.5, 2.0);
	glutSolidCube(1);
	glPopMatrix();

	glPopMatrix();

}
void DrawWorkTable() {
	glPushMatrix();
	glTranslatef(2, 0, -3.8);
	glColor3f(0.1, 0.1, 0.1);

	// mat ban
	glPushMatrix();
	glTranslatef(0, 2, 0);
	glScalef(3.7, 0.2, 1.5);
	glutSolidCube(1);
	glPopMatrix();

	// tuban
	glPushMatrix();
	glTranslatef(1.2, 1, -0.1);
	glScalef(1, 2, 1.2);
	glutSolidCube(1);
	glPopMatrix();

	// hop tuban
	glColor3f(0.2, 0.2, 0.2);
	glPushMatrix();
	glTranslatef(1.2, 0.7, 0);
	glScalef(0.85, 0.5, 1.2);
	glutSolidCube(1);
	glPopMatrix();

	// hop tuban
	glColor3f(0.2, 0.2, 0.2);
	glPushMatrix();
	glTranslatef(1.2, 1.5, 0);
	glScalef(0.85, 0.5, 1.2);
	glutSolidCube(1);
	glPopMatrix();

	// chan ban trai
	glPushMatrix();
	glTranslatef(-1.45, 1, -0.1);
	glScalef(0.3, 2, 1.2);
	glutSolidCube(1);
	glPopMatrix();



	glPopMatrix();

}
void DrawDoor() {
	glPushMatrix();

	glTranslatef(-3.5, 1.7, -4.7);

	glColor3f(0.5, 0.5, 0.5);
	glPushMatrix();
	glTranslatef(0.0, 0.0, 0.0);
	glScalef(1.6, 3.0, 0.2);
	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(0.0, 0.0, 0.0);
	glPushMatrix();
	glTranslatef(-0.3, 0.8, 0.0);
	glScalef(0.4, 1.0, 0.22);
	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(0.0, 0.0, 0.0);
	glPushMatrix();
	glTranslatef(0.3, 0.8, 0.0);
	glScalef(0.4, 1.0, 0.22);
	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(0.0, 0.0, 0.0);
	glPushMatrix();
	glTranslatef(0.0, -0.6, 0.0);
	glScalef(1.0, 1.3, 0.22);
	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(0.0, 0.0, 0.0);
	glPushMatrix();
	glTranslatef(-0.6, 0.2, 0.1);
	glScalef(0.2, 0.2, 0.2);
	glutSolidSphere(0.5, 50, 50);
	glPopMatrix();
	glPopMatrix();
}
void DrawPainting() {
	glPushMatrix();
	glTranslatef(-4.75, 6, -2);

	// Khung tranh

	glColor3f(0.2, 0.5, 0.8);
	glPushMatrix();
	glRotatef(-90, 0, 1, 0);
	glScalef(4.0, 2, 0.15);
	glutSolidCube(1.0);
	glPopMatrix();


	glRotatef(90, 0, 1, 0);
	glTranslatef(0.0, 0.0, 0.05);
	glScalef(1.55, 1.25, 0.2);


	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glVertex3f(-1.4, 0.9, 0.0);
	glVertex3f(1.4, 0.9, 0.0);
	glVertex3f(1.4, -0.9, 0.0);
	glVertex3f(-1.4, -0.9, 0.0);
	glEnd();

	// Máº·t trá»i
	glColor3f(1.0, 0.13, 0.0);
	glPushMatrix();
	glTranslatef(0.0, 0.45, 0.01);
	glutSolidSphere(0.3, 30, 30);
	glPopMatrix();

	// CÃ¢y
	glColor3f(0.3, 0.2, 0.1);
	glPushMatrix();
	glTranslatef(-0.8, -0.5, 0.01);
	glScalef(0.15, 0.6, 0.5);
	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(0.0, 0.6, 0.0);
	glPushMatrix();
	glTranslatef(-0.7, -0.2, 0.3);
	glutSolidSphere(0.3, 20, 20);
	glPopMatrix();

	glColor3f(0.0, 0.6, 0.0);
	glPushMatrix();
	glTranslatef(-0.8, 0.1, 0.3);
	glutSolidSphere(0.3, 20, 20);
	glPopMatrix();

	glColor3f(0.0, 0.6, 0.0);
	glPushMatrix();
	glTranslatef(-0.9, -0.2, 0.3);
	glutSolidSphere(0.3, 20, 20);
	glPopMatrix();

	// DÃ£y nÃºi
	glColor3f(0.4, 0.3, 0.2);
	glBegin(GL_TRIANGLES);

	// NÃºi 1
	glVertex3f(0.1, -0.8, 0.13);
	glVertex3f(0.7, 0.2, 0.13);
	glVertex3f(1.3, -0.8, 0.13);

	// NÃºi 2 
	glVertex3f(-0.4, -0.8, 0.13);
	glVertex3f(0.1, -0.25, 0.13);
	glVertex3f(0.6, -0.8, 0.13);



	glEnd();

	glPopMatrix();
	glPopMatrix();
}
void DrawClock() {
	glPushMatrix();
	glTranslatef(0, 6, -4.7);

	// Máº·t Ä‘á»“ng há»“
	glColor3f(0.8, 0.6, 0.4);
	glPushMatrix();
	glScalef(0.8, 0.8, 0.1);
	glutSolidTorus(0.1, 0.8, 40, 40);
	glPopMatrix();


	glColor3f(0.0, 0.0, 0.0);
	glPushMatrix();
	glScalef(0.9, 0.9, 0.2);
	glutSolidTorus(0.05, 0.85, 40, 40);
	glPopMatrix();

	// Kim giá»
	glColor3f(0.0, 0.0, 0.0);
	glPushMatrix();
	glRotatef(30, 0, 0, 1);
	glScalef(0.4, 0.04, 0.04);
	glutSolidCube(1.0);
	glPopMatrix();


	glColor3f(0.0, 0.0, 0.0);
	glPushMatrix();
	glRotatef(120, 0, 0, 1);
	glScalef(0.6, 0.02, 0.02);
	glutSolidCube(1.0);
	glPopMatrix();


	glColor3f(1.0, 0.0, 0.0);
	glPushMatrix();
	glRotatef(180, 0, 0, 1);
	glScalef(0.7, 0.01, 0.01);
	glutSolidCube(1.0);
	glPopMatrix();


	glColor3f(0.0, 0.0, 0.0);
	for (int i = 1; i <= 12; i++) {
		glPushMatrix();
		glRotatef(i * 30, 0, 0, 1);
		glTranslatef(0.55, 0, 0.05);
		glutSolidCube(0.05);
		glPopMatrix();
	}

	glPopMatrix();
}
void drawKeyboardWithFrame() {
	glPushMatrix();
	glTranslatef(1.6, 2.15, -3.5);
	glScalef(0.3, 0.3, 0.3);
	glColor3f(0.5, 0.5, 0.5); // Gray color for the keyboard base

	// Draw keyboard base
	glBegin(GL_QUADS);
	glVertex3f(-2.0, 0.0, -1.0);
	glVertex3f(2.0, 0.0, -1.0);
	glVertex3f(2.0, 0.0, 1.0);
	glVertex3f(-2.0, 0.0, 1.0);
	glEnd();

	glColor3f(0.8, 0.8, 0.8); // Light gray color for the keys

	// Draw keys
	float keyWidth = 0.2;
	float keyHeight = 0.2;
	float keyDepth = 0.2;
	for (float x = -1.9; x <= 1.8; x += 0.4) {
		for (float z = -0.8; z <= 0.8; z += 0.4) {
			glBegin(GL_QUADS);
			glVertex3f(x, 0.01, z);
			glVertex3f(x + keyWidth, 0.01, z);
			glVertex3f(x + keyWidth, 0.01, z + keyDepth);
			glVertex3f(x, 0.01, z + keyDepth);
			glEnd();
		}
	}

	// Draw frame
	glColor3f(0.0, 0.0, 0.0); // Black color for the frame
	glLineWidth(3.0);
	glBegin(GL_LINE_LOOP);
	glVertex3f(-2.0, 0.0, -1.0);
	glVertex3f(2.0, 0.0, -1.0);
	glVertex3f(2.0, 0.0, 1.0);
	glVertex3f(-2.0, 0.0, 1.0);
	glEnd();
	glPopMatrix();

}
void disPlay() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glTranslatef(0, 0, -30); // Di chuyển camera ra xa đối tượng

	glRotatef(angleX, 0, 1, 0); // Xoay theo trục y
	glRotatef(angleY, 1, 0, 0); // Xoay theo trục x

	DrawCoodinate3D();
	DrawRoomWall();
	DrawTV();
	DrawBookCase();
	DrawSofa1();
	drawSofa3();
	DrawWorkTable();
	DrawDoor();
	DrawPainting();
	DrawClock();
	drawKeyboardWithFrame();
	//glutSolidCube(3);
	glFlush();
	glutSwapBuffers();
}


int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1000, 1000);
	glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH) - 1000) / 2, (glutGet(GLUT_SCREEN_HEIGHT) - 1000) / 2);
	glutCreateWindow("officeRoom");
	init();
	initLight();
	glutReshapeFunc(reShape);
	glutDisplayFunc(disPlay); // Gọi hàm vẽ
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouseButton);
	glutMotionFunc(mouseMotion);
	glutMainLoop();
	return 0;
}

