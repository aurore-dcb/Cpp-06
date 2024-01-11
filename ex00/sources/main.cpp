#include "../includes/ScalarConverter.hpp"

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

/* convertit de la chaine vers un double */
bool convertStrToDouble(const std::string& str, double& nbr) {

    std::istringstream iss(str);
    return !(iss >> nbr).fail();
}

int main(int argc, char **argv) {

    if (argc != 2) {
        std::cerr << "Wrong number of arguments." << std::endl;
        return (1);
    }
    ScalarConverter::convert(argv[1]);
    return (0);
}