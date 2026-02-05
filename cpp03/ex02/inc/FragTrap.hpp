#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <string>
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
protected:
	enum	// constants used by the class
	{
		e_defHP = 100,
		e_defEP = 100,
		e_defDMG = 30
	};
public:
	//> Orthodox Canonical Form
	FragTrap(void);
	FragTrap(const std::string& name);
	FragTrap(const FragTrap& other);
	FragTrap& operator=(const FragTrap& other);
	~FragTrap(void);

	//> Member Functions
	// Special ability
	void highFivesGuys(void);
};

#endif // FRAGTRAP_HPP