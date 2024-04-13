#include "glut.h"
#include <stdlib.h>
#include <vector>
#include <iostream>

std::vector <int> x;
std::vector <int> y;
double n = 0;

void DrowPoint() {
	for (int i = 0; i < x.size(); ++i) {
		
		if ((-pow(x[i], 3) + pow(x[i], 3) < 2) &&
			(-x[i] + y[i] < 1) &&
			(-2 < x[i] < 2) &&
			(-2 < y[i] < 2)) {
			glBegin(GL_POINTS);
			glColor3f(1, 1, 0);
			glVertex2f(x[i], y[i]);
			glEnd();
		}
		else {
			
			glBegin(GL_POINTS);
			glColor3f(1, 0, 0);
			glVertex2f(x[i], y[i]);
			glEnd();
		}
		
	}
}


void Display(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	
	if (x.size() > 500) {
		std::cout << n / x.size() * 400;
		exit(1);
	}
	DrowPoint();
	
	x.push_back(rand() % 200 - 100);
	y.push_back(rand() % 200 - 100);
	if ((-pow(x.back(), 3) + pow(y.back(), 3) < 2) &&
		(-x.back() + y.back() < 1) &&
		(-2 < x.back() < 2) &&
		(-2 < y.back() < 2)) n++;
	glutSwapBuffers();
}
void timer(int = 0) {
	Display();
	glutTimerFunc(20, timer, 0);
}


int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(400, 400);
	glutCreateWindow("Num3");
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100, 100, -100, 100);
	glutDisplayFunc(Display);
	glutTimerFunc(10, timer, 0);
	glutMainLoop();

	return 0;
}