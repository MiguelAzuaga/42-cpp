#include "FragTrap.hpp"
#include <iostream>

//> ANSI color codes

static const char* C_RST = "\033[0m";
static const char* C_BOT = "\033[31m"; // Color of the bot: Red
static const char* C_MAG = "\033[35m";

//> Orthodox Canonical Form

FragTrap::FragTrap(void) : ClapTrap()
{
	_hitPoints = e_defHP;
	_energyPoints = e_defEP;
	_attackDamage = e_defDMG;

	std::cout << C_BOT << "FragTrap " << this->_name
			  << " has been " << C_MAG << "created!" << C_RST
			  << C_BOT << " (Default constructor)" << C_RST << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	_hitPoints = e_defHP;
	_energyPoints = e_defEP;
	_attackDamage = e_defDMG;

	std::cout << C_BOT << "FragTrap " << this->_name
			  << " has been " << C_MAG << "created!" << C_RST << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout << C_BOT << "FragTrap " << this->_name
			  << " has been " << C_MAG << "created!" << C_RST
			  << C_BOT << " (Copy of " << other.getName() << ")" << C_RST << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);

		std::cout << C_BOT << "FragTrap " << this->_name
				  << " is now equal to FragTrap " << other.getName() << C_RST << std::endl;
	}
	return *this;
}

FragTrap::~FragTrap(void)
{
	std::cout << C_BOT << "FragTrap " << this->_name
			  << " has been " << C_MAG << "destroyed!" << C_RST << std::endl;
}

//> Member Functions

void FragTrap::highFivesGuys(void)
{
	std::cout << C_BOT << "FragTrap " << this->_name
			  << " is asking everyone for a high-five!" << C_RST << std::endl;
}