#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int Fixed::_fractBits = 8;

/// Constructors & Destructors
Fixed::Fixed(void) :_rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other): _rawBits(other._rawBits)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(const int value): _rawBits(value << Fixed::_fractBits)
{
	std::cout << "Int constructor called" << std::endl;
}
Fixed::Fixed(const float value): _rawBits(static_cast<int>(roundf(value * (1 << Fixed::_fractBits))))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_rawBits = other._rawBits;
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

/// Member functions
int Fixed::toInt( void ) const
{
	return (this->_rawBits >> Fixed::_fractBits);
}

float Fixed::toFloat( void ) const
{
	return (static_cast<float>(this->_rawBits) / (1 << this->_fractBits));
}

/// Getters & Setters
int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_rawBits;
}

void Fixed::setRawBits(int const raw)
{
	this->_rawBits = raw;
}


std::ostream& operator<<(std::ostream& out, const Fixed& value)
{
	out << value.toFloat();
	return out;
}