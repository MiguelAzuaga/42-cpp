#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string _name;
	bool _signed;
	const int _gradeToSign;
	const int _gradeToExecute;

public:
	//> Orthodox Canonical AForm
	AForm();
	AForm(const std::string name, const int gradeToSign, const int gradeToExecute);
	AForm(const AForm& other);
	AForm& operator=(const AForm& other);
	virtual ~AForm();

	//> Exceptions
	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
	class FormNotSignedException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

	//> Member Functions
	void beSigned(const Bureaucrat& bureaucrat);
	void execute(Bureaucrat const & executor) const;

	//> Getters
	const std::string& getName() const;
	bool getSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;

protected:
	virtual void executeAction() const = 0;
};

//> Stream
std::ostream& operator<<(std::ostream& out, const AForm& in);

#endif // AFORM_HPP