#ifndef GTUSET_H
#define GTUSET_H
#include "GTUContainer.h"
#include <iostream>
#include <fstream>
#include <memory>

template <class T>
class GTUSet : public GTUContainer <T> {
    public:
        GTUSet(int size);
        GTUSet(){}
        bool empty()override;
        void insert(T inserted)override ;
        int size()override;
        int max_size()override;
        std::shared_ptr< T > sp;        //array deleter will be add

    private:
        T& operator[](int index);               //Make work easy this will be private
        int capacity = 1;
        int size_ = 0;
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
    throw(index < 0 || index >= size);
    return sp.get()[index];
}
template<typename T> 
T& GTUSet<T>::operator[](int index)  {
    return sp.get()[index];
}

template<typename T>
bool GTUSet<T>::contains(T value) {
    for(int i = 0;i<size_;i++) {
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
    this->size_++;
}

template<typename T> 
bool GTUSet<T>::empty() {
    return size_ == 0;
}

template<class T> 
int GTUSet<T>::size(){
    return size_;
}
template<class T> 
int GTUSet<T>::max_size(){
    return capacity;
}

template<class T>
void GTUSet<T>::insert(T inserted) { 
    if (contains(inserted))
        return;
    if (size_ >= capacity) { 
        capacity *= 2;
        std::shared_ptr< T > spcopy(new T[capacity], std::default_delete<T[]>());
        for(int i = 0;i< capacity / 2 ; i++){
            spcopy.get()[i] = (*this)[i];
        }
        sp = spcopy;
    }
    insertSorted(size_,inserted);
}


#endif




/*class GTUIterator{
            public:
                GTUIterator(){}
                GTUIterator(std::shared_ptr< T > sp_) : iter(sp_){}
                GTUIterator operator =(std::shared_ptr< T> x){
                    iter = x;
                    return (*this);
                }
                friend std::ostream & operator <<(std::ostream & outputStream, GTUIterator x) {
                    std::cout << **x ;
                    return outputStream;
                }
                std::shared_ptr<T>& operator *(){
                    return iter;
                }
                std::shared_ptr<T>& operator ->(){
                    return *iter;
                }
                GTUIterator operator ++(){
                    iter++;
                    return *this;
                }
            public:
                std::shared_ptr<T> iter;
        };
        GTUIterator begin() {
            GTUIterator x = sp.get();
            return(GTUIterator(x));
        }*/