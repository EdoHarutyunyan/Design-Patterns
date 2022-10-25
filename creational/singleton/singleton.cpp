#include <iostream>
#include "singleton.h"

Singleton* Singleton::s_instance = 0;

Singleton* Singleton::get_instance()
{
    if(!s_instance) {
        s_instance = new Singleton();
        std::cout << "There is no instance so we created one.\n";
        return s_instance;
    }
    else {
        std::cout << "Hey this is the same instance!\n";
        return s_instance;
    }
}
