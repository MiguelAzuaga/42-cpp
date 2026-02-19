#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string _name;
	bool _signed;
	const int _gradeToSign;
	const int _gradeToExecute;

public:
	//> Orthodox Canonical Form
	Form();
	Form(const std::string name, const int gradeToSign, const int gradeToExecute);
	Form(const Form& other);
	Form& operator=(const Form& other);
	~Form();

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

	//> Member Functions
	void beSigned(const Bureaucrat& bureaucrat);

	//> Getters
	const std::string& getName() const;
	bool getSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
};

//> Stream
std::ostream& operator<<(std::ostream& out, const Form& in);

#endif // FORM_HPP