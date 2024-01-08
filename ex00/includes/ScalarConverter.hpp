#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter {

    public :
        ScalarConverter( void );
        ~ScalarConverter( void );
        ScalarConverter( const ScalarConverter& cpy);
        ScalarConverter& operator=(const ScalarConverter& rhs);

        static void convert( std::string str);
};

#endif