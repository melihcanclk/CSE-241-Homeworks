#include "GTUSet.h"
#include "GTUVector.h"
#include <iostream>
using namespace std;

void printSet(STLGTUSet::GTUSet<double> setForDouble);
void printVector(STLGTUVector::GTUVector<int> vectorForInt);

int main()
{
    STLGTUSet::GTUSet<double> setForDouble(3); //How to create array of GTUset pointers
    setForDouble.insert(5.6);
    setForDouble.insert(7.7);
    setForDouble.insert(10.9);
    printSet(setForDouble);
    setForDouble.insert(5.6);
    printSet(setForDouble);
    setForDouble.insert(95.12);
    printSet(setForDouble);
    GTUIterator<double> i = setForDouble.begin();
    i++;
    setForDouble.erase(i);
    printSet(setForDouble);
    setForDouble.erase(i);
    printSet(setForDouble);
    i = setForDouble.begin();
    setForDouble.insert(i, 55);
    printSet(setForDouble);
    i = setForDouble.begin();
    setForDouble.insert(i, 96);
    printSet(setForDouble);
    setForDouble.clear();
    printSet(setForDouble);
    setForDouble.insert(6.4);
    setForDouble.insert(3.7);
    setForDouble.insert(143.1243);
    printSet(setForDouble);

    cout << "----------------------------------------------------\n";
    STLGTUVector::GTUVector<int> vectorForInt(3); //How to create array of GTUset pointers
    GTUIterator<int> iter = vectorForInt.begin();
    vectorForInt.insert(iter, 6);
    iter++;
    vectorForInt.insert(iter, 45);
    iter++;
    vectorForInt.insert(iter, 8);
    iter++;
    vectorForInt.insert(iter, 123);
    printVector(vectorForInt);
    iter++;
    vectorForInt.insert(iter, 554);
    printVector(vectorForInt);
    iter++;
    vectorForInt.insert(iter, 66);
    printVector(vectorForInt);
    iter--;
    iter--;
    vectorForInt.erase(iter);
    printVector(vectorForInt);
    iter--;
    vectorForInt.erase(iter);
    printVector(vectorForInt);
    vectorForInt.insert(iter, 45);
    printVector(vectorForInt);
    iter++;
    vectorForInt.insert(iter, 85);
    printVector(vectorForInt);
    iter++;
    vectorForInt.clear();
    printVector(vectorForInt);
    iter = vectorForInt.begin();
    vectorForInt.insert(iter, 65);
    iter++;
    vectorForInt.insert(iter, 77);
    iter++;
    vectorForInt.insert(iter, 123);
    printVector(vectorForInt);
    return 0;
}

void printSet(STLGTUSet::GTUSet<double> setForDouble)
{
    //cout << "Beginning of the set is " << *(setForDouble.begin()) << endl;
    cout << "Size of setForDouble is " << setForDouble.size() << endl;
    cout << "MaxSize of setForDouble is " << setForDouble.max_size() << endl;
    cout << "Empty of setForDouble is " << setForDouble.empty() << endl;
    for (GTUIterator<double> i = setForDouble.begin(); i != setForDouble.end(); i++)
    {
        std::cout << *i << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;
}
void printVector(STLGTUVector::GTUVector<int> vectorForInt)
{
    cout << "Beginning of the vector is " << *(vectorForInt.begin()) << endl;
    cout << "Size of vectorForInt is " << vectorForInt.size() << endl;
    cout << "MaxSize of vectorForInt is " << vectorForInt.max_size() << endl;
    cout << "Empty of vectorForInt is " << vectorForInt.empty() << endl;
    for (GTUIterator<int> iter = vectorForInt.begin(); iter != vectorForInt.end(); iter++)
    {
        std::cout << *iter << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;
}