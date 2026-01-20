#include "Zombie.hpp"

Zombie::Zombie() :_name("") {}

Zombie::Zombie( std::string name )
{
	_name = name;
}

Zombie::~Zombie()
{
	std::cout << this->_name << " is dead 💀 (for real this time)" << std::endl;
}

void Zombie::announce() const
{
	if (this->_name.empty())
		std::cout << "This zombie's parents didn't care enough about them to give them a name :(";
	else
		std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(const std::string& name)
{
	_name = name;
}
