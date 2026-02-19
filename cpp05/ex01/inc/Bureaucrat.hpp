#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include "Form.hpp"

#define MIN_GRADE 150
#define MAX_GRADE 1

class Form;

class Bureaucrat
{
private:
	const std::string _name;
	int _grade;

public:
	//> Orthodox Canonical Form
	Bureaucrat();
	Bureaucrat(const std::string name, int grade);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);
	~Bureaucrat();

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
	void incrementGrade();
	void decrementGrade();
	void signForm(Form& form);

	//> Getters
	const std::string& getName() const;
	int getGrade() const;
};

//> Stream
std::ostream& operator<<(std::ostream& out, const Bureaucrat& in);

#endif // BUREAUCRAT_HPP