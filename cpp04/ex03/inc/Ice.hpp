#ifndef ICE_HPP
#define ICE_HPP

#include <string>
#include "AMateria.hpp"

class Ice : public AMateria
{
public:
	//> Orthodox Canonical Form
	Ice();
	Ice(const Ice& other);
	Ice& operator=(const Ice& other);
	~Ice();

	//> Member Functions
	AMateria* clone() const;
	void use(ICharacter& target);
};

#endif // ICE_HPP