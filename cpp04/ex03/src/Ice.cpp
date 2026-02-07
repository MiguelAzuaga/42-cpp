#include "Ice.hpp"
#include <iostream>

//> Orthodox Canonical Form

Ice::Ice() : AMateria("ice") {}

Ice::~Ice() {}

Ice::Ice(const Ice& other) : AMateria(other)
{
	this->_type = other._type;
}

Ice& Ice::operator=(const Ice& other)
{
	if (this != &other)
		AMateria::operator=(other);
	return *this;
}

//> Member Functions
AMateria* Ice::clone() const
{
	return new Ice();
}

void Ice::use(ICharacter& target) // TODO Change Output
{
	std::cout << "* shoots an ice bolt at "
			  << target.getName() << " *" << std::endl;
}
