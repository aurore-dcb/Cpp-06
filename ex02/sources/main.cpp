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
        std::cout << "ptr Type: A" << std::endl;
    } else if (B* b = dynamic_cast<B*>(p)) {
        std::cout << "ptr Type: B" << std::endl;
    } else if (C* c = dynamic_cast<C*>(p)) {
        std::cout << "ptr Type: C" << std::endl;
    } else {
        std::cout << "ptr Type: Unknown" << std::endl;
    }
}

void identify(Base& p) {

    try {
        A& a = dynamic_cast<A&>(p);
        std::cout << "ref Type: A" << std::endl;
        (void)a;
        return;
    } catch (std::exception& e) {}
    try {
        B& b = dynamic_cast<B&>(p);
        std::cout << "ref Type: B" << std::endl;
        (void)b;
        return;
    } catch (std::exception& e) {}
    try {
        C& c = dynamic_cast<C&>(p);
        std::cout << "ref Type: C" << std::endl;
        (void)c;
        return;
    } catch (std::exception& e) {}
    std::cout << "ref Type: Unknown" << std::endl;
}



int main() {

    Base *p = generate();
    identify(p);
    identify(*p);
    delete p;
    
    return (0);
}
