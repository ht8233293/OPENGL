#include"glut.h"
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>


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
	

	// Tạo phản ứng sự kiện
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);

	// Vào vòng lặp chính của cửa sổ
	glutMainLoop();

}
