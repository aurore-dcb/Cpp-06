#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <stdint.h>
#include "../includes/Data.hpp"

class Serializer {

    public :
        Serializer( const Serializer& cpy);
        Serializer& operator=(const Serializer& rhs);

        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
    
    private :
        Serializer( void );
        ~Serializer( void );
};

#endif