#ifndef GTUSET_H
#define GTUSET_H
#include "GTUContainer.h"
#include <iostream>
#include <memory>

template <class T>
class GTUSet : public GTUContainer {
    public:
        GTUSet(int size);
        GTUSet(){}
        const T operator[](int index)const;
        T& operator[](int index);
        bool empty()override;
    private:
        std::shared_ptr< T > sp;        //array deleter will be add
        int capacity;
        int size;
};

template<typename T> 
GTUSet<T>::GTUSet(int size) {
    while(size > capacity){
        capacity *= 2;
    } 
    std::shared_ptr< T > spcopy(new T[capacity], std::default_delete<T[]>());
    sp = spcopy;
    this->size = size;
    std::cout << "constructor called" << std::endl;
}
template<typename T> 
const T GTUSet<T>::operator[](int index) const{
    return sp.get()[index];
}
template<typename T> 
T& GTUSet<T>::operator[](int index) {
    return sp.get()[index];
}
template<typename T> 
bool GTUSet<T>::empty() {
    
}

#endif