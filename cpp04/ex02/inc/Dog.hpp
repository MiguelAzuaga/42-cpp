#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"
#include <string>

class Dog : public AAnimal
{
private:
	Brain* _brain;
public:
	//> Orthodox Canonical Form
	Dog();
	Dog(const Dog& other);
	Dog& operator=(const Dog& other);
	~Dog();

	//> Member Functions
	void makeSound() const;

	//> Getters & Setters
	std::string getIdea(size_t index) const;
	void setIdea(size_t index, std::string idea);
};

#endif // DOG_HPP