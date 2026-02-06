#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal
{
protected:
	std::string _type;

public:
	//> Orthodox Canonical Form
	Animal();
	Animal(const std::string type);
	Animal(const Animal& other);
	Animal& operator=(const Animal& other);
	virtual ~Animal();

	//> Member Functions
	virtual void makeSound() const;

	//> Getters
	const std::string& getType() const;

};

#endif // ANIMAL_HPP