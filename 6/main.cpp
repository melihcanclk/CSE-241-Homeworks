#include "GTUSet.h"
#include <iostream>

int main()
{
    GTUSet<double> arr(3);
    arr.insert(3);
    arr.insert(7);
    arr.insert(10);
    arr.insert(19);

    for(GTUSet<double>::iterator i = arr.begin(); i != arr.end(); i++)
    {
        std::cout << *i << " ";
    }

    std::cout << std::endl;
    return 0;
}