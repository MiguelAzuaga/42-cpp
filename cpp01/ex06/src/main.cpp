#include "Harl.hpp"
#include <iostream>
#include <string>

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Usage: ./harlFilter <LEVEL>" << std::endl;
		return 1;
	}

	std::string level = argv[1];
	Harl harl;

	int lvl;

	if (level == "DEBUG")
		lvl = 0;
	else if (level == "INFO")
		lvl = 1;
	else if (level == "WARNING")
		lvl = 2;
	else if (level == "ERROR")
		lvl = 3;
	else
		lvl = -1;

	switch (lvl) {
		case 0:  // DEBUG
			harl.complain("DEBUG");
		case 1:  // INFO
			harl.complain("INFO");
		case 2:  // WARNING
			harl.complain("WARNING");
		case 3:  // ERROR
			harl.complain("ERROR");
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			std::cout << "Although there are several ways to deal with Harl, one of the most effective is to SWITCH it off." << std::endl;
	}

	return 0;
}
