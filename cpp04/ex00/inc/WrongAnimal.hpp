#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>

class WrongAnimal
{
protected:
	std::string _type;

public:
	//> Orthodox Canonical Form
	WrongAnimal();
	WrongAnimal(const std::string type);
	WrongAnimal(const WrongAnimal& other);
	WrongAnimal& operator=(const WrongAnimal& other);
	virtual ~WrongAnimal();

	//> Member Functions
	void makeSound() const;

	//> Getters
	const std::string& getType() const;

};

#endif // WRONGANIMAL_HPP