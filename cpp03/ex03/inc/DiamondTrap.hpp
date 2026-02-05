#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
	std::string _name;	// DiamondTrap's own name

public:
	//> Orthodox Canonical Form
	DiamondTrap(void);
	DiamondTrap(const std::string& name);
	DiamondTrap(const DiamondTrap& other);
	DiamondTrap& operator=(const DiamondTrap& other);
	~DiamondTrap(void);

	//> Resolve
	using ScavTrap::attack;
	using ClapTrap::takeDamage;
	using ClapTrap::beRepaired;
	using ScavTrap::guardGate;
	using FragTrap::highFivesGuys;

	//> Member Functions
	// Special ability
	void whoAmI();

	//> Getters
	const std::string& getDiamondName() const;
};

std::ostream& operator<<(std::ostream& out, const DiamondTrap& in);

#endif // DIAMONDTRAP_HPP