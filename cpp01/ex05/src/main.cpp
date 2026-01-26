#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl harl;
	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");
	harl.complain("TEST");
	harl.complain("OTHER");
	if (argc >= 2)
	{
		for (int i = 1; i < argc; i++)
			harl.complain(argv[i]);
	}
	return 0;
}