#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource()
{
	for (int i = 0; i < this->_maxMateria; i++)
		this->_materia[i] = 0;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < this->_maxMateria; i++)
		delete this->_materia[i];
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	for (int i = 0; i < this->_maxMateria; i++)
	{
		if (other._materia[i])
			this->_materia[i] = other._materia[i]->clone();
		else
			this->_materia[i] = 0;
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	if (this != &other)
	{
		for (int i = 0; i < this->_maxMateria; i++)
		{
			delete this->_materia[i];
			this->_materia[i] = 0;

			if (other._materia[i])
				this->_materia[i] = other._materia[i]->clone();
		}
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* m)
{
	if (!m)
		return;
	for (int i = 0; i < this->_maxMateria; i++)
	{
		if (!this->_materia[i])
		{
			this->_materia[i] = m;
			return;
		}
	}
	std::cout << "Materia Full! I have only 4 slots to learn!"
			  << std::endl;
	delete m;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < this->_maxMateria; i++)
	{
		if (this->_materia[i] && this->_materia[i]->getType() == type)
			return this->_materia[i];
	}
	std::cout << "Unknown Materia! Please learn first."
			  << std::endl;
	return NULL;
}