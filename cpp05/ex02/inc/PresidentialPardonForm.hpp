#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <string>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	std::string _target;
	enum
	{
		GRADE_SIGN = 25,
		GRADE_EXEC = 5
	};

public:
	//> Orthodox Canonical Form
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string& target);
	PresidentialPardonForm(const PresidentialPardonForm& other);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
	~PresidentialPardonForm();

	//> Member Functions
	virtual void executeAction() const;
};

#endif // PRESIDENTIALPARDONFORM_HPP