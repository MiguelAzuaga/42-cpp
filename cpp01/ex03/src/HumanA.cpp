#include "HumanA.hpp"

HumanA::HumanA(const std::string& name, Weapon &weapon)
	:_name(name), _weapon(weapon) {}

HumanA::~HumanA() {}

const void HumanA::attack()
{
	std::cout << _name;
	std::cout << " attacks with their ";
	std::cout << _weapon.getType();
	std::cout << std::endl;
}
