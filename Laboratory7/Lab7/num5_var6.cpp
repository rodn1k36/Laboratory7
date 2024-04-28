//#include "glut.h"
//#include <stdlib.h>
//#include <iostream>
//#include <cmath>
//
//int n, king, horse;
//int quare_size = 10;
//int count = 1;
//
//void DrawQuads(int left_up_x, int left_up_y) {
//    glBegin(GL_QUADS);
//    glVertex2f(left_up_x, left_up_y);
//    glVertex2f(left_up_x + quare_size, left_up_y);
//    glVertex2f(left_up_x + quare_size, left_up_y - quare_size);
//    glVertex2f(left_up_x, left_up_y - quare_size);
//    glEnd();
//}
//
//void DrawLineLoop(int left_up_x, int left_up_y) {
//    glLineWidth(2);
//    glColor3f(0, 0, 0);
//    glBegin(GL_LINE_LOOP);
//    glVertex2f(left_up_x, left_up_y);
//    glVertex2f(left_up_x + quare_size, left_up_y);
//    glVertex2f(left_up_x + quare_size, left_up_y - quare_size);
//    glVertex2f(left_up_x, left_up_y - quare_size);
//    glEnd();
//}
//
//void DrawPoint(int x, int y) {
//    glPointSize(6);
//    glBegin(GL_POINTS);
//    glVertex2f(x, y);
//    glEnd();
//}
//
////bool HorseMove(int vertical, int gorizontal, int count) {
////    int move_vtc[3] = { -2, -2, -1 };
////    int move_grzt[3] = { -1, 1, -2 };
////    for (int i = 0; i < 3; ++i) {
////        if (horse / n + move_vtc[i] == vertical && horse % n + horse / n + move_grzt[i] == gorizontal)
////            return true;
////    }
////    return false;
////}
////
////bool KingMove(int vertical, int gorizontal, int count) {
////    int move_vtc[8] = { 1, 1, 1, 0, 0, -1, -1, -1 };
////    int move_grzt[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
////    for (int i = 0; i < 8; ++i) {
////        if (king / n + move_vtc[i] == vertical && king % n + king / n + move_grzt[i] == gorizontal)
////            return true;
////    }
////    return false;
////}
//int dx[] = { 2, 1, -1, -2, -2, -1, 1, 2 };
//int dy[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
//
//bool isValid(int x, int y, int n, int k) {
//    return x > y + dy[k] && x <= n && y >= 0 && y < n;
//}
//void HorseMove() {
//    int i = horse / n;
//    int j = i + (horse - 1) % 7;
//    for (int k = 0; k < 8; k++) {
//           int x = i + dx[k];
//           int y = j + dy[k];
//         if (isValid(x, y, n, k)) {
//              glColor3f(1, 0, 0);
//              DrawPoint(j * quare_size + 7, -(i * quare_size + 5));
//         }
//    }
//}
//
//void DrawField() {
//    bool flag = true;
//
//    for (int i = 0; i < n; i++) {
//        for (int j = i; j < n + i; j++, count++) {
//            /*if (HorseMove(i, j, count)) {
//                glColor3f(1, 0, 0);
//                DrawPoint(j * quare_size + 7, -(i * quare_size + 5));
//            }
//            if (KingMove(i, j, count)) {
//                glColor3f(0, 1, 1);
//                DrawPoint(j * quare_size + 7, -(i * quare_size + 5));
//            }*/
//            if (count == horse) {
//                glColor3f(1, 0, 0); // красная лошадь
//                DrawQuads(j * 10, -i * 10);
//            }
//            if (count == king) {
//                glColor3f(0, 1, 1); // голубой король
//                DrawQuads(j * 10, -i * 10);
//            }
//            DrawLineLoop(j * 10, -i * 10);
//            glRasterPos2f(j * quare_size + 7, -(i * quare_size + 5));
//            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, count % 10 + 48);
//            if (i * n + j > 9) {
//                glRasterPos2f(j * quare_size + 2, -(i * quare_size + 5));
//                glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, count / 10 + 48);
//            }
//
//            
//            /*int arr[8] = { -2 * n + 1, -2 * n + 3, -n - 1, -n + 4, n - 4, n + 1, 2 * n - 1, 2 * n - 4 };
//
//            if (horse + arr[0] <= (i+1 - 2) * n && count == horse + arr[0]) {
//                DrawPoint(j * 10 + 5, -i * 10 - 5);
//            }*/
//
//
//        }
//    }
//    glFlush();
//}
// //8 king 12 horse
////bool HorseMove(int count) {
////    int arr[8] = { -2 * n + 1, -2 * n + 3, -n - 1, -n + 4, n - 4, n + 1, 2 * n - 1, 2 * n - 4 };
////    for (int i = 0; i < 8; ++i) {
////        if (count + arr[i] < i * n + j + i) {
////            return true;
////        }
////    }
////    return false;
////}
//
//void Display(void) {
//    glClear(GL_COLOR_BUFFER_BIT);
//    DrawField();
//    HorseMove();
//    glFlush();
//}
//
//int main(int argc, char** argv) {
//    std::cout << "Enter n: ";
//    std::cin >> n;
//    std::cout << "Enter king cell: \n";
//    std::cin >> king;
//    std::cout << "Enter horse cell: \n";
//    std::cin >> horse;
//    if (king == horse || king > n * n || horse > n * n) {
//        std::cout << "Enter correct cell";
//        exit(0);
//    }
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//    glutInitWindowSize(800, 800);
//    glutCreateWindow("Num5_var6");
//    glClearColor(1, 1, 1, 0);
//    glMatrixMode(GL_PROJECTION);
//    gluOrtho2D(0, 200, -200, 0);
//    glutDisplayFunc(Display);
//
//    glutMainLoop();
//
//    return 0;
//}
