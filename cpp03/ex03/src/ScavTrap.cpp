#include "ScavTrap.hpp"
#include <iostream>

//> ANSI color codes

static const char* C_RST = "\033[0m";
static const char* C_BOT = "\033[33m"; // Color of the bot: Yellow
static const char* C_MAG = "\033[35m";

//> Orthodox Canonical Form

ScavTrap::ScavTrap(void) : ClapTrap()
{
	_hitPoints = e_defHP;
	_energyPoints = e_defEP;
	_attackDamage = e_defDMG;

	std::cout << C_BOT << "ScavTrap " << this->_name
			  << " has been " << C_MAG << "created!" << C_RST
			  << C_BOT << " (Default constructor)" << C_RST << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	_hitPoints = e_defHP;
	_energyPoints = e_defEP;
	_attackDamage = e_defDMG;

	std::cout << C_BOT << "ScavTrap " << this->_name
			  << " has been " << C_MAG << "created!" << C_RST << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << C_BOT << "ScavTrap " << this->_name
			  << " has been " << C_MAG << "created!" << C_RST
			  << C_BOT << " (Copy of " << other.getName() << ")" << C_RST << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);

		std::cout << C_BOT << "ScavTrap " << this->_name
				  << " is now equal to ScavTrap " << other.getName() << C_RST << std::endl;
	}
	return *this;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << C_BOT << "ScavTrap " << this->_name
			  << " has been " << C_MAG << "destroyed!" << C_RST << std::endl;
}

//> Member Functions

void ScavTrap::attack(const std::string& target)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << C_BOT << "ScavTrap " << this->_name
				  << " is dead and cannot attack. 💀" << C_RST << std::endl;
		return;
	}
	if (this->_energyPoints <= 0)
	{
		std::cout << C_BOT << "ScavTrap " << this->_name
				  << " is out of energy and needs to rest" << C_RST << std::endl;
		return;
	}
	this->_energyPoints--;
	std::cout << C_BOT << "ScavTrap " << this->_name
			  << " fiercely attacks " << C_MAG << target << C_RST
			  << C_BOT << ", dealing " << C_MAG << this->_attackDamage << C_RST
			  << C_BOT << " points of damage!" << C_RST << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << C_BOT << "ScavTrap " << this->_name
			  << " is now in Gate keeper mode!" << C_RST << std::endl;
}