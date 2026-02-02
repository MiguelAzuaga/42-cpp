#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"
#include <ostream>

class Point
{
private:
	const Fixed _x;
	const Fixed _y;

public:
	Point();
	~Point();
	Point(const float x, const float y);
	Point(const Point& other);

	const Fixed& getX(void) const;
	const Fixed& getY(void) const;
};
std::ostream& operator<<(std::ostream& out, const Point& value);

#endif // POINT_HPP
