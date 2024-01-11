#include "../includes/ScalarConverter.hpp"

bool is_char(const std::string& str) {

    if (str.length() == 1) {
        if (str[0] >= '0' && str[0] <= '9')
            return false;
        return true;
    }
    return false;
}

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

    float nbr;
    int pts = 0;
    unsigned int i = 0;

    if (str[0] == '-' || str[0] == '+')
        i++;
    while (i < str.length() - 1) {
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
    if (pts != 1 || str[i] != 'f' || !convertStrToFloat(str, nbr))
        return false;
    if (nbr < -std::numeric_limits<float>::max() || nbr > std::numeric_limits<float>::max())
        return false;
    return true;
}

bool is_double(const std::string& str) {

    double nbr;
    int pts = 0;
    unsigned int i = 0;

    if (str[0] == '-' || str[0] == '+')
        i++;
    while (i < str.length()) {
        if (str[i] == '.') {
            i++;
            pts++;
        }
        else if ((str[i] >= '0' && str[i] <= '9'))
            i++;
        else
            return false;
    }
    if (pts != 1 || !convertStrToDouble(str, nbr))
        return false;
    if (nbr < -std::numeric_limits<double>::max() || nbr > std::numeric_limits<double>::max())
        return false;
    return true;
}
