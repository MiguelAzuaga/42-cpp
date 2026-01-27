#include "Harl.hpp"
#include <iostream>
#include <string>

enum Level {
	DEBUG,
	INFO,
	WARNING,
	ERROR,
	UNKNOWN
};

Level getLevel(const std::string& level) {
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++) {
		if (level == levels[i])
			return static_cast<Level>(i);
	}
	return UNKNOWN;
}

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Usage: ./harlFilter <LEVEL>" << std::endl;
		return 1;
	}

	std::string level = argv[1];
	Harl harl;

	switch (getLevel(level)) {
		case DEBUG:
			harl.complain("DEBUG");
		case INFO:
			harl.complain("INFO");
		case WARNING:
			harl.complain("WARNING");
		case ERROR:
			harl.complain("ERROR");
			break;
		case UNKNOWN:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			std::cout << "Although there are several ways to deal with Harl, one of the most effective is to SWITCH it off." << std::endl;
	}

	return 0;
}