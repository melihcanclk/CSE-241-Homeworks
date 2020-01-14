/*------------------GEBZE TECHNICAL UNIVERSITY---------------------*
*                    Name : Melihcan Çilek                         *
*                    Student Number : 1801042092                   *
*------------------------------------------------------------------*/
#include "GTUSet.h"
#include "GTUVector.h"
#include <iostream>
using namespace std;
using namespace STLGTUContainer;

template<typename T>
void printSet(GTUSet<T> setForDouble);
template<typename T>
void printVector(GTUVector<T> vectorForInt);

bool isDeviderIntoThree(int i){
    return i%3 ==0;
}

bool isSumGreatherThan30(int i){
    return i>30;
}

template<typename T>
void print (T i) {  
  std::cout << i << ' ' ;
}

template <typename T>
GTUIterator<T> find(GTUIterator<T> first, GTUIterator<T> last, T input){
    for (GTUIterator<double> i = first; i != last; i++)
    {
        if(*i == input){
            return i;
        }
    }
    return last;
}

template <typename T>
GTUIterator<T> find_if(GTUIterator<T> first, GTUIterator<T> last,bool (*f)(T)){
    for (GTUIterator<T> i = first; i != last; i++)
    {
        if((*f)(*i)){
            return i;
        }
    }
}

template <typename T>
GTUIterator<T> for_each(GTUIterator<T> first, GTUIterator<T> last, void (*f)(T)){
    
    for (GTUIterator<T> i = first; i != last; i++)
    {
        (*f)(*i);
    }

}
int main()
{
    GTUSet<double> setForDouble(3); //How to create array of GTUSet pointers
    setForDouble.insert(5.6);
    setForDouble.insert(7.7);
    setForDouble.insert(10.9);
    printSet(setForDouble);
    setForDouble.insert(5.6);
    printSet(setForDouble);
    setForDouble.insert(95.12);
    printSet(setForDouble);
    std::cout << "Finding if 10.9 is in the set or not " << std::endl;
    find(setForDouble.begin(),setForDouble.end(),95.12) == setForDouble.end() ? std::cout << "Not in the set" : std::cout << "In the set" ;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Finding if 85.4 is in the set or not " << std::endl;
    find(setForDouble.begin(),setForDouble.end(),85.4) == setForDouble.end() ? std::cout << "Not in the set" : std::cout << "In the set" ;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Printing all elements of set by using for_each function" << std::endl;
    for_each(setForDouble.begin(),setForDouble.end(),print);
    std::cout << std::endl;
    std::cout << std::endl;
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
    GTUVector<int> vectorForInt(3); //How to create array of GTUVector pointers
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
    std::cout << "First element of that vector that can be devider into three is ";
    std::cout << *(find_if(vectorForInt.begin(),vectorForInt.end(),isDeviderIntoThree));
    std::cout << std::endl;
    std::cout << std::endl;
    iter = vectorForInt.begin();
    vectorForInt.insert(iter, 3);
    printVector(vectorForInt);
    std::cout << "First element of that vector that can be devider into three is ";
    std::cout << *(find_if(vectorForInt.begin(),vectorForInt.end(),isDeviderIntoThree));
    std::cout << std::endl;
    std::cout << std::endl;
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

template <typename T>
void printSet(GTUSet<T> setForDouble)
{
    //cout << "Beginning of the set is " << *(setForDouble.begin()) << endl;
    cout << "Size of setForDouble is " << setForDouble.size() << endl;
    cout << "MaxSize of setForDouble is " << setForDouble.max_size() << endl;
    cout << "Empty of setForDouble is " << setForDouble.empty() << endl;
    for (GTUIterator<T> i = setForDouble.begin(); i != setForDouble.end(); i++)
    {
        std::cout << *i << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;
}

template <typename T>
void printVector(GTUVector<T> vectorForInt)
{
    cout << "Beginning of the vector is " << *(vectorForInt.begin()) << endl;
    cout << "Size of vectorForInt is " << vectorForInt.size() << endl;
    cout << "MaxSize of vectorForInt is " << vectorForInt.max_size() << endl;
    cout << "Empty of vectorForInt is " << vectorForInt.empty() << endl;
    for (GTUIterator<T> iter = vectorForInt.begin(); iter != vectorForInt.end(); iter++)
    {
        std::cout << *iter << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;
}
