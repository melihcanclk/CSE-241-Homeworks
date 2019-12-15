#include "GTUContainer.cpp"
#include <iostream> 
using namespace std; 

int main() { 
    int arr[5] = {1, 2, 3, 4, 5}; 
    GTUContainer<int> a(arr, 5); 
    a.print(); 
    return 0; 
} 