#ifndef FIXED_HPP
# define FIXED_HPP
# include <ostream>


class Fixed
{
private:
	int _rawBits;
	static const int _fractBits;
public:
	Fixed();
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& other);
	~Fixed();

	int		toInt( void ) const;
	float	toFloat( void ) const;
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
};
std::ostream& operator<<(std::ostream& out, Fixed const& in);

#endif // FIXED_HPP