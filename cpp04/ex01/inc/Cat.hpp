#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <string>

class Cat : public Animal
{
private:
	Brain* _brain;
public:
	//> Orthodox Canonical Form
	Cat();
	Cat(const Cat& other);
	Cat& operator=(const Cat& other);
	~Cat();

	//> Member Functions
	void makeSound() const;

	//> Getters & Setters
	std::string getIdea(size_t index) const;
	void setIdea(size_t index, std::string idea);
};

#endif // CAT_HPP