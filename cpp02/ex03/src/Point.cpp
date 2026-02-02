#include "Point.hpp"

Point::Point() :_x(0), _y(0) {}

Point::~Point() {}

Point::Point(const Point& other) :_x(other._x), _y(other._y) {}

Point::Point(const float x, const float y) : _x(x), _y(y) {}

const Fixed& Point::getX(void) const { return this->_x; }

const Fixed& Point::getY(void) const { return this->_y; }

std::ostream& operator<<(std::ostream& out, const Point& value)
{
	out << "[" << value.getX() << "," << value.getY() << "]";
	return out;
}