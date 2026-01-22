#include <iostream>
#include <fstream>

#define USAGE "Usage: ./replace <filename> <s1> <s2> "

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << USAGE << std::endl;
		return 1;
	}
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	std::ifstream	file;
	std::string		line;
	file.open(argv[1]);
	if (!file.is_open())
	{
		std::cout << "File not found" << std::endl;
		return (1);
	}
	std::string		file_name = (std::string)argv[1] + ".replace";
	std::ofstream	rep(file_name.c_str());
	size_t	pos;
	while(std::getline(file, line))
	{
		pos = 0;
   		while ((pos = line.find(argv[2], pos)) != std::string::npos)
		{
			line.erase(pos, ((std::string)argv[2]).length());
			line.insert(pos, (std::string)argv[3]);
			pos += ((std::string)argv[3]).length();

		}
		if (!std::cin.eof())
			rep << line << std::endl;
	}
	rep.close();
	file.close();
}