#ifndef GTUSET_H
#define GTUSET_H
#include "GTUContainer.h"
#include <iostream>
#include <memory>

template <class T>
class GTUSet : public GTUContainer <T> {
    public:
        GTUSet(int size);
        GTUSet(){}
        bool empty()override;
        void insert(T inserted)override ;
        int getsize();                      //getter for size of set
        int getCapacity();
        T& operator[](int index);               //Make work easy
    private:
        std::shared_ptr< T > sp;        //array deleter will be add
        int capacity = 1;
        int size = 0;
        const T operator[](int index)const;     //Make work easy

        bool contains(T value);
        void insertSorted(int size, T numberInserted);
};

template<typename T> 
GTUSet<T>::GTUSet(int size) {
    while(size > capacity){
        capacity *= 2;
    } 
    std::shared_ptr< T > spcopy(new T[capacity], std::default_delete<T[]>());
    sp = spcopy;
    std::cout << "constructor called" << std::endl;
}
template<typename T> 
const T GTUSet<T>::operator[](int index) const{
    if(index < 0 || index >= size){
        exit(0);
    }
    return sp.get()[index];
}
template<typename T> 
T& GTUSet<T>::operator[](int index)  {
    return sp.get()[index];
}

template<typename T>
bool GTUSet<T>::contains(T value) {
    for(int i = 0;i<size;i++) {
        if((*this)[i] == value) {
            return true;
        }
    }
    return false;
}

template<typename T>
void GTUSet<T>::insertSorted(int size, T numberInserted) {
    int i;
    for (i = size - 1; (i >= 0 && (*this)[i] > numberInserted); i--)
        (*this)[i + 1] = (*this)[i];

    (*this)[i + 1] = numberInserted;
    this->size++;
}

template<typename T> 
bool GTUSet<T>::empty() {
    return size == 0;
}

template<class T>
void GTUSet<T>::insert(T inserted) {        //Küçükten büyüğe bakma
    if (contains(inserted))
        return;
    if (size >= capacity) {
        capacity *= 2;
        std::shared_ptr< T > spcopy(new T[capacity], std::default_delete<T[]>());
        for(int i = 0;i< capacity / 2 ; i++){
            spcopy.get()[i] = (*this)[i];
        }
        sp = spcopy;
    }
    insertSorted(size,inserted);
}

template<class T>
int GTUSet<T>::getCapacity() {        //Küçükten büyüğe bakma
    return capacity;
}

template<class T>
int GTUSet<T>::getsize() {        //Küçükten büyüğe bakma
    return size;
}

#endif