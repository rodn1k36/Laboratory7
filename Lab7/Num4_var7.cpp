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
//
//void DrowGraf() {
//	glPointSize(1.5f);
//	for (int i = 0; i < x.size(); ++i) {
//		glBegin(GL_POINTS);
//		glVertex2f(x[i], y[i]);
//		glEnd();
//	}
//}
//
//void DrowRandomPoint() {
//	double x = (double)(rand() % 200 - 100) / 100;
//	double y = (double)(rand() % 200 - 100) / 100;
//	double function_y = (pow(x, 2) * sin(2 * x) + cos(2 * x) * x) / 2 - 0.25 * sin(2 * x);
//
//	if (function_y > 0) {
//		if (0 <= y <= function_y) n++;
//	}
//	else
//		if (function_y <= y <= 0) n++;
//
//	glPointSize(1.5f);
//	glBegin(GL_POINTS);
//	glVertex2f(x, y);
//	glEnd();
//}
//
//void DrowLines() {
//	glBegin(GL_LINES);
//	glVertex2f(-10, 0);
//	glVertex2f(10, 0);
//	glVertex2f(0, 10);
//	glVertex2f(0, -10);
//	glEnd();
//}
//
//void renderScene(void) {
//	if (N > 100) {
//		std::cout << "Answer: " << sin(2) / 2 + cos(2) << std::endl;
//		std::cout << "Metod Monte-Karlo: " << (double)n / (double)N;
//		exit(1);
//	}
//	N++;
//	glClear(GL_COLOR_BUFFER_BIT);
//	glColor3f(1.0f, 1.0f, 1.0f);
//	DrowLines();
//	DrowGraf();
//	glColor3f(1.0f, 1.0f, 1.0f);
//	DrowRandomPoint();
//	glutSwapBuffers();
//}
//
//int main(int argc, char** argv) {
//
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
//	glutInitWindowPosition(100, 100);
//	glutInitWindowSize(400, 400);
//	glutCreateWindow("Num4_a");
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluOrtho2D(-1, 1, -1, 1); // нормальные координаты а не через float
//
//	x.push_back(-1);
//	y.push_back((pow(x.back(), 2) * sin(2 * x.back()) +
//		cos(2 * x.back()) * x.back()) / 2 - 0.25 * sin(2 * x.back()));
//	for (int i = 0; i < 200; ++i) {
//		x.push_back(x.back()+=0.01);
//		y.push_back((pow(x.back(), 2) * sin(2 * x.back()) +
//			cos(2 * x.back()) * x.back()) / 2 - 0.25 * sin(2 * x.back()));
//	}
//	glutDisplayFunc(renderScene);
//	glutIdleFunc(renderScene);
//
//	glutMainLoop();
//	// sin(2) / 2 + cos(2)
//	return 0;
//}