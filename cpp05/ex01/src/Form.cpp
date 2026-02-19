#include "../inc/Form.hpp"

//> Orthodox Canonical Form

Form::Form()
	: _name("Default"),
	  _signed(false),
	  _gradeToSign(150),
	  _gradeToExecute(150)
{
}

Form::~Form()
{
}

Form::Form(const std::string name, const int gradeToSign, const int gradeToExecute)
	: _name(name),
	  _signed(false),
	  _gradeToSign(gradeToSign),
	  _gradeToExecute(gradeToExecute)
{
	if (_gradeToSign < MAX_GRADE || _gradeToExecute < MAX_GRADE)
		throw GradeTooHighException();
	else if (_gradeToSign > MIN_GRADE || _gradeToExecute > MIN_GRADE)
		throw GradeTooLowException();
}

Form::Form(const Form& other)
	: _name(other._name),
	  _signed(other._signed),
	  _gradeToSign(other._gradeToSign),
	  _gradeToExecute(other._gradeToExecute)
{
}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
		this->_signed = other._signed;
	return *this;
}

//> Exceptions

const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

//> Member Functions

void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= this->_gradeToSign)
		_signed = true;
	else
		throw GradeTooLowException();
}

//> Getters

const std::string& Form::getName() const { return this->_name; }

bool Form::getSigned() const { return this->_signed; }

int Form::getGradeToSign() const { return this->_gradeToSign; }

int Form::getGradeToExecute() const { return this->_gradeToExecute; }

//> Stream

std::ostream& operator<<(std::ostream& out, const Form& in)
{
	out << "Form "
		<< in.getName()
		<< (in.getSigned() ? " is signed" : " is not signed")
		<< std::endl;
	return out;
}