#include "WrongAnimal.hpp"
#include <iostream>

//> Orthodox Canonical Form

WrongAnimal::WrongAnimal() : _type("Default")
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string type) : _type(type)
{
	std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : _type(other._type)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	if (this != &other)
	{
		this->_type = other._type;
		std::cout << "WrongAnimal assignment operator called" << std::endl;
	}

	return *this;
}

//> Member Functions
void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal sound" << std::endl;
}

//> Getters
const std::string& WrongAnimal::getType() const
{
	return this->_type;
}