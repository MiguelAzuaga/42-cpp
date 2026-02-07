#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include "ICharacter.hpp"

class AMateria
{
protected:
	std::string _type;

public:
	//> Orthodox Canonical Form
	AMateria();
	AMateria(const std::string type);
	AMateria(const AMateria& other);
	AMateria& operator=(const AMateria& other);
	virtual ~AMateria();

	//> Member Functions
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);

	//> Getters
	const std::string& getType() const;
};

#endif // AMATERIA_HPP