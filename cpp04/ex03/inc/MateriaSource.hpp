#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"
#include <string>

class MateriaSource : public IMateriaSource
{
private:
	static const int _maxMateria = 4;
	AMateria* _materia[_maxMateria];

public:
	//> Orthodox Canonical Form
	MateriaSource();
	MateriaSource(const MateriaSource& other);
	MateriaSource& operator=(const MateriaSource& other);
	~MateriaSource();

	//> Member Functions
	void learnMateria(AMateria* m);
	AMateria* createMateria(const std::string& type);
};

#endif // MATERIASOURCE_HPP