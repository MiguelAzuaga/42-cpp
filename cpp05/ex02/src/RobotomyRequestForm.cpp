#include "RobotomyRequestForm.hpp"
#include <fstream>
#include <cstdlib>

//> Orthodox Canonical Form

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequest", GRADE_SIGN, GRADE_EXEC),
	  _target("default")
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("RobotomyRequest", GRADE_SIGN, GRADE_EXEC),
	  _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other),
	  _target(other._target)
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return *this;
}

//> Member Functions

void RobotomyRequestForm::executeAction() const
{
	std::cout << "bzzzzzz, rat-a-tat-tat" << std::endl;
	if (rand() % 2 == 0)
		std::cout << this->_target
				  << " has been robotomized successfully."
				  << std::endl;
	else
		std::cout << this->_target
				  << " robotomy failed."
				  << std::endl;
}