#include "GTUSet.h"
#include <iostream>
//for loop'da son eleman basmıyor
int main()
{
    GTUSet<int> l; // initialize the linked list
    GTUIterator<int> iter;

    for (int i = 1; i <= 10; i++)
    {
        l.insert(i);
    }
    iter = l.begin();
    for(;iter != l.end();iter++){
        std::cout << (**iter);
    }
    std::cout << std::endl;
    iter--;
    l.erase(iter);
    l.print();
    l.clear();
    l.insert(0);
    l.print();
    return 0;
}