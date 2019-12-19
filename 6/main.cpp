#include "GTUSet.h"
#include <iostream>
//++ operator'ü range dışına çıkınca exception verecek
//program biterken iterator'ı yanlış delete'liyor.
int main()
{
    GTUSet<int>::GTUIterator i;
    GTUSet<int> arr(3);
    arr.insert(3);
    arr.insert(7);
    arr.insert(10);
    std::cout << &arr[0] << "\n" << &arr[1]<< "\n" << &arr[2]<< "\n" ;
    std::cout << "Capacity: " << arr.max_size() << std::endl;
    std::cout << "Size: " << arr.size()<< std::endl;
    i = arr.begin();
    std::cout << *i << std::endl;
    i = arr.end();
    std::cout << *i;
    /*for(; ++i)
    {
        std::cout << *i << " ";
    }*/
    std::cout << std::endl;
    arr.insert(19);
    arr. insert(1);
    std::cout << "Capacity: " << arr.max_size() << std::endl;
    std::cout << "Size: " << arr.size()<< std::endl;
    
    /*for(i = arr.begin(); i != arr.end(); ++i)
    {
        std::cout << *i << " ";
    }*/
    
    std::cout << std::endl;
    return 0;
}