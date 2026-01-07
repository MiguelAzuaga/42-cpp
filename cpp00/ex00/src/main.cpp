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

	std::string result;
	bool in_space = false;

	for (int i = 1; i < argc; i++)
	{
		std::string arg(argv[i]);

		std::string::size_type start = arg.find_first_not_of(" \t");
		std::string::size_type end = arg.find_last_not_of(" \t");
		if (start == std::string::npos)
			continue;
		arg = arg.substr(start, end - start + 1);

		for (std::string::size_type j = 0; j < arg.length(); j++)
		{
			char c = arg[j];
			if (std::isspace(static_cast<unsigned char>(c)))
			{
				if (!in_space)
				{
					result += ' ';
					in_space = true;
				}
			}
			else
			{
				result += std::toupper(static_cast<unsigned char>(c));
				in_space = false;
			}
		}

		if (i != argc - 1)
		{
			result += ' ';
			in_space = true;
		}
	}

	std::cout << result << std::endl;

	return 0;
}
