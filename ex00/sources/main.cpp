#include "../includes/ScalarConverter.hpp"
#include <string>
#include <iostream>
#include <sstream>
#include <limits>

/* convertit de la chaine vers un int */
bool convertStrToInt(const std::string& str, int& nbr) {

    std::istringstream iss(str);
    return !(iss >> nbr).fail();
}

/* convertit de la chaine vers un float */
bool convertStrToFloat(const std::string& str, float& nbr) {

    std::istringstream iss(str);
    return !(iss >> nbr).fail();
}

/* determiner si l'argument est un int, char, float ou double*/
bool is_int(const std::string &str) {
    
    int i = 0;
    int nbr;

    if (str[0] == '-' || str[0] == '+')
        i++;
    while (str[i]) {
        if (str[i] < '0' || str[i] > '9')
            return false;
        i++;
    }
    if (!convertStrToInt(str, nbr) || nbr < -2147483648 || nbr > 2147483647)
        return false;
    return true;
}

bool is_float(const std::string& str) {

    unsigned i = 0;
    float nbr;
    int pts = 0;

    if (str[0] == '-' || str[0] == '+')
        i++;
    while (i < str.length() - 1) {
            // std::cout << "fin" << std::endl;
        if (i == str.length() - 1) {
            if (str[i] != 'f')
                return false;
            i++;
        }
        else if (str[i] == '.') {
            i++;
            pts++;
        }
        else if ((str[i] >= '0' && str[i] <= '9'))
            i++;
        else
            return false;
    }
    if (pts != 1 || str[i] != 'f')
        return false;
    if (!convertStrToFloat(str, nbr) || (nbr < std::numeric_limits<float>::min()) || (nbr > std::numeric_limits<float>::max()))
        std::cout << (nbr < std::numeric_limits<float>::min()) << std::endl;
        // return false;
    if (nbr < std::numeric_limits<float>::min() || nbr > std::numeric_limits<float>::max())
        return false;
    std::cout << !convertStrToFloat(str, nbr) << std::endl;
    std::cout << (nbr > std::numeric_limits<float>::max()) << std::endl;
    std::cout << (nbr < std::numeric_limits<float>::min()) << std::endl;
    std::cout << nbr << std::endl;
    return true;
}


int main(int argc, char **argv) {

    if (argc != 2) {
        std::cerr << "Wrong number of arguments." << std::endl;
        return (1);
    }
    // std::cout << is_int(argv[1]) << std::endl;
    std::cout << is_float(argv[1]) << std::endl;
    // float a = +.05;
    // std::cout << a << std::endl;
    return (0);
}