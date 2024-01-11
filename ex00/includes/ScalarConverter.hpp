#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <limits>
#include <cctype>

class ScalarConverter {

    public :
        ScalarConverter( void );
        ~ScalarConverter( void );
        ScalarConverter( const ScalarConverter& cpy);
        ScalarConverter& operator=(const ScalarConverter& rhs);

        static void convert( const std::string& str );
};

bool is_char(const std::string& str);
bool is_int(const std::string &str);
bool is_float(const std::string& str);
bool is_double(const std::string& str);
bool is_lim(const std::string& str);

bool convertStrToInt(const std::string& str, int& nbr);
bool convertStrToFloat(const std::string& str, float& nbr);
bool convertStrToDouble(const std::string& str, double& nbr);


#endif