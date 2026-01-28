#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

#define RESET	"\033[0m"
#define PURPLE	"\033[0;35m"
#define BLUE	"\033[0;94m"
#define YELLOW	"\033[0;93m"
#define RED		"\033[0;91m"

class Harl
{

public:
	Harl();
	~Harl();

	void debug(void);
	void info(void);
	void warning(void);
	void error(void);

	void complain(const std::string& level);

private:
	typedef void (Harl::*harlMemFn)(void);
};

#endif // HARL_HPP
