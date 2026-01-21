#include "HumanB.hpp"

HumanB::HumanB(const std::string& name)
	:_name(name), _weapon(NULL) {}

HumanB::~HumanB() {}

void HumanB::attack()
{
	if (_weapon == NULL)
	{
		std::cout << _name;
		std::cout << " attacks with their fists";
		std::cout << std::endl;

		return;
	}
	std::cout << _name;
	std::cout << " attacks with their ";
	std::cout << _weapon->getType();
	std::cout << std::endl;
}

void HumanB::setWeapon(Weapon& newWeapon)
{
	_weapon = &newWeapon;
}
