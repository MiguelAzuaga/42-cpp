

#include "../inc/IMateriaSource.hpp"
#include "../inc/ICharacter.hpp"
#include "../inc/AMateria.hpp"

#include "../inc/MateriaSource.hpp"
#include "../inc/Character.hpp"
#include "../inc/Ice.hpp"
#include "../inc/Cure.hpp"
#include <iostream>

int main()
{
    std::cout << "\nTest 1 ----------------------\n";
    {
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());
        ICharacter* me = new Character("me");
        AMateria* tmp;
        tmp = src->createMateria("ice");
        me->equip(tmp);
        tmp = src->createMateria("cure");
        me->equip(tmp);
        ICharacter* bob = new Character("bob");
        me->use(0, *bob);
        me->use(1, *bob);

        delete bob;
        delete me;
        delete src;
    }

    std::cout << "\nTest 2 ----------------------\n";
    {
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Ice());
        ICharacter* me = new Character("me");
        AMateria* tmp;
        tmp = src->createMateria("ICE"); // wrong name
        me->equip(tmp);
        ICharacter* kiko = new Character("kiko");
        me->use(0, *kiko);
        tmp = src->createMateria("ice");
        me->use(0, *kiko); // dont use because not equip
        me->equip(tmp);
        me->use(0, *kiko);

        delete src;
        delete kiko;
        delete me;
    }

    std::cout << "\nTest 3 ----------------------\n";
    {
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());
        ICharacter* me = new Character("me");
        AMateria* tmp;
        tmp = src->createMateria("ice");
        me->equip(tmp);
        me->equip(tmp);
        me->equip(tmp);
        me->equip(tmp);
        me->equip(tmp);
        ICharacter* kiko = new Character("kiko");
        me->use(0, *kiko);
        tmp = src->createMateria("ice");
        me->unequip(0);
        me->unequip(-1); // invalid index
        me->unequip(42); // invalid index
        me->use(0, *kiko); // dont use because not equip
        me->equip(tmp);
        me->use(0, *kiko);

        delete src;
        delete kiko;
        delete me;
    }
        std::cout << "\nTest 4 ---------------------- CLONES\n";
    {
        IMateriaSource* src = new MateriaSource();

        src->learnMateria(new Ice());
        src->learnMateria(new Cure());

        ICharacter* me = new Character("me");
        ICharacter* kiko = new Character("kiko");

        AMateria* tmp;
        tmp = src->createMateria("ice");
        me->equip(tmp);
        me->equip(tmp);
        tmp = src->createMateria("cure");
        me->equip(tmp);
        me->equip(tmp);
        me->equip(tmp);
        me->use(0, *kiko);
        me->use(1, *kiko);
        me->use(2, *kiko);
        me->use(3, *kiko);

        AMateria* cloneTmp(tmp);

        cloneTmp = src->createMateria("ice");
        me->unequip(3);
        me->equip(cloneTmp); // equip with clone ' materia ice'
        me->use(3, *me);
        me->unequip(3);
        me->equip(tmp); // equip with orifinal ' materia cure'
        me->use(3, *me);

        delete src;
        delete me;
        delete kiko;
    }
    return 0;
}