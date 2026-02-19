#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <string>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
	std::string _target;
	enum
	{
		GRADE_SIGN = 72,
		GRADE_EXEC = 45
	};


public:
	//> Orthodox Canonical Form
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string& target);
	RobotomyRequestForm(const RobotomyRequestForm& other);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
	~RobotomyRequestForm();

	//> Member Functions
	virtual void executeAction() const;
};

#endif // ROBOTOMYREQUESTFORM_HPP