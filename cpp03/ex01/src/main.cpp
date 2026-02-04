#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main(void)
{
	ScavTrap s1;
	std::cout << s1 << std::endl;
	s1.attack("Target dummy");
	std::cout << s1 << std::endl;
	ScavTrap s2("CT-002");
	std::cout << s2 << std::endl;
	s2.takeDamage(5);
	std::cout << s2 << std::endl;
	ScavTrap s3(s2);
	std::cout << s3 << std::endl;
	s3.takeDamage(50);
	std::cout << s3 << std::endl;
	s3.attack("Target dummy");
	s2.attack("Target dummy");
	std::cout << s3 << std::endl;
	ScavTrap s4("CT-004");
	s4 = s2;
	std::cout << s4 << std::endl;
	s4.attack("Target dummy");
	s4.guardGate();
	std::cout << s4 << std::endl;
	for (int i = 0; i < 5; i++)
		s2.beRepaired(1);
	std::cout << s1 << std::endl;
	std::cout << s2 << std::endl;
	std::cout << s3 << std::endl;
	std::cout << s4 << std::endl;
}