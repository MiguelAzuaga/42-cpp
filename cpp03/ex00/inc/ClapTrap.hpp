#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# include <ostream>

class ClapTrap
{
private:
	std::string	_name;
	int			_hitPoints;
	int			_energyPoints;
	int			_attackDamage;

public:
	//>OCF
	ClapTrap();
	ClapTrap(const std::string name);
	ClapTrap(const ClapTrap& other);
	~ClapTrap();

	//>MemFn
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	//>Getters
	const std::string& getName() const;
	int getHitPoints() const;
	int getEnergyPoints() const;
	int getAttackDamage() const;
};

#endif // CLAPTRAP_HPP