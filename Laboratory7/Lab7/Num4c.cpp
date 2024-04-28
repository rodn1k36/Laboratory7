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
//double n = 0;
//double N = 0;
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
//	double function_y = xr.back() * pow(3, xr.back());
//	for (int i = 0; i < xr.size(); ++i) {
//		if ((((0 <= yr[i] && yr[i] <= xr[i] * pow(3, xr[i])))
//				|| (yr[i] <= 0 && yr[i] >= xr[i] * pow(3, xr[i])))
//			&& (-2 <= xr[i] && xr[i] <= 2)) {
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
//	if (yr.back() <= function_y && 0 <= yr.back() && (-2 <= xr.back() && xr.back() <= 2)) n++;
//	else if (yr.back() <= 0 && function_y <= yr.back() && (-2 <= xr.back() && xr.back() <= 2)) n++;
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
//	if (N > 5000) {
//		std::cout << "Answer: " << "9.2218" << std::endl;
//		std::cout << "Metod Monte-Karlo: " << n / N * 400;
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
//	x.push_back(-2);
//	y.push_back(x.back() * pow(3, x.back()));
//	for (int i = 0; i < 400; i += 1) { // координаты графика
//		x.push_back(x.back() += 0.01);
//		y.push_back(x.back() * pow(3, x.back()));
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
//	glutCreateWindow("Num4_c");
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