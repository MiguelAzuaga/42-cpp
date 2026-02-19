#include "PresidentialPardonForm.hpp"
#include <fstream>

//> Orthodox Canonical Form

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("PresidentialPardon", GRADE_SIGN, GRADE_EXEC),
	  _target("default")
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: AForm("PresidentialPardon", GRADE_SIGN, GRADE_EXEC),
	  _target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
	: AForm(other),
	  _target(other._target)
{
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return *this;
}

//> Member Functions

void PresidentialPardonForm::executeAction() const
{
	std::cout << this->_target
			  << " has been pardoned by Zaphod Beeblebrox."
			  << std::endl;
}