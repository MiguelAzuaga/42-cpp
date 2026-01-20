#include "Zombie.hpp"

Zombie* newZombie( std::string name );
void randomChump( std::string name );

int main()
{
	Zombie *z = newZombie("HeapFoo");
	if (!z)
		return 1;
	z->announce();

	// Zombie *y = randomChump("StackBar");
	randomChump("StackBar");

	delete z;

	return 0;
}


Zombie* newZombie( std::string name )
{
	Zombie* z = new Zombie(name);
	return z;
}

void randomChump( std::string name )
{
	Zombie z(name);
	z.announce();
}