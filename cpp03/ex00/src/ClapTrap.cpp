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
			:_name("Default"),
			_hitPoints(DEF_HP),
			_energyPoints(DEF_EP),
			_attackDamage(DEF_DMG)
{
	std::cout << C_GRN << "ClapTrap " << this->_name
			  << " has been " << C_MAG << "created!" << C_RST << C_GRN
			  << "(Default constructor)" << C_RST << std::endl;
}

ClapTrap::ClapTrap(const std::string name)
			:_name(name),
			_hitPoints(DEF_HP),
			_energyPoints(DEF_EP),
			_attackDamage(DEF_DMG)
{
	std::cout << C_GRN << "ClapTrap " << this->_name
			  << " has been " << C_MAG << "created!" << C_RST << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
			:_name(other._name),
			_hitPoints(other._hitPoints),
			_energyPoints(other._energyPoints),
			_attackDamage(other._attackDamage)
{
	std::cout << C_GRN << "ClapTrap " << this->_name
			  << " has been " << C_MAG << "created!" << C_RST << C_GRN
			  << "(Copy of" + other.getName() + ")" << C_RST << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	std::cout << C_GRN << "ClapTrap " << this->_name
			  << " is now equal to ClapTrap "
			  << other._name << C_RST << std::endl;
	if (this != &other)
	{
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return *this;
}


ClapTrap::~ClapTrap(void)
{
	std::cout << C_GRN << "ClapTrap " << this->_name
			  << " has been " << C_MAG << "destroyed!" << C_RST
			  << std::endl;
}

//> MemFn
void ClapTrap::attack(const std::string& target)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << C_GRN << "ClapTrap " << this->_name
				  << " is dead and cannot attack. 💀" << C_RST << std::endl;
		return;
	}
	else if (this->_energyPoints <= 0)
	{
		std::cout << C_GRN << "Claptrap " << this->_name
				  << " is out of energy and needs to rest" << C_RST << std::endl;
		return;
	}
	this->_energyPoints--;
	std::cout << C_GRN << "ClapTrap " << this->_name
			  << " attacks " << C_CYN << target << C_RST
			  << C_GRN << ", causing " << C_MAG << this->_attackDamage << C_RST
			  << C_GRN << " points of damage!" << C_RST << std::endl;
	return;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << C_GRN << "ClapTrap " << this->_name
				  << " is already dead. 💀" << C_RST << std::endl;
		return;
	}
	std::cout << C_GRN << "ClapTrap " << this->_name
			  << " is attacked, taking " << C_MAG << amount << C_RST
			  << C_GRN << " points of damage!" << C_RST << std::endl;
	if (this->_hitPoints > amount)
	{
		this->_hitPoints -= amount;
	}
	else
	{
		this->_hitPoints = 0;
	std::cout << C_GRN << "ClapTrap " << this->_name
			  << " is now dead. 😵" << C_RST << std::endl;
	}
	return;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << C_GRN << "ClapTrap " << this->_name
				  << " is dead and cannot repair 💀" << C_RST << std::endl;
		return;
	}
	else if (this->_energyPoints <= 0)
	{
		std::cout << C_GRN << "ClapTrap " << this->_name
				  << " is out of energy and needs to rest" << C_RST << std::endl;
		return;
	}
	this->_energyPoints--;
	this->_hitPoints += amount;
	std::cout << C_GRN << "ClapTrap " << this->_name
			  << " repairs itself, gaining " << C_MAG << amount << C_RST
			  << C_GRN << " points of health!" << C_RST << std::endl;
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

std::ostream& operator<<(std::ostream& out, const ClapTrap& in)
{
	out << in.getName() << " HP:" << C_MAG << in.getHitPoints() << C_RST
		<< " " << " EP:" << C_MAG << in.getEnergyPoints() << C_RST
		<< " " << " DMG:" << C_MAG << in.getAttackDamage() << C_RST;
	return out;
}