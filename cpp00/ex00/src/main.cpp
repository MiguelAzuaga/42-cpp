#include <iostream>
#include <cctype>
#include <string>

int main(int argc, char **argv)
{
	if (argc <= 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}

	std::string	line;

	for (int i = 1; i < argc; i++)
		line = line.append(argv[i]);

	for (std::size_t i = 0; i < line.length(); i++)
		line[i] = std::toupper(line[i]);

	std::cout << line << std::endl;

	return 0;
}