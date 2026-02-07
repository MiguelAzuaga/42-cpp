#include "Cat.hpp"
#include <iostream>

//> Orthodox Canonical Form

Cat::Cat() : AAnimal("Cat"), _brain(new Brain())
{
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::~Cat()
{
	delete this->_brain;
	std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(const Cat& other) : AAnimal(other)
{
	this->_brain = new Brain(*other._brain);
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		AAnimal::operator=(other);
		delete this->_brain;
		this->_brain = new Brain(*other._brain);
		std::cout << "Cat assignment operator called" << std::endl;
	}

	return *this;
}

//> Member Functions

void Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}

//> Getters & Setters

std::string Cat::getIdea(size_t index) const
{
	return this->_brain->getIdea(index);
}

void Cat::setIdea(size_t index, std::string idea)
{
	this->_brain->setIdea(index, idea);
}