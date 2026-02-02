#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int Fixed::_fractBits = 8;

//> Constructors & Destructors
Fixed::Fixed(void) :_rawBits(0)
{}

Fixed::Fixed(const Fixed& other): _rawBits(other._rawBits)
{}

Fixed::Fixed(const int value): _rawBits(value << Fixed::_fractBits)
{}
Fixed::Fixed(const float value): _rawBits(static_cast<int>(roundf(value * (1 << Fixed::_fractBits))))
{}

Fixed::~Fixed()
{}

Fixed& Fixed::operator=(const Fixed& other)
{
	if (this != &other)
	this->_rawBits = other._rawBits;
return *this;
}

//> Comparison Operators
bool Fixed::operator>(const Fixed& other) const
{
	return this->getRawBits() > other.getRawBits();
}

bool Fixed::operator<(const Fixed& other) const
{
	return this->getRawBits() < other.getRawBits();
}
bool Fixed::operator>=(const Fixed& other) const
{
	return this->getRawBits() >= other.getRawBits();
}

bool Fixed::operator<=(const Fixed& other) const
{
	return this->getRawBits() <= other.getRawBits();
}

bool Fixed::operator==(const Fixed& other) const
{
	return this->getRawBits() == other.getRawBits();
}

bool Fixed::operator!=(const Fixed& other) const
{
	return this->getRawBits() != other.getRawBits();
}

//> Arithmetic Operators
Fixed Fixed::operator+(const Fixed& other) const
{
	Fixed result;
	result._rawBits = this->_rawBits + other._rawBits;
	return result;
}

Fixed Fixed::operator-(const Fixed& other) const
{
	Fixed result;
	result._rawBits = this->_rawBits - other._rawBits;
	return result;
}

Fixed Fixed::operator*(const Fixed& other) const
{
	long long tmp = static_cast<long long>(this->_rawBits) * static_cast<long long>(other._rawBits);
	Fixed result;
	result.setRawBits(tmp >> _fractBits);
	return result;
}

Fixed Fixed::operator/(const Fixed& other) const
{
	if (other._rawBits == 0)
	{
		throw std::runtime_error("Division by zero");
	}
	Fixed result;
	long long tmp = static_cast<long long>(this->_rawBits) << _fractBits;
	result.setRawBits(static_cast<int>(tmp / other._rawBits));
	return result;
}

//> Increment/Decrement Operators
Fixed& Fixed::operator++(void)
{
	// this->_rawBits += (1 << _fractBits);
	++this->_rawBits;
	return *this;
}

Fixed& Fixed::operator--(void)
{
	// this->_rawBits -= (1 << _fractBits);
	--this->_rawBits;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	// this->_rawBits += (1 << _fractBits);
	++this->_rawBits;
	return tmp;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	// this->_rawBits -= (1 << _fractBits);
	--this->_rawBits;
	return tmp;
}

//> Member functions
int Fixed::toInt( void ) const
{
	return (this->_rawBits >> Fixed::_fractBits);
}

float Fixed::toFloat( void ) const
{
	return (static_cast<float>(this->_rawBits) / (1 << this->_fractBits));
}

// Getters & Setters
int Fixed::getRawBits() const
{
	return this->_rawBits;
}

void Fixed::setRawBits(int const raw)
{
	this->_rawBits = raw;
}

// Min/Max Member Functions
Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a <= b)
		return a;
	return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a >= b)
		return a;
	return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    if (a <= b)
        return a;
    return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    if (a >= b)
        return a;
    return b;
}

std::ostream& operator<<(std::ostream& out, const Fixed& value)
{
	out << value.toFloat();
	return out;
}