#include <iostream>
#include <vector>
#include <memory>
#include <iterator>
#include <cassert>
#include "GTUContainer.h"

template <typename T>
class GTUSet : public GTUContainer<T>
{
    public:
        GTUSet(int size);
        GTUSet(){}
        bool empty()override;
        void insert(T inserted)override ;
        int size()override;
        int max_size()override;

        class iterator
        {
            public:
                iterator(T* ptr) : ptr_(ptr) { }
                iterator operator++() { iterator i = *this; ptr_++; return i; }
                iterator operator++(int junk) { ptr_++; return *this; }
                T& operator*() { return *ptr_; }
                T* operator->() { return ptr_; }
                bool operator==(const iterator & rhs) { return ptr_ == rhs.ptr_; }
                bool operator!=(const iterator & rhs) { return ptr_ != rhs.ptr_; }
            private:
                T* ptr_;
        };

        class const_iterator
        {
            public:
                typedef std::forward_iterator_tag iterator_category;
                const_iterator(T* ptr) : ptr_(ptr) { }
                const_iterator operator++() { const_iterator i = *this; ptr_++; return i; }
                const_iterator operator++(int junk) { ptr_++; return *this; }
                const T& operator*() { return *ptr_; }
                const T* operator->() { return ptr_; }
                bool operator==(const const_iterator& rhs) { return ptr_ == rhs.ptr_; }
                bool operator!=(const const_iterator& rhs) { return ptr_ != rhs.ptr_; }
            private:
                T* ptr_;
        };

        iterator begin()
        {
            return iterator(sp.get());
        }

        iterator end()
        {
            return iterator(sp.get() + size_);
        }

        const_iterator begin() const
        {
            return const_iterator(sp.get());
        }

        const_iterator end() const
        {
            return const_iterator(sp.get() + size_);
        }

    private:
        std::shared_ptr<T> sp;
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