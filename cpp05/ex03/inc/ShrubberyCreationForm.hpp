#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <string>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
	std::string _target;
	enum
	{
		GRADE_SIGN = 145,
		GRADE_EXEC = 137
	};

public:
	//> Orthodox Canonical Form
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string& target);
	ShrubberyCreationForm(const ShrubberyCreationForm& other);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
	~ShrubberyCreationForm();

	//> Member Functions
	virtual void executeAction() const;
};

#endif // SHRUBBERYCREATIONFORM_HPP