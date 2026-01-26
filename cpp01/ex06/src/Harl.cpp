#include "Harl.hpp"

// Constructor
Harl::Harl()
{
	initLevels();
}

// Destructor
Harl::~Harl() {}

// Initialize the map
void Harl::initLevels()
{
	levels["DEBUG"] = &Harl::debug;
	levels["INFO"] = &Harl::info;
	levels["WARNING"] = &Harl::warning;
	levels["ERROR"] = &Harl::error;
}

// Member functions
void Harl::debug()
{
	std::cout << PURPLE << "[DEBUG]" << RESET
			  << " I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"
			  << std::endl;
}

void Harl::info()
{
	std::cout << BLUE << "[INFO]" << RESET
			  << " I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
			  << std::endl;
}

void Harl::warning()
{
	std::cout << YELLOW << "[WARNING]" << RESET
			  << " I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month."
			  << std::endl;
}

void Harl::error()
{
	std::cout << RED << "[ERROR]" << RESET
			  << " This is unacceptable! I want to speak to the manager now."
			  << std::endl;
}

// Complain function using map
void Harl::complain(const std::string& level)
{
	std::map<std::string, harlMemFn>::iterator it = levels.find(level);
	if (it != levels.end())
	{
		harlMemFn func = it->second;
		(this->*func)();
	}
	else
	{
		std::cout << "[" << level << "] This level does not exist!" << std::endl;
	}
}
