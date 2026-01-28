#include "Harl.hpp"

// Constructor
Harl::Harl() {}

// Destructor
Harl::~Harl() {}

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

// Complain function using array
void Harl::complain(const std::string& level)
{
	const std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	harlMemFn functions[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			(this->*functions[i])();
			return;
		}
	}
	std::cout << "[" << level << "] This level does not exist!" << std::endl;
}
