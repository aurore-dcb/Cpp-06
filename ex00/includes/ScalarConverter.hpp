#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>
#include <iostream>

class ScalarConverter {

    public :
        ScalarConverter( void );
        ~ScalarConverter( void );
        ScalarConverter( const ScalarConverter& cpy);
        ScalarConverter& operator=(const ScalarConverter& rhs);

        static void convert( std::string str);
};

// bool is_int(const std::string &str) {
    
//     try {
//         size_t pos;
//         int value = std::stoi(str, &pos);
//         std::cout << "value : " << value << std::endl;
//         if (pos != str.length())
//             return false;
//     }
//     catch (const std::invalid_argument& e) {
//         std::cout << "Exception caught: " << e.what() << std::endl;
//         return false;
//     } catch (const std::out_of_range& e) {
//         std::cout << "Exception caught: " << e.what() << std::endl;
//         return false;
//     }
//     return true;
// }

#endif