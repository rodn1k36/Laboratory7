//#include "glut.h"
//#include <time.h>
//#include <stdlib.h>
//#include <string>
//#include <vector>
//
//int width = 640, height = 480;
//
////void DrawPoint(double x, double y)
////{
////	glPointSize(5.0f);
////	glColor3f(0, 0, 0);
////	glBegin(GL_POINTS);
////	glVertex2f(x, y);
////	glVertex2f(x, y);
////	glEnd();
////}
//
//void Start() {
//	start_point.x = 40;
//	start_point.y = 50;
//	finish_point[0].x = rand() % 640;
//	finish_point[0].x = rand() % 480;
//	finish_point[1].x = rand() % 640;
//	finish_point[1].x = rand() % 480;
//	finish_point[2].x = rand() % 640;
//	finish_point[2].x = rand() % 480;
//}
//
//struct {
//	double x;
//	double y;
//	int k = 0;
//} point;
//
//void DrawPoint(double x, double y)
//{
//	glPointSize(0.8f);
//	glColor3f(1, 0, 0);
//	glBegin(GL_POINTS);
//	glVertex2f(x, y);
//	glVertex2f(x, y);
//	glEnd();
//}
//
//struct {
//	double x;
//	double y;
//	
//} finish_point[3];
//
//void DrawFinish() {
//	for (int i = 0; i < 3; ++i)
//		DrawPoint(finish_point[i].x, finish_point[i].y);
//}
//
//void move() {
//	
//	int dice_number = rand() % 15 + 1;
//	
//	if (dice_number < 4) {
//		double Ax = finish_point[0].x - point.x;
//		double Ay = finish_point[0].y - point.y;
//		double length_xy = abs(pow(Ax, 2) + pow(Ay, 2));
//		point.x += Ax / length_xy * 0.5;
//		point.y += Ay / length_xy * 0.5;
//		// определять координаты новой точки
//	}
//	else if (dice_number < 7) {}
//	else if (dice_number < 10) {}
//	else if (dice_number < 13) {}
//	else {}
//
//	++point.k;
//	if (point.k == 100)
//		exit(1);
//}
//
////struct {
////	int x;
////	int y;
////} snake[maxSnakeLength];
//
//// ???
//struct {
//	double x;
//	double y;
//} start_point;
//
//void DrawStart() {
//	DrawPoint(start_point.x, start_point.y);
//}
//
//void DrawFinish() {
//	DrawPoint(finish_point[0].x, finish_point[0].y);
//	DrawPoint(finish_point[1].x, finish_point[1].y);
//	DrawPoint(finish_point[2].x, finish_point[2].y);
//}
//
//void timer(int = 0) {
//	Display();
//	move();
//	glutTimerFunc(100, timer, 0);
//}
//
//
//
//void Display() {
//	glClear(GL_COLOR_BUFFER_BIT);
//	DrawStart();
//	DrawPoint(point.x, point.y);
//	DrawFinish();
//	glFlush();
//	glutSwapBuffers();
//}
//
//int main(int argc, char** argv)
//{
//	// N = 5 случайных точек, M = 15 граний кубика, R = 0.50;
//	// 1, 2, 3 грань - первая точка; 4, 5, 6 - вторая точка; 7, 8, 9 - третья; 10, 11, 12 - четвертая; 13, 14, 15 - пятая точка
//	srand(time(0));
//	Start();
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//
//	glutInitWindowSize(width, height);
//	glutCreateWindow("Number2_Variable56");
//	glClearColor(1.0, 1.0, 1.0, 1.0);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluOrtho2D(0, width, 0, height);
//	glutDisplayFunc(Display);
//	glutTimerFunc(100, timer, 0);
//	glutMainLoop();
//	return 0;
//}