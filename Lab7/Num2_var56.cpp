#include "glut.h"
#include <time.h>
#include <stdlib.h>
#include <string>
#include <vector>

int width = 640, height = 640;

std::vector <double> point_x;
std::vector <double> point_y;

int finish_xy[5][2];
int start_xy[2] = { 100 , 10 };

void DrawPointline()
{
	for (int i = 0; i < point_x.size(); ++i) {
		glPointSize(1.0f);
		glColor3f(0, 0, 0);
		glBegin(GL_POINTS);
		glVertex2f(point_x[i], point_y[i]);
		glEnd();
	}
}

void DrawPoint(double x, double y) {
	glPointSize(5.0f);
	glColor3f(1, 0, 0);
	glBegin(GL_POINTS);
	glVertex2f(x, y);
	glEnd();
}



struct Point {
	double x;
	double y;
	int k = 0;
};

void DrawFinish() {
	for (int i = 0; i < 5; ++i)
		DrawPoint(finish_xy[i][0], finish_xy[i][1]);
}

void move() {
	srand(time(0));
	int dice_number = rand() % 15 + 1;
	
	if (dice_number < 4) {
		double Ax = finish_xy[0][0] - point_x.back();
		double Ay = finish_xy[0][1] - point_y.back();
		double length_xy = sqrt(pow(Ax, 2) + pow(Ay, 2)); // длина вектора чтобы поделить на нее и получить единичный
		point_x.push_back(point_x.back() + Ax / length_xy * 0.5);
		point_y.push_back(point_y.back() + Ay / length_xy * 0.5);
		 //определять координаты новой точки
	}
	else if (dice_number < 7) {
		double Ax = finish_xy[1][0] - point_x.back();
		double Ay = finish_xy[1][1] - point_y.back();
		double length_xy = sqrt(pow(Ax, 2) + pow(Ay, 2));
		point_x.push_back(point_x.back() + Ax / length_xy * 0.5);
		point_y.push_back(point_y.back() + Ay / length_xy * 0.5);
	}
	else if (dice_number < 10) {
		double Ax = finish_xy[2][0] - point_x.back();
		double Ay = finish_xy[2][1] - point_y.back();
		double length_xy = sqrt(pow(Ax, 2) + pow(Ay, 2));
		point_x.push_back(point_x.back() + Ax / length_xy * 0.5);
		point_y.push_back(point_y.back() + Ay / length_xy * 0.5);
	}
	else if (dice_number < 13) {
		double Ax = finish_xy[3][0] - point_x.back();
		double Ay = finish_xy[3][1] - point_y.back();
		double length_xy = sqrt(pow(Ax, 2) + pow(Ay, 2));
		point_x.push_back(point_x.back() + Ax / length_xy * 0.5);
		point_y.push_back(point_y.back() + Ay / length_xy * 0.5);
	}
	else {
		double Ax = finish_xy[4][0] - point_x.back();
		double Ay = finish_xy[4][1] - point_y.back();
		double length_xy = sqrt(pow(Ax, 2) + pow(Ay, 2));
		point_x.push_back(point_x.back() + Ax / length_xy * 0.5);
		point_y.push_back(point_y.back() + Ay / length_xy * 0.5);
	}

}

//struct {
//	int x;
//	int y;
//} snake[maxSnakeLength];
//
// ???


void DrawStart() {
	DrawPoint(start_xy[0], start_xy[1]);
}


void Display(void) {
	if (point_x.size() > 10000) exit(0);
	glClear(GL_COLOR_BUFFER_BIT);
	DrawStart();
	DrawPointline();
	move();
	DrawFinish();
	glFlush();
	glutSwapBuffers();
}

void timer(int = 0) {
	Display();
	glutTimerFunc(100, timer, 0);
}

int main(int argc, char** argv)
{
	srand(time(0));
	for (int i = 0; i < 5; ++i)
		for (int j = 0; j < 2; ++j)
			finish_xy[i][j] = rand() % 200 - 100;
	/*N = 5 случайных точек, M = 15 граний кубика, R = 0.50;
	 1, 2, 3 грань - первая точка; 4, 5, 6 - вторая точка; 7, 8, 9 - третья; 10, 11, 12 - четвертая; 13, 14, 15 - пятая точка*/
	point_x.push_back(start_xy[0]);
	point_y.push_back(start_xy[1]);
	//Start();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	glutInitWindowSize(width, height);
	glutCreateWindow("Number2_Variable56");
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100, 100, -100, 100);
	glutDisplayFunc(Display);
	
	glutTimerFunc(100, timer, 0);
	glutMainLoop();
	return 0;
}