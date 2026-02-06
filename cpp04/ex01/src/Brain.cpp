#include "Brain.hpp"
#include <iostream>

//> Orthodox Canonical Form

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain(const Brain& other)
{
	for (int i = 0; i < MAX_IDEAS; i++)
		this->_ideas[i] = other._ideas[i];
	std::cout << "Brain copy constructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& other)
{
	if (this != &other)
	{
		for (int i = 0; i < MAX_IDEAS; i++)
			this->_ideas[i] = other._ideas[i];
		std::cout << "Brain assignment operator called" << std::endl;
	}

	return *this;
}

//> Getters & Setters

std::string Brain::getIdea(size_t index) const
{
	if (index >= MAX_IDEAS)
	{
		std::cerr << "Index out of range in Brain::getIdea\n";
		return "";
	}

	return this->_ideas[index];
}

void Brain::setIdea(size_t index, std::string idea)
{
	if (index >= MAX_IDEAS)
	{
		std::cerr << "Index out of range in Brain::setIdea\n";
		return;
	}

	this->_ideas[index] = idea;

	return;
}