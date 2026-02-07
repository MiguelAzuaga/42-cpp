#include "Animal.hpp"
#include <iostream>

//> Orthodox Canonical Form

Animal::Animal() : _type("Default")
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(const std::string type) : _type(type)
{
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal& other) : _type(other._type)
{
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
	if (this != &other)
	{
		this->_type = other._type;
		std::cout << "Animal assignment operator called" << std::endl;
	}

	return *this;
}

//> Member Functions
void Animal::makeSound() const
{
	std::cout << "Animal sound" << std::endl;
}

//> Getters
const std::string& Animal::getType() const
{
	return this->_type;
}