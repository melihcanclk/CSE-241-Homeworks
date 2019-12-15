#include "GTUSet.h"
#include "GTUVector.h"
#include <iostream> 
using namespace std; 

int main() { 
    GTUSet <int> a(3);
    a[2] = 3;
    cout << a[2];
    return 0; 
} 