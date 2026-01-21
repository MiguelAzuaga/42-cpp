#include <iostream>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string* ptr = &str;
	std::string& ref = str;

	std::cout << "The memory address of the string variable:";
	std::cout << &str << std::endl;
	std::cout << "The memory address held by stringPTR:";
	std::cout << &ptr << std::endl;
	std::cout << "The memory address held by stringREF:";
	std::cout << &ref << std::endl;

	std::cout << "The value of the string variable:";
	std::cout << str << std::endl;
	std::cout << "The value pointed to by stringPTR:";
	std::cout << *ptr << std::endl;
	std::cout << "The value pointed to by stringREF:";
	std::cout << ref << std::endl;
}