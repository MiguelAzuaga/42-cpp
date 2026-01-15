#include <iostream>
#include <iomanip>
#include <cctype>
#include "PhoneBook.hpp"

static bool isAlphanumerical(const std::string &str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!std::isalnum(str[i]) && str[i] != ' ' && str[i] != '_')
			return false;
	}
	return true;
}

static std::string prompt(const std::string &label)
{
	std::string input;

	while (true)
	{
		std::cout << label;
		
		std::getline(std::cin, input);

		if (std::cin.eof())
		{
			std::cout << std::endl;
			std::exit(0);
		}

		if (input.empty())
		{
			std::cout << "Error: Field cannot be empty. Please try again." << std::endl;
			continue;
		}

		if (!isAlphanumerical(input))
		{
			std::cout << "Error: Field must contain only alphanumerical characters. Please try again." << std::endl;
			continue;
		}

		break;
	}
	return input;
}

static void printColumn(const std::string &str)
{
	if (str.length() > DISPLAY_COL_SIZE)
		std::cout << str.substr(0, 9) << ".";
	else
		std::cout << std::setw(DISPLAY_COL_SIZE) << str;
}

static void displayTable(const PhoneBook &pb)
{
	int count = pb.getContactCount();

	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	for (int i = 0; i < count; i++)
	{
		const Contact &c = pb.getContact(i);

		std::cout << "|" << std::setw(DISPLAY_COL_SIZE) << i + 1 << "|";
		printColumn(c.getFirstName());
		std::cout << "|";
		printColumn(c.getLastName());
		std::cout << "|";
		printColumn(c.getNickName());
		std::cout << "|" << std::endl;
	}
}

void	searchContact(const PhoneBook &pb)
{
	if (pb.getContactCount() < 1)
	{
		std::cout << "Please add a contact before searching" << std::endl;
		return;
	}
	std::string input;

	displayTable(pb);

	std::cout << "Index: ";

	std::getline(std::cin, input);
	if (input.length() != 1 || !std::isdigit(input[0]))
	{
		std::cout << "Error: Invalid index. Please enter a valid index." << std::endl;
		return;
	}
	int index = atoi(input.c_str());

	if (index >= 1 && index <= pb.getContactCount())
	{
		const Contact &c = pb.getContact(index - 1);
		std::cout << "First name: " << c.getFirstName() << std::endl;
		std::cout << "Last name: " << c.getLastName() << std::endl;
		std::cout << "Nickname: " << c.getNickName() << std::endl;
		std::cout << "Phone number: " << c.getPhoneNumber() << std::endl;
		std::cout << "Darkest secret: " << c.getDarkestSecret() << std::endl;
	}
	else
	{
		std::cout << "Error: Invalid index. Please enter a valid index." << std::endl;
	}
}

int main()
{
	PhoneBook pb;
	std::string command;

	while (true)
	{
		std::cout << "Command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, command);
		if (std::cin.eof())
		{
			std::cout << std::endl;
			std::exit(0);
		}

		if (command == "ADD")
		{
			std::string first = prompt("First name: ");
			std::string last = prompt("Last name: ");
			std::string nick = prompt("Nickname: ");
			std::string phone = prompt("Phone number: ");
			std::string secret = prompt("Darkest secret: ");

			Contact c(first, last, nick, phone, secret);
			pb.addContact(c);
		}
		else if (command == "SEARCH")
		{
			searchContact(pb);
		}
		else if (command == "EXIT")
			break;
	}
	return 0;
}
