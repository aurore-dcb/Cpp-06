#include "../includes/ScalarConverter.hpp"

ScalarConverter::ScalarConverter( void ) {}

ScalarConverter::~ScalarConverter( void ) {}

ScalarConverter::ScalarConverter( const ScalarConverter & cpy ) {

    *this = cpy;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& rhs) {

    (void)rhs;
    return *this;
}

void convertFromChar(const std::string& str) {

    std::cout << "char: '" << str[0] << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(str[0]) << std::endl;
    std::cout << "float: " << static_cast<float>(str[0]) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(str[0]) << ".0" << std::endl;
}

void convertFromInt(const std::string& str) {

    int nb;
    convertStrToInt(str, nb);
    if (nb >= 32 && nb <= 126) {
        std::cout << "char: '" << static_cast<char>(nb) << "'" << std::endl;
    } else if ((nb >= 0 && nb <= 32) || nb == 127) {
        std::cout << "char: non displayable" << std::endl;
    } else {
        std::cout << "char: impossible" << std::endl;
    }
    std::cout << "int: " << nb << std::endl;
    std::cout << "float: " << static_cast<float>(nb) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(nb) << ".0" << std::endl;
}

void convertFromFloat(const std::string& str) {

    float nb;
    convertStrToFloat(str, nb);
    if (nb >= 32 && nb <= 126) {
        std::cout << "char: '" << static_cast<char>(nb) << "'" << std::endl;
    } else if ((nb >= 0 && nb <= 32) || nb == 127) {
        std::cout << "char: non displayable" << std::endl;
    } else {
        std::cout << "char: impossible" << std::endl;
    }
    if (nb >= static_cast<float>(-2147483648) && nb <= static_cast<float>(2147483647))
        std::cout << "int: " << static_cast<int>(nb) << std::endl;
    else
        std::cout << "int: impossible" << std::endl;
    if (nb == static_cast<int>(nb)) {
        std::cout << "float: " << static_cast<float>(nb) << ".0f" << std::endl;
    } else {
        std::cout << "float: " << static_cast<float>(nb) << "f" << std::endl;
    }
    if (nb == static_cast<int>(nb)) {
        std::cout << "double: " << static_cast<double>(nb) << ".0" << std::endl;
    } else {
        std::cout << "double: " << static_cast<double>(nb) << std::endl;
    }
}

void convertFromDouble(const std::string& str) {

    double nb;
    convertStrToDouble(str, nb);
    if (nb >= 32 && nb <= 126) {
        std::cout << "char: '" << static_cast<char>(nb) << "'" << std::endl;
    } else if ((nb >= 0 && nb <= 32) || nb == 127) {
        std::cout << "char: non displayable" << std::endl;
    } else {
        std::cout << "char: impossible" << std::endl;
    }
    if (nb >= static_cast<float>(-2147483648) && nb <= static_cast<float>(2147483647))
        std::cout << "int: " << static_cast<int>(nb) << std::endl;
    else
        std::cout << "int: impossible" << std::endl;
    if (nb >= static_cast<double>(std::numeric_limits<float>::min()) && nb <= static_cast<double>(std::numeric_limits<float>::max()))
    {
        if (static_cast<float>(nb) == static_cast<int>(nb))
            std::cout << "float: " << static_cast<float>(nb) << ".0f" << std::endl;
        else
            std::cout << "float: " << static_cast<float>(nb) << "f" << std::endl;
    }
    else
            std::cout << "float: impossible" << std::endl;
    if (nb == static_cast<int>(nb)) {
        std::cout << "double: " << static_cast<double>(nb) << ".0" << std::endl;
    } else {
        std::cout << "double: " << static_cast<double>(nb) << std::endl;
    }
}

void convertFromLim(const std::string& str) {

    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    if (str == "nanf" || str == "-inff" || str == "+inff") {
        std::cout << "float: " << str << std::endl;
    } else {
        std::cout << "float: " << str << "f" << std::endl;
    }
    if (str == "nanf")
        std::cout << "double: nan" << std::endl;
    else if (str == "-inff")
        std::cout << "double: -inf" << std::endl;
    else if (str == "+inff")
        std::cout << "double: +inf" << std::endl;
    else
        std::cout << "double: " << str << std::endl;
}

/* Converti str dans les 3 autres type qu'elle n'est pas */
void ScalarConverter::convert(const std::string& str) {

    if (is_lim(str)) {
        convertFromLim(str);
    } else if (is_char(str)) {
        convertFromChar(str);
    } else if (is_int(str)) {
        convertFromInt(str);
    } else if (is_float(str)) {
        convertFromFloat(str);
    } else if (is_double(str)) {
        convertFromDouble(str);
    } else {
        std::cout << "char: impossible" <<
        std::endl << "int: impossible" <<
        std::endl << "float: impossible" <<
        std::endl << "double: impossible" << std::endl;
    }
}