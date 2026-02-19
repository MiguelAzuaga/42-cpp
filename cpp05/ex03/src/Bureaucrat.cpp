#include "../inc/Bureaucrat.hpp"

//> Orthodox Canonical Form

Bureaucrat::Bureaucrat() : _name("John Doe"), _grade(150)
{
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade)
{
	if (grade < MAX_GRADE)
		throw GradeTooHighException();
	else if (grade > MIN_GRADE)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade)
{
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
		this->_grade = other.getGrade();
	return *this;
}

//> Exceptions

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

//> Member Functions

void Bureaucrat::incrementGrade()
{
	if (this->_grade <= MAX_GRADE)
		throw GradeTooHighException();
	this->_grade -= 1;
}

void Bureaucrat::decrementGrade()
{
	if (this->_grade >= MIN_GRADE)
		throw GradeTooLowException();
	this->_grade += 1;
}

void Bureaucrat::signForm(AForm& form)
{
	if (form.getSigned())
	{
		std::cout << "Form "
				  << form.getName()
				  << " is already signed"
				  << std::endl;
		return;
	}
	try
	{
		form.beSigned(*this);
		std::cout << this->_name
				  << " signed form "
				  << form.getName()
				  << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << this->_name
				  << " couldn't sign form "
				  << form.getName()
				  << " because "
				  << e.what()
				  << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form) const
{
	try
	{
		form.execute(*this);
		std::cout << this->_name
				  << " executed "
				  << form.getName()
				  << std::endl;
	}
	catch(const std::exception & e)
	{
		std::cout << this->_name
				  << " couldn't execute "
				  << form.getName()
				  << " because "
				  << e.what()
				  << std::endl;
	}
}

//> Getters

const std::string& Bureaucrat::getName() const { return this->_name; }

int Bureaucrat::getGrade() const { return this->_grade; }

//> Stream

std::ostream& operator<<(std::ostream& out, const Bureaucrat in)
{
	out << in.getName()
		<< ", bureaucrat grade "
		<< in.getGrade()
		<< std::endl;
	return out;
}