#include "Zombie.hpp"
#include <cstring>
#include <sstream>

Zombie* zombieHorde( int N, std::string name )
{
	if (N <= 0)
		return NULL;

	Zombie* horde = new Zombie[N];
	std::stringstream ss;

	for (int i = 0; i < N; i++)
	{
		ss.str("");
		ss.clear();
		ss << (i + 1);
		horde[i].setName(name + "_" + ss.str());
	}
	return horde;
}