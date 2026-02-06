#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#define MAX_IDEAS 100

class Brain
{
private:
	std::string _ideas[MAX_IDEAS];

public:
	//> Orthodox Canonical Form
	Brain();
	Brain(const Brain& other);
	Brain& operator=(const Brain& other);
	~Brain();

	//> Getters & Setters
	std::string getIdea(size_t index) const;
	void setIdea(size_t index, std::string idea);

};

#endif // BRAIN_HPP