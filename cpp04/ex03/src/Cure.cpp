#include "Cure.hpp"
#include <iostream>

//> Orthodox Canonical Form

Cure::Cure() : AMateria("Cure") {}

Cure::~Cure() {}

Cure::Cure(const Cure& other) : AMateria(other)
{
	this->_type = other._type;
}

Cure& Cure::operator=(const Cure& other)
{
	if (this != &other)
		AMateria::operator=(other);
	return *this;
}

//> Member Functions
AMateria* Cure::clone() const
{
	return new Cure();
}

void Cure::use(ICharacter& target) // TODO Change Output
{
	std::cout << "* heals " << target.getName()
			  << " wounds *" << std::endl;
}