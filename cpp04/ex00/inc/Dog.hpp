#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include <string>

class Dog : public Animal
{
protected:
	std::string _type;

public:
	//> Orthodox Canonical Form
	Dog();
	Dog(const Dog& other);
	Dog& operator=(const Dog& other);
	~Dog();

	//> Member Functions
	void makeSound() const;
};

#endif // DOG_HPP