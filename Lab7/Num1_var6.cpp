//#include "glut.h"
//#include <fstream>
//#include <string>
//#include <vector>
//#include <iostream>
//
//int WinWidth = 640,
//WinHeight = 480;
//int WinFar = 10;
//int xx, yy, xxx, yyy;
//
//
//void DrawPoint(int x, int y)
//{
//	glPointSize(5.0f);
//	glColor3f(0, 0, 0);
//	glBegin(GL_POINTS);
//	glVertex2f(x, y);
//	glVertex2f(x, y);
//	glEnd();
//}
//
//void DrawLine(int x1, int y1, int x2, int y2) {
//	glLineWidth(6);
//	glColor3f(0, 0, 0);
//	glBegin(GL_LINES);
//	glVertex2f(x1, y1);
//	glVertex2f(x2, y2);
//	glEnd();
//}
//
//struct Point {
//	int x;
//	int y;
//};
//
//std::vector <Point> Points;
//
//void Display() {
//	glClear(GL_COLOR_BUFFER_BIT);
//	DrawLine(-100, 0, 100, 0);
//	DrawLine(0, -100, 0, 100);
//	for (int i = 0; i < Points.size(); ++i){
//		DrawPoint(Points[i].x, Points[i].y);
//	}
//	DrawLine(xx, yy, xxx, yyy);
//	glEnd();
//	glFlush();
//}
//
//void Start() {
//	std::ifstream in("input.txt");
//
//	while (!in.eof()) {
//		Point temp;
//		std::string x, y;
//		in >> x;
//		in >> y;
//		temp.x = atoi(x.c_str());
//		temp.y = atoi(y.c_str());
//		Points.push_back(temp);
//	}
//	in.close();
//
//	if (Points.size() > 1) {
//		int is_up = 0;
//		int is_down = 0;
//		int diff = 10000;
//		for (int i = 0; i < Points.size() - 1; ++i) {
//			for (int j = i + 1; j < Points.size(); ++j) {
//				int ij_x = Points[j].x - Points[i].x;
//				int ij_y = Points[j].y - Points[i].y;
//				for (int l = 0; l < Points.size(); ++l) {
//					int normal_equation = ij_y * (Points[l].x - Points[i].x) - ij_x * (Points[l].y - Points[i].y);
//					if (normal_equation > 0) ++is_up;
//					else if (normal_equation < 0) ++is_down;
//				}
//				if (diff > abs(is_up - is_down)) {
//					diff = abs(is_up - is_down);
//					/*x1 =  Points[i].x;
//					y1 = Points[i].y;
//					x2 = Points[j].x;
//					y2 = Points[j].y;*/
//					xx = 100;
//					Points[j].x - Points[i].x != 0 ? yy = ij_y * (xx - Points[i].x) / (Points[j].x - Points[i].x) + Points[i].y : yy = 100, xx = Points[i].x;
//					xxx = -100;
//					Points[j].x - Points[i].x != 0 ? yyy = ij_y * (xxx - Points[i].x) / (Points[j].x + Points[i].x) + Points[i].y : yyy = -100, xxx = Points[j].x;
//
//				}
//				is_up = 0;
//				is_down = 0;
//			}
//		}
//	}
//	else {
//		exit(0);
//		std::cout << "incorrect value";
//	}
//}
//
//int main(int argc, char** argv)
//{
//	Start();
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glutInitWindowSize(WinWidth, WinHeight);
//	glutInitWindowPosition(150, 150);
//	glutCreateWindow("Lesson 01");
//	glClearColor(1, 1, 1, 1.0);
//	glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluOrtho2D(-100.0, 100.0, -100.0, 100.0);
//	
//	glutDisplayFunc(Display);
//
//	glutMainLoop();
//	return 0;
//}