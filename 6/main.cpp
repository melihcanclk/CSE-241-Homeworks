#include "GTUSet.h"
#include <iostream>

int main()
{
    GTUSet<double> point3d(3);
    point3d.insert(3);
    point3d.insert(7);
    point3d.insert(10);

    for(GTUSet<double>::iterator i = point3d.begin(); i != point3d.end(); i++)
    {
        std::cout << *i << " ";
    }

    std::cout << std::endl;
    return 0;
}