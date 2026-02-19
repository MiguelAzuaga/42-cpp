#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
private:

public:
	//> Orthodox Canonical Form
	Intern();
	Intern(const Intern& other);
	Intern& operator=(const Intern& other);
	~Intern();

	//> Exceptions
	class FormNotFoundException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

	//> Member Functions
	AForm* makeForm(const std::string& name, const std::string& target);
};

#endif // INTERN_HPP