#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <string>

class AAnimal
{
protected:
	std::string _type;

public:
	//> Orthodox Canonical Form
	AAnimal();
	AAnimal(const std::string type);
	AAnimal(const AAnimal& other);
	AAnimal& operator=(const AAnimal& other);
	virtual ~AAnimal();

	//> Member Functions
	virtual void makeSound() const = 0;

	//> Getters
	const std::string& getType() const;

};

#endif // AANIMAL_HPP