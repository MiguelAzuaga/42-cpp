
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>
#include <string>


void printSeparator(const std::string& title)
{
	std::cout << "\n" << std::string(50, '=') << std::endl;
	std::cout << title << std::endl;
	std::cout << std::string(50, '=') << std::endl;
}

void printAnimal(const std::string& label, const Animal& animal)
{
	std::cout << label << ": Type = " << animal.getType() << ", Sound = ";
	animal.makeSound();
}

void printWrongAnimal(const std::string& label, const WrongAnimal& animal)
{
	std::cout << label << ": Type = " << animal.getType() << ", Sound = ";
	animal.makeSound();
}

int main()
{
	printSeparator("TEST 1: CONSTRUCTION AND DESTRUCTION");
	{
		std::cout << "Creating Animal, Dog, Cat, WrongAnimal, WrongCat..." << std::endl;
		Animal* a = new Animal();
		Animal* d = new Dog();
		Animal* c = new Cat();
		WrongAnimal* wa = new WrongAnimal();
		WrongAnimal* wc = new WrongCat();
		std::cout << "Deleting all..." << std::endl;
		delete a;
		delete d;
		delete c;
		delete wa;
		delete wc;
	}


	printSeparator("TEST 2: POLYMORPHISM - ANIMAL ARRAY");
	{
		Animal* zoo[4];
		zoo[0] = new Dog();
		zoo[1] = new Dog();
		zoo[2] = new Cat();
		zoo[3] = new Cat();
		for (int i = 0; i < 4; ++i) {
			std::cout << "Animal[" << i << "] type: " << zoo[i]->getType() << ", sound: ";
			zoo[i]->makeSound();
		}
		for (int i = 0; i < 4; ++i) delete zoo[i];
	}

	printSeparator("TEST 3: POLYMORPHISM - WRONGANIMAL ARRAY");
	{
		WrongAnimal* wrongZoo[2];
		wrongZoo[0] = new WrongAnimal();
		wrongZoo[1] = new WrongCat();
		for (int i = 0; i < 2; ++i) {
			std::cout << "WrongAnimal[" << i << "] type: " << wrongZoo[i]->getType() << ", sound: ";
			wrongZoo[i]->makeSound();
		}
		for (int i = 0; i < 2; ++i) delete wrongZoo[i];
	}

	printSeparator("TEST 4: COPY CONSTRUCTION");
	{
		Dog d1;
		Dog d2(d1);
		Cat c1;
		Cat c2(c1);
		printAnimal("Dog d1", d1);
		printAnimal("Dog d2", d2);
		printAnimal("Cat c1", c1);
		printAnimal("Cat c2", c2);
	}

	printSeparator("TEST 5: ASSIGNMENT OPERATOR");
	{
		Dog d1;
		Dog d2;
		d2 = d1;
		Cat c1;
		Cat c2;
		c2 = c1;
		printAnimal("Dog d1", d1);
		printAnimal("Dog d2", d2);
		printAnimal("Cat c1", c1);
		printAnimal("Cat c2", c2);
	}

	printSeparator("TEST 6: BASE CLASS SOUND");
	{
		Animal a;
		printAnimal("Animal", a);
		WrongAnimal wa;
		printWrongAnimal("WrongAnimal", wa);
	}

	printSeparator("END OF TESTS");
	return 0;
}