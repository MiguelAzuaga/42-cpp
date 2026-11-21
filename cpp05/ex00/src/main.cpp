#include "../inc/Bureaucrat.hpp"
#include <iostream>

int main()
{
	std::cout << "\n// Example 1: Constructor throws exception" << std::endl;
	try
	{
		Bureaucrat alice("Alice", 0);	// Invalid grade
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n// Example 2: Increment throws exception" << std::endl;
	try
	{
		Bureaucrat bob("Bob", 1);
		std::cout << bob.getName() << ", grade " << bob.getGrade() << std::endl;
		bob.incrementGrade();			// Will throw - already at highest grade
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n// Example 3: Decrement throws exception" << std::endl;
	try
	{
		Bureaucrat charlie("Charlie", 150);
		charlie.decrementGrade();		// Will throw - already at lowest grade
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n// Example 4: Creat without treating exception" << std::endl;
	Bureaucrat dave("Dave", 200);		// Invalid

	std::cout << "\n// Example 5: Generic test after crash" << std::endl;
	try
	{
		Bureaucrat eve("Eve", 20);		// Valid
	}
	catch (std::exception &e)
	{
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}

	return 0;
}