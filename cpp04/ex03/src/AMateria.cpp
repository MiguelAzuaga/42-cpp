#include "AMateria.hpp"
#include <iostream>

//> Orthodox Canonical Form

AMateria::AMateria() : _type("Unknown") {}

AMateria::~AMateria() {}

AMateria::AMateria(const std::string type) : _type(type) {}

AMateria::AMateria(const AMateria& other) : _type(other._type) {}

AMateria& AMateria::operator=(const AMateria& other)
{
	if (this != &other)
		this->_type = other._type;
	return *this;
}

//> Member Functions

void AMateria::use(ICharacter& target)
{
	std::cout << "AMateria used on "
			  << target.getName() << std::endl;
}

//> Getters

std::string const& AMateria::getType() const
{
	return this->_type;
}