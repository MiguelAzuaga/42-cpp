#include "ShrubberyCreationForm.hpp"
#include <fstream>

//> Orthodox Canonical Form

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreation", GRADE_SIGN, GRADE_EXEC),
	  _target("default")
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("ShrubberyCreation", GRADE_SIGN, GRADE_EXEC),
	  _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other),
	  _target(other._target)
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return *this;
}

//> Member Functions

void ShrubberyCreationForm::executeAction() const
{
	std::ofstream file((this->_target + "_shrubbery").c_str());
	file << "     ^      ^      ^     \n"
		 << "    ^^^    ^^^    ^^^    \n"
		 << "   ^^^^^  ^^^^^  ^^^^^   \n"
		 << "  ^^^^^^^  ^^^^^  ^^^^^  \n"
		 << " ^^^^^^^^^  ^^^^^  ^^^^^ \n"
		 << "    | |    | |    | |    \n";
	file.close();
}