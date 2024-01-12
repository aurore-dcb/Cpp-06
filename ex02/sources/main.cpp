#include "../includes/Base.hpp"
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"

#include <cstdlib>
#include <ctime>

Base* generate(void) {

    std::srand(static_cast<unsigned>(std::time(NULL)));
    int randomChoice = std::rand() % 3;
    switch (randomChoice) {
        case 0:
            return new A();
        case 1:
            return new B();
        case 2:
            return new C();
        default:
            return NULL;
    }
}

void identify(Base* p) {

    if (A* a = dynamic_cast<A*>(p)) {
        std::cout << "Type: A" << std::endl;
    } else if (B* b = dynamic_cast<B*>(p)) {
        std::cout << "Type: B" << std::endl;
    } else if (C* c = dynamic_cast<C*>(p)) {
        std::cout << "Type: C" << std::endl;
    }
}

void identify(Base& p) {
    
}



int main() {

    Base *r = generate();
    identify(r);
    delete r;
    return (0);
}
