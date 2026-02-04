#include "ClapTrap.hpp"
#include <iostream>

int main(void)
{
	ClapTrap c1;
	std::cout << c1 << std::endl;
	c1.attack("Target dummy");
	std::cout << c1 << std::endl;
	ClapTrap c2("CT-002");
	std::cout << c2 << std::endl;
	c2.takeDamage(5);
	std::cout << c2 << std::endl;
	ClapTrap c3(c2);
	std::cout << c3 << std::endl;
	c3.takeDamage(50);
	std::cout << c3 << std::endl;
	c3.attack("Target dummy");
	c2.attack("Target dummy");
	std::cout << c3 << std::endl;
	ClapTrap c4("CT-004");
	c4 = c2;
	std::cout << c3 << std::endl;
	while (c1.getEnergyPoints() > 0)
		c1.beRepaired(1);
	std::cout << c1 << std::endl;
	std::cout << c2 << std::endl;
	std::cout << c3 << std::endl;
}