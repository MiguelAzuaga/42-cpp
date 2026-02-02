#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>
#include <string>

// ANSI color codes
static const char* C_RST = "\033[0m";
static const char* C_RED = "\033[31m";
static const char* C_GRN = "\033[32m";
static const char* C_YEL = "\033[33m";
static const char* C_CYN = "\033[36m";
static const char* C_MAG = "\033[35m";

bool isInside(const Point A, const Point B, const Point C, const Point p);

void runCase(const Point& A, const Point& B, const Point& C, const Point& p, const std::string& desc, bool expected)
{
	static int i = 0;

	i++;
	std::cout << C_MAG << "[CASE " << i << "]" << C_RST << desc << "\n";
	std::cout << C_CYN << "Triangle: " << C_RST << A << B << C << "\n";
	std::cout << C_CYN << "Point: " << C_RST << p << " -> ";
	bool res = isInside(A, B, C, p);
	if (res)
		std::cout << C_GRN << "Result: INSIDE" << C_RST;
	else
		std::cout << C_RED << "Result: OUTSIDE" << C_RST;
	std::cout << " | Expected: ";
	std::cout << (expected ? std::string(C_GRN) + "INSIDE" + C_RST : std::string(C_RED) + "OUTSIDE" + C_RST);
	std::cout << "\n\n";
}

void tester()
{
	std::cout << C_YEL << "=== isInside Comprehensive Tester ===" << C_RST << "\n\n";

	//> Simple right triangle
	Point A(0.0f, 0.0f);
	Point B(0.0f, 4.0f);
	Point C(3.0f, 0.0f);

	runCase(A, B, C, Point(1.0f, 1.0f), "Point clearly inside", true);
	runCase(A, B, C, Point(3.0f, 0.0f), "Point on vertex C", true);
	runCase(A, B, C, Point(0.0f, 2.0f), "Point on edge AB (mid) ", true);
	runCase(A, B, C, Point(1.5f, 0.0f), "Point on edge AC (mid)", true);
	runCase(A, B, C, Point(-1.0f, -1.0f), "Point clearly outside (below-left)", false);
	runCase(A, B, C, Point(2.9f, 0.1f), "Point very near edge but inside", true);
	runCase(A, B, C, Point(2.9f, 0.5f), "Point near edge but outside", false);

	//> All vertices on the same line
	Point D(0.0f, 0.0f);
	Point E(1.0f, 1.0f);
	Point F(2.0f, 2.0f);

	runCase(D, E, F, Point(1.0f, 1.0f), "Degenerate triangle, point at middle vertex", true);
	runCase(D, E, F, Point(3.0f, 3.0f), "Degenerate triangle, collinear outside segment", false);

	//> Large coordinates and negative coordinates
	Point G(-10.0f, -10.0f);
	Point H(10.0f, -10.0f);
	Point I(0.0f, 20.0f);

	runCase(G, H, I, Point(0.0f, 0.0f), "Large triangle, center point", true);
	runCase(G, H, I, Point(0.0f, -11.0f), "Point just below base (outside)", false);

	//> Thin triangle: near-collinear but valid
	Point J(0.0f, 0.0f);
	Point K(100.0f, 0.001f);
	Point L(200.0f, 0.0f);

	runCase(J, K, L, Point(100.0f, 0.0005f), "Thin triangle, point inside tiny height", true);
	runCase(J, K, L, Point(100.0f, 0.002f), "Thin triangle, point outside above", false);

	std::cout << C_YEL << "=== Tester Complete ===" << C_RST << "\n";
}

int main(void)
{
	tester();
	return 0;
}