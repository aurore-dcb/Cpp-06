#include "../includes/Serializer.hpp"

Serializer::Serializer( void ) {}

Serializer::~Serializer( void ) {}

Serializer::Serializer( const Serializer & cpy ) {

    *this = cpy;
}

Serializer& Serializer::operator=(const Serializer& rhs) {

    (void)rhs;
    return *this;
}

uintptr_t Serializer::serialize(Data* ptr) {

    uintptr_t value = reinterpret_cast<uintptr_t>(ptr);
    return value;
}

Data* Serializer::deserialize(uintptr_t raw) {

    Data *value = reinterpret_cast<Data*>(raw);
    return value;
}