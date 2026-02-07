#include "AAnimal.hpp"
#include <iostream>

//> Orthodox Canonical Form

AAnimal::AAnimal() : _type("Default")
{
	std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor called" << std::endl;
}

AAnimal::AAnimal(const std::string type) : _type(type)
{
	std::cout << "AAnimal constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& other) : _type(other._type)
{
	std::cout << "AAnimal copy constructor called" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& other)
{
	if (this != &other)
	{
		this->_type = other._type;
		std::cout << "AAnimal assignment operator called" << std::endl;
	}

	return *this;
}

//> Getters
const std::string& AAnimal::getType() const
{
	return this->_type;
}