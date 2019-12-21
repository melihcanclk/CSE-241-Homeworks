#include "GTUSet.h"
#include <iostream>

int main()
{
    GTUSet<int> l; // initialize the linked list
    GTUIterator<int> iter;

    for (int i = 1; i <= 10; i++)
    {
        l.insert(i);
    }
    for(iter = l.begin();iter != nullptr;iter++){
        std::cout << (**iter);
    }
    std::cout << std::endl;
    l.insert(0);
    for(iter = l.begin();iter != nullptr;iter++){
        std::cout << (**iter);
    }
    iter++;
    std::cout << (**iter) << std::endl;
    return 0;
}