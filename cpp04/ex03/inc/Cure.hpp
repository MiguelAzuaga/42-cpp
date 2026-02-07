#ifndef CURE_HPP
#define CURE_HPP

#include <string>
#include "AMateria.hpp"

class Cure : public AMateria
{
public:
	//> Orthodox Canonical Form
	Cure();
	Cure(const Cure& other);
	Cure& operator=(const Cure& other);
	~Cure();

	//> Member Functions
	AMateria* clone() const;
	void use(ICharacter& target);
};

#endif // CURE_HPP