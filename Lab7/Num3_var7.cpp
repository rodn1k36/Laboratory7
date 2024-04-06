//#include "glut.h"
//#include <stdlib.h>
//#include <vector>
//#include <iostream>
//
//std::vector <int> x;
//std::vector <int> y;
//int n = 0;
//
//void DrowPoint(std::vector <int>& x, std::vector <int>& y) {
//	for (int i = 0; i < x.size(); ++i) {
//		glBegin(GL_POINTS);
//		glVertex2f(x[i], y[i]);
//		glEnd();
//		
//	}
//}
//
//void renderScene(void) {
//	if (x.size() > 500) {
//		std::cout << (double)x.size() / (double)n;
//		exit(1);
//	}
//	x.push_back(rand() % 200 - 100);
//	y.push_back(rand() % 200 - 100);
//	if (-pow(x.back(), 3) + pow(y.back(), 3) < 2 &&
//		-x.back() + y.back() < 1 &&
//		-2 < x.back() < 2 &&
//		-2 < y.back() < 2) n++;
//	glClear(GL_COLOR_BUFFER_BIT);
//	glColor3f(1.0f, 1.0f, 1.0f);
//
//	glEnd();
//	DrowPoint(x, y);
//	glutSwapBuffers();
//}
//
//int main(int argc, char** argv) {
//	
//	// инициализаци€
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
//	glutInitWindowPosition(100, 100);
//	glutInitWindowSize(400, 400);
//	glutCreateWindow("Num3");
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluOrtho2D(-100, 100, -100, 100); // нормальные координаты а не через float
//	// регистраци€ обратных вызовов
//	glutDisplayFunc(renderScene);
//	glutIdleFunc(renderScene);
//	// ќсновной цикл GLUT
//	glutMainLoop();
//	return 0;
//}