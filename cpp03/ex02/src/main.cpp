#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

void printSeparator(const std::string& title)
{
    std::cout << "\n" << std::string(50, '=') << std::endl;
    std::cout << title << std::endl;
    std::cout << std::string(50, '=') << std::endl;
}

void printStats(const std::string& label, const ClapTrap& clap)
{
    std::cout << label << ": " << clap << std::endl;
}

int main()
{
    printSeparator("TEST 1: ALL TYPES CONSTRUCTION");
    {
        std::cout << "\nCreating ClapTrap:" << std::endl;
        ClapTrap clap("CT-100");

        std::cout << "\nCreating ScavTrap:" << std::endl;
        ScavTrap scav("ST-200");

        std::cout << "\nCreating FragTrap:" << std::endl;
        FragTrap frag("FT-300");

        std::cout << "\nDestruction (reverse order):" << std::endl;
    }

    printSeparator("TEST 2: STATS COMPARISON");
    {
        ClapTrap clap("Clappy");
        ScavTrap scav("Scavvy");
        FragTrap frag("Fraggy");

        printStats("ClapTrap", clap);
        printStats("ScavTrap", scav);
        printStats("FragTrap", frag);
    }

    printSeparator("TEST 3: FRAGTRAP ATTACKS");
    {
        FragTrap frag("Attacker");
        printStats("Initial", frag);

        frag.attack("Enemy-1");
        frag.attack("Enemy-2");
        frag.attack("Enemy-3");
        printStats("After 3 attacks", frag);
    }

    printSeparator("TEST 4: FRAGTRAP DURABILITY");
    {
        FragTrap frag("Tank");
        printStats("Initial", frag);

        frag.takeDamage(30);
        printStats("After 30 damage", frag);

        frag.takeDamage(50);
        printStats("After 50 more damage", frag);

        frag.takeDamage(20);
        printStats("After 20 more damage", frag);
    }

    printSeparator("TEST 5: FRAGTRAP OVERKILL");
    {
        FragTrap frag("Doomed");
        printStats("Initial", frag);

        frag.takeDamage(250);
        printStats("After overkill", frag);

        std::cout << "\nTrying actions when dead:" << std::endl;
        frag.attack("ghost");
        frag.beRepaired(10);
        frag.highFivesGuys();
    }

    printSeparator("TEST 6: FRAGTRAP REPAIR");
    {
        FragTrap frag("Healer");
        printStats("Initial", frag);

        frag.takeDamage(70);
        printStats("After 70 damage", frag);

        frag.beRepaired(25);
        printStats("After repair", frag);

        frag.beRepaired(100);
        printStats("After mega repair", frag);
    }

    printSeparator("TEST 7: FRAGTRAP ENERGY ENDURANCE");
    {
        FragTrap frag("Energizer");
        printStats("Initial", frag);

        std::cout << "\nPerforming 100 actions:" << std::endl;
        for (int i = 0; i < 50; i++) {
            frag.attack("dummy");
        }
        std::cout << "50 attacks done..." << std::endl;
        for (int i = 0; i < 50; i++) {
            frag.beRepaired(1);
        }
        std::cout << "50 repairs done..." << std::endl;
        printStats("After 100 actions", frag);

        std::cout << "\nTrying to act with no energy:" << std::endl;
        frag.attack("dummy");
        frag.beRepaired(5);
    }

    printSeparator("TEST 8: HIGH FIVES");
    {
        FragTrap frag("Friendly");
        printStats("Initial", frag);

        frag.highFivesGuys();
        frag.highFivesGuys();

        frag.attack("enemy");
        frag.highFivesGuys();

        frag.takeDamage(60);
        frag.highFivesGuys();
    }

    printSeparator("TEST 9: SCAVTRAP VS FRAGTRAP");
    {
        ScavTrap scav("Scav-Fighter");
        FragTrap frag("Frag-Fighter");

        printStats("ScavTrap", scav);
        printStats("FragTrap", frag);

        std::cout << "\nScavTrap attacks:" << std::endl;
        scav.attack("FragTrap");

        std::cout << "\nFragTrap attacks:" << std::endl;
        frag.attack("ScavTrap");

        std::cout << "\nSpecial abilities:" << std::endl;
        scav.guardGate();
        frag.highFivesGuys();
    }

    printSeparator("TEST 10: FRAGTRAP COPY CONSTRUCTOR");
    {
        FragTrap frag1("Original");
        frag1.takeDamage(40);
        frag1.attack("test");
        frag1.beRepaired(10);

        printStats("Original before copy", frag1);

        FragTrap frag2(frag1);
        printStats("Copy after construction", frag2);

        frag2.highFivesGuys();
        printStats("Copy after action", frag2);
        printStats("Original unchanged", frag1);
    }

    printSeparator("TEST 11: FRAGTRAP ASSIGNMENT");
    {
        FragTrap frag1("Source");
        frag1.takeDamage(50);
        for (int i = 0; i < 10; i++) {
            frag1.attack("dummy");
        }

        FragTrap frag2("Destination");

        printStats("Before assignment - frag1", frag1);
        printStats("Before assignment - frag2", frag2);

        frag2 = frag1;
        std::cout << "\nAfter frag2 = frag1:" << std::endl;
        printStats("frag1", frag1);
        printStats("frag2", frag2);
    }

    printSeparator("TEST 12: FRAGTRAP COMBAT SCENARIO");
    {
        FragTrap frag("Warrior");
        printStats("Initial", frag);

        std::cout << "\n=== Round 1 ===" << std::endl;
        frag.attack("enemy");
        frag.takeDamage(35);
        frag.beRepaired(20);
        printStats("After round 1", frag);

        std::cout << "\n=== Round 2 ===" << std::endl;
        frag.highFivesGuys();
        frag.attack("enemy");
        frag.takeDamage(45);
        printStats("After round 2", frag);

        std::cout << "\n=== Round 3 ===" << std::endl;
        frag.beRepaired(30);
        frag.attack("enemy");
        frag.highFivesGuys();
        printStats("After round 3", frag);
    }

    printSeparator("TEST 13: POLYMORPHISM WITH ALL TYPES");
    {
        ClapTrap* bots[3];

        bots[0] = new ClapTrap("Poly-Clap");
        bots[1] = new ScavTrap("Poly-Scav");
        bots[2] = new FragTrap("Poly-Frag");

        std::cout << "\nAll bots via base pointer:" << std::endl;
        for (int i = 0; i < 3; i++) {
            printStats("Bot", *bots[i]);
            bots[i]->attack("target");
        }

        std::cout << "\nCleanup:" << std::endl;
        for (int i = 0; i < 3; i++) {
            delete bots[i];
        }
    }

    printSeparator("TEST 14: ENERGY EFFICIENCY COMPARISON");
    {
        ScavTrap scav("Scav-Energy");
        FragTrap frag("Frag-Energy");

        std::cout << "\nScavTrap - 50 energy:" << std::endl;
        printStats("Initial", scav);
        for (int i = 0; i < 50; i++) {
            scav.attack("dummy");
        }
        printStats("After 50 attacks", scav);
        scav.attack("dummy");  // Should fail

        std::cout << "\nFragTrap - 100 energy:" << std::endl;
        printStats("Initial", frag);
        for (int i = 0; i < 100; i++) {
            frag.attack("dummy");
        }
        printStats("After 100 attacks", frag);
        frag.attack("dummy");  // Should fail
    }

    printSeparator("END OF TESTS");
    return 0;
}