#ifndef WRONGWrongCat_HPP
#define WRONGWrongCat_HPP

#include "WrongAnimal.hpp"
#include <string>

class WrongCat : public WrongAnimal
{
protected:
	std::string _type;

public:
	//> Orthodox Canonical Form
	WrongCat();
	WrongCat(const WrongCat& other);
	WrongCat& operator=(const WrongCat& other);
	~WrongCat();

	//> Member Functions
	void makeSound() const;
};

#endif // WRONGWrongCat_HPP