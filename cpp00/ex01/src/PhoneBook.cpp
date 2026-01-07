#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
	: _contactCount(0)
{
}

PhoneBook::~PhoneBook() {}

void PhoneBook::addContact(const Contact &contact)
{
	_contacts[_contactCount++ % 8] = contact;
	std::cout << "Contact added successfully!\n" << std::endl;
}

const Contact &PhoneBook::getContact(int index) const
{
	return _contacts[index];
}

int PhoneBook::getContactCount() const
{
	return (_contactCount < 8 ? _contactCount : 8);
}