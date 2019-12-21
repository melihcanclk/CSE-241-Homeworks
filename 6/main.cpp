#include "GTUSet.h"
#include <iostream>
#include <vector>
#include <iterator>

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
     std::cout << (**iter);
    l.insert(0);
    l.print();
    return 0;
}