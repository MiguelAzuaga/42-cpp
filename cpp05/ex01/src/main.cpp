#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"
#include <iostream>
#include <cassert>
#include <sstream>

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

void test_form_valid() {
	Form f("Form", 100, 100);
	assert(f.getName() == "Form");
	assert(f.getGradeToSign() == 100);
	assert(f.getGradeToExecute() == 100);
}

void test_form_exceptions() {
	try {
		Form f("Form", 0, 100);
		assert(false);
	} catch (const std::exception& e) {
		assert(std::string(e.what()) == "Grade is too high");
	}
	try {
		Form f("Form", 100, 151);
		assert(false);
	} catch (const std::exception& e) {
		assert(std::string(e.what()) == "Grade is too low");
	}
}

void test_form_be_signed() {
	Bureaucrat b("Test", 50);
	Form f("Form", 100, 100);
	f.beSigned(b);
	assert(f.getSigned() == true);
}

int main() {
	test_bureaucrat_valid();
	test_bureaucrat_increment_decrement();
	test_bureaucrat_exceptions();
	test_form_valid();
	test_form_exceptions();
	test_form_be_signed();

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
		Form f("F", 20, 20);
		f.beSigned(b); // sign once
		b.signForm(f); // already signed
		Form f2("F2", 20, 20);
		b.signForm(f2); // should succeed
		Bureaucrat low("Low", 100);
		Form f3("F3", 10, 10);
		low.signForm(f3); // should fail
	}

	// Form: default constructor, destructor, copy, assignment
	{
		Form f1;
		Form f2 = f1;
		Form f3("CopyForm", 100, 100);
		f3 = f1;
	}

	// Form: constructor gradeToSign/gradeToExecute too high/low
	try { Form f("F", 0, 100); assert(false); } catch (const std::exception& e) { assert(std::string(e.what()) == "Grade is too high"); }
	try { Form f("F", 100, 0); assert(false); } catch (const std::exception& e) { assert(std::string(e.what()) == "Grade is too high"); }
	try { Form f("F", 151, 100); assert(false); } catch (const std::exception& e) { assert(std::string(e.what()) == "Grade is too low"); }
	try { Form f("F", 100, 151); assert(false); } catch (const std::exception& e) { assert(std::string(e.what()) == "Grade is too low"); }

	// Form: beSigned success and failure
	{
		Bureaucrat b("B", 10);
		Form f("F", 20, 20);
		f.beSigned(b); // should succeed
		assert(f.getSigned() == true);
		Bureaucrat low("Low", 100);
		Form f2("F2", 10, 10);
		try {
			f2.beSigned(low);
			assert(false);
		} catch (const std::exception& e) {
			assert(std::string(e.what()) == "Grade is too low");
		}
	}

	// Form: operator<< stream output
	{
		Form f("StreamForm", 100, 100);
		std::ostringstream oss;
		oss << f;
		assert(oss.str().find("StreamForm") != std::string::npos);
	}

	std::cout << "All tests passed!" << std::endl;
	return 0;
}
