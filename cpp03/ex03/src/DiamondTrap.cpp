#include "DiamondTrap.hpp"
#include <iostream>

//> ANSI color codes

static const char* C_RST = "\033[0m";
static const char* C_BOT = "\033[36m"; // Color of the bot: Cyan
static const char* C_MAG = "\033[35m";

//> Orthodox Canonical Form

DiamondTrap::DiamondTrap(void)
	: ClapTrap("Default_clap_name"), ScavTrap(), FragTrap(), _name("Default")
{
	this->_hitPoints   = FragTrap::e_defHP;
	this->_energyPoints = ScavTrap::e_defEP;
	this->_attackDamage = FragTrap::e_defDMG;

	std::cout << C_BOT << "DiamondTrap " << this->_name
			  << " has been " << C_MAG << "created!" << C_RST
			  << C_BOT << " (Default constructor)" << C_RST << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name)
	: ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name)
{
	this->_hitPoints   = FragTrap::e_defHP;
	this->_energyPoints = ScavTrap::e_defEP;
	this->_attackDamage = FragTrap::e_defDMG;

	std::cout << C_BOT << "DiamondTrap " << this->_name
			  << " has been " << C_MAG << "created!" << C_RST << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
	: ClapTrap(other), ScavTrap(other), FragTrap(other), _name(other._name)
{
	std::cout << C_BOT << "DiamondTrap " << this->_name
			  << " has been " << C_MAG << "created!" << C_RST
			  << C_BOT << " (Copy of " << other.getName() << ")" << C_RST << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);

		// DiamondTrap-specific member
		this->_name = other._name;

		std::cout << C_BOT << "DiamondTrap " << this->_name
				  << " is now equal to DiamondTrap " << other._name << C_RST << std::endl;
	}
	return *this;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << C_BOT << "DiamondTrap " << this->_name
			  << " has been " << C_MAG << "destroyed!" << C_RST << std::endl;
}

//> Member Functions

void DiamondTrap::whoAmI()
{
	std::cout << C_BOT << "I am DiamondTrap " << this->_name
			  << " and my ClapTrap name is " << C_MAG << ClapTrap::_name << "!" << C_RST << std::endl;
}

//> Getters

const std::string& DiamondTrap::getDiamondName() const
{
	return this->_name;
}

std::ostream& operator<<(std::ostream& out, const DiamondTrap& in)
{
	out << "DiamondTrap " << in.getDiamondName()
		<< " (" << "ClapTrap: " << in.ClapTrap::getName() << ") "
		<< "HP:" << C_MAG << in.getHitPoints() << C_RST
		<< " EP:" << C_MAG << in.getEnergyPoints() << C_RST
		<< " DMG:" << C_MAG << in.getAttackDamage() << C_RST;
	return out;
}