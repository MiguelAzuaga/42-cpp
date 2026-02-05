#include "ClapTrap.hpp"
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
	printSeparator("TEST 1: CONSTRUCTION & DESTRUCTION");
	{
		ClapTrap clap1;
		ClapTrap clap2("CT-2023");
		ClapTrap clap3(clap2);

		printStats("Default", clap1);
		printStats("Named", clap2);
		printStats("Copy", clap3);
	}

	printSeparator("TEST 2: BASIC ATTACKS");
	{
		ClapTrap clap("Attacker");
		printStats("Initial", clap);

		clap.attack("Target-1");
		clap.attack("Target-2");
		clap.attack("Target-3");
		printStats("After 3 attacks", clap);
	}

	printSeparator("TEST 3: TAKING DAMAGE");
	{
		ClapTrap clap("Tank");
		printStats("Initial", clap);

		clap.takeDamage(3);
		printStats("After 3 damage", clap);

		clap.takeDamage(5);
		printStats("After 5 more damage", clap);

		clap.takeDamage(2);
		printStats("After 2 more damage", clap);
	}

	printSeparator("TEST 4: OVERKILL DAMAGE");
	{
		ClapTrap clap("Fragile");
		printStats("Initial", clap);

		clap.takeDamage(100);
		printStats("After overkill", clap);

		std::cout << "\nTrying to attack when dead:" << std::endl;
		clap.attack("ghost");

		std::cout << "\nTrying to repair when dead:" << std::endl;
		clap.beRepaired(5);
	}

	printSeparator("TEST 5: REPAIR");
	{
		ClapTrap clap("Medic");
		printStats("Initial", clap);

		clap.takeDamage(7);
		printStats("After damage", clap);

		clap.beRepaired(3);
		printStats("After repair", clap);

		clap.beRepaired(10);
		printStats("After big repair", clap);
	}

	printSeparator("TEST 6: ENERGY DEPLETION");
	{
		ClapTrap clap("Marathon");
		printStats("Initial", clap);

		std::cout << "\nAttacking 10 times (should succeed):" << std::endl;
		for (int i = 0; i < 10; i++) {
			clap.attack("dummy");
		}
		printStats("After 10 attacks", clap);

		std::cout << "\nTrying to attack with no energy:" << std::endl;
		clap.attack("dummy");

		std::cout << "\nTrying to repair with no energy:" << std::endl;
		clap.beRepaired(5);
	}

	printSeparator("TEST 7: MIXED ACTIONS");
	{
		ClapTrap clap("Warrior");
		printStats("Initial", clap);

		clap.attack("enemy");
		clap.takeDamage(4);
		clap.beRepaired(2);
		clap.attack("enemy");
		clap.takeDamage(3);
		clap.beRepaired(1);
		printStats("After combat", clap);
	}

	printSeparator("TEST 8: ASSIGNMENT OPERATOR");
	{
		ClapTrap clap1("Original");
		clap1.takeDamage(5);
		clap1.attack("test");

		ClapTrap clap2("Copy");
		printStats("Before assignment - clap1", clap1);
		printStats("Before assignment - clap2", clap2);

		clap2 = clap1;
		std::cout << "\nAfter clap2 = clap1:" << std::endl;
		printStats("clap1", clap1);
		printStats("clap2", clap2);
	}

	printSeparator("TEST 9: EDGE CASE - EXACTLY LETHAL DAMAGE");
	{
		ClapTrap clap("Doomed");
		printStats("Initial", clap);

		clap.takeDamage(10);  // Exactly lethal
		printStats("After exactly lethal damage", clap);

		clap.attack("anything");
	}

	printSeparator("TEST 10: REPAIR SPAM");
	{
		ClapTrap clap("Healer");
		printStats("Initial", clap);

		std::cout << "\nRepairing 5 times:" << std::endl;
		for (int i = 0; i < 5; i++) {
			clap.beRepaired(2);
		}
		printStats("After 5 repairs", clap);
	}

	printSeparator("END OF TESTS");
	return 0;
}