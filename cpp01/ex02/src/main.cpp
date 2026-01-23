#include <iostream>
#include <memory>

int main()
{
	std::string stringSTR = "HI THIS IS BRAIN";
	std::string* stringPTR = &stringSTR;
	std::string& stringREF = stringSTR;

	std::cout << "The memory address of the string variable:";
	std::cout << __addressof(stringSTR) << std::endl;
	std::cout << "The memory address held by stringPTR:";
	std::cout << stringPTR << std::endl;
	std::cout << "The memory address held by stringREF:";
	std::cout << __addressof(stringSTR) << std::endl;

	std::cout << "The value of the string variable:";
	std::cout << stringSTR << std::endl;
	std::cout << "The value pointed to by stringPTR:";
	std::cout << *stringPTR << std::endl;
	std::cout << "The value pointed to by stringREF:";
	std::cout << stringREF << std::endl;
}