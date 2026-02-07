#include "WrongCat.hpp"
#include <iostream>

//> Orthodox Canonical Form

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
	if (this != &other)
	{
		this->_type = other._type;
		std::cout << "WrongCat assignment operator called" << std::endl;
	}

	return *this;
}

//> Member Functions

void WrongCat::makeSound() const
{
	std::cout << " WrongCat Meow" << std::endl;
}