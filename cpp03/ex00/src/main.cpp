#include "ClapTrap.hpp"
#include <iostream>

void displaystatus(const ClapTrap n)
{
	std::cout << n.getName() << " HP:" << n.getHitPoints();
	std::cout << " " << n.getName() << " EP:" << n.getEnergyPoints();
	std::cout << " " << n.getName() << " DMG:" << n.getAttackDamage() << std::endl;
}

int main(void)
{
	ClapTrap c1;
	displaystatus(c1);
	c1.attack("Target dummy");
	displaystatus(c1);
	ClapTrap c2("c2");
	displaystatus(c2);
	c2.takeDamage(5);
	displaystatus(c2);
	ClapTrap c3(c2);
	displaystatus(c3);
	c3.takeDamage(50);
	displaystatus(c3);
	c3.attack("Target dummy");
	c2.attack("Target dummy");
	displaystatus(c3);
	while (c1.getEnergyPoints() > 0)
		c1.beRepaired(1);
	displaystatus(c1);
}