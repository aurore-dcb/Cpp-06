#include "../includes/Serializer.hpp"
#include "../includes/Data.hpp"
#include <iostream>

void display(Data *data) {
    std::cout << "Data: " << data->d1 << ", " << data->d2 << std::endl;
}

int main() {

    Data myData;
    myData.d1 = 42;
    myData.d2 = 4.2;
    display(&myData);

    uintptr_t test = Serializer::serialize(&myData);
    Data *newData = Serializer::deserialize(test);

    display(newData);

    return (0);
}