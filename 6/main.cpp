#include "GTUSet.h"
#include <iostream>

int main()
{
    GTUSet<char> setforchar; // initialize the linked list
    GTUIterator<char> iter;

    setforchar.insert('a');
    setforchar.insert('b');
    setforchar.insert('c');
    setforchar.insert('d');
    setforchar.insert('e');
    setforchar.insert('f');
    setforchar.insert('g');
    for(iter = setforchar.begin();iter != setforchar.end();iter++){
        std::cout << (**iter);
    }
    std::cout << std::endl;
    setforchar.insert('h');
    for(iter = setforchar.begin();iter != setforchar.end();iter++){
        std::cout << (**iter);
    }
    std::cout << "\n";
    for(iter = setforchar.end();iter != setforchar.begin();iter--){
        std::cout << (**iter);
    }
    std::cout << std::endl;
    setforchar.insert('h');
    for(iter = setforchar.end();iter != setforchar.begin();iter--){
        std::cout << (**iter);
    }
    std::cout << std::endl;
    setforchar.insert('i');
    for(iter = setforchar.end();iter != setforchar.begin();iter--){
        std::cout << (**iter);
    }
    std::cout << std::endl;
    setforchar.clear();
    for(iter = setforchar.end();iter != setforchar.begin();iter--){
        std::cout << (**iter);
    }
    std::cout << std::endl;
    //setforchar.print();
    return 0;
}