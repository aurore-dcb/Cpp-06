#include "../includes/Serializer.hpp"
#include "../includes/Data.hpp"
#include <iostream>

void display(Data *data) {
    std::cout << "int: " << data->d1 << ", float: " << data->d2 << std::endl;
}

int main() {

    Data myData;
    myData.d1 = 42;
    myData.d2 = 4.2;
    std::cout << "Initial Data: " << std::endl;
    display(&myData);

    std::cout << std::endl << "Serialization..." << std::endl;
    uintptr_t test = Serializer::serialize(&myData);
    std::cout << "Deserialization..." << std::endl << std::endl;
    Data *newData = Serializer::deserialize(test);

    std::cout << "Final Data: " << std::endl;
    display(newData);

    return (0);
}