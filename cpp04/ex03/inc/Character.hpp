#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
private:
	std::string _name;
	static const int _maxInv = 4;
	AMateria* _inventory[_maxInv];

public:
	//> Orthodox Canonical Form
	Character();
	Character(const std::string name);
	Character(const Character& other);
	Character& operator=(const Character& other);
	~Character(); // TODO virt if parent

	//> Member Functions
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);

	//> Getters
	const std::string& getName() const;
};

#endif // CHARACTER_HPP