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
	if (!argv[1] || std::string(argv[1]).empty())
	{
		std::cerr << "Error: filename cannot be empty" << std::endl;
		return 1;
	}
	if (!argv[2] || std::string(argv[2]).empty())
	{
		std::cerr << "Error: s1 cannot be empty" << std::endl;
		return 1;
	}
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	// Create I/O streams and verify if they work.
	std::ifstream infile(filename.c_str(), std::ios::in);
	if (!infile.is_open())
	{
		std::cerr << "File failed to open:" << filename << std::endl;
		return 1;
	}
	std::string fileReplace(filename.append(".replace"));

	std::ofstream outfile(fileReplace.c_str(), std::ios::out);
	if (!outfile.is_open())
	{
		std::cerr << "File failed to open:" << filename.append(".replace") << std::endl;
		return 1;
	}

	std::string line;
	while (std::getline(infile, line))
	{
		size_t pos = 0;
		// Changes s1 for s2 while pos != -1
		while ((pos = line.find(s1, pos)) != std::string::npos)
		{
			line.erase(pos, s1.length());
			line.insert(pos, s2);

			pos += s2.length();
		}
		outfile << line << std::endl;
	}
	infile.close();
	outfile.close();
	return 0;
}
