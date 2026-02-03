#include "ClapTrap.hpp"
#include <iostream>

//> ANSI color codes
static const char* C_RST = "\033[0m";
static const char* C_RED = "\033[31m";
static const char* C_GRN = "\033[32m";
static const char* C_YEL = "\033[33m";
static const char* C_CYN = "\033[36m";
static const char* C_MAG = "\033[35m";

//> Default values
#define DEF_HP 10
#define DEF_EP 10
#define DEF_DMG 0

//> OCF
ClapTrap::ClapTrap(void)
			:_name(std::string(C_GRN) + "ClapTrap" + C_RST),
			_hitPoints(DEF_HP),
			_energyPoints(DEF_EP),
			_attackDamage(DEF_DMG)
{
	std::cout << "ClapTrap " << this->_name << " has been " << C_YEL << "created!" << C_RST << "(Default constructor)" << std::endl;
}

ClapTrap::ClapTrap(const std::string name)
			:_name(C_GRN + name + C_RST),
			_hitPoints(DEF_HP),
			_energyPoints(DEF_EP),
			_attackDamage(DEF_DMG)
{
	std::cout << "ClapTrap " << this->_name << " has been " << C_YEL << "created!" << C_RST << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
			:_name(other._name),
			_hitPoints(other._hitPoints),
			_energyPoints(other._energyPoints),
			_attackDamage(other._attackDamage)
{
	std::cout << "ClapTrap " << this->_name << " has been " << C_YEL << "created!" << C_RST << "(Copy of" + other.getName() + ")" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap " << this->_name << " has been " << C_RED << "destroyed!" << C_RST << std::endl;
}

//> MemFn
void ClapTrap::attack(const std::string& target)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " is dead and cannot attack. 💀" << std::endl;
		return;
	}
	else if (this->_energyPoints <= 0)
	{
		std::cout << "Claptrap " << this->_name << " is out of energy and needs to rest" << std::endl;
		return;
	}
	this->_energyPoints--;
	std::cout << this->_name << " attacks " << C_CYN << target << C_RST << ", causing " << C_MAG << this->_attackDamage << C_RST << " points of damage!" << std::endl;
	return;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " is already dead. 💀" << std::endl;
		return;
	}
	std::cout << this->_name << " is attacked, taking " << C_MAG << amount << C_RST << " points of damage!" << std::endl;
	if (this->_hitPoints > amount)
	{
		this->_hitPoints -= amount;
	}
	else
	{
		this->_hitPoints = 0;
		std::cout << this->_name << " is now dead. 😵" << std::endl;
	}
	return;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "ClapTrap" << this->_name << " is dead and cannot repair 💀" << std::endl;
		return;
	}
	else if (this->_energyPoints <= 0)
	{
		std::cout << "Claptrap" << this->_name << " is out of energy and needs to rest" << std::endl;
		return;
	}
	this->_energyPoints--;
	this->_hitPoints += amount;
	std::cout << this->_name << " repairs itself, gaining " << C_MAG << amount << C_RST << " points of health!" << std::endl;
	return;
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
