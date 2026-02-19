#include "../inc/AForm.hpp"

//> Orthodox Canonical AForm

AForm::AForm()
	: _name("Default"),
	  _signed(false),
	  _gradeToSign(150),
	  _gradeToExecute(150)
{
}

AForm::~AForm()
{
}

AForm::AForm(const std::string name, const int gradeToSign, const int gradeToExecute)
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

AForm::AForm(const AForm& other)
	: _name(other._name),
	  _signed(other._signed),
	  _gradeToSign(other._gradeToSign),
	  _gradeToExecute(other._gradeToExecute)
{
}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
		this->_signed = other._signed;
	return *this;
}

//> Exceptions

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return "The form is not signed.";
}

//> Member Functions

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw GradeTooLowException();
	this->_signed = true;
}

void AForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->_gradeToExecute)
		throw AForm::GradeTooLowException();
	else if (!this->_signed)
		throw AForm::FormNotSignedException();
	executeAction();
}

//> Getters

const std::string& AForm::getName() const { return this->_name; }

bool AForm::getSigned() const { return this->_signed; }

int AForm::getGradeToSign() const { return this->_gradeToSign; }

int AForm::getGradeToExecute() const { return this->_gradeToExecute; }

//> Stream

std::ostream& operator<<(std::ostream& out, const AForm& in)
{
	out << "AForm "
		<< in.getName()
		<< (in.getSigned() ? " is signed" : " is not signed")
		<< std::endl;
	return out;
}