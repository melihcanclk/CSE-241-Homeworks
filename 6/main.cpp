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
    iter = l.begin();
    std::cout << (**iter) << std::endl;
    iter++;
    std::cout << (**iter) << std::endl;
    iter = l.end();
    std::cout << (**iter) << std::endl;
    iter--;
    std::cout << (**iter) << std::endl;
    l.insert(17);
    l.print();
    l.insert(0);
    l.print();
    return 0;
}