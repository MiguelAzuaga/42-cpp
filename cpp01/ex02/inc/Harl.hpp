#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>

std::string _levels[4]
{
	"DEBUG", "INFO", "WARNING", "ERROR"
};

class Harl
{
	private:


	public:
		Harl();
		~Harl();

		void debug( void );
		void info( void );
		void warning( void );
		void error( void );

		void complain( std::string level );
};

#endif // HARL_HPP