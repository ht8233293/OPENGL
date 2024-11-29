#include "glut.h";

GLboolean redFlag = true, od = false;
double eyeX = 23, eyeY = 10.0, eyeZ = 12.0, refX = 0, refY = 1, refZ = 2;

//
void setLight0(bool flag);  // Thiết lập ánh sáng 0
void setLight1(bool flag);  // Thiết lập ánh sáng 1
void setLight2(bool flag);  // Thiết lập ánh sáng 2


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

// 	// Thiết lập màu sắc cho vật liệu sử dụng trong vẽ
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

bool RoomLight = true;  // Ánh sáng phòng
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

//l1
void bacThem() {
	//glEnable(GL_LIGHTING);
	GLfloat light_pos[] = { -2.0, 2.0, 2.0, 1.0 };
	glLightfv(GL_LIGHT1, GL_POSITION, light_pos);
	//Thi?t l?p màu môi tr??ng c?a v?t li?u
	GLfloat ambient[] = { 0.44705883,0.67058825,0.4862745, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
	//Thi?t l?p ?? khuy?ch tán màu
	GLfloat diff_use[] = { 0.44705883,0.67058825,0.4862745, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff_use);
	//Thi?t l?p ?? ph?n chi?u
	GLfloat specular[] = { 0.44705883,0.67058825,0.4862745, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
	//Thi?t l?p ?? l?n cho specular
	GLfloat shininess = 10.0f;
	glMateriali(GL_FRONT, GL_SHININESS, shininess);

	glutSolidCube(1);
}
//l2
void sach() {
	//glEnable(GL_LIGHTING);
	GLfloat light_pos[] = { -2.0, 2.0, 2.0, 1.0 };
	glLightfv(GL_LIGHT2, GL_POSITION, light_pos);
	//Thi?t l?p màu môi tr??ng c?a v?t li?u
	GLfloat ambient[] = { 0.4117647,0.17254902,0.28627452, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
	//Thi?t l?p ?? khuy?ch tán màu
	GLfloat diff_use[] = { 0.4117647,0.17254902,0.28627452, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff_use);
	//Thi?t l?p ?? ph?n chi?u
	GLfloat specular[] = { 0.44705883,0.67058825,0.4862745, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
	//Thi?t l?p ?? l?n cho specular
	GLfloat shininess = 10.0f;
	glMateriali(GL_FRONT, GL_SHININESS, shininess);

	glPushMatrix();
	glTranslatef(0, -0.16, 0.22);
	glRotatef(15, 8, 0, 0);
	glScaled(1, 1, 0.3);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glRotatef(15, 8, 0, 0);
	glScaled(1, 1.3, 0.2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0.16, 0.22);
	glRotatef(15, 8, 0, 0);
	glScaled(1, 1.3, 0.2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0.1, 0.6);
	glRotatef(15, 8, 0, 0);
	glScaled(1, 1.3, 0.2);
	glutSolidCube(1);
	glPopMatrix();
}
//l3
void caiTu() {
	//vi tri nguon sang
	GLfloat light_pos[] = { -5.0, 5.0, 1.0, 0.0 };
	glLightfv(GL_LIGHT3, GL_POSITION, light_pos);
	//Thiet lap mau moi truong vat lieu
	GLfloat ambient[] = { 0.9, 0.7, 0.1, 0.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
	//Thiet lap do khuech tan mau
	GLfloat diff_use[] = { 1.0, 0.5, 0.5, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff_use);
	//thiet lap do phan chieu
	GLfloat specular[] = { 1.0, 0.5, 0.5, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
	//Thiet lap do lon cho do phan chieu
	GLfloat shininess = 20.0f;
	glMateriali(GL_FRONT, GL_SHININESS, shininess);
	// Vẽ than tu
	glPushMatrix();
	glTranslatef(0.0, 0.0, -0.1);
	glScalef(5.0, 1.8, 2);
	glutSolidCube(1.0); // Vẽ hình hộp chữ nhật
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.5, 0.0, 1.1);
	glutSolidSphere(0.1, 100, 100);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.5, 0.0, 1.1);
	glutSolidSphere(0.1, 100, 100);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2.5, 0.0, 0.0);
	glScalef(0.2, 2.0, 2.2);
	glutSolidCube(1.0); // Vẽ hình hộp chữ nhật
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-2.5, 0.0, 0.0);
	glScalef(0.2, 2.0, 2.2);
	glutSolidCube(1.0); // Vẽ hình hộp chữ nhật
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, 0.0, 0.0);
	glScalef(0.2, 2.0, 2.2);
	glutSolidCube(1.0); // Vẽ hình hộp chữ nhật
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, 0.9, 0.0);
	glScalef(5.2, 0.2, 2.2);
	glutSolidCube(1.0); // Vẽ hình hộp chữ nhật
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, 0.9, 0.0);
	glScalef(5.2, 0.2, 2.2);
	glutSolidCube(1.0); // Vẽ hình hộp chữ nhật
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, -0.9, 0.0);
	glScalef(5.2, 0.2, 2.2);
	glutSolidCube(1.0); // Vẽ hình hộp chữ nhật
	glPopMatrix();

	// Vẽ chân tu
	glPushMatrix();
	glTranslatef(2.0, -0.8, 0.6);
	glScalef(0.2, 1.0, 0.2);
	glutSolidCube(1.0); // Vẽ hình hộp chữ nhật
	glPopMatrix();

	// Vẽ chân tu
	glPushMatrix();
	glTranslatef(2.0, -0.8, -0.6);
	glScalef(0.2, 1.0, 0.2);
	glutSolidCube(1.0); // Vẽ hình hộp chữ nhật
	glPopMatrix();

	// Vẽ chân tu
	glPushMatrix();
	glTranslatef(-2.0, -0.8, 0.6);
	glScalef(0.2, 1.0, 0.2);
	glutSolidCube(1.0); // Vẽ hình hộp chữ nhật
	glPopMatrix();

	// Vẽ chân tu
	glPushMatrix();
	glTranslatef(-2.0, -0.8, -0.6);
	glScalef(0.2, 1.0, 0.2);
	glutSolidCube(1.0); // Vẽ hình hộp chữ nhật
	glPopMatrix();
}
//l2
void soFa() {
	//glEnable(GL_LIGHTING);
	GLfloat light_pos[] = { 2.0, 5.0, 5.0, 1.0 };
	glLightfv(GL_LIGHT2, GL_POSITION, light_pos);
	//Thi?t l?p màu môi tr??ng c?a v?t li?u
	GLfloat ambient[] = { 0.62352943, 0.5921569, 0.5764706, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
	//Thi?t l?p ?? khuy?ch tán màu
	GLfloat diff_use[] = { 0.62352943, 0.5921569, 0.5764706, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff_use);
	//Thi?t l?p ?? ph?n chi?u
	GLfloat specular[] = { 1.0, 1.0, 1.0, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
	//Thi?t l?p ?? l?n cho specular
	GLfloat shininess = 10.0f;
	glMateriali(GL_FRONT, GL_SHININESS, shininess);
	// Vẽ phan tua
	glPushMatrix();
	glScalef(1.0, 3.0, 6.0); // Phóng to chiều dài 7 lần, chiều rộng 0.3 lần, chiều cao 3 lần
	glutSolidCube(1.0); // Vẽ hình hộp chữ nhật
	glPopMatrix();

	// Vẽ phan ngoi
	glPushMatrix();
	glTranslatef(0.9, -0.75, 0.0); // Dịch chuyển sang phải 2.5, xuống dưới 1.5, và về phía trước 1.5
	glScalef(2.0, 1.5, 6.0); // Phóng to chiều rộng 0.2 lần, chiều cao 2 lần, chiều sâu 0.2 lần
	glutSolidCube(1.0); // Vẽ hình hộp chữ nhật
	glPopMatrix();
}
//l2
void caiGhe() {
	//vi tri nguon sang
	GLfloat light_pos[] = { -5.0, 5.0, 1.0, 0.0 };
	glLightfv(GL_LIGHT2, GL_POSITION, light_pos);
	//Thiet lap mau moi truong vat lieu
	GLfloat ambient[] = { 0.4, 0.0, 0.0, 0.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
	//Thiet lap do khuech tan mau
	GLfloat diff_use[] = { 0.9, 0.5, 0.5, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff_use);
	//thiet lap do phan chieu
	GLfloat specular[] = { 1.0, 0.5, 0.5, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
	//Thiet lap do lon cho do phan chieu
	GLfloat shininess = 20.0f;
	glMateriali(GL_FRONT, GL_SHININESS, shininess);

	// Vẽ mặt Ghế 
	glPushMatrix();
	glTranslatef(0.0, 0.5, 0.0);
	glScalef(2.0, 0.3, 2.0);
	glutSolidCube(1.0); // Vẽ hình hộp chữ nhật
	glPopMatrix();

	// Vẽ chân Ghế
	glPushMatrix();
	glTranslatef(0.8, 0.0, 0.8);
	glScalef(0.2, 1.0, 0.2);
	glutSolidCube(1.0); // Vẽ hình hộp chữ nhật
	glPopMatrix();

	// Vẽ chân Ghế
	glPushMatrix();
	glTranslatef(0.8, 0.0, -0.8);
	glScalef(0.2, 1.0, 0.2);
	glutSolidCube(1.0);
	glPopMatrix();

	// Vẽ chân Ghế
	glPushMatrix();
	glTranslatef(-0.8, 0.0, 0.8);
	glScalef(0.2, 1.0, 0.2);
	glutSolidCube(1.0); // Vẽ hình hộp chữ nhật
	glPopMatrix();

	// Vẽ chân Ghế
	glPushMatrix();
	glTranslatef(-0.8, 0.0, -0.8);
	glScalef(0.2, 1.0, 0.2);
	glutSolidCube(1.0); // Vẽ hình hộp chữ nhật
	glPopMatrix();
}
//l2
void caiBan() {
	//vi tri nguon sang
	GLfloat light_pos[] = { -5.0, 5.0, 1.0, 0.0 };
	glLightfv(GL_LIGHT2, GL_POSITION, light_pos);
	//Thiet lap mau moi truong vat lieu
	GLfloat ambient[] = { 0.4, 0.0, 0.0, 0.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
	//Thiet lap do khuech tan mau
	GLfloat diff_use[] = { 0.9, 0.5, 0.5, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff_use);
	//thiet lap do phan chieu
	GLfloat specular[] = { 1.0, 0.5, 0.5, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
	//Thiet lap do lon cho do phan chieu
	GLfloat shininess = 20.0f;
	glMateriali(GL_FRONT, GL_SHININESS, shininess);

	// Vẽ mặt bàn
	glPushMatrix();
	glTranslatef(0.0, 0.9, 0.0);
	glScalef(3.0, 0.3, 7.0);
	glutSolidCube(1.0); // Vẽ hình hộp chữ nhật
	glPopMatrix();

	// Vẽ chân bàn
	glPushMatrix();
	glTranslatef(1.0, 0.0, 2.6);
	glScalef(0.2, 1.8, 0.2);
	glutSolidCube(1.0); // Vẽ hình hộp chữ nhật
	glPopMatrix();

	// Vẽ chân bàn
	glPushMatrix();
	glTranslatef(-1.0, 0.0, -2.6);
	glScalef(0.2, 1.8, 0.2);
	glutSolidCube(1.0); // Vẽ hình hộp chữ nhật
	glPopMatrix();

	// Vẽ chân bàn
	glPushMatrix();
	glTranslatef(-1.0, 0.0, 2.6);
	glScalef(0.2, 1.8, 0.2);
	glutSolidCube(1.0); // Vẽ hình hộp chữ nhật
	glPopMatrix();

	// Vẽ chân bàn
	glPushMatrix();
	glTranslatef(1.0, 0.0, -2.6);
	glScalef(0.2, 1.8, 0.2);
	glutSolidCube(1.0); // Vẽ hình hộp chữ nhật
	glPopMatrix();
}
//l4
void caiTiVi() {
	//vi tri nguon sang
	GLfloat light_pos[] = { -5.0, 5.0, 1.0, 0.0 };
	glLightfv(GL_LIGHT4, GL_POSITION, light_pos);
	//Thiet lap mau moi truong vat lieu
	GLfloat ambient[] = { 0.137, 0.1, 0.36, 0.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
	//Thiet lap do khuech tan mau
	GLfloat diff_use[] = { 0.137, 0.1, 0.36, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff_use);
	//thiet lap do phan chieu
	GLfloat specular[] = { 0.0, 0.5, 0.5, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
	//Thiet lap do lon cho do phan chieu
	GLfloat shininess = 20.0f;
	glMateriali(GL_FRONT, GL_SHININESS, shininess);

	//ve man hinh
	glPushMatrix();
	glTranslatef(0.0, 0.0, -0.2);
	glScalef(3.0, 1.7, 0.2);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.6, 0.0, 0.0);
	glScalef(0.2, 2.0, 0.6);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.6, 0.0, 0.0);
	glScalef(0.2, 2.0, 0.6);
	glutSolidCube(1.0);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(0.0, 0.9, 0.0);
	glScalef(3.4, 0.2, 0.6);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, -0.9, 0.0);
	glScalef(3.4, 0.2, 0.6);
	glutSolidCube(1.0);
	glPopMatrix();

	// Vẽ chân tivi
	glPushMatrix();
	glTranslatef(0.0, -1.3, 0.0);
	glScalef(0.4, 0.5, 0.4);
	glutSolidCube(1.0); // Vẽ hình hộp chữ nhật
	glPopMatrix();

	// Vẽ de tivi
	glPushMatrix();
	glTranslatef(0.0, -1.4, 0.0);
	glScalef(1.0, 0.3, 0.8);
	glutSolidCube(1.0);
	glPopMatrix();
}
//l5
void Hoa() {
	GLfloat light_pos[] = { 5.0, 5.0, 1.0, 0.0 };
	glLightfv(GL_LIGHT5, GL_POSITION, light_pos);
	//Thiet lap mau moi truong vat lieu
	GLfloat ambient[] = { 1.0, 0.0 ,0.0, 0.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
	//Thiet lap do khuech tan mau
	GLfloat diff_use[] = { 1, 0.5, 0.5, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff_use);
	//thiet lap do phan chieu
	GLfloat specular[] = { 0.5, 0.5, 0.5, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
	//Thiet lap do lon cho do phan chieu
	GLfloat shininess = 20.0f;
	glMateriali(GL_FRONT, GL_SHININESS, shininess);

	glPushMatrix();
	glTranslatef(0.0, 4, 0.0);
	glScalef(0.4, 5, 0.4);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, 7, 0.0);
	glScalef(0.9, 0.7, 0.9);
	glutSolidDodecahedron();
	glPopMatrix();
	glFlush();
}
//l6
void caiBinhHoa() {
	Hoa();
	GLfloat light_pos[] = { 5.0, 5.0, 1.0, 0.0 };
	glLightfv(GL_LIGHT6, GL_POSITION, light_pos);
	//Thiet lap mau moi truong vat lieu
	GLfloat ambient[] = { 0.0, 1.0 ,1.0, 0.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
	//Thiet lap do khuech tan mau
	GLfloat diff_use[] = { 0.0, 1.0, 1.0, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff_use);
	//thiet lap do phan chieu
	GLfloat specular[] = { 0.0, 0.0, 1.0, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
	//Thiet lap do lon cho do phan chieu
	GLfloat shininess = 20.0f;
	glMateriali(GL_FRONT, GL_SHININESS, shininess);

	//vẽ thân bình
	glPushMatrix();
	glScalef(0.7, 1.3, 0.7);
	glutSolidSphere(2, 100, 100); // Vẽ hình hộp chữ nhật
	glPopMatrix();

	//vẽ miệng bình
	glPushMatrix();
	glTranslatef(0.0, 4.5, 0.0);
	glScalef(0.35, 1.1, 0.35);
	glRotatef(90, 8.0, 0.0, 0.0); // Xoay vật thể quanh trục (8,0,0)
	glutSolidCone(3, 4, 100, 100);
	glPopMatrix();

	//vẽ đế bình
	glPushMatrix();
	glTranslatef(0.0, -2.5, 0.0);
	glScalef(0.3, 0.4, 0.3);
	glRotatef(-90, 8.0, 0.0, 0.0); // Xoay vật thể quanh trục (8,0,0)
	glutSolidCone(3, 4, 100, 100);
	glPopMatrix();

	glFlush();
}
//l6
void boAmChen() {
	GLfloat light_pos[] = { 5.0, 5.0, 1.0, 0.0 };
	glLightfv(GL_LIGHT6, GL_POSITION, light_pos);
	//Thiet lap mau moi truong vat lieu
	GLfloat ambient[] = { 0.0, 1.0 ,1.0, 0.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
	//Thiet lap do khuech tan mau
	GLfloat diff_use[] = { 0.0, 1.0, 1.0, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff_use);
	//thiet lap do phan chieu
	GLfloat specular[] = { 0.0, 0.0, 1.0, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
	//Thiet lap do lon cho do phan chieu
	GLfloat shininess = 20.0f;
	glMateriali(GL_FRONT, GL_SHININESS, shininess);
	glPushMatrix();
	glTranslatef(0.5, 0.0, 0.5); 
	glScalef(0.2, 0.4, 0.2);
	glutSolidCube(1.0); // Vẽ hình hộp chữ nhật
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.5, 0.0, -0.5); 
	glScalef(0.2, 0.4, 0.2); 
	glutSolidCube(1.0); // Vẽ hình hộp chữ nhật
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.5, 0.0, 0.5);
	glScalef(0.2, 0.4, 0.2); 
	glutSolidCube(1.0); // Vẽ hình hộp chữ nhật
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.5, 0.0, -0.5); 
	glScalef(0.2, 0.4, 0.2);
	glutSolidCube(1.0); // Vẽ hình hộp chữ nhật
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, 0.3, -1.5); 
	glutSolidTeapot(0.6);
	glPopMatrix();
}
//l2
void tranh() {
	glDisable(GL_LIGHTING);
	glColor3f(1,1,1);
	glPushMatrix();
	glTranslatef(-0.1, 0.0, 0.0);
	glScalef(0.08, 2.73, 4.0);
	glutSolidCube(1.0);
	glPopMatrix();
	glEnable(GL_LIGHTING);

	GLfloat light_pos[] = { 5.0, 5.0, 1.0, 0.0 };
	glLightfv(GL_LIGHT2, GL_POSITION, light_pos);
	//Thiet lap mau moi truong vat lieu
	GLfloat ambient[] = { 1.0, 1.0 ,0.0, 0.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
	//Thiet lap do khuech tan mau
	GLfloat diff_use[] = { 1.0, 1.0, 0.0, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff_use);
	//thiet lap do phan chieu
	GLfloat specular[] = { 1.0, 1.0, 0.0, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
	//Thiet lap do lon cho do phan chieu
	GLfloat shininess = 20.0f;
	glMateriali(GL_FRONT, GL_SHININESS, shininess);

	glPushMatrix();
	glTranslatef(0.0, 1.5, 0.0); 
	glScalef(0.3, 0.2, 4.0);
	glutSolidCube(1.0); 
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, -1.5, 0.0);
	glScalef(0.3, 0.2, 4.0); 
	glutSolidCube(1.0); 
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, 0.0, -1.9); 
	glScalef(0.3, 3.0, 0.2);
	glutSolidCube(1.0); // Vẽ hình hộp chữ nhật
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, 0.0, 1.9);
	glScalef(0.4, 3.0, 0.2); 
	glutSolidCube(1.0); // Vẽ hình hộp chữ nhật
	glPopMatrix();
}
//l2
void caiBongDen() {
	glColor3f(1, 1, 0); // Màu vàng
	glMaterialfv(GL_FRONT, GL_AMBIENT, matYellow); // Màu ánh sáng môi trường
	glMaterialfv(GL_FRONT, GL_DIFFUSE, matYellow); // Màu phản xạ khu vực
	glMaterialfv(GL_FRONT, GL_SPECULAR, matWhite); // Màu phản xạ gương
	glMaterialfv(GL_FRONT, GL_SHININESS, matShininess); // Bậc bóng
	glMaterialfv(GL_FRONT, GL_EMISSION, matBlack); // Màu phát xạ (đen)
	if (CeilingLight) glMaterialfv(GL_FRONT, GL_EMISSION, matYellow); // Nếu đèn trần được bật, sử dụng màu vàng

	glEnable(GL_LIGHTING);
	glRotatef(-90, 8.0, 0.0, 0.0); // Xoay vật thể quanh trục (1,1,0)
	glutSolidCone(0.8, 0.7, 100, 100);
	glDisable(GL_LIGHTING);
	glColor3f(0.9, 0.9, 0.9);
	glutSolidSphere(0.5, 100, 100);
	glEnable(GL_LIGHTING);
}
//l5 	setLight0(RoomLight); // Thiết lập nguồn sáng 0 dựa trên trạng thái của biến RoomLight
//setLight2(CeilingLight); // Thiết lập nguồn sáng 2 dựa trên trạng thái của biến CeilingLight
void caiQuat()
{
	GLfloat light_pos[] = { 5.0, 5.0, 1.0, 0.0 };
	glLightfv(GL_LIGHT5, GL_POSITION, light_pos);
	//Thiet lap mau moi truong vat lieu
	GLfloat ambient[] = { 0.24705882,0.050980393,0.05882353, 0.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
	//Thiet lap do khuech tan mau
	GLfloat diff_use[] = { 0.24705882,0.050980393,0.05882353, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff_use);
	//thiet lap do phan chieu
	GLfloat specular[] = { 0.1, 1.0, 1.0, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
	//Thiet lap do lon cho do phan chieu
	GLfloat shininess = 20.0f;
	glMateriali(GL_FRONT, GL_SHININESS, shininess);

	//cuc trung tam
	glColor3f(0, 0, 0);
	glPushMatrix();
	glScalef(1.5, 0.7, 1.5);
	glutSolidSphere(1.5, 100, 100);
	glPopMatrix();

	glPushMatrix();
	glScalef(7, 0.2, 0.5);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glRotatef(90, 0, 8, 0);
	glScalef(7, 0.2, 0.5);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, 0.0, 5.6);
	glScalef(2, 0.2, 5);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, 0.0, -5.6);
	glScalef(2, 0.2, 5);
	glutSolidCube(1);
	glPopMatrix();

	//canh 1
	glPushMatrix();
	glTranslatef(5.6, 0.0, 0.0);
	glScalef(5, 0.2, 2);
	glutSolidCube(1);
	glPopMatrix();

	//canh 2
	glPushMatrix();
	glTranslatef(-5.6, 0.0, 0.0);
	glScalef(5, 0.2, 2);
	glutSolidCube(1);
	glPopMatrix();

	//day treo
	glPushMatrix();
	glTranslatef(0.0, 3, 0.0);
	glScalef(0.1, 4, 0.1);
	glutSolidCube(1);
	glPopMatrix();

	//ba cai coc
	glPushMatrix();
	glTranslatef(0.8, -1.2, -0.3);
	glScalef(0.3, 2, 0.3);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.8, -1.2, -0.3);
	glScalef(0.3, 2, 0.3);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, -1.2, 0.7);
	glScalef(0.3, 2, 0.3);
	glutSolidCube(1);
	glPopMatrix();

	//ba cai bong
	glPushMatrix();
	glTranslatef(0.0, -2, 0.7);
	caiBongDen();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.8, -2, -0.3);
	caiBongDen();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.8, -2, -0.3);
	caiBongDen();
	glPopMatrix();
}
//l2
void caiGia() {
	//glEnable(GL_LIGHTING);
	GLfloat light_pos[] = { 2.0, 5.0, 5.0, 1.0 };
	glLightfv(GL_LIGHT2, GL_POSITION, light_pos);
	//Thi?t l?p màu môi tr??ng c?a v?t li?u
	GLfloat ambient[] = { 0.8, 0.5,0.5, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
	//Thi?t l?p ?? khuy?ch tán màu
	GLfloat diff_use[] = { 0.8, 0.6,0.0, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff_use);
	//Thi?t l?p ?? ph?n chi?u
	GLfloat specular[] = { 1.0, 1.0, 1.0, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
	//Thi?t l?p ?? l?n cho specular
	GLfloat shininess = 10.0f;
	glMateriali(GL_FRONT, GL_SHININESS, shininess);
	//tam ngang 1
	glPushMatrix();
	glTranslatef(2.3, 8.8, 0.0);
	glScalef(5.0, 0.5, 9.0);
	glutSolidCube(1);
	glPopMatrix();

	//tam ngang giua tren
	glPushMatrix();
	glTranslatef(2.3, 4.55, 0.0);
	glScalef(5.0, 0.5, 9.0);
	glutSolidCube(1);
	glPopMatrix();

	//tam ngang giua
	glPushMatrix();
	glTranslatef(2.3, 0.0, 0.0);
	glScalef(5.0, 0.5, 9.0);
	glutSolidCube(1);
	glPopMatrix();

	//tam ngang giua duoi
	glPushMatrix();
	glTranslatef(2.3, -4.55, 0.0);
	glScalef(5.0, 0.5, 9.0);
	glutSolidCube(1);
	glPopMatrix();

	//tam ngang duoi
	glPushMatrix();
	glTranslatef(2.3, -8.8, 0.0);
	glScalef(5.0, 0.5, 9.0);
	glutSolidCube(1);
	glPopMatrix();

	//tam doc sau
	glPushMatrix();
	//glTranslatef(2.0, 0.5, 3.0);
	glScalef(0.5, 18.0, 9.0);
	glutSolidCube(1);
	glPopMatrix();

	//tam doc trai
	glPushMatrix();
	glTranslatef(2.3, 0.0, -4.7);
	glScalef(5.0, 18.0, 0.5);
	//glRotatef(90, 8.0, 0.0, 0.0); // Xoay vật thể quanh trục (8,0,0)
	glutSolidCube(1);
	glPopMatrix();

	//tam doc phai
	glPushMatrix();
	glTranslatef(2.3, 0.0, 4.7);
	glScalef(5.0, 18.0, 0.5);
	//glRotatef(90, 8.0, 0.0, 0.0); // Xoay vật thể quanh trục (8,0,0)
	glutSolidCube(1);
	glPopMatrix();
}
//l3
void conLon() {
	GLfloat light_pos[] = { 5.0, 5.0, 0.0, 0.0 };
	glLightfv(GL_LIGHT3, GL_POSITION, light_pos);
	//Thiet lap mau moi truong vat lieu
	GLfloat ambient[] = { 1.0, 0.0, 0.0, 0.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
	//Thiet lap do khuech tan mau
	GLfloat diff_use[] = { 1.0, 0.0, 0.0, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff_use);
	//thiet lap do phan chieu
	GLfloat specular[] = { 0.2, 0.2, 0.2, 0.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
	//Thiet lap do lon cho do phan chieu
	GLfloat shininess = 10.0;
	glMateriali(GL_FRONT, GL_SHININESS, shininess);
	
	//ve than
	glPushMatrix();
	glScalef(0.7, 0.7, 1.0);
	glutSolidSphere(1.0, 100, 100);
	glPopMatrix();

	//ve chan truoc
	glPushMatrix();
	glTranslatef(-0.4, -0.4, 0.3);
	glScalef(0.2, 0.7, 0.2);
	glutSolidCube(1.0);
	glPopMatrix();

	//ve chan truoc
	glPushMatrix();
	glTranslatef(0.4, -0.4, 0.3);
	glScalef(0.2, 0.7, 0.2);
	glutSolidCube(1.0);
	glPopMatrix();

	//ve chan
	glPushMatrix();
	glTranslatef(0.4, -0.4, -0.3);
	glScalef(0.2, 0.7, 0.2);
	glutSolidCube(1.0);
	glPopMatrix();

	//ve chan
	glPushMatrix();
	glTranslatef(-0.4, -0.4, -0.3);
	glScalef(0.2, 0.7, 0.2);
	glutSolidCube(1.0);
	glPopMatrix();

	//ve tai
	glPushMatrix();
	glTranslatef(-0.3, 0.45, 0.5);
	glScalef(0.7, 1.0, 0.3);
	glutSolidSphere(0.3, 100, 100);
	glPopMatrix();

	//ve tai
	glPushMatrix();
	glTranslatef(0.3, 0.45, 0.5);
	glScalef(0.7, 1.0, 0.3);
	glutSolidSphere(0.3, 100, 100);
	glPopMatrix();

	//ve mui
	glPushMatrix();
	glTranslatef(0.0, 0.0, 1);
	glScalef(0.1, 0.1, 0.1);
	glutSolidTorus(1, 1, 100, 100);
	glPopMatrix();
}
//l2
void cuaSo() {
	glDisable(GL_LIGHTING);
	//kinh
	glColor3f(0.0, 1.0, 1.0);
	glPushMatrix();
	glTranslatef(0.0, 0.0, 3);
	//glRotatef(30, 8, 0, 0);
	glScalef(0.01, 9, 6);
	glutSolidCube(1);
	glPopMatrix();
	glEnable(GL_LIGHTING);

	GLfloat light_pos[] = { 5.0, 5.0, 5.0, 1.0 };
	glLightfv(GL_LIGHT2, GL_POSITION, light_pos);
	//Thi?t l?p màu môi tr??ng c?a v?t li?u
	GLfloat ambient[] = { 0.8, 0.4 ,0.1, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
	//Thi?t l?p ?? khuy?ch tán màu
	GLfloat diff_use[] = { 0.8, 0.4 ,0.1, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff_use);
	//Thi?t l?p ?? ph?n chi?u
	GLfloat specular[] = { 0.8, 0.4 ,0.1, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
	//Thi?t l?p ?? l?n cho specular
	GLfloat shininess = 10.0f;
	glMateriali(GL_FRONT, GL_SHININESS, shininess);

	//thanh doc 1 
	glPushMatrix();
	//glTranslatef(0.0, 3, 0.6);
	//glRotatef(30, 8, 0, 0);
	glScalef(0.3, 9, 0.3);
	glutSolidCube(1);
	glPopMatrix();


	//thanh doc 2 
	glPushMatrix();
	glTranslatef(0.0, 0.0, 6);
	//glRotatef(30, 8, 0, 0);
	glScalef(0.3, 9, 0.3);
	glutSolidCube(1);
	glPopMatrix();

	//thanh doc 3 
	glPushMatrix();
	glTranslatef(0.0, 0.0, 3);
	//glRotatef(30, 8, 0, 0);
	glScalef(0.3, 9, 0.3);
	glutSolidCube(1);
	glPopMatrix();

	//thanh ngang tren
	glPushMatrix();
	glTranslatef(0.0, 4.35, 3.0);
	//glRotatef(30, 8, 0, 0);
	glScalef(0.3, 0.3, 6);
	glutSolidCube(1);
	glPopMatrix();

	//thanh ngang giua
	glPushMatrix();
	glTranslatef(0.0, 1.5, 3.0);
	//glRotatef(30, 8, 0, 0);
	glScalef(0.3, 0.3, 6);
	glutSolidCube(1);
	glPopMatrix();

	//thanh ngang giua
	glPushMatrix();
	glTranslatef(0.0, -1.5, 3.0);
	//glRotatef(30, 8, 0, 0);
	glScalef(0.3, 0.3, 6);
	glutSolidCube(1);
	glPopMatrix();

	//thanh ngang duoi
	glPushMatrix();
	glTranslatef(0.0, -4.35, 3.0);
	//glRotatef(30, 8, 0, 0);
	glScalef(0.3, 0.3, 6);
	glutSolidCube(1);
	glPopMatrix();
}
//l2
void caicua() {
	//glEnable(GL_LIGHTING);
	GLfloat light_pos[] = { -2.0, 2.0, 2.0, 1.0 };
	glLightfv(GL_LIGHT2, GL_POSITION, light_pos);
	//Thi?t l?p màu môi tr??ng c?a v?t li?u
	GLfloat ambient[] = { 0.40392157,0.15686275,0.023529412, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
	//Thi?t l?p ?? khuy?ch tán màu
	GLfloat diff_use[] = { 0.40392157,0.15686275,0.023529412, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff_use);
	//Thi?t l?p ?? ph?n chi?u
	GLfloat specular[] = { 0.6117647,0.32941177,0.1764706, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
	//Thi?t l?p ?? l?n cho specular
	GLfloat shininess = 10.0f;
	glMateriali(GL_FRONT, GL_SHININESS, shininess);

	//khung cua
	glPushMatrix();
	glTranslatef(0.0, 0.0, 0.0);
	glScalef(0.3, 10, 6);
	glutSolidCube(1);
	glPopMatrix();

	//tam tren 
	glPushMatrix();
	glTranslatef(0.0, 4.6, 0.0);
	glScalef(0.6, 1, 6);
	glutSolidCube(1);
	glPopMatrix();

	//tam giua 
	glPushMatrix();
	glTranslatef(0.0, 0.0, 0.0);
	glScalef(0.6, 1, 6);
	glutSolidCube(1);
	glPopMatrix();

	//tam duoi 
	glPushMatrix();
	glTranslatef(0.0, -4.6, 0.0);
	glScalef(0.6, 1, 6);
	glutSolidCube(1);
	glPopMatrix();

	//tam ben
	glPushMatrix();
	glTranslatef(0.0, 0.0, -2.6);
	glScalef(0.6, 10, 1);
	glutSolidCube(1);
	glPopMatrix();

	//tam ben
	glPushMatrix();
	glTranslatef(0.0, 0.0, 2.6);
	glScalef(0.6, 10, 1);
	glutSolidCube(1);
	glPopMatrix();

	//tam trong
	glPushMatrix();
	glTranslatef(0.0, 2.4, 0.0);
	glScalef(0.6, 2.5, 2.5);
	glutSolidCube(1);
	glPopMatrix();

	//tam trong
	glPushMatrix();
	glTranslatef(0.0, -2.4, 0.0);
	glScalef(0.6, 2.5, 2.5);
	glutSolidCube(1);
	glPopMatrix();

	//co dinh tay cam
	glPushMatrix();
	glTranslatef(-0.13, 1, -2.5);
	glScalef(1.8, 0.35, 0.35);
	glutSolidCube(1);
	glPopMatrix();

	//co dinh tay cam
	glPushMatrix();
	glTranslatef(-0.13, -1, -2.5);
	glScalef(1.8, 0.35, 0.35);
	glutSolidCube(1);
	glPopMatrix();

	//tay cam truoc
	glPushMatrix();
	glTranslatef(0.85, 0.0, -2.5);
	glScalef(0.4, 3, 0.4);
	glutSolidCube(1);
	glPopMatrix();

	//tay cam sau
	glPushMatrix();
	glTranslatef(-0.85, 0.0, -2.5);
	glScalef(0.4, 3, 0.4);
	glutSolidCube(1);
	glPopMatrix();

}
//l2
void vecay() {
	glDisable(GL_LIGHTING);
	glColor3f(0.49019608, 0.20392157, 0.047058824);
	glPushMatrix();
	glTranslatef(0.0, 2.5, 0.0);
	glScalef(0.3, 5, 0.3);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, 3, 0.6);
	glRotatef(30, 8, 0, 0);
	glScalef(0.3, 2.5, 0.3);
	glutSolidCube(1);
	glPopMatrix();
	glEnable(GL_LIGHTING);

	GLfloat light_pos[] = { 5.0, 5.0, 1.0, 1.0 };
	glLightfv(GL_LIGHT2, GL_POSITION, light_pos);
	//Thi?t l?p màu môi tr??ng c?a v?t li?u
	GLfloat ambient[] = { 0.0, 1.0 ,0.0, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
	//Thi?t l?p ?? khuy?ch tán màu
	GLfloat diff_use[] = { 0.0, 1.0, 0.0, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff_use);
	//Thi?t l?p ?? ph?n chi?u
	GLfloat specular[] = { 0.0, 1.0, 0.0, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
	//Thi?t l?p ?? l?n cho specular
	GLfloat shininess = 10.0f;
	glMateriali(GL_FRONT, GL_SHININESS, shininess);

	glPushMatrix();
	glTranslatef(0.0, 3.5, 1);
	glScalef(0.5, 0.5, 0.5);
	glutSolidDodecahedron();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, 6, 0.0);
	glScalef(0.8, 0.8, 0.8);
	glutSolidDodecahedron();
	glPopMatrix();
}
//l3
void chaucay() {
	vecay();
	GLfloat light_pos[] = { 5.0, 5.0, 1.0, 1.0 };
	glLightfv(GL_LIGHT3, GL_POSITION, light_pos);
	//Thi?t l?p màu môi tr??ng c?a v?t li?u
	GLfloat ambient[] = { 1.0, 0.5 ,0.0, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
	//Thi?t l?p ?? khuy?ch tán màu
	GLfloat diff_use[] = { 1.0, 0.5, 0.0, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff_use);
	//Thi?t l?p ?? ph?n chi?u
	GLfloat specular[] = { 0.0, 0.0, 1.0, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
	//Thi?t l?p ?? l?n cho specular
	GLfloat shininess = 10.0f;
	glMateriali(GL_FRONT, GL_SHININESS, shininess);

	//vẽ thân bình
	glPushMatrix();
	glScalef(1.0, 0.7, 1.0);
	glutSolidSphere(2, 100, 100); // Vẽ hình hộp chữ nhật
	glPopMatrix();

	//vẽ miệng bình
	glPushMatrix();
	glTranslatef(0.0, 1.5, 0.0);
	glScalef(0.5, 0.5, 0.5);
	glRotatef(90, 8.0, 0.0, 0.0); // Xoay vật thể quanh trục (8,0,0)
	glutSolidCone(3, 4, 100, 100);
	glPopMatrix();

	//vẽ miệng bình
	glPushMatrix();
	glTranslatef(0.0, -1.6, 0.0);
	glScalef(0.4, 0.4, 0.4);
	glRotatef(-90, 8.0, 0.0, 0.0); // Xoay vật thể quanh trục (8,0,0)
	glutSolidCone(3, 4, 100, 100);
	glPopMatrix();
}

void DrawCoordinate() {
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
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 0.0, 10.0);
	glEnd();

	glEnable(GL_LIGHTING);
}

void keybroad(unsigned char key, int x, int y) {
	switch (key)
	{
	case '1':
		glEnable(GL_LIGHT1);
		break;
	case '2':
		glEnable(GL_LIGHT2);
		break;
	case '3':
		glDisable(GL_LIGHT1);
		glDisable(GL_LIGHT2);
		break;
	case'4': // Ánh sáng phòng
		RoomLight = !RoomLight;
		break;
	case'5': // Ánh sáng trần nhà
		CeilingLight = !CeilingLight;
		break;
	case 'w': // move eye point upwards along Y axis
		eyeY += 1.0;
		break;
	case 's': // move eye point downwards along Y axis
		eyeY -= 1.0;
		break;
	case 'a': // move eye point left along X axis
		eyeX -= 1.0;
		break;
	case 'd': // move eye point right along X axis
		eyeX += 1.0;
		break;
	case 'o':  //zoom out
		eyeZ += 1;
		break;
	case 'i': //zoom in
		eyeZ -= 1;
		break;
	case 'r': //back to default eye point and ref point
		eyeX = 23.0; eyeY = 10.0; eyeZ = 12.0;
		refX = 0.0; refY = 1.0; refZ = 2.0;
		break;
	case 'q': //back to default eye point and ref point
		eyeX = 30.0; eyeY = 10.0; eyeZ = 30.0;
		refX = 0.0; refY = 0.0; refZ = 0.0;
		break;
	case 'p': //back to default eye point and ref point
		eyeX = 0.0; eyeY = 5.0; eyeZ = 10.0;
		refX = 20.0; refY = 6.0; refZ = 8.0;
		break;
	case 't': //back to default eye point and ref point
		eyeX = 23.0; eyeY = 3.0; eyeZ = 10.0;
		refX = 0.0; refY = 5.0; refZ = 6.0;
		break;
	case 'j': // move ref point upwards along Y axis
		refY += 1.0;
		break;
	case 'n': // move ref point downwards along Y axis
		refY -= 1.0;
		break;
	case 'b': // move ref point left along X axis
		refX -= 1.0;
		break;
	case 'm': // move eye point right along X axis
		refX += 1.0;
		break;
	case 'k':  //move ref point away from screen/ along z axis
		refZ += 1;
		break;
	case 'l': //move ref point towards screen/ along z axis
		refZ -= 1;
		break;
	case 'c': //turn on/off fan
		if (od == false) {
			od = true; break;
		}
		else {
			od = false; break;
		}
	default:
		break;
	}
	glutPostRedisplay();
}

void tuong() {
	//GLfloat light_pos[] = { -5.0, 5.0, 1.0, 1.0 };
	//glLightfv(GL_LIGHT7, GL_POSITION, light_pos);
	////Thi?t l?p màu môi tr??ng c?a v?t li?u
	//GLfloat ambient[] = { 0.87058824, 0.8176471, 0.16470589, 1.0 };
	//glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
	////Thi?t l?p ?? khuy?ch tán màu
	//GLfloat diff_use[] = { 0.87058824, 0.8176471, 0.16470589, 1.0 };
	//glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff_use);
	////Thi?t l?p ?? ph?n chi?u
	//GLfloat specular[] = { 0.0, 0.0, 0.0, 1.0 };
	//glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
	////Thi?t l?p ?? l?n cho specular
	//GLfloat shininess = 10.0f;
	//glMateriali(GL_FRONT, GL_SHININESS, shininess);

	////sau tivi
	//glPushMatrix();
	//glTranslatef(0.0, 5.5, 6.5);
	//glScalef(0.1, 11, 13);
	//glutSolidCube(1);
	//glPopMatrix();

	////sau tranh
	//glPushMatrix();
	//glTranslatef(11.5, 5.5, 0.0);
	//glScalef(23, 11, 0.1);
	//glutSolidCube(1);
	//glPopMatrix();

	////canh tu giay
	//glPushMatrix();
	//glTranslatef(23, 5.5, 1.35);
	//glScalef(0.1, 11, 2.6);
	//glutSolidCube(1);
	//glPopMatrix();

	////doi dien tu giay
	//glPushMatrix();
	//glTranslatef(23, 5.5, 12.7);
	//glScalef(0.1, 11, 0.6);
	//glutSolidCube(1);
	//glPopMatrix();

	////tren cua
	//glPushMatrix();
	//glTranslatef(23, 8.72, 6.5);
	//glScalef(0.1, 4.5, 13);
	//glutSolidCube(1);
	//glPopMatrix();

	////noc nha
	//glPushMatrix();
	//glTranslatef(11.5, 11, 6.5);
	//glScalef(23, 0.1, 13);
	//glutSolidCube(1);
	//glPopMatrix();
	//
	////mat duoi
	//glPushMatrix();
	//glTranslatef(11.5, 0.0, 6.5);
	//glScalef(23, 0.1, 13);
	//glutSolidCube(1);
	//glPopMatrix();

	////sau cua so
	//glPushMatrix();
	//glTranslatef(11.5, 5.5, 13);
	//glScalef(23, 11, 0.1);
	//glutSolidCube(1);
	//glPopMatrix();

	//Thiết lập smooth shading
	glShadeModel(GL_SMOOTH);

	glBegin(GL_QUADS);
	glColor3f(0.5, 0.5, 0.5);

	//mat sau tranh
	glNormal3f(0.0, 0.0, 1.0);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(23.0, 0.0, 0.0);
	glVertex3f(23.0, 10.0, 0.0);
	glVertex3f(0.0, 10.0, 0.0);

	//mat sau tivi
	glNormal3f(-1.0, 0.0, 0.0);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 0.0, 13.0);
	glVertex3f(0.0, 10.0, 13.0);
	glVertex3f(0.0, 10.0, 0.0);

	//noc nha
	glNormal3f(0.0, 1.0, 0.0);
	glVertex3f(0.0, 10.0, 0.0);
	glVertex3f(23.0, 10.0, 0.0);
	glVertex3f(23.0, 10.0, 13.0);
	glVertex3f(0.0, 10.0, 13.0);

	//san nha
	glNormal3f(0.0, -1.0, 0.0);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(23.0, 0.0, 0.0);
	glVertex3f(23.0, 0.0, 13.0);
	glVertex3f(0.0, 0.0, 13.0);

	//mat sau cua so
	glNormal3f(0.0, 0.0, 1.0);
	glVertex3f(0.0, 0.0, 13.0);
	glVertex3f(23.0, 0.0, 13.0);
	glVertex3f(23.0, 10.0, 13.0);
	glVertex3f(0.0, 10.0, 13.0);

	//tren cua  ok
	glNormal3f(-1.0, 0.0, 0.0);
	glVertex3f(23.0, 6.6, 0.0);
	glVertex3f(23.0, 6.6, 13.0);
	glVertex3f(23.0, 10.0, 13.0);
	glVertex3f(23.0, 10.0, 0.0);

	//canh tu giay
	glNormal3f(-1.0, 0.0, 0.0);
	glVertex3f(23.0, 0.0, 0.0);
	glVertex3f(23.0, 0.0, 2.5);
	glVertex3f(23.0, 10.0, 2.5);
	glVertex3f(23.0, 10.0, 0.0);

	//doi dien tu giay
	glNormal3f(-1.0, 0.0, 0.0);
	glVertex3f(23.0, 0.0, 13.0);
	glVertex3f(23.0, 0.0, 12.48);
	glVertex3f(23.0, 10.0, 12.48);
	glVertex3f(23.0, 10.0, 13.0);
	

	glEnd();
}

void Display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(eyeX, eyeY, eyeZ, refX, refY, refZ, 0, 1, 0); 
	DrawCoordinate();

	setLight0(RoomLight); // Thiết lập nguồn sáng 0 dựa trên trạng thái của biến RoomLight
	setLight2(CeilingLight); // Thiết lập nguồn sáng 2 dựa trên trạng thái của biến CeilingLight

	//ke sach
	glPushMatrix();
	glTranslatef(0.7, 3.26, 1.5);	
	glScaled(0.2, 0.25, 0.25);
	caiGia();
	glPopMatrix();

	//conlon
	glPushMatrix();
	glTranslatef(1, 3.58, 1.3);
	glScaled(0.5, 0.5, 0.5);
	conLon();
	glPopMatrix();

	//binh tren ke
	glPushMatrix();
	glTranslatef(1.2, 2.49, 1.3);
	glScaled(0.3, 0.1, 0.3);
	caiBinhHoa();
	glPopMatrix();

	//tu tivi
	glPushMatrix();
	glTranslatef(1, 1.88, 5.5);
	glRotatef(90,0,8,0);
	glScaled(0.9, 0.7, 0.4); //(z,y,x)
	caiTu();
	glPopMatrix();

	//sach tren ke
	glPushMatrix();
	glTranslatef(1.2, 4.65, 1.45);
	glScaled(0.7, 0.4, 1.2);
	sach();
	glPopMatrix();

	//tivi
	glPushMatrix();
	glTranslatef(1, 4, 5.5);
	glRotatef(90,0,8,0);
	glScaled(1.3, 1, 0.5); //(z, y, x)
	caiTiVi();
	glPopMatrix();

	//sofa x
	glPushMatrix();
	glTranslatef(8.5, 2, 0.7);
	glRotatef(-90, 0, 8, 0);
	glScaled(0.9, 0.7, 0.9); //(z, y, x)
	soFa();
	glPopMatrix();

	//sofa z
	glPushMatrix();
	glTranslatef(13, 2, 6);
	glRotatef(-180, 0, 8, 0);
	glScaled(0.9, 0.7, 0.9); //(z, y, x)
	soFa();
	glPopMatrix();

	//cai ban
	glPushMatrix();
	glTranslatef(8.3, 1.55, 6);
	glScaled(1.0, 0.7, 0.6); 
	caiBan();
	glPopMatrix();

	//cai ghe
	glPushMatrix();
	glTranslatef(8.3, 1.3, 9.5);
	glScaled(0.6, 0.7, 0.6);
	caiGhe();
	glPopMatrix();

	//bo am chen
	glPushMatrix();
	glTranslatef(8.3, 2.4, 6);
	glScaled(0.5, 0.5, 0.5);
	boAmChen();
	glPopMatrix();

	//binh hoa tren ban
	glPushMatrix();
	glTranslatef(8.2, 2.75, 7.3);
	glScaled(0.17, 0.17, 0.17);
	caiBinhHoa();
	glPopMatrix();

	//tranh
	glPushMatrix();
	glTranslatef(9, 6, 0.3);
	glRotatef(-90, 0, 8, 0);
	glScaled(1.0, 0.8, 1.55);//(z, y, x)
	tranh();
	glPopMatrix();

	//chau cay canh tivi
	glPushMatrix();
	glTranslatef(1, 1.8, 8.8);
	glScaled(0.35, 0.4, 0.35);
	chaucay();
	glPopMatrix();

	//tu giay
	glPushMatrix();
	glTranslatef(17.5, 2, 1.2);
	glScaled(0.7, 1.5, 0.7);
	caiTu();
	glPopMatrix();

	//binh hoa tren tu dep
	glPushMatrix();
	glTranslatef(18, 4, 1);
	glScaled(0.17, 0.17, 0.17);
	caiBinhHoa();
	glPopMatrix();

	//cua dong
	if (!od) {
		//cua ra vao
		glPushMatrix();
		glTranslatef(23, 3.3, 10);
		glScaled(0.8, 0.65, 0.8);
		caicua();
		glPopMatrix();

		//cua ra vao
		glPushMatrix();
		glTranslatef(23, 3.3, 5);
		glRotatef(180, 8, 0, 0);
		glScaled(0.8, 0.65, 0.8);
		caicua();
		glPopMatrix();
	}
	//cua mo
	else {
		//cua ra vao phia cua so
		glPushMatrix();
		glTranslatef(25.4, 3.3, 12.5);
		glRotatef(-90, 0, 8, 0);
		glScaled(0.8, 0.65, 0.8);
		caicua();
		glPopMatrix();

		//cua ra vao gan tu dep
		glPushMatrix();
		glTranslatef(25.4, 3.3, 2.5);
		glRotatef(90, 0, 8, 0);
		glRotatef(180, 8, 0, 0);
		glScaled(0.8, 0.65, 0.8);
		caicua();
		glPopMatrix();
	}

	//cua so
	glPushMatrix();
	glTranslatef(7, 4.7, 13);
	glRotatef(90, 0, 8, 0);
	glScaled(0.5, 0.4, 0.6);//(z,y,x)
	cuaSo();
	glPopMatrix();

	//chau cay gan cua
	glPushMatrix();
	glTranslatef(16.5, 0.65, 12);
	glScaled(0.4, 0.4, 0.4);
	chaucay();
	glPopMatrix();

	//quat
	glPushMatrix();
	glTranslatef(8, 8, 7);
	glScaled(0.4, 0.4, 0.4);
	caiQuat();
	glPopMatrix();

	//bac them
	glPushMatrix();
	glTranslatef(7.5, 0.5, 6.5);
	glScaled(15, 1, 13);
	bacThem();
	glPopMatrix();

	tuong();

	glFlush();
}

void ReShape(int width, int height) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	float ratio = (float)width / (float)height;
	gluPerspective(45.0, ratio, 1, 100.0);
	glMatrixMode(GL_MODELVIEW);
}

void Init() {
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	/*glEnable(GL_LIGHT1);
	glEnable(GL_LIGHT2);
	glEnable(GL_LIGHT3);
	glEnable(GL_LIGHT4);
	glEnable(GL_LIGHT5);
	glEnable(GL_LIGHT6);
	glEnable(GL_LIGHT7);*/
	glEnable(GL_DEPTH_TEST);
}

int main() {
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("phong khach");
	Init();
	glutReshapeFunc(ReShape);
	glutDisplayFunc(Display);
	glutKeyboardFunc(keybroad);
	glutMainLoop();
	return 0;
}