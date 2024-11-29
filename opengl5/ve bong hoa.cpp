#include "glut.h"
#include"glut.h"

#include "cmath"
void drawCooodiNate() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glBegin(GL_LINES);

	glColor3f(1.0, 0.0, 0.0); // mau` ve~
	glVertex2f(-1, 0);
	glVertex2f(1, 0);

	glColor3f(0.0, 1.0, 0.0);
	glVertex2f(0, -1);
	glVertex2f(0, 1);
	glEnd();

	//glBegin(GL_TRIANGLES);
	//glColor3f(1.0, 0.41, 0.63);
	//glVertex2f(0.0, 0.0);
	//glVertex2f(0.2, 0.0);
	//glVertex2f(0.1, 0.2);
	//glEnd();


	//glFlush();

	//// vẽ dịch trục tam giác
	//glPushMatrix();
	//glTranslated(-0.5, 0.0, 0.0);
	//glBegin(GL_TRIANGLES);
	//glColor3f(1.0, 0.41, 0.63);
	//glVertex2f(0.0, 0.0);
	//glVertex2f(0.2, 0.0);
	//glVertex2f(0.1, 0.2);
	//glEnd();
	//glPopMatrix();
	////xoay trục toạ độ

	//glRotatef(45, 0.0, 0.0, 1.0);
	//glBegin(GL_TRIANGLES);
	//glColor3f(0.5, 0.5, 0.5);
	//glVertex2f(0.0, 0.0);
	//glVertex2f(0.2, 0.0);
	//glVertex2f(0.1, 0.2);
	//glEnd();


	//glFlush();






}

void disPlay() {
	glClear(GL_COLOR_BUFFER_BIT);
	//drawCircleShape(0.5);
	drawCooodiNate();
	// 
	//ve hinh tron


	glPushMatrix();
	glTranslated(-0.1, 0.0, 0.0);
	glColor3f(1.0, 0.0, 0.0);
	glutSolidSphere(0.1, 40, 40);

	glPopMatrix();

	glPushMatrix();
	glTranslated(0.1, 0.0, 0.0);
	glColor3f(1.0, 0.0, 0.0);
	glutSolidSphere(0.1, 40, 40);

	glPopMatrix();


	glPushMatrix();
	glTranslated(0.0, -0.1, 0.0);
	glColor3f(1.0, 0.0, 0.0);
	glutSolidSphere(0.1, 40, 40);

	glPopMatrix();


	glPushMatrix();
	glTranslated(0.0, 0.1, 0.0);
	glColor3f(1.0, 0.0, 0.0);
	glutSolidSphere(0.1, 40, 40);

	glPopMatrix();


	glColor3f(1.0, 1.0, 0.0);
	glutSolidSphere(0.1, 40, 40);

	glEnd();
	glFlush();

}

int main(int argc, char** argv) {
	glutInitWindowPosition(500, 500);
	glutInitWindowSize(1500, 1500);
	glutInit(&argc, argv);
	glutCreateWindow("Basic Shape");
	glClearColor(0.0, 0.0, 0.0, 0.0); // Màu nền trắng
	glutDisplayFunc(disPlay); // Gọi hàm vẽ
	glutMainLoop();

	glutInitWindowPosition(1000, 1500);
	return 0;
}
