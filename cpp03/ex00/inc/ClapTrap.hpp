#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <ostream>

class ClapTrap
{
private:
	std::string	_name;
	int			_hitPoints;
	int			_energyPoints;
	int			_attackDamage;

	enum	// constants used by the class
	{
		e_defHP  = 10,
		e_defEP  = 10,
		e_defDMG = 0
	};

public:
	//> Orthodox Canonical Form
	ClapTrap(void);
	ClapTrap(const std::string name);
	ClapTrap(const ClapTrap& other);
	ClapTrap& operator=(const ClapTrap& other);
	~ClapTrap(void);

	//> Member Functions
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	//> Getters
	const std::string& getName(void) const;
	int getHitPoints(void) const;
	int getEnergyPoints(void) const;
	int getAttackDamage(void) const;
};

std::ostream& operator<<(std::ostream& out, const ClapTrap& in);

#endif // CLAPTRAP_HPP