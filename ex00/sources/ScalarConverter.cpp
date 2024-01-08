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