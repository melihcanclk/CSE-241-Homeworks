#include "GTUSet.h"
#include "GTUVector.h"
#include <iostream> 
using namespace std; 

int main() { 
    GTUSet <int> a(3);
    cout << a.empty() << endl;
    a.insert(3);
    cout << a.empty() << endl;
    for (int i = 0 ; i < a.getCapacity();i++){
        cout << a[i] ;
    }
    cout << endl;
    a.insert(2);
    for (int i = 0 ; i < a.getCapacity();i++){
        cout << a[i] ;
    }
    cout << endl;
    a.insert(1);
    for (int i = 0 ; i < a.getCapacity();i++){
        cout << a[i] ;
    }
    cout << endl;
    a.insert(7);
    for (int i = 0 ; i < a.getCapacity();i++){
        cout << a[i] ;
    }
    cout << endl;
    a.insert(8);
    for (int i = 0 ; i < a.getCapacity();i++){
        cout << a[i] ;
    }
    cout << endl;
    return 0; 
} 