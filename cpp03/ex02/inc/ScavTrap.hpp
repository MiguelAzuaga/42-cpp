#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <string>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
protected:
	enum	// constants used by the class
	{
		e_defHP = 100,
		e_defEP = 50,
		e_defDMG = 20
	};
public:
	//> Orthodox Canonical Form
	ScavTrap(void);
	ScavTrap(const std::string& name);
	ScavTrap(const ScavTrap& other);
	ScavTrap& operator=(const ScavTrap& other);
	~ScavTrap(void);

	//> Member Functions
	// Override attack
	void attack(const std::string& target);
	// Special ability
	void guardGate();
};

#endif // SCAVTRAP_HPP