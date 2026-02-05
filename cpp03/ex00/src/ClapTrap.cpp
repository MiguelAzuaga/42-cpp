#include "ClapTrap.hpp"
#include <iostream>

//> ANSI color codes

static const char* C_RST = "\033[0m";
static const char* C_BOT = "\033[32m"; // Color of the bot: Green
static const char* C_MAG = "\033[35m";

//> Orthodox Canonical Form

ClapTrap::ClapTrap(void)
	: _name("Default"),
	  _hitPoints(e_defHP),
	  _energyPoints(e_defEP),
	  _attackDamage(e_defDMG)
{
	std::cout << C_BOT << "ClapTrap " << this->_name
			  << " has been " << C_MAG << "created!" << C_RST
			  << C_BOT << " (Default constructor)" << C_RST << std::endl;
}

ClapTrap::ClapTrap(const std::string name)
	: _name(name),
	  _hitPoints(e_defHP),
	  _energyPoints(e_defEP),
	  _attackDamage(e_defDMG)
{
	std::cout << C_BOT << "ClapTrap " << this->_name
			  << " has been " << C_MAG << "created!" << C_RST << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
	: _name(other._name),
	  _hitPoints(other._hitPoints),
	  _energyPoints(other._energyPoints),
	  _attackDamage(other._attackDamage)
{
	std::cout << C_BOT << "ClapTrap " << this->_name
			  << " has been " << C_MAG << "created!" << C_RST
			  << C_BOT << " (Copy of " << other.getName() << ")" << C_RST << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	if (this != &other)
	{
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;

		std::cout << C_BOT << "ClapTrap " << this->_name
				  << " is now equal to ClapTrap " << other._name << C_RST << std::endl;
	}
	return *this;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << C_BOT << "ClapTrap " << this->_name
			  << " has been " << C_MAG << "destroyed!" << C_RST << std::endl;
}

//> Member Functions

void ClapTrap::attack(const std::string& target)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << C_BOT << "ClapTrap " << this->_name
				  << " is dead and cannot attack. 💀" << C_RST << std::endl;
		return;
	}
	if (this->_energyPoints <= 0)
	{
		std::cout << C_BOT << "ClapTrap " << this->_name
				  << " is out of energy and needs to rest" << C_RST << std::endl;
		return;
	}
	this->_energyPoints--;
	std::cout << C_BOT << "ClapTrap " << this->_name
			  << " attacks " << C_MAG << target << C_RST
			  << C_BOT << ", causing " << C_MAG << this->_attackDamage << C_RST
			  << C_BOT << " points of damage!" << C_RST << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << C_BOT << "ClapTrap " << this->_name
				  << " is already dead. 💀" << C_RST << std::endl;
		return;
	}
	std::cout << C_BOT << "ClapTrap " << this->_name
			  << " is attacked, taking " << C_MAG << amount << C_RST
			  << C_BOT << " points of damage!" << C_RST << std::endl;
	if (this->_hitPoints > static_cast<int>(amount))
	{
		this->_hitPoints -= static_cast<int>(amount);
	}
	else
	{
		this->_hitPoints = 0;
		std::cout << C_BOT << "ClapTrap " << this->_name
				  << " is now dead. 😵" << C_RST << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << C_BOT << "ClapTrap " << this->_name
				  << " is dead and cannot repair. 💀" << C_RST << std::endl;
		return;
	}
	if (this->_energyPoints <= 0)
	{
		std::cout << C_BOT << "ClapTrap " << this->_name
				  << " is out of energy and needs to rest" << C_RST << std::endl;
		return;
	}
	this->_energyPoints--;
	this->_hitPoints += static_cast<int>(amount);
	std::cout << C_BOT << "ClapTrap " << this->_name
			  << " repairs itself, gaining " << C_MAG << amount << C_RST
			  << C_BOT << " points of health!" << C_RST << std::endl;
}

//> Getters

const std::string& ClapTrap::getName(void) const
{
	return this->_name;
}

int ClapTrap::getHitPoints(void) const
{
	return this->_hitPoints;
}

int ClapTrap::getEnergyPoints(void) const
{
	return this->_energyPoints;
}

int ClapTrap::getAttackDamage(void) const
{
	return this->_attackDamage;
}

std::ostream& operator<<(std::ostream& out, const ClapTrap& in)
{
	out << in.getName() << " HP:" << C_MAG << in.getHitPoints() << C_RST
		<< " EP:" << C_MAG << in.getEnergyPoints() << C_RST
		<< " DMG:" << C_MAG << in.getAttackDamage() << C_RST;
	return out;
}