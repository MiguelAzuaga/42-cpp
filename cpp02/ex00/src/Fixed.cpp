#include "Fixed.hpp"
#include <iostream>

const int Fixed::_fractBits = 8;

/// Constructors & Destructors
Fixed::Fixed(void) :_rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other): _rawBits(other._rawBits);
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(Fixed const& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->setRawBits(other.getRawBits());
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

/// Getters & Setters
int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_rawBits);
}

void Fixed::setRawBits(int const raw)
{
	this->_rawBits = raw;
}
