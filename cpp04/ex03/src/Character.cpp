#include "Character.hpp"
#include <iostream>

//> Orthodox Canonical Form

Character::Character() : _name("NULL")
{
	for (int i = 0; i < this->_maxInv; i++)
		this->_inventory[i] = 0;
}

Character::~Character()
{
	for (int i = 0; i < this->_maxInv; i++)
		delete this->_inventory[i];
}

Character::Character(const std::string name) : _name(name)
{
	for (int i = 0; i < this->_maxInv; i++)
		this->_inventory[i] = 0;
}

Character::Character(const Character& other) : _name(other._name)
{
	for (int i = 0; i < this->_maxInv; i++)
	{
		if (other._inventory[i])
			this->_inventory[i] = other._inventory[i]->clone();
		else
			this->_inventory[i] = 0;
	}
}

Character& Character::operator=(const Character& other)
{
	if (this != &other)
	{
		this->_name = other._name;
		for (int i = 0; i < this->_maxInv; i++)
		{
			delete this->_inventory[i];
			this->_inventory[i] = 0;

			if (other._inventory[i])
				this->_inventory[i] = other._inventory[i]->clone();
		}
	}
	return *this;
}

//> Member Functions

void Character::equip(AMateria* m)
{
	if (!m)
		return;
	for (unsigned int i = 0; i < this->_maxInv; i++)
	{
		if (!this->_inventory[i])
		{
			this->_inventory[i] = m->clone();
			std::cout << _name << " equiped Materia " << m->getType()
					  << " in slot " << i << std::endl;
			return;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= this->_maxInv)
		std::cerr << "Index out of range in Character::unequip"
				  << std::endl;
	else if (!this->_inventory[idx])
		std::cerr << "Cannot unequip empty inventory slots"
				  << std::endl;
	else
	{
		delete this->_inventory[idx];
		this->_inventory[idx] = 0;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= this->_maxInv)
		std::cerr << "Index out of range in Character::use"
				  << std::endl;
	else if (!this->_inventory[idx])
		std::cout << "Inventory slot is empty"
				  << std::endl;
	else
	{
		this->_inventory[idx]->use(target);
		delete this->_inventory[idx];
		this->_inventory[idx] = 0;
	}
}

//> Getters
const std::string& Character::getName() const
{
	return this->_name;
}