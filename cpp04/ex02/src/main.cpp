#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>
#include <iomanip>

void printSeparator(const std::string& title)
{
	std::cout << "\n" << std::string(50, '=') << std::endl;
	std::cout << title << std::endl;
	std::cout << std::string(50, '=') << std::endl;
}

void printType(const std::string& label, const AAnimal& animal)
{
	std::cout << label << ": type = " << animal.getType() << std::endl;
}

void testDeepCopyDog()
{
	printSeparator("DEEP COPY TEST: DOG");
	Dog dog1;
	dog1.setIdea(0, "Chase cats");
	dog1.setIdea(1, "Eat treats");
	Dog dog2 = dog1; // Copy constructor
	dog2.setIdea(0, "Sleep all day");
	std::cout << "dog1 idea[0]: " << dog1.getIdea(0) << std::endl;
	std::cout << "dog2 idea[0]: " << dog2.getIdea(0) << std::endl;
	std::cout << "dog1 idea[1]: " << dog1.getIdea(1) << std::endl;
	std::cout << "dog2 idea[1]: " << dog2.getIdea(1) << std::endl;
}

void testDeepCopyCat()
{
	printSeparator("DEEP COPY TEST: CAT");
	Cat cat1;
	cat1.setIdea(0, "Climb curtains");
	cat1.setIdea(1, "Nap in sun");
	Cat cat2;
	cat2 = cat1; // Assignment operator
	cat2.setIdea(1, "Knock over glass");
	std::cout << "cat1 idea[0]: " << cat1.getIdea(0) << std::endl;
	std::cout << "cat2 idea[0]: " << cat2.getIdea(0) << std::endl;
	std::cout << "cat1 idea[1]: " << cat1.getIdea(1) << std::endl;
	std::cout << "cat2 idea[1]: " << cat2.getIdea(1) << std::endl;
}

int main()
{
	const int N = 6;
	AAnimal* animals[N];

	printSeparator("AANIMAL ARRAY CREATION");
	for (int i = 0; i < N; ++i) {
		if (i < N / 2) {
			animals[i] = new Dog();
		} else {
			animals[i] = new Cat();
		}
		printType("Created", *animals[i]);
	}

	printSeparator("AANIMAL ARRAY SOUNDS");
	for (int i = 0; i < N; ++i) {
		std::cout << "AAnimal[" << i << "] (" << animals[i]->getType() << ") sound: ";
		animals[i]->makeSound();
	}

	printSeparator("DEEP COPY TESTS");
	testDeepCopyDog();
	testDeepCopyCat();

	printSeparator("AANIMAL ARRAY DELETION");
	for (int i = 0; i < N; ++i) {
		delete animals[i];
	}

	printSeparator("ABSTRACT CLASS TEST");
	// NOTE Uncommenting the following line should cause a compilation error, since AAnimal is abstract:
	// AAnimal test;
	// test.makeSound();

	printSeparator("END OF TESTS");
	return 0;
}