#include <cassert>
#include <iostream>
#include <sstream>

#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"

void test_bureaucrat_valid() {
	Bureaucrat b("Test", 100);
	assert(b.getName() == "Test");
	assert(b.getGrade() == 100);
}

void test_bureaucrat_increment_decrement() {
	Bureaucrat b("Test", 100);
	b.incrementGrade();
	assert(b.getGrade() == 99);
	b.decrementGrade();
	assert(b.getGrade() == 100);
}

void test_bureaucrat_exceptions() {
	try {
		Bureaucrat b("Test", 0);
		assert(false);
	} catch (const std::exception& e) {
		assert(std::string(e.what()) == "Grade is too high");
	}
	try {
		Bureaucrat b("Test", 151);
		assert(false);
	} catch (const std::exception& e) {
		assert(std::string(e.what()) == "Grade is too low");
	}
}


void test_presidential_pardon_form_valid() {
	PresidentialPardonForm pf("Target");
	assert(pf.getName() == "PresidentialPardon");
	assert(pf.getGradeToSign() == 25);
	assert(pf.getGradeToExecute() == 5);
}

void test_presidential_pardon_form_exceptions() {
	try {
		PresidentialPardonForm pf("Target");
		Bureaucrat b("Test", 150);
		pf.beSigned(b);
		pf.execute(b);
		assert(false);
	} catch (const std::exception& e) {
		assert(std::string(e.what()) == "Grade is too low");
	}
}

void test_presidential_pardon_form_be_signed() {
	Bureaucrat b("Test", 5);
	PresidentialPardonForm pf("Target");
	pf.beSigned(b);
	assert(pf.getSigned() == true);
}

int main() {
	test_bureaucrat_valid();
	test_bureaucrat_increment_decrement();
	test_bureaucrat_exceptions();
	test_presidential_pardon_form_valid();
	test_presidential_pardon_form_exceptions();
	test_presidential_pardon_form_be_signed();

	// Bureaucrat: default constructor, destructor, copy, assignment
	{
		Bureaucrat b1;
		Bureaucrat b2 = b1;
		Bureaucrat b3("CopyTest", 100);
		b3 = b1;
	}

	// Bureaucrat: incrementGrade at MAX_GRADE
	try {
		Bureaucrat b("Test", 1);
		b.incrementGrade();
		assert(false);
	} catch (const std::exception& e) {
		assert(std::string(e.what()) == "Grade is too high");
	}

	// Bureaucrat: decrementGrade at MIN_GRADE
	try {
		Bureaucrat b("Test", 150);
		b.decrementGrade();
		assert(false);
	} catch (const std::exception& e) {
		assert(std::string(e.what()) == "Grade is too low");
	}

	// Bureaucrat: signForm already signed, successful, and failed
	{
		Bureaucrat b("Signer", 10);
		PresidentialPardonForm pf("F");
		pf.beSigned(b);  // sign once
		b.signForm(pf);  // already signed
		PresidentialPardonForm pf2("F2");
		b.signForm(pf2);  // should succeed
		Bureaucrat low("Low", 100);
		PresidentialPardonForm pf3("F3");
		low.signForm(pf3);  // should fail
	}

	// PresidentialPardonForm: default constructor, destructor, copy, assignment
	{
		PresidentialPardonForm pf1;
		PresidentialPardonForm pf2 = pf1;
		PresidentialPardonForm pf3("CopyForm");
		pf3 = pf1;
	}

	// PresidentialPardonForm: execute exceptions (not signed)
	{
		Bureaucrat exec("Exec", 1);
		PresidentialPardonForm pf("Target");
		try {
			pf.execute(exec);
			assert(false);
		} catch (const std::exception& e) {
			assert(std::string(e.what()) == "The form is not signed.");
		}
	}

	// Bureaucrat: executeForm success and exception
	{
		Bureaucrat exec("Exec", 1);
		PresidentialPardonForm pf("Target");
		pf.beSigned(exec);
		exec.executeForm(pf); // should succeed
		Bureaucrat low("Low", 150);
		try {
			low.executeForm(pf); // should throw
			// assert(false);
		} catch (const std::exception& e) {
			assert(std::string(e.what()) == "Grade is too low");
		}
	}

	// AForm: execute exceptions (not signed)
	{
		Bureaucrat exec("Exec", 1);
		PresidentialPardonForm pf("Target");
		try {
			pf.execute(exec);
			assert(false);
		} catch (const std::exception& e) {
			assert(std::string(e.what()) == "The form is not signed.");
		}
	}

	// Derived forms: constructors, assignment, executeAction
	{
		PresidentialPardonForm pf1;
		PresidentialPardonForm pf2("Target");
		PresidentialPardonForm pf3 = pf2;
		pf1 = pf2;
		RobotomyRequestForm rf1;
		RobotomyRequestForm rf2("Target");
		RobotomyRequestForm rf3 = rf2;
		rf1 = rf2;
		ShrubberyCreationForm sf1;
		ShrubberyCreationForm sf2("Target");
		ShrubberyCreationForm sf3 = sf2;
		sf1 = sf2;
		Bureaucrat exec("Exec", 1);
		pf2.beSigned(exec);
		pf2.execute(exec);
		rf2.beSigned(exec);
		rf2.execute(exec);
		sf2.beSigned(exec);
		sf2.execute(exec);
	}

	std::cout << "All tests passed!" << std::endl;
	return 0;
}
