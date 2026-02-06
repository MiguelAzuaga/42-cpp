#include "Dog.hpp"
#include <iostream>

//> Orthodox Canonical Form

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		this->_type = other._type;
		std::cout << "Dog assignment operator called" << std::endl;
	}

	return *this;
}

//> Member Functions

void Dog::makeSound() const
{
	std::cout << "Woof Woof" << std::endl;
}