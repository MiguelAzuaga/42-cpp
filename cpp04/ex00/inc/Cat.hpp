#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include <string>

class Cat : public Animal
{
protected:
	std::string _type;

public:
	//> Orthodox Canonical Form
	Cat();
	Cat(const Cat& other);
	Cat& operator=(const Cat& other);
	~Cat();

	//> Member Functions
	void makeSound() const;
};

#endif // CAT_HPP