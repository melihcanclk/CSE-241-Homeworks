#include "GTUSet.h"
#include <iostream>
//++ operator'ü range dışına çıkınca exception verecek
//program biterken iterator'ı yanlış delete'liyor.
int main()
{
    GTUSet<int>::GTUIterator i ;
    GTUSet<int> arr(3);
    arr.insert(3);
    arr.insert(7);
    arr.insert(10);
    std::cout << "Capacity: " << arr.max_size() << std::endl;
    std::cout << "Size: " << arr.size()<< std::endl;

    for(i = arr.begin(); i != arr.end(); i++)
    {
        std::cout << **i << " ";
    }
    arr.insert(14);
    
    i = arr.end();  //late assign end function
    
    /*for(i = arr.begin(); i != arr.end(); i++)
    {
        std::cout << **i << " ";
    }*/
    std::cout << std::endl;
    return 0;
}