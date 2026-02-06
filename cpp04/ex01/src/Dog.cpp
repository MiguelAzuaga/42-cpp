#include "Dog.hpp"
#include <iostream>

//> Orthodox Canonical Form

Dog::Dog() : Animal("Dog"), _brain(new Brain())
{
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::~Dog()
{
	delete this->_brain;
	std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
	this->_brain = new Brain(*other._brain);
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		delete this->_brain;
		this->_brain = new Brain(*other._brain);
		std::cout << "Dog assignment operator called" << std::endl;
	}

	return *this;
}

//> Member Functions

void Dog::makeSound() const
{
	std::cout << "Woof Woof" << std::endl;
}

//> Getters & Setters

std::string Dog::getIdea(size_t index) const
{
	return this->_brain->getIdea(index);
}

void Dog::setIdea(size_t index, std::string idea)
{
	this->_brain->setIdea(index, idea);
}