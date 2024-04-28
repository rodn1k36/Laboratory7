//#include "glut.h"
//#include <fstream>
//#include <string>
//#include <vector>
//#include <iostream>
//
//int WinWidth = 640,
//WinHeight = 480;
//int WinFar = 10;
//int  line_x1;
//int line_x2;
//int line_y1;
//int line_y2;
//
//std::vector <int> x;
//std::vector <int> y;
//
//void DrawPoint(int x, int y)
//{
//	glPointSize(5.0f);
//	glColor3f(1, 0, 0);
//	glBegin(GL_POINTS);
//	glVertex2f(x, y);
//	glEnd();
//}
//
//void DrawLine(int x1, int y1, int x2, int y2) {
//	glLineWidth(3);
//	glColor3f(0, 0, 0);
//	glBegin(GL_LINES);
//	glVertex2f(x1, y1);
//	glVertex2f(x2, y2);
//	glEnd();
//}
//
//
//
//void Display() {
//	glClear(GL_COLOR_BUFFER_BIT);
//	DrawLine(-100, 0, 100, 0);
//	DrawLine(0, -100, 0, 100);
//	for (int i = 0; i < x.size(); ++i){
//		DrawPoint(x[i], y[i]);
//	}
//	DrawLine(line_x1, line_y1, line_x2, line_y2);
//	glFlush();
//}
//
//void Start() {
//	std::ifstream in("input.txt");
//
//	while (!in.eof()) {
//		std::string tmp_x, tmp_y;
//		in >> tmp_x;
//		in >> tmp_y;
//		x.push_back ( atoi(tmp_x.c_str()) );
//		y.push_back ( atoi(tmp_y.c_str()) );
//	}
//	in.close();
//
//	if (x.size() > 1 && y.size() > 1 ){
//		int is_up = 0;
//		int is_down = 0;
//		int diff = 10000;
//		for (int i = 0; i < x.size() - 1; ++i) {
//			for (int j = i + 1; j < x.size(); ++j) {
//				int ij_x = x[j] - x[i];
//				int ij_y = y[j] - y[i];
//				for (int l = 0; l < x.size(); ++l) {
//					int normal_equation = ij_y * (x[l] - x[i]) - ij_x * (y[l] - y[i]);
//					if (normal_equation > 0) is_up++;
//					else if (normal_equation < 0) is_down++;
//				}
//				if (diff > abs(is_up - is_down)) {
//					diff = abs(is_up - is_down);
//					line_x1 =  x[i];
//					line_y1 = y[i];
//					line_x2 = x[j];
//					line_y2 = y[j];
//					/*line_x1 = x[i];
//					x[j] - x[i] != 0 ? line_y1 = ij_y * (line_x1 - x[i]) / (x[j] - x[i]) + y[i] : line_y1 = y[i];
//					line_x2 = x[j];
//					x[j] - x[i] != 0 ? line_y2 = ij_y * (line_x2 - x[i]) / (x[j] + x[i]) + y[i] : line_y2 = y[j];*/
//
//				}
//				is_up = 0;
//				is_down = 0;
//			}
//		}
//	}
//	else {
//		exit(1);
//		std::cout << "incorrect value";
//	}
//}
//
//
//int main(int argc, char** argv)
//{
//	Start();
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glutInitWindowSize(WinWidth, WinHeight);
//	glutInitWindowPosition(150, 150);
//	glutCreateWindow("Num1");
//	glClearColor(1, 1, 1, 0);
//	glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluOrtho2D(-100.0, 100.0, -100.0, 100.0);
//	
//	glutDisplayFunc(Display);
//
//	glutMainLoop();
//	return 0;
//}