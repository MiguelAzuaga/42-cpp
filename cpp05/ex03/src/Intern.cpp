
#include "Intern.hpp"

static AForm* createShrubbery(const std::string& target);
static AForm* createRobotomy(const std::string& target);
static AForm* createPresidential(const std::string& target);

//> Orthodox Canonical Form

Intern::Intern()
{
}

Intern::~Intern()
{
}

Intern::Intern(const Intern& other)
{
	*this = other;
}

Intern& Intern::operator=(const Intern& other)
{
	if (this != &other)
		*this = other;
	return *this;
}

//> Exceptions

const char* Intern::FormNotFoundException::what() const throw()
{
	return "Form not found.";
}
//> Member functions

AForm* Intern::makeForm(const std::string& name, const std::string& target)
{
	std::string list[3] =
	{
		"shrubbery form",
		"robotomy form",
		"presidential form"
	};
	AForm* (*creators[3])(const std::string&) =
	{
		createShrubbery,
		createRobotomy,
		createPresidential
	};

	for (int i = 0; i < 3; i++)
	{
		if (name == list[i])
		{
			std::cout << "Intern creates "
					  << name
					  << std::endl;
			return creators[i](target);
		}
	}

	std::cout << "Form not found" << std::endl;
	return NULL;
}

//> Helper functions
static AForm* createShrubbery(const std::string& target)
{
	return new ShrubberyCreationForm(target);
}

static AForm* createRobotomy(const std::string& target)
{
	return new RobotomyRequestForm(target);
}

static AForm* createPresidential(const std::string& target)
{
	return new PresidentialPardonForm(target);
}