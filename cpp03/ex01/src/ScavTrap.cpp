#include "ScavTrap.hpp"
#include <iostream>

//> ANSI color codes
static const char* C_RST = "\033[0m";
static const char* C_RED = "\033[31m";
static const char* C_GRN = "\033[93m";
static const char* C_YEL = "\033[33m";
static const char* C_CYN = "\033[36m";
static const char* C_MAG = "\033[35m";

//> Default values
#define DEF_HP 100
#define DEF_EP 50
#define DEF_DMG 20

//> OCF
ScavTrap::ScavTrap(void) :ClapTrap()
{
	_hitPoints = DEF_HP;
	_energyPoints = DEF_EP;
	_attackDamage = DEF_DMG;
	std::cout << C_YEL << "ScavTrap " << this->_name
			  << " has been " << C_MAG << "created!" << C_RST << C_YEL
			  << "(Default constructor)" << C_RST << std::endl;

}

ScavTrap::ScavTrap(const std::string& name) :ClapTrap(name)
{
	_hitPoints = DEF_HP;
	_energyPoints = DEF_EP;
	_attackDamage = DEF_DMG;

	std::cout << C_YEL << "ScavTrap " << this->_name
			  << " has been " << C_MAG << "created!" << C_RST << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << C_YEL << "ScavTrap " << this->_name
			  << " has been " << C_MAG << "created!" << C_RST << C_YEL
			  << "(Copy of" + other.getName() + ")" << C_RST << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << C_YEL << "ScavTrap " << this->_name
			  << " is now equal to ScavTrap "
			  << other._name << C_RST << std::endl;
	this->ClapTrap::operator=(other);
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << C_YEL << "ScavTrap " << this->_name
			  << " has been " << C_MAG << "destroyed!" << C_RST
			  << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->_hitPoints == 0)
	{
		std::cout << C_YEL << "ScavTrap " << this->_name
				  << " is dead and cannot attack. 💀" << C_RST << std::endl;
		return;
	}
	if (this->_energyPoints == 0)
	{
		std::cout << C_YEL << "Scavtrap " << this->_name
				  << " is out of energy and needs to rest" << C_RST << std::endl;
		return;
	}
	this->_energyPoints--;
	std::cout << C_YEL << "ScavTrap " << _name
			  << " fiercely attacks " << C_CYN << target << C_RST
			  << C_YEL << ", dealing " << C_MAG << _attackDamage << C_RST
			  << C_YEL << " points of damage!" << C_RST << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << C_YEL << "ScavTrap " << _name
			  << " is now in Gate keeper mode!" << C_RST << std::endl;
}