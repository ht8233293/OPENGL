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
	}



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
	glEnd();
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




	/**Cây Giáng Sinh
	GLUquadricObj* quadratic;
	quadratic = gluNewQuadric();
gluQuadricNormals(quadratic, GLU_SMOOTH);
	gluQuadricTexture(quadratic, GL_TRUE);

	glPushMatrix();
	glColor3f(0.5, 1, 0.5); // Màu xanh lá cây
	glMaterialfv(GL_FRONT, GL_AMBIENT, matYellowGreen); // Màu ánh sáng môi trường
	glMaterialfv(GL_FRONT, GL_DIFFUSE, matYellowGreen); // Màu phản xạ khu vực
	glMaterialfv(GL_FRONT, GL_SPECULAR, matWhite); // Màu phản xạ gương
	glMaterialfv(GL_FRONT, GL_SHININESS, matShininess); // Bậc bóng
	glMaterialfv(GL_FRONT, GL_EMISSION, matBlack); // Màu phát xạ (đen)
	glTranslatef(8, -2, -2); // Di chuyển đến vị trí của cây Giáng Sinh
	glTranslatef(0, ChristmasTreeJumpDis, 0); // Hoạt cảnh nhảy
	glRotatef(ChristmasTreeAng, 0, 1, 0); // Hoạt cảnh xoay

	glPushMatrix();
	glTranslatef(0, 1.5, 0); // Di chuyển lên lớp 1
	glRotatef(270, 1, 0, 0); // Xoay (270 độ theo trục x)
	glutSolidCone(0.8, 1, 20, 20); // Vẽ hình nón
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0.5, 0); // Di chuyển lên lớp 2
	glRotatef(270, 1, 0, 0); // Xoay (270 độ theo trục x)
	glutSolidCone(1.2, 1.5, 16, 16); // Vẽ hình nón
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -0.8, 0); // Di chuyển lên lớp 3
	glRotatef(270, 1, 0, 0); // Xoay (270 độ theo trục x)
	glutSolidCone(1.5, 2, 16, 16); // Vẽ hình nón
	glPopMatrix();

	glColor3f(205 / 255, 200 / 255, 200 / 255); // Màu gỗ
	glPushMatrix(); // Thân cây
	glTranslatef(0, -0.8, 0);
	glRotatef(90, 1, 0, 0);
	gluCylinder(quadratic, 0.3, 0.5, 1, 20, 20);
	glPopMatrix();

	glColor3f(1, 1, 1); // Màu trắng
	glPushMatrix(); // Cành cây
	glTranslatef(1.3, -0.5, 0);
	glRotatef(90, 1, 0, 0);
	gluCylinder(quadratic, 0.2, 0.2, 0.3, 20, 20);
	glPopMatrix();**/

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
