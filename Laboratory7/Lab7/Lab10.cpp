#include <iostream>
#include "glut.h"
#include <vector>

struct Point {
	double x = 0;
	double y = 0;
	Point() = default;
	Point(double x, double y) : x(x), y(y) {};
	bool operator== (const Point& obj) const {
		return x == obj.x && y == obj.y;
	}
	bool operator!= (const Point& obj) const {
		return !(*this == obj);
	}
};

class Line {
private:
	Point P1;
	Point P2;
public:
	Line(const Point& P1, const Point& P2) : P1(P1), P2(P2) { 
		if (P1.x == P2.x || P1.y == P2.y)
			throw 1;
	}
	Line(const double k, const double b) {
		P1.x = 0;
		P1.y = k * P1.x + b;
	}
	Line(const Point& P, const double k) : P1(P) {
		double b = P.y - k * P.x;
		P2.x = P1.x + 10;
		P2.y = k * P2.x + b;
	}
	bool operator== (const Line& L) const {
		if ((L.P1.x - P1.x) / (P2.x - P1.x) == ((L.P1.y - P1.x) / (P2.y - P1.y))
			&& (L.P2.x - P1.x) / (P2.x - P1.x) == ((L.P2.y - P1.x) / (P2.y - P1.y)))
			return true;
		return false;
	}
	bool operator!= (const Line& L) const {
		return !(*this == L);
	}
};

class Shape {
public:
	virtual void Draw() = 0;
};

class Polygon : public Shape {
protected:
	std::vector <Point> vertices;
public:
	Polygon(std::vector <Point> vertices) : vertices(vertices) { };
	/*Polygon(...) {
		va_list args;
	}*/
	size_t verticesCount() {
		return vertices.size();
	}
	std::vector<Point> getVertices() const {
		return vertices;
	}
	bool isConvex() {
		double SumAngle = 0;
		for (int i = 0; i < vertices.size(); ++i) {
			// угол A B C ( B в центре, A предыдушая точка, В следующая )
			if (i == 0)
			{
				double BA[2] = { vertices[vertices.size() - 1].x - vertices[i].x,
				vertices[vertices.size() - 1].y - vertices[i].y };
				double BC[2] = { vertices[i + 1].x - vertices[i].x,
				vertices[i + 1].y - vertices[i].y };
				double scalar_BA_BC = BA[0] * BC[0] + BA[1] * BC[1];
				double lenBA = sqrt(BA[0] * BA[0] + BA[1] * BA[1]);
				double lenBC = sqrt(BC[0] * BC[0] + BC[1] * BC[1]);
				SumAngle += acos(scalar_BA_BC / lenBA * lenBC);
			}
			else if (i == vertices.size())
			{
				double BA[2] = { vertices[i - 1].x - vertices[i].x,
				vertices[i - 1].y - vertices[i].y };
				double BC[2] = { vertices[0].x - vertices[i].x,
				vertices[0].y - vertices[i].y };
				double scalar_BA_BC = BA[0] * BC[0] + BA[1] * BC[1];
				double lenBA = sqrt(BA[0] * BA[0] + BA[1] * BA[1]);
				double lenBC = sqrt(BC[0] * BC[0] + BC[1] * BC[1]);
				SumAngle += acos(scalar_BA_BC / lenBA * lenBC);
			}
			else {
				double BA[2] = { vertices[i - 1].x - vertices[i].x,
				vertices[i - 1].y - vertices[i].y };
				double BC[2] = { vertices[i + 1].x - vertices[i].x,
				vertices[i + 1].y - vertices[i].y };
				double scalar_BA_BC = BA[0] * BC[0] + BA[1] * BC[1];
				double lenBA = sqrt(BA[0] * BA[0] + BA[1] * BA[1]);
				double lenBC = sqrt(BC[0] * BC[0] + BC[1] * BC[1]);
				SumAngle += acos(scalar_BA_BC / lenBA * lenBC);
			}
		}
		return SumAngle * 180 / 3.1415 == 180;
	}
};

class Ellipse : public Shape {
private:
	std::pair<Point, Point> focuses;
	double r;
public:
	Ellipse(const Point& P1, const Point& P2, double r) : focuses({ P1, P2 }), r(r) {};
	std::pair<Point, Point> focuses() {
		return focuses;
	}
	/*std::pair<Line, Line> directrices() {

	}
	double eccentricity() {

	}
	Point center() {

	} */
};

void renderScene() {
	glClear(GL_COLOR_BUFFER_BIT);

	glFlush();
}

void glutAddMenuEntry(char* name, int value) {

}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glClearColor(0, 1, 1, 1);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(400, 400);
	glutCreateWindow("Laboratory №10");
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-200, 200, -200, 200);
	glutDisplayFunc(renderScene);

	int glutCreateMenu(void glutAddMenuEntry());
	glutMainLoop();

	return 0;
}