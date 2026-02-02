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
	//> Comparison Operators
	bool operator>(const Fixed& other) const;
	bool operator<(const Fixed& other) const;
	bool operator>=(const Fixed& other) const;
	bool operator<=(const Fixed& other) const;
	bool operator==(const Fixed& other) const;
	bool operator!=(const Fixed& other) const;
	//> Arithmetic Operators
	Fixed operator+(const Fixed& other) const;
	Fixed operator-(const Fixed& other) const;
	Fixed operator*(const Fixed& other) const;
	Fixed operator/(const Fixed& other) const;
	//> Increment/Decrement Operators
	Fixed& operator++(void);
	Fixed& operator--(void);
	// Int symbolizes that the increment/decrement occurs AFTER receiving the pointer
	Fixed operator++(int);
	Fixed operator--(int);

	~Fixed();

	//> Member Functions
	int		toInt( void ) const;
	float	toFloat( void ) const;
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );

	// Min/Max MemFn
	static Fixed& min(Fixed& a, Fixed& b);
	static Fixed& max(Fixed& a, Fixed& b);
	static const Fixed& min(const Fixed& a, const Fixed& b);
	static const Fixed& max(const Fixed& a, const Fixed& b);
};
std::ostream& operator<<(std::ostream& out, const Fixed& in);

#endif // FIXED_HPP