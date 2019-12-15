#include "GTUContainer.h"
#include <iostream>

template <typename T> 
GTUContainer<T>::GTUContainer(T arr[], int s) { 
    ptr = new T[s]; 
    size = s; 
    for(int i = 0; i < size; i++) 
        ptr[i] = arr[i]; 
} 
  
template <typename T> 
void GTUContainer<T>::print() { 
    for (int i = 0; i < size; i++) 
        std::cout<<" "<<*(ptr + i); 
    std::cout << std::endl; 
} 