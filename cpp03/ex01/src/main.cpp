#include "ScavTrap.hpp"
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
	printSeparator("TEST 1: CONSTRUCTION CHAINING");
	{
		std::cout << "\nCreating ClapTrap:" << std::endl;
		ClapTrap clap("CT-100");

		std::cout << "\nCreating ScavTrap:" << std::endl;
		ScavTrap scav("ST-200");

		std::cout << "\nDestruction (reverse order):" << std::endl;
	}

	printSeparator("TEST 2: STATS COMPARISON");
	{
		ClapTrap clap("Clappy");
		ScavTrap scav("Scavvy");

		printStats("ClapTrap", clap);
		printStats("ScavTrap", scav);
	}

	printSeparator("TEST 3: SCAVTRAP ATTACKS");
	{
		ScavTrap scav("Warrior");
		printStats("Initial", scav);

		scav.attack("Enemy-1");
		scav.attack("Enemy-2");
		scav.attack("Enemy-3");
		printStats("After 3 attacks", scav);
	}

	printSeparator("TEST 4: SCAVTRAP DURABILITY");
	{
		ScavTrap scav("Tank");
		printStats("Initial", scav);

		scav.takeDamage(30);
		printStats("After 30 damage", scav);

		scav.takeDamage(50);
		printStats("After 50 more damage", scav);

		scav.takeDamage(20);
		printStats("After 20 more damage", scav);
	}

	printSeparator("TEST 5: SCAVTRAP OVERKILL");
	{
		ScavTrap scav("Fragile");
		printStats("Initial", scav);

		scav.takeDamage(200);
		printStats("After overkill", scav);

		std::cout << "\nTrying actions when dead:" << std::endl;
		scav.attack("ghost");
		scav.beRepaired(10);
		scav.guardGate();
	}

	printSeparator("TEST 6: SCAVTRAP REPAIR");
	{
		ScavTrap scav("Medic");
		printStats("Initial", scav);

		scav.takeDamage(60);
		printStats("After 60 damage", scav);

		scav.beRepaired(20);
		printStats("After repair", scav);

		scav.beRepaired(50);
		printStats("After big repair", scav);
	}

	printSeparator("TEST 7: SCAVTRAP ENERGY DEPLETION");
	{
		ScavTrap scav("Marathon");
		printStats("Initial", scav);

		std::cout << "\nPerforming 50 actions (should succeed):" << std::endl;
		for (int i = 0; i < 25; i++) {
			scav.attack("dummy");
		}
		for (int i = 0; i < 25; i++) {
			scav.beRepaired(1);
		}
		printStats("After 50 actions", scav);

		std::cout << "\nTrying to act with no energy:" << std::endl;
		scav.attack("dummy");
		scav.beRepaired(5);
	}

	printSeparator("TEST 8: GATE KEEPER MODE");
	{
		ScavTrap scav("Guardian");
		printStats("Initial", scav);

		scav.guardGate();
		scav.guardGate();
		scav.guardGate();

		scav.takeDamage(50);
		scav.guardGate();
	}

	printSeparator("TEST 9: COPY CONSTRUCTOR");
	{
		ScavTrap scav1("Original");
		scav1.takeDamage(30);
		scav1.attack("test");

		printStats("Original before copy", scav1);

		ScavTrap scav2(scav1);
		printStats("Copy after construction", scav2);

		scav2.attack("another test");
		printStats("Copy after action", scav2);
		printStats("Original unchanged", scav1);
	}

	printSeparator("TEST 10: ASSIGNMENT OPERATOR");
	{
		ScavTrap scav1("Source");
		scav1.takeDamage(40);
		scav1.attack("test");

		ScavTrap scav2("Destination");

		printStats("Before assignment - scav1", scav1);
		printStats("Before assignment - scav2", scav2);

		scav2 = scav1;
		std::cout << "\nAfter scav2 = scav1:" << std::endl;
		printStats("scav1", scav1);
		printStats("scav2", scav2);
	}

	printSeparator("TEST 11: MIXED COMBAT");
	{
		ScavTrap scav("Fighter");
		printStats("Initial", scav);

		scav.guardGate();
		scav.attack("enemy");
		scav.takeDamage(25);
		scav.beRepaired(15);
		scav.attack("enemy");
		scav.takeDamage(30);
		scav.guardGate();
		scav.beRepaired(10);

		printStats("After combat", scav);
	}

	printSeparator("TEST 12: POLYMORPHISM");
	{
		ClapTrap* ptr = new ScavTrap("Polymorphic");
		printStats("Via base pointer", *ptr);

		ptr->attack("test");  // Calls ScavTrap's attack!
		ptr->takeDamage(20);
		ptr->beRepaired(10);

		printStats("After actions", *ptr);

		delete ptr;
	}

	printSeparator("END OF TESTS");
	return 0;
}