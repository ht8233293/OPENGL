#include "glut.h"
#include "math.h"
float objectPositionX = 0.0f;
float objectPositionY = 0.0f;
float objectPositionZ = 0.0f;

float cameraAngleX = 0.0f;
float cameraAngleY = 0.0f;

int startX, startY;
float angleX = 0;
float angleY = 0;
bool isDragging = false;
bool isZoomMode = false;
bool isDoorOpen = false;

void setLight0(bool flag);  // Thiết lập ánh sáng 0
void setLight1(bool flag);  // Thiết lập ánh sáng 1
void setLight2(bool flag);  // Thiết lập ánh sáng 2

void createCuboid(float x, float y, float z, float width, float height, float depth) {
	glPushMatrix(); // Lưu lại ma trận biến đổi hiện tại
	glTranslatef(x, y, z); // Di chuyển khối hộp đến tọa độ xác định
	glScalef(width, height, depth); // Tỷ lệ hóa khối hộp theo chiều rộng, chiều cao, và chiều sâu

	// Vẽ một khối lập phương đơn vị với tâm tại gốc tọa độ, sau đó áp dụng tỷ lệ hóa
	glutSolidCube(1.0);

	glPopMatrix(); // Khôi phục lại ma trận biến đổi ban đầu
}


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



void reShape(int width, int height) {
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	float ratio = (float)width / (float)height;
	gluPerspective(45.0, ratio, 1, 100.0);
	glMatrixMode(GL_MODELVIEW);
}
void DrawCoodinate2D() {
	//x
	glColor3f(1, 1, 1);
	glBegin(GL_LINES);
	glVertex3f(100, 0, 0);
	glVertex3f(-100, 0, 0);
	glEnd();
	//y
	glColor3f(1, 1, 1);
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
	//tran
	glPushMatrix();
	glTranslatef(0.0, 9.46, 0.0);
	glScalef(10.0, 0.6, 10.0);
	glutSolidCube(1);
	glPopMatrix();
	//
	glPushMatrix();
	glTranslatef(5, 4.75, 0.0); // Đặt vị trí của bức tường mới 
	glScalef(0.5, 10, 10); // Kích thước của bức tường mới (chiều dài, chiều cao, độ dày) 
	glutSolidCube(1);
	glPopMatrix();
}


//tủ sách
void DrawBook() {
	glColor3f(1, 1, 1);

	// khối trang sách
	glPushMatrix();
	glScalef(0.7, 0.7, 0.2);
	glutSolidCube(1);
	glPopMatrix();

	// bìa 1
	glColor3f(0.5, 0.5, 0.5); // Màu xám cho bìa 1
	glPushMatrix();
	glTranslatef(0, 0, 0.1);
	glScalef(0.8, 0.8, 0.05);
	glutSolidCube(1);
	glPopMatrix();

	// bìa 2
	glPushMatrix();
	glTranslatef(0, 0, -0.1);
	glScalef(0.8, 0.8, 0.05);
	glutSolidCube(1);
	glPopMatrix();

	// bìa 3 mặt trước
	glPushMatrix();
	glTranslatef(0.4, 0, 0);
	glScalef(0.05, 0.8, 0.25);
	glutSolidCube(1);
	glPopMatrix();
}
void DrawBookWithY(float y) {
	float start = -1.2;
	float end = 3;

	float delta = start;
	for (int i = 0; i <= (end - start) / 0.3f; i++) {
		glPushMatrix();
		glTranslatef(0, y, delta);
		DrawBook();
		glPopMatrix();
		delta += 0.3f;
	}
}
// Hàm vẽ tủ sách với nhiều tầng và các bên hỗ trợ
void DrawBookCase() {
	glPushMatrix(); // Lưu lại trạng thái ma trận ban đầu

	// Đặt vị trí tủ sách trong không gian 3D
	glTranslatef(-4.2, 0.5, -3.2); // Di chuyển đến vị trí thích hợp
	glScalef(1, 1, 1); // Thiết lập tỉ lệ (ở đây là 1:1:1, không thay đổi)

	// Đặt màu nâu cho tủ sách
	glColor3f(0.7, 0.5, 0.3); // Màu nâu nhạt cho kệ sách

	// Vẽ tầng thứ nhất của tủ sách
	glPushMatrix(); // Bắt đầu khối thứ nhất
	glTranslatef(0, 0.1, 0.7); // Di chuyển lên để tạo tầng tiếp theo
	glScalef(1, 0.2, 4.25); // Tạo hình chữ nhật mỏng, dài
	glutSolidCube(1); // Vẽ khối lập phương đã được định dạng
	glPopMatrix(); // Kết thúc khối thứ nhất

	// Vẽ tầng thứ hai của tủ sách
	glPushMatrix(); // Bắt đầu khối thứ hai
	glTranslatef(0, 1.7, 0.7); // Di chuyển lên để tạo tầng tiếp theo
	glScalef(1, 0.2, 4.25); // Tỉ lệ tương tự tầng thứ nhất
	glutSolidCube(1); // Vẽ khối lập phương
	glPopMatrix(); // Kết thúc khối thứ hai

	// Vẽ tầng thứ ba của tủ sách
	glPushMatrix(); // Bắt đầu khối thứ ba
	glTranslatef(0, 3.2, 0.7); // Tiếp tục di chuyển lên
	glScalef(1, 0.2, 4.25); // Tỉ lệ tương tự các tầng khác
	glutSolidCube(1); // Vẽ khối lập phương
	glPopMatrix(); // Kết thúc khối thứ ba

	// Vẽ tầng thứ tư của tủ sách
	glPushMatrix(); // Bắt đầu khối thứ tư
	glTranslatef(0, 4.7, 0.7); // Di chuyển lên trên nữa
	glScalef(1, 0.2, 4.25); // Tỉ lệ như các tầng khác
	glutSolidCube(1); // Vẽ khối lập phương
	glPopMatrix(); // Kết thúc khối thứ tư

	// Vẽ thành bên trái của tủ sách
	glPushMatrix(); // Bắt đầu khối bên trái
	glTranslatef(0, 2.2, 2.8); // Đặt thành bên trái
	glScalef(1, 5.2, 0.2); // Tỉ lệ để tạo thành mỏng, cao
	glutSolidCube(1); // Vẽ khối lập phương
	glPopMatrix(); // Kết thúc khối bên trái

	// Vẽ thành bên trái của tủ sách
	glPushMatrix(); // Bắt đầu khối bên trái
	glTranslatef(0, 2.2, 1.4); // Đặt thành bên trái
	glScalef(1, 5.2, 0.2); // Tỉ lệ để tạo thành mỏng, cao
	glutSolidCube(1); // Vẽ khối lập phương
	glPopMatrix(); // Kết thúc khối bên trái

	// Vẽ thành giữa của tủ sách
	glPushMatrix(); // Bắt đầu khối bên trái
	glTranslatef(0, 2.2, 0); // Đặt thành bên trái
	glScalef(1, 5.2, 0.2); // Tỉ lệ để tạo thành mỏng, cao
	glutSolidCube(1); // Vẽ khối lập phương
	glPopMatrix(); // Kết thúc khối bên trái

	// Vẽ thành bên phải của tủ sách
	glPushMatrix(); // Bắt đầu khối bên phải
	glTranslatef(0, 2.2, -1.4); // Đặt thành bên phải
	glScalef(1, 5.2, 0.2); // Tỉ lệ như thành bên trái
	glutSolidCube(1); // Vẽ khối lập phương
	glPopMatrix(); // Kết thúc khối bên phải

	// Gọi các hàm để vẽ sách trên các tầng khác nhau
	DrawBookWithY(0.5); // Vẽ sách ở tầng thấp
	DrawBookWithY(2.2); // Vẽ sách ở tầng giữa
	DrawBookWithY(3.7); // Vẽ sách ở tầng cao hơn

	glPopMatrix(); // Khôi phục trạng thái ma trận ban đầu
}



//vẽ bàn học
void DrawWorkTable() {
	glPushMatrix();
	glTranslatef(2, 0, -3.8);
	glColor3f(0.6, 0.4, 0.2);

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

//vẽ màn hình máy tính
void DrawComputer() {
	// Phần đáy máy tính
	glPushMatrix();
	glTranslatef(2, 2.1, -4.2); // Đặt vị trí của máy tính
	glScalef(0.6, 0.05, 0.4); // Kích thước của phần đáy máy tính
	glColor3f(0, 0, 0); // Màu của máy tính
	glutSolidCube(1); // Vẽ phần đáy máy tính
	glPopMatrix(); // Kết thúc phần đáy máy tính 

	// Phần cổ máy tính
	glPushMatrix();
	glTranslatef(2, 2.6, -4.2); // Di chuyển đến vị trí của cổ máy tính
	glScalef(0.1, 0.8, 0.1); // Thay đổi kích thước để vẽ thành hình hộp chữ nhật (chiều dài, chiều cao, chiều rộng)
	glutSolidCube(1); // Vẽ hình hộp chữ nhật
	glPopMatrix(); // Kết thúc phần cổ máy tính

	// Phần màn hình
	glPushMatrix();
	glTranslatef(2, 2.9, -4.2); // Di chuyển đến vị trí của màn hình
	glScalef(2.0, 1.0, 0.1); // Thay đổi kích thước để vẽ thành hình hộp chữ nhật (chiều dài, chiều cao, chiều rộng)
	glutSolidCube(1); // Vẽ hình hộp chữ nhật
	glPopMatrix(); // Kết thúc phần màn hình
}



void DrawChairLeg(float x, float z) {
	glPushMatrix();
	glTranslated(x, -0.1, z); // Dịch chuyển theo tọa độ x và z
	glScalef(0.15, 0.4, 0.15); // Scale chiều rộng và chiều sâu
	glutSolidCube(1);
	glPopMatrix();
	glEnd();
}

//vẽ bàn phím
void DrawKeyboard() {
	// Thân bàn phím
	glColor3f(0.3, 0.3, 0.3);
	glPushMatrix();
	glTranslatef(2, 2.1, -3.5);
	glScalef(1.4, 0.1, 0.7); // Thay đổi tỉ lệ tại đây
	glutSolidCube(1);
	glPopMatrix();

	// Phím trắng
	glColor3f(0.9, 0.9, 0.9);
	glPushMatrix();
	glTranslatef(2.3, 2.2, -3.8);
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 3; ++j) {
			glPushMatrix();
			glTranslatef(0.12 * (2 - i), 0, 0.3 * j);
			glScalef(0.1, 0.05, 0.1);
			glutSolidCube(1);
			glPopMatrix();
		}
	}
	glPopMatrix();

	// Phím đen
	glColor3f(0.1, 0.1, 0.1);
	glPushMatrix();
	glTranslatef(2.3, 2.1, -3.8);
	for (int i = 1; i < 10; i += 2) {
		for (int j = 0; j < 3; ++j) {
			glPushMatrix();
			glTranslatef(0.12 * (2 - i), 0, 0.3 * j);
			glScalef(0.08, 0.05, 0.06);
			glutSolidCube(1);
			glPopMatrix();
		}
	}
	glPopMatrix();
}

// Hàm vẽ cửa với các phần khác nhau như cánh cửa, thanh chắn, và tay nắm cửa
void DrawDoor() {
	glPushMatrix(); // Lưu trạng thái ma trận hiện tại

	// Thiết lập vị trí và xoay cửa trên tường bên trái
	glTranslatef(-4.7, 1.65, 3); // Định vị cửa ở không gian 3D
	glRotatef(90.0, 0.0, 1.0, 0.0); // Xoay 90 độ để đặt cửa trên tường bên trái

	// Vẽ cánh cửa chính
	glColor3f(1, 1, 1); // Trắng
	glPushMatrix(); // Bắt đầu khối cánh cửa
	glTranslatef(0.0, 0.0, 0.0); // Vị trí ban đầu cho cánh cửa
	glScalef(1.6, 3.0, 0.2); // Tỉ lệ để tạo ra hình chữ nhật dọc, mỏng
	glutSolidCube(1.0); // Vẽ khối lập phương, sau đó sẽ thành hình chữ nhật nhờ tỉ lệ
	glPopMatrix(); // Kết thúc khối cánh cửa

	// Vẽ phần trên cùng của cánh cửa
	glColor3f(0.5, 0.7, 1.0); // Màu xanh dương nhạt
	glPushMatrix(); // Bắt đầu khối thanh chắn
	glTranslatef(-0.1, 0.8, 0.0); // Định vị thanh chắn phía trên bên trái cửa
	glScalef(0.7, 1.0, 0.22); // Tỉ lệ để tạo thanh chắn mỏng
	glutSolidCube(1.0); // Vẽ khối lập phương đã định dạng
	glPopMatrix(); // Kết thúc khối thanh chắn

	// Tạo thanh chắn trên bên phải của cửa
	glPushMatrix(); // Bắt đầu khối thanh chắn khác
	glTranslatef(0.3, 0.8, 0.0); // Định vị thanh chắn trên bên phải cửa
	glScalef(0.4, 1.0, 0.22); // Tỉ lệ để tạo thanh chắn mỏng
	glutSolidCube(1.0); // Vẽ khối lập phương
	glPopMatrix(); // Kết thúc khối thanh chắn

	// Tạo thanh chắn dưới cùng của cửa
	glPushMatrix(); // Bắt đầu khối thanh chắn khác
	glTranslatef(0.0, -0.6, 0.0); // Định vị thanh chắn phía dưới cửa
	glScalef(1.0, 1.3, 0.22); // Tỉ lệ để tạo thanh chắn rộng
	glutSolidCube(1.0); // Vẽ khối lập phương đã định dạng
	glPopMatrix(); // Kết thúc khối thanh chắn

	// Tạo tay nắm cửa
	glColor3f(0.0, 0.0, 0.0); // Màu đen cho tay nắm cửa
	glPushMatrix(); // Bắt đầu khối tay nắm
	glTranslatef(-0.6, 0.2, 0.1); // Định vị tay nắm cửa
	glScalef(0.2, 0.2, 0.2); // Tỉ lệ nhỏ hơn cho tay nắm
	glutSolidSphere(0.5, 50, 50); // Vẽ hình cầu làm tay nắm cửa
	glPopMatrix(); // Kết thúc khối tay nắm

	glPopMatrix(); // Khôi phục trạng thái ma trận ban đầu
}

//vẽ ghế
void DrawChair() {
	glPushMatrix();
	glTranslatef(1.8, 1.3, -3.0); // Di chuyển vị trí của ghế phía trước bàn học
	glScalef(0.8, 1.0, 0.8); // Thay đổi kích thước của ghế
	glColor3f(0.5, 0.35, 0.05);

	// Chân ghế 1
	glPushMatrix();
	glTranslatef(-0.8, -0.6, -0.8);
	glScalef(0.2, 1, 0.2); // Thay đổi kích thước của chân ghế
	glutSolidCube(1);
	glPopMatrix();

	// Chân ghế 2
	glPushMatrix();
	glTranslatef(0.8, -0.6, -0.8);
	glScalef(0.2, 1, 0.2); // Thay đổi kích thước của chân ghế
	glutSolidCube(1);
	glPopMatrix();

	// Chân ghế 3
	glPushMatrix();
	glTranslatef(-0.8, -0.6, 0.8);
	glScalef(0.2, 1, 0.2); // Thay đổi kích thước của chân ghế
	glutSolidCube(1);
	glPopMatrix();

	// Chân ghế 4
	glPushMatrix();
	glTranslatef(0.8, -0.6, 0.8);
	glScalef(0.2, 1, 0.2); // Thay đổi kích thước của chân ghế
	glutSolidCube(1);
	glPopMatrix();

	// Mặt ghế
	glPushMatrix();
	glTranslatef(0, -0.1, 0);
	glScalef(1.8, 0.1, 1.8); // Thay đổi kích thước của mặt ghế
	glutSolidCube(1);
	glPopMatrix();

	// Tựa lưng
	glPushMatrix();
	glTranslatef(0, 0.6, 0.8); // Đặt tựa lưng ở phía sau ghế
	glScalef(1.8, 2, 0.2); // Kích thước của tựa lưng
	glutSolidCube(1);
	glPopMatrix();

	glPopMatrix();

}

// Vẽ cửa sổ
void DrawWindow() {
	// Khung cửa sổ
	glColor3f(1, 1, 1); // Màu xám cho khung cửa sổ
	glPushMatrix();
	glTranslatef(4.7, 4.75, 0.0); // Di chuyển vị trí của cửa sổ đến tường bên trái
	glRotatef(90.0, 0.0, 1.0, 0.0); // Xoay cửa sổ để nó nằm ở tường bên trái 
	glScalef(2.4, 2.0, 0.1); // Kích thước của cửa sổ (chiều sâu là 0.1)
	glutSolidCube(1.0); // Vẽ hình hộp chữ nhật
	glPopMatrix();

	// Kính cửa sổ
	glColor3f(0.7, 0.9, 1.0); // Màu xanh nước biển nhạt cho kính cửa sổ
	glPushMatrix();
	glTranslatef(4.6, 4.75, 0.01); // Di chuyển vị trí của kính cửa sổ (một chút sau khung cửa sổ)
	glRotatef(90.0, 0.0, 1.0, 0.0); // Xoay cửa sổ để nó nằm ở tường bên trái 
	glScalef(2.38, 1.98, 0.01); // Kích thước của kính cửa sổ (nhỏ hơn khung để tạo hiệu ứng viền)
	glutSolidCube(1.0); // Vẽ hình hộp chữ nhật
	glColor3f(0.0, 0.0, 0.0); // Màu đen
	createCuboid(0, 0, 2, 1, 0.1, 6); // Thanh chắn trên
	createCuboid(0, 0, 2, 0.1, 1, 6); // Thanh chắn trên
	glPopMatrix();
}



void DrawPainting() {
	glPushMatrix();
	glTranslatef(-4.75, 7, 0);

	// Khung tranh
	glColor3f(1.0, 1.0, 0.0); // Màu vàng
	glPushMatrix();
	glRotatef(-90, 0, 1, 0);
	glScalef(4.2, 2.2, 0.15); // Thay đổi kích thước
	glutSolidCube(1.0);
	glPopMatrix();

	glRotatef(90, 0, 1, 0);
	glTranslatef(0.0, 0.0, 0.05);
	glScalef(1.55, 1.25, 0.2);

	// Phần cốt truyện
	glColor3f(0.6, 0.6, 0.6); // Màu xám
	glBegin(GL_QUADS);
	glVertex3f(-1.4, 0.9, 0.0);
	glVertex3f(1.4, 0.9, 0.0);
	glVertex3f(1.4, -0.9, 0.0);
	glVertex3f(-1.4, -0.9, 0.0);
	glEnd();

	// Mặt trời
	glColor3f(1.0, 0.6, 0.0); // Màu cam sáng
	glPushMatrix();
	glTranslatef(0.0, 0.45, 0.01);
	glutSolidSphere(0.3, 30, 30);
	glPopMatrix();

	// Cây
	glColor3f(0.5, 0.35, 0.05); // Màu nâu sáng
	glPushMatrix();
	glTranslatef(-0.8, -0.5, 0.01);
	glScalef(0.15, 0.6, 0.5);
	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(0.0, 0.7, 0.0); // Màu xanh lá cây
	glPushMatrix();
	glTranslatef(-0.7, -0.2, 0.3);
	glutSolidSphere(0.3, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.8, 0.1, 0.3);
	glutSolidSphere(0.3, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.9, -0.2, 0.3);
	glutSolidSphere(0.3, 20, 20);
	glPopMatrix();

	// Cây 2
	glColor3f(0.5, 0.35, 0.05); // Màu nâu sáng
	glPushMatrix();
	glTranslatef(1, -0.5, 0.01);
	glScalef(0.15, 0.6, 0.5);
	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(0.0, 0.7, 0.0); // Màu xanh lá cây
	glPushMatrix();
	glTranslatef(1, -0.2, 0.3);
	glutSolidSphere(0.3, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1, 0.1, 0.3);
	glutSolidSphere(0.3, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1, -0.2, 0.3);
	glutSolidSphere(0.3, 20, 20);
	glPopMatrix();

	glPopMatrix();
}

void DrawClock() {
	glPushMatrix();
	glTranslatef(0, 6, -4.7);

	// Mặt đồng hồ
	glColor3f(1.0, 1.0, 1.0); // Màu trắng

	glPushMatrix();
	glScalef(0.8, 0.8, 0.1);
	glutSolidTorus(0.1, 0.8, 40, 40);
	glPopMatrix();

	// Viền đồng hồ
	glColor3f(0.0, 0.0, 0.0); // Màu đen cho viền đồng hồ

	glPushMatrix();
	glScalef(0.9, 0.9, 0.2);
	glutSolidTorus(0.05, 0.85, 40, 40);
	glPopMatrix();

	// Kim giờ
	glColor3f(0.0, 0.0, 0.0); // Màu đen cho kim giờ

	glPushMatrix();
	glRotatef(30, 0, 0, 1);
	glScalef(0.4, 0.04, 0.04);
	glutSolidCube(1.0);
	glPopMatrix();

	// Kim phút
	glColor3f(0.0, 0.0, 0.0); // Màu đen cho kim phút

	glPushMatrix();
	glRotatef(120, 0, 0, 1);
	glScalef(0.6, 0.02, 0.02);
	glutSolidCube(1.0);
	glPopMatrix();

	// Kim giây
	glColor3f(1.0, 0.0, 0.0); // Màu đỏ cho kim giây

	glPushMatrix();
	glRotatef(180, 0, 0, 1);
	glScalef(0.7, 0.01, 0.01);
	glutSolidCube(1.0);
	glPopMatrix();

	// Số trên đồng hồ
	glColor3f(0.0, 0.0, 0.0); // Màu đen cho số trên đồng hồ

	for (int i = 1; i <= 12; i++) {
		glPushMatrix();
		glRotatef(i * 30, 0, 0, 1);
		glTranslatef(0.55, 0, 0.05);
		glutSolidCube(0.05);
		glPopMatrix();
	}

	glPopMatrix();
}

void DrawAircondition() {
	// Đặt màu trắng để vẽ khung chính
	glColor3f(1.0f, 1.0f, 1.0f); // Màu trắng

	// Chân đế điều hòa nhỏ hơn với tọa độ trung tâm và kích thước giảm
	createCuboid(3.0f, 7.45f, -4.25f, 3.15f, 0.15f, 1.0f); // Chân đế

	// Kệ trên cùng, giảm kích thước và vị trí thấp hơn
	createCuboid(3.0f, 8.045f, -4.25f, 3.15f, 0.15f, 1.0f); // Kệ trên cùng

	// Các cột bên giảm kích thước và gần hơn
	createCuboid(1.45f, 7.75f, -4.25f, 0.15f, 0.75f, 1.0f);  // Cột bên trái
	createCuboid(4.5f, 7.75f, -4.25f, 0.15f, 0.75f, 1.0f);   // Cột bên phải

	// Sử dụng màu đen cho các phần chắn phía trước
	glColor3f(0.0f, 0.0f, 0.0f); // Màu đen

	// Các thanh chắn phía trước điều hòa với kích thước nhỏ hơn
	createCuboid(3.0f, 7.75f, -4.30f, 3.0f, 0.05f, 1.0f); // Thanh chắn trên
	createCuboid(3.0f, 7.625f, -4.30f, 3.0f, 0.05f, 1.0f); // Thanh chắn giữa
	createCuboid(3.0f, 7.5f, -4.30f, 3.0f, 0.05f, 1.0f);  // Thanh chắn dưới

	// Màu xanh lá cây cho phần nhỏ phía trước điều hòa
	glColor3f(0.0f, 1.0f, 0.0f); // Màu xanh lá cây

	// Tạo phần nhỏ phía trước như quạt gió với kích thước nhỏ hơn
	createCuboid(2.0f, 8.0f, -3.85f, 0.1f, 0.05f, 0.5f);

	// Đặt màu trắng cho các tấm chắn phía sau điều hòa
	glColor3f(1.0f, 1.0f, 1.0f); // Màu trắng

	// Tạo các tấm chắn phía sau điều hòa với kích thước nhỏ hơn
	createCuboid(3.f, 7.75f, -3.83f, 3.f, 0.75f, 0.05f);  // Tấm chắn sau bên trong
	createCuboid(3.f, 7.75f, -5.025f, 3.f, 0.75f, 0.05f);   // Tấm chắn sau bên ngoài
}




void disPlay() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(0, -3, -25); // Di chuyển camera ra xa đối tượng
	glRotatef(angleX, 0, 1, 0); // Xoay theo trục y
	glRotatef(angleY, 1, 0, 0); // Xoay theo trục x
	glTranslatef(objectPositionX, objectPositionY, objectPositionZ);

	// Xoay camera
	glRotatef(cameraAngleX, 1.0f, 0.0f, 0.0f);
	glRotatef(cameraAngleY, 0.0f, 1.0f, 0.0f);

	//
	setLight0(RoomLight); // Thiết lập nguồn sáng 0 dựa trên trạng thái của biến RoomLight
	setLight2(CeilingLight); // Thiết lập nguồn sáng 2 dựa trên trạng thái của biến CeilingLight

	//
	glPushMatrix(); // Đèn trần
	glColor3f(1, 1, 0); // Màu vàng
	glMaterialfv(GL_FRONT, GL_AMBIENT, matYellow); // Màu ánh sáng môi trường
	glMaterialfv(GL_FRONT, GL_DIFFUSE, matYellow); // Màu phản xạ khu vực
	glMaterialfv(GL_FRONT, GL_SPECULAR, matWhite); // Màu phản xạ gương
	glMaterialfv(GL_FRONT, GL_SHININESS, matShininess); // Bậc bóng
	glMaterialfv(GL_FRONT, GL_EMISSION, matBlack); // Màu phát xạ (đen)
	if (CeilingLight) glMaterialfv(GL_FRONT, GL_EMISSION, matYellow); // Nếu đèn trần được bật, sử dụng màu vàng
	glTranslatef(0.0, 8.9, 0.0); // Di chuyển đến vị trí của đèn trần
	glRotatef(270, 1, 0, 0); // Xoay (270 độ theo trục x)
	glScalef(0.5, 0.5, 0.5); // Thu nhỏ đèn trần đi một nửa 
	glutSolidCone(1, 1, 16, 16); // Vẽ hình nón
	glPopMatrix();


	glColor3f(1, 0.8, 0.2);
	glMaterialfv(GL_FRONT, GL_AMBIENT, matBrown); // Màu ánh sáng môi trường
	glMaterialfv(GL_FRONT, GL_DIFFUSE, matBrown); // Màu phản xạ khu vực
	glMaterialfv(GL_FRONT, GL_SPECULAR, matWhite); // Màu phản xạ gương
	glMaterialfv(GL_FRONT, GL_SHININESS, matShininess); // Bậc bóng
	glMaterialfv(GL_FRONT, GL_EMISSION, matBlack); // Màu phát xạ (đen)

	// Giường
	glColor3f(1, 0.8, 0.5);
	glMaterialfv(GL_FRONT, GL_AMBIENT, matBrown); // Màu ánh sáng môi trường
	glMaterialfv(GL_FRONT, GL_DIFFUSE, matBrown); // Màu phản xạ khu vực
	glMaterialfv(GL_FRONT, GL_SPECULAR, matWhite); // Màu phản xạ gương
	glMaterialfv(GL_FRONT, GL_SHININESS, matShininess); // Bậc bóng
	glMaterialfv(GL_FRONT, GL_EMISSION, matBlack); // Màu phát xạ (đen)
	//chan giuong
	glPushMatrix();
	glTranslatef(-1.5, 1.5, -4); // Di chuyển đến vị trí của giường
	glScalef(2.5, 2.5, 0.5); // Thay đổi kích thước để vẽ thành hình hộp chữ nhật
	glutSolidCube(1); // Vẽ giường
	glPopMatrix(); // Kết thúc phần giường

	glPushMatrix();
	glTranslatef(-1.5, 1.2, -2); // Di chuyển đến vị trí của giường
	glScalef(2.5, 0.5, 4); // Thay đổi kích thước để vẽ thành hình hộp chữ nhật
	glutSolidCube(1); // Vẽ giường
	glPopMatrix(); // Kết thúc phần giường

	glPushMatrix();
	glTranslatef(-1.5, 0.8, -0.23); // Di chuyển đến vị trí của giường
	glScalef(2.5, 1, 0.5); // Thay đổi kích thước để vẽ thành hình hộp chữ nhật
	glutSolidCube(1); // Vẽ giường
	glPopMatrix(); // Kết thúc phần giường

	// Nệm của giường
	glPushMatrix();
	glColor3f(0.0f, 0.0f, 1.0f); // Xanh dương
	glMaterialfv(GL_FRONT, GL_AMBIENT, matPink); // Màu ánh sáng môi trường
	glMaterialfv(GL_FRONT, GL_DIFFUSE, matPink); // Màu phản xạ khu vực
	glMaterialfv(GL_FRONT, GL_SPECULAR, matWhite); // Màu phản xạ gương
	glMaterialfv(GL_FRONT, GL_SHININESS, matShininess); // Bậc bóng
	glMaterialfv(GL_FRONT, GL_EMISSION, matBlack); // Màu phát xạ (đen)
	glTranslatef(-1.5, 1.6, -2); // Di chuyển đến vị trí của giường
	glScalef(2.5, 0.4, 4); // Thay đổi kích thước để vẽ thành hình hộp chữ nhật
	glutSolidCube(1); // Vẽ nệm giường
	glPopMatrix(); // Kết thúc phần nệm giường

	DrawCoodinate3D(); 
	DrawRoomWall();
	DrawBookCase();
	DrawWorkTable();
	DrawComputer();
	DrawKeyboard();
	DrawDoor();
	DrawChair();
	DrawWindow();
	DrawPainting();
	DrawClock();
	DrawAircondition();

	glFlush();
	glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case'1': // Ánh sáng phòng
		RoomLight = !RoomLight;
		break;
	case'2': // Ánh sáng trần nhà
		CeilingLight = !CeilingLight;
		break;
	case 'd': // Di chuyển sang trái khi phím 'a' được nhấn
		objectPositionX -= 0.1f;
		break;
	case 'a': // Di chuyển sang phải khi phím 'd' được nhấn
		objectPositionX += 0.1f;
		break;
	case 'w': // Tiến đi khi phím 'w' được nhấn
		objectPositionZ += 0.1f;
		break;
	case 's': // Lùi lại khi phím 's' được nhấn
		objectPositionZ -= 0.1f;
		break;
	case 'k': // Xoay camera lên
		cameraAngleX += 5.0f;
		break;
	case 'i': // Xoay camera xuống
		cameraAngleX -= 5.0f;
		break;
	case 'j': // Xoay camera sang trái
		cameraAngleY -= 5.0f;
		break;
	case 'l': // Xoay camera sang phải
		cameraAngleY += 5.0f;
		break;
	}

	glutPostRedisplay();

}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1000, 1000);
	glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH) - 1000) / 2, (glutGet(GLUT_SCREEN_HEIGHT) - 1000) / 2);
	glutCreateWindow("officeRoom");
	init();
	glutReshapeFunc(reShape);
	glutDisplayFunc(disPlay); // Gọi hàm vẽ
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouseButton);
	glutMotionFunc(mouseMotion);
	glutMainLoop();
	return 0;
}