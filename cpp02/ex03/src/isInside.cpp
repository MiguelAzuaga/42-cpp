#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

Fixed cross(const Point& l1, const Point& l2, const Point& point)
{
	// Cross product of AB and AC
	return (l2.getX() - l1.getX()) * (point.getY() - l1.getY()) - (l2.getY() - l1.getY()) * (point.getX() - l1.getX());
}

bool sameSide(const Point& l1, const Point& l2, const Point& vertex, const Point& point)
{
	Fixed cp1 = cross(l1, l2, vertex);
	Fixed cp2 = cross(l1, l2, point);

	// Points on the line (cross == 0) are considered on the same side.
	return (cp1 * cp2) >= Fixed(0);
}

// If triangle is a line, p must be collinear and within the bounding box
bool checkCollinear(const Point A, const Point B, const Point C, const Point p)
{
	// Check if p is not collinear with AB
	if (cross(A, B, p).getRawBits() != 0)
	{
		return false;
	}

	// Use Fixed::min/max helpers to compute bounding box
	const Fixed& minX = Fixed::min(Fixed::min(A.getX(), B.getX()), C.getX());
	const Fixed& maxX = Fixed::max(Fixed::max(A.getX(), B.getX()), C.getX());
	const Fixed& minY = Fixed::min(Fixed::min(A.getY(), B.getY()), C.getY());
	const Fixed& maxY = Fixed::max(Fixed::max(A.getY(), B.getY()), C.getY());

	if (p.getX() >= minX && p.getX() <= maxX && p.getY() >= minY && p.getY() <= maxY)
	{
		return true;
	}

	return false;
}

bool isInside(const Point A, const Point B, const Point C, const Point p)
{
	bool result = false;
	// Check degenerate (collinear) triangle
	if (cross(A, B, C).getRawBits() == 0)
	{
		result = checkCollinear(A, B, C, p);
	}
	else if (sameSide(A, B, C, p) && sameSide(B, C, A, p) && sameSide(C, A, B, p))
	{
		result = true;
	}
	if (result == true)
	{
		std::cout << "Point:" << p;
		std::cout << " is inside the " << A << B << C << " Triangle!" << std::endl;
	}
	else
	{
		std::cout << "NOPE!" << std::endl;
	}

	return result;
}
