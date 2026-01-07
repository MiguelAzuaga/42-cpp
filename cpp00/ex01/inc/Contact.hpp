#ifndef contact_HPP
# define contact_HPP

# include <string>

# define MAX_CONTACTS 8

class Contact
{
	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickName;
		std::string	_phoneNumber;
		std::string	_darkestSecret;

	public:
		Contact();
		Contact(const std::string &first,
				const std::string &last,
				const std::string &nick,
				const std::string &phone,
				const std::string &secret);
		~Contact();

		const std::string &getFirstName() const;
		const std::string &getLastName() const;
		const std::string &getNickName() const;
		const std::string &getPhoneNumber() const;
		const std::string &getDarkestSecret() const;
};

#endif // contact_HPP