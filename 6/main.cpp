#include "GTUSet.h"
#include "GTUVector.h"
#include <iostream>
#include <memory>
using namespace std;

int main() {
    GTUSet <int> a(5);
    for(int i = 0;i< a.max_size();i++){
        cout << a.sp.get()[i];
    }
    cout << "\n";
    a.insert(4);
    a.insert(44);
    a.insert(56);
    for(int i = 0;i< a.max_size();i++){
        cout << a.sp.get()[i];
    }
    return 0;
}
