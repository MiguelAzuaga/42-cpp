#include "ClapTrap.hpp"
#include <iostream>

int main(void)
{
	ClapTrap c1;
	std::cout << "c1 HP:" << c1.getHitPoints() << " c1 EP:" << c1.getEnergyPoints() << std::endl;
	c1.attack("Target dummy");
	std::cout << "c1 HP:" << c1.getHitPoints() << " c1 EP:" << c1.getEnergyPoints() << std::endl;
	ClapTrap c2("c2");
	std::cout << "c2 HP:" << c2.getHitPoints() << " c2 EP:" << c2.getEnergyPoints() << std::endl;
	c2.takeDamage(5);
	std::cout << "c2 HP:" << c2.getHitPoints() << " c2 EP:" << c2.getEnergyPoints() << std::endl;
	ClapTrap c3(c2);
	std::cout << "c3 HP:" << c3.getHitPoints() << " c3 EP:" << c3.getEnergyPoints() << std::endl;
	c3.takeDamage(50);
	std::cout << "c3 HP:" << c3.getHitPoints() << " c3 EP:" << c3.getEnergyPoints() << std::endl;
	c3.attack("Target dummy");
	c2.attack("Target dummy");
	std::cout << "c2 HP:" << c2.getHitPoints() << " c2 EP:" << c2.getEnergyPoints() << std::endl;
	while (c1.getEnergyPoints() > 0)
		c1.beRepaired(1);
	std::cout << "c1 HP:" << c1.getHitPoints() << " c1 EP:" << c1.getEnergyPoints() << std::endl;
}