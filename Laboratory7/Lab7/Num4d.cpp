//#include "glut.h"
//#include <stdlib.h>
//#include <vector>
//#include <iostream>
//#include <cmath>
//
//std::vector <double> x;
//std::vector <double> y;
//const double p = 3.1415;
//std::vector <double> xr;
//std::vector <double> yr;
//int n = 0;
//int N = 0;
//
//void DrowGraf() {
//	glColor3f(1.0f, 1.0f, 1.0f);
//	glPointSize(1.5f);
//	for (int i = 0; i < x.size(); ++i) {
//		glBegin(GL_POINTS);
//		glVertex2f(x[i], y[i]);
//		glEnd();
//	}
//}
//
//
//
//void DrowRandomPoint() {
//
//	xr.push_back(((double)(rand() % 2000) - 1000) / 100);
//	yr.push_back(((double)(rand() % 2000) - 1000) / 100);
//	double function_y = 1 / (sqrt(12 * xr.back() + 9 * pow(xr.back(), 2) + 2));
//	for (int i = 0; i < xr.size(); ++i) {
//		if ((((0 <= yr[i] && yr[i] <= 1 / (sqrt(12 * xr[i] + 9 * pow(xr[i], 2) + 2))))
//			|| (yr[i] <= 0 && yr[i] >= 1 / (sqrt(12 * xr[i] + 9 * pow(xr[i], 2) + 2))))
//			&& (0 <= xr[i] && xr[i] <= 9)) {
//			glBegin(GL_POINTS);
//			glColor3f(1, 0, 0);
//			glVertex2f(xr[i], yr[i]);
//			glEnd();
//		}
//		else {
//			glBegin(GL_POINTS);
//			glColor3f(0, 1, 0);
//			glVertex2f(xr[i], yr[i]);
//			glEnd();
//		}
//	}
//	if (yr.back() < function_y && 0 <= yr.back() && (0 < xr.back() && xr.back() < 9)) n++;
//	else if (yr.back() < 0 && function_y <= yr.back() && (0 < xr.back() && xr.back() < 9)) n--;
//}
//
//void DrowLines() {
//	glColor3f(1.0f, 1.0f, 1.0f);
//	glBegin(GL_LINES);
//	glVertex2f(-10, 0);
//	glVertex2f(10, 0);
//	glVertex2f(0, 10);
//	glVertex2f(0, -10);
//	glEnd();
//}
//
//void renderScene(void) {
//	if (N > 10000) {
//		std::cout << "Answer: " << "0.9439" << std::endl;
//		std::cout << "Metod Monte-Karlo: " << (double)n / (double)N * 400;
//		exit(1);
//	}
//	++N;
//	glClear(GL_COLOR_BUFFER_BIT);
//	DrowLines();
//	DrowGraf();
//	DrowRandomPoint();
//	glutSwapBuffers();
//}
//
//void Start() {
//	x.push_back(0);
//	y.push_back(1 / (sqrt(12*x.back() + 9 * pow(x.back(), 2) + 2)));
//	for (int i = 0; i < 900; i += 1) { // координаты графика
//		x.push_back(x.back() += 0.01);
//		y.push_back(1 / (sqrt(12 * x.back() + 9 * pow(x.back(), 2) + 2)));
//	}
//}
//
//int main(int argc, char** argv) {
//
//	Start();
//
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
//	glClearColor(0, 1, 1, 1.0);
//	glutInitWindowPosition(100, 100);
//	glutInitWindowSize(400, 400);
//	glutCreateWindow("Num4_a");
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluOrtho2D(-10, 10, -10, 10); // нормальные координаты а не через float
//	glutDisplayFunc(renderScene);
//	glutIdleFunc(renderScene);
//
//	glutMainLoop();
//
//	// sin(2) / 2 + cos(2)
//	return 0;
//}