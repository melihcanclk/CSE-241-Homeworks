/*------------------GEBZE TECHNICAL UNIVERSITY---------------------*
*                    Name : Melihcan Çilek                         *
*                    Student Number : 1801042092                   *
*------------------------------------------------------------------*/
#include "GTUSet.h"
#include "GTUVector.h"
#include <iostream>

int main()
{
    GTUSet<char> setforchar; // initialize the linked list
    GTUIterator<char> iter = setforchar.begin();

    setforchar.insert('a');
    setforchar.insert('b');
    setforchar.insert('c');
    setforchar.insert('d');
    setforchar.insert('e');
    setforchar.insert('f');
    setforchar.insert('g');
    for (iter = setforchar.begin(); iter != setforchar.end(); iter++)
    {
        std::cout << (*iter);
    }
    std::cout << std::endl;
    setforchar.insert('h');
    for (iter = setforchar.begin(); iter != setforchar.end(); iter++)
    {
        std::cout << (*iter);
    }
    std::cout << "\n";
    for (iter = setforchar.end(); iter != setforchar.begin(); iter--)
    {
        std::cout << (*iter);
    }
    std::cout << std::endl;
    setforchar.insert('h'); //add same variable to set
    for (iter = setforchar.end(); iter != setforchar.begin(); iter--)
    {
        std::cout << (*iter);
    }
    //iterator at the beginning
    std::cout << std::endl;
    iter++;
    iter++;
    setforchar.erase(iter); //b will be deleted
    for (iter = setforchar.begin(); iter != setforchar.end(); iter++)
    {
        std::cout << (*iter);
    }
    std::cout << std::endl;
    //setforchar.print();

    std::cout << "-----------------------------------------------------------------------------------------------------" << std::endl;
    GTUVector<int> vectorforint;
    GTUIterator<int> itervector = vectorforint.begin();
    for (int i = 0; i<10; i++)
    {
        vectorforint.insert(itervector, i);
        itervector++;
    }

    itervector--;
    vectorforint.insert(itervector,12);
    for (itervector = vectorforint.begin(); itervector != vectorforint.end(); itervector++)
    {
        std::cout << (*itervector);
    }
    std::cout << std::endl;
    for (int i = 0; i<vectorforint.size(); i++)
    {
        std::cout << vectorforint[i];
    }
    return 0;
}
