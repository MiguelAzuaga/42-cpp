#include "Cat.hpp"
#include <iostream>

//> Orthodox Canonical Form

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		this->_type = other._type;
		std::cout << "Cat assignment operator called" << std::endl;
	}

	return *this;
}

//> Member Functions

void Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}