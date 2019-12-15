#ifndef GTUCONTAINER_H
#define GTUCONTAINER_H
#include <iostream>
#include <memory> 

template <class T> 
class GTUContainer { 
    private: 
        std::shared_ptr <T> ptr;
        int size; 
    public: 
        GTUContainer(T arr[], int s); 
        void print(); 
}; 

#endif