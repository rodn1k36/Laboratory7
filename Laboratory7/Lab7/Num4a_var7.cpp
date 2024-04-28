//#include "glut.h"
//#include <stdlib.h>
//#include <vector>
//#include <iostream>
//#include <cmath>
//
//std::vector <double> x;
//std::vector <double> y;
//
//std::vector <double> xr;
//std::vector <double> yr;
//int n = 0;
//int N = 0;
//int m = 0;
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
//	xr.push_back((double)(rand() % 200 - 100) / 100); // прямоугольник 2 * 2
//	yr.push_back((double)(rand() % 200 - 100) / 100);
//	double function_y = pow(xr.back(), 2) * cos(2 * xr.back());
//	for (int i = 0; i < xr.size(); ++i) {
//		if (yr[i] <= pow(xr[i], 2) * cos(2 * xr[i]) && 0 <= yr[i] || yr[i] <= 0 && pow(xr[i], 2) * cos(2 * xr[i]) <= yr[i]) {
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
//	if (yr.back() <= function_y && 0 <= yr.back()) n++;
//	else if (yr.back() <= 0 && function_y <= yr.back()) n--;
//}
//
//void DrowLines() {
//	glColor3f(1.0f, 1.0f, 1.0f);
//	glBegin(GL_LINES);
//	glVertex2f(-10, 0);
//	glVertex2f(10, 0); //1.07
//	glVertex2f(0, 10);
//	glVertex2f(0, -10);
//	glEnd();
//}
//
//void renderScene(void) {
//	if (N > 1000) {
//		std::cout << "Answer: " << "0.0385019" << std::endl;
//		std::cout << "Metod Monte-Karlo: " << (double)n / (double)N * 4;
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
//	x.push_back(-1.01);
//	y.push_back(pow(x.back(), 2) * cos(2 * x.back()));
//	for (int i = 0; i < 200; ++i) { // координаты графика
//		x.push_back(x.back() += 0.01);
//		y.push_back(x.back() * x.back() * cos(2 * x.back()));
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
//	gluOrtho2D(-1, 1, -1, 1); // нормальные координаты а не через float
//	glutDisplayFunc(renderScene);
//	glutIdleFunc(renderScene);
//
//	glutMainLoop();
//
//	// sin(2) / 2 + cos(2)
//	return 0;
//}