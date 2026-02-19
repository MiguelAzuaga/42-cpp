
#include <iostream>
#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/Intern.hpp"


int main() {
    // Bureaucrat basic usage
    Bureaucrat b1("Alice", 42);
    std::cout << b1 << std::endl;
    b1.incrementGrade();
    b1.decrementGrade();

    // Bureaucrat exception (grade too high)
    try {
        Bureaucrat b2("Bob", 0);
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    // Bureaucrat exception (grade too low)
    try {
        Bureaucrat b3("Carl", 151);
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Forms: construction and signing
    PresidentialPardonForm pf("Marvin");
    RobotomyRequestForm rf("Bender");
    ShrubberyCreationForm sf("Garden");

    Bureaucrat signer("Signer", 5);
    pf.beSigned(signer);
    rf.beSigned(signer);
    sf.beSigned(signer);

    // Execute forms (success)
    signer.executeForm(pf);
    signer.executeForm(rf);
    signer.executeForm(sf);

    // Try to execute unsigned form
    PresidentialPardonForm pf2("Unsigned");
    try {
        signer.executeForm(pf2);
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Try to sign with low grade
    Bureaucrat low("Low", 150);
    try {
        pf2.beSigned(low);
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Try to execute with low grade
    pf2.beSigned(signer);
    try {
        low.executeForm(pf2);
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Copy and assignment
    Bureaucrat bcopy = b1;
    bcopy = signer;
    PresidentialPardonForm pfcopy = pf;
    pfcopy = pf2;
    RobotomyRequestForm rcopy = rf;
    rcopy = rf;
    ShrubberyCreationForm scopy = sf;
    scopy = sf;

    // Polymorphism: AForm pointer
    AForm* forms[3];
    forms[0] = new PresidentialPardonForm("Poly1");
    forms[1] = new RobotomyRequestForm("Poly2");
    forms[2] = new ShrubberyCreationForm("Poly3");
    for (int i = 0; i < 3; ++i) {
        forms[i]->beSigned(signer);
        signer.executeForm(*forms[i]);
        delete forms[i];
    }

    // Intern usage: create forms dynamically
    Intern intern;
    AForm* f1 = intern.makeForm("shrubbery form", "TreeTarget");
    AForm* f2 = intern.makeForm("robotomy form", "BotTarget");
    AForm* f3 = intern.makeForm("presidential form", "PresidentTarget");
    AForm* f4 = intern.makeForm("unknown form", "Nobody"); // should fail
    if (f1) {
        f1->beSigned(signer);
        signer.executeForm(*f1);
        delete f1;
    }
    if (f2) {
        f2->beSigned(signer);
        signer.executeForm(*f2);
        delete f2;
    }
    if (f3) {
        f3->beSigned(signer);
        signer.executeForm(*f3);
        delete f3;
    }
    if (!f4) {
        std::cout << "Intern could not create unknown form." << std::endl;
    }

    std::cout << "Partial coverage main complete." << std::endl;
    return 0;
}
