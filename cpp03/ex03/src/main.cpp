#include "DiamondTrap.hpp"
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
	printSeparator("TEST 1: CONSTRUCTION HIERARCHY");
	{
		std::cout << "\nCreating ClapTrap:" << std::endl;
		ClapTrap clap("CT");

		std::cout << "\nCreating ScavTrap:" << std::endl;
		ScavTrap scav("ST");

		std::cout << "\nCreating FragTrap:" << std::endl;
		FragTrap frag("FT");

		std::cout << "\nCreating DiamondTrap:" << std::endl;
		DiamondTrap diamond("DT");

		std::cout << "\nDestruction (reverse order):" << std::endl;
	}

	printSeparator("TEST 2: STATS COMPARISON - ALL TYPES");
	{
		ClapTrap clap("Clappy");
		ScavTrap scav("Scavvy");
		FragTrap frag("Fraggy");
		DiamondTrap diamond("Diamondy");

		printStats("ClapTrap ", clap);
		printStats("ScavTrap ", scav);
		printStats("FragTrap ", frag);
		printStats("DiamondTrap", diamond);
	}

	printSeparator("TEST 3: WHOAMI FUNCTIONALITY");
	{
		DiamondTrap diamond("TestBot");
		printStats("Stats", diamond);
		diamond.whoAmI();

		std::cout << std::endl;
		DiamondTrap diamond2("AnotherBot");
		diamond2.whoAmI();
	}

	printSeparator("TEST 4: DIAMONDTRAP ATTACKS (SCAVTRAP STYLE)");
	{
		DiamondTrap diamond("Warrior");
		printStats("Initial", diamond);

		std::cout << "\nAttacking (should use ScavTrap's attack):" << std::endl;
		diamond.attack("Enemy-1");
		diamond.attack("Enemy-2");
		diamond.attack("Enemy-3");
		printStats("After 3 attacks", diamond);
	}

	printSeparator("TEST 5: DIAMONDTRAP HYBRID STATS");
	{
		DiamondTrap diamond("Hybrid");
		printStats("Initial", diamond);

		std::cout << "\nHP: 100 (FragTrap)" << std::endl;
		std::cout << "EP: 50 (ScavTrap)" << std::endl;
		std::cout << "DMG: 30 (FragTrap)" << std::endl;
		std::cout << "Attack: ScavTrap style" << std::endl;
	}

	printSeparator("TEST 6: DIAMONDTRAP DURABILITY");
	{
		DiamondTrap diamond("Tank");
		printStats("Initial", diamond);

		diamond.takeDamage(30);
		printStats("After 30 damage", diamond);

		diamond.takeDamage(40);
		printStats("After 40 more damage", diamond);

		diamond.takeDamage(30);
		printStats("After 30 more damage", diamond);
	}

	printSeparator("TEST 7: DIAMONDTRAP OVERKILL");
	{
		DiamondTrap diamond("Doomed");
		printStats("Initial", diamond);

		diamond.takeDamage(300);
		printStats("After overkill", diamond);

		std::cout << "\nTrying actions when dead:" << std::endl;
		diamond.attack("ghost");
		diamond.beRepaired(10);
		diamond.whoAmI();
		diamond.guardGate();
		diamond.highFivesGuys();
	}

	printSeparator("TEST 8: DIAMONDTRAP REPAIR");
	{
		DiamondTrap diamond("Medic");
		printStats("Initial", diamond);

		diamond.takeDamage(60);
		printStats("After 60 damage", diamond);

		diamond.beRepaired(25);
		printStats("After repair", diamond);

		diamond.beRepaired(50);
		printStats("After big repair", diamond);
	}

	printSeparator("TEST 9: DIAMONDTRAP ENERGY (SCAVTRAP AMOUNT)");
	{
		DiamondTrap diamond("Marathon");
		printStats("Initial", diamond);

		std::cout << "\nPerforming 50 actions (should work - has 50 energy):" << std::endl;
		for (int i = 0; i < 25; i++) {
			diamond.attack("dummy");
		}
		std::cout << "25 attacks done..." << std::endl;
		for (int i = 0; i < 25; i++) {
			diamond.beRepaired(1);
		}
		std::cout << "25 repairs done..." << std::endl;
		printStats("After 50 actions", diamond);

		std::cout << "\nTrying to act with no energy:" << std::endl;
		diamond.attack("dummy");
		diamond.beRepaired(5);
	}

	printSeparator("TEST 10: ALL SPECIAL ABILITIES");
	{
		DiamondTrap diamond("Special");
		printStats("Initial", diamond);

		std::cout << "\nDiamondTrap special:" << std::endl;
		diamond.whoAmI();

		std::cout << "\nScavTrap special:" << std::endl;
		diamond.guardGate();

		std::cout << "\nFragTrap special:" << std::endl;
		diamond.highFivesGuys();

		std::cout << "\nAll specials again:" << std::endl;
		diamond.whoAmI();
		diamond.guardGate();
		diamond.highFivesGuys();
	}

	printSeparator("TEST 11: DIAMONDTRAP COPY CONSTRUCTOR");
	{
		DiamondTrap diamond1("Original");
		diamond1.takeDamage(40);
		diamond1.attack("test");
		diamond1.beRepaired(20);

		printStats("Original before copy", diamond1);
		diamond1.whoAmI();

		std::cout << "\nCreating copy:" << std::endl;
		DiamondTrap diamond2(diamond1);
		printStats("Copy after construction", diamond2);
		diamond2.whoAmI();

		std::cout << "\nModifying copy:" << std::endl;
		diamond2.attack("another test");
		diamond2.takeDamage(10);

		printStats("Copy after modification", diamond2);
		printStats("Original unchanged", diamond1);
	}

	printSeparator("TEST 12: DIAMONDTRAP ASSIGNMENT");
	{
		DiamondTrap diamond1("Source");
		diamond1.takeDamage(50);
		for (int i = 0; i < 10; i++) {
			diamond1.attack("dummy");
		}

		DiamondTrap diamond2("Destination");

		printStats("Before assignment - diamond1", diamond1);
		diamond1.whoAmI();
		printStats("Before assignment - diamond2", diamond2);
		diamond2.whoAmI();

		std::cout << "\nPerforming assignment:" << std::endl;
		diamond2 = diamond1;

		std::cout << "\nAfter diamond2 = diamond1:" << std::endl;
		printStats("diamond1", diamond1);
		diamond1.whoAmI();
		printStats("diamond2", diamond2);
		diamond2.whoAmI();
	}

	printSeparator("TEST 13: COMBAT SCENARIO");
	{
		DiamondTrap diamond("Combatant");
		printStats("Initial", diamond);
		diamond.whoAmI();

		std::cout << "\n=== Round 1 ===" << std::endl;
		diamond.guardGate();
		diamond.attack("enemy");
		diamond.takeDamage(35);
		printStats("After round 1", diamond);

		std::cout << "\n=== Round 2 ===" << std::endl;
		diamond.beRepaired(20);
		diamond.attack("enemy");
		diamond.takeDamage(25);
		printStats("After round 2", diamond);

		std::cout << "\n=== Round 3 ===" << std::endl;
		diamond.highFivesGuys();
		diamond.attack("enemy");
		diamond.takeDamage(40);
		printStats("After round 3", diamond);

		std::cout << "\n=== Final Status ===" << std::endl;
		diamond.whoAmI();
		diamond.beRepaired(30);
		printStats("Final", diamond);
	}

	printSeparator("TEST 14: POLYMORPHISM - ALL FOUR TYPES");
	{
		ClapTrap* army[4];

		army[0] = new ClapTrap("Poly-Clap");
		army[1] = new ScavTrap("Poly-Scav");
		army[2] = new FragTrap("Poly-Frag");
		army[3] = new DiamondTrap("Poly-Diamond");

		std::cout << "\nAll robots via base pointer:" << std::endl;
		for (int i = 0; i < 4; i++) {
			printStats("Robot", *army[i]);
			army[i]->attack("target");
		}

		std::cout << "\nCleanup:" << std::endl;
		for (int i = 0; i < 4; i++) {
			delete army[i];
		}
	}

	printSeparator("TEST 15: NAME DISAMBIGUATION");
	{
		DiamondTrap diamond("NameTest");

		std::cout << "\nDiamondTrap name vs ClapTrap name:" << std::endl;
		diamond.whoAmI();

		std::cout << "\nExpected:" << std::endl;
		std::cout << "- DiamondTrap name: NameTest" << std::endl;
		std::cout << "- ClapTrap name: NameTest_clap_name" << std::endl;
	}

	printSeparator("TEST 16: VIRTUAL INHERITANCE TEST");
	{
		std::cout << "DiamondTrap should have only ONE ClapTrap base" << std::endl;
		std::cout << "This is achieved through virtual inheritance\n" << std::endl;

		DiamondTrap diamond("VirtualTest");
		printStats("Stats", diamond);

		std::cout << "\nIf you see duplicate ClapTrap constructors, virtual inheritance failed!" << std::endl;
		std::cout << "You should see only ONE ClapTrap construction per DiamondTrap." << std::endl;
	}

	printSeparator("TEST 17: STRESS TEST - MULTIPLE DIAMONDS");
	{
		std::cout << "\nCreating multiple DiamondTraps:" << std::endl;
		DiamondTrap d1("Alpha");
		DiamondTrap d2("Beta");
		DiamondTrap d3("Gamma");

		d1.whoAmI();
		d2.whoAmI();
		d3.whoAmI();

		std::cout << "\nAll attacking:" << std::endl;
		d1.attack("target");
		d2.attack("target");
		d3.attack("target");

		std::cout << "\nAll using specials:" << std::endl;
		d1.guardGate();
		d2.highFivesGuys();
		d3.whoAmI();

		printStats("Alpha  ", d1);
		printStats("Beta   ", d2);
		printStats("Gamma  ", d3);

		std::cout << "\nDestruction:" << std::endl;
	}

	printSeparator("TEST 18: EDGE CASE - EXACTLY LETHAL");
	{
		DiamondTrap diamond("ExactDeath");
		printStats("Initial", diamond);

		diamond.takeDamage(100);  // Exactly lethal
		printStats("After exactly 100 damage", diamond);

		diamond.attack("anything");
		diamond.whoAmI();
	}

	printSeparator("END OF TESTS");
	return 0;
}