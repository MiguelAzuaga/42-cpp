#ifndef phonebook_HPP
#define phonebook_HPP

#include <iostream>
#include <cstdlib>
#include "Contact.hpp"

#define MAX_CONTACTS 8
#define DISPLAY_COL_SIZE 10

class PhoneBook
{
	private:
		Contact	_contacts[MAX_CONTACTS];
		int		_contactCount;

	public:
		PhoneBook();
		~PhoneBook();

		void			addContact(const Contact &contact);

		// Getters
		const Contact&	getContact(int index) const;
		int				getContactCount() const;
};

#endif // phonebook_HPP