#include "../includes/ScalarConverter.hpp"

ScalarConverter::ScalarConverter( void ) {}

ScalarConverter::~ScalarConverter( void ) {}

ScalarConverter::ScalarConverter( const ScalarConverter & cpy) {

    *this = cpy;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& rhs) {

    (void)rhs;
    return *this;
}

/* Convertit str dans les 3 autres type qu'elle n'est pas */
void ScalarConverter::convert( std::string str) {

    (void)str;
}