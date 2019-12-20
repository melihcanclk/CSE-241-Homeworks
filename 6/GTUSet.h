#include <iostream>
#include <vector>
#include <memory>
#include <iterator>
#include <cassert>
#include "GTUContainer.h"

template<typename T>
void Deleter( T* ptr);

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
        ~GTUSet(){
        }
        
        class GTUIterator
        {
            public:
                GTUIterator() { }
                GTUIterator(std::shared_ptr<T> ptr);
                GTUIterator(T* ptr) : ptr_(ptr){
                }
                    
                GTUIterator operator++() { 
                    GTUIterator *x= new GTUIterator(ptr_.get() + 1) ;
                    std::swap(this->ptr_,x->ptr_);
                    return *this;
                }
                GTUIterator operator++(int junk) {

                    GTUIterator *x= new GTUIterator(ptr_.get() + 1) ;
                    std::swap(this->ptr_,x->ptr_);
                    return *this;
                }
                std::shared_ptr<T>& operator*() { return ptr_; }
                std::shared_ptr<T> operator->() { return ptr_; }
                bool operator==(const GTUIterator & rhs) { return ptr_ == rhs.ptr_; }
                bool operator!=(const GTUIterator & rhs) { return ptr_ != rhs.ptr_; }
                
            private:
                
                std::shared_ptr<T> ptr_;
        };

        class GTUIteratorConst
        {
            public:
                GTUIteratorConst(T* ptr) : ptr_(ptr) { }
                GTUIteratorConst operator++() { GTUIteratorConst i = *this; ptr_++; return i; }
                GTUIteratorConst operator++(int junk) { ptr_++; return *this; }
                const T& operator*() { return *ptr_; }
                const T* operator->() { return ptr_; }
                bool operator==(const GTUIteratorConst& rhs) { return ptr_ == rhs.ptr_; }
                bool operator!=(const GTUIteratorConst& rhs) { return ptr_ != rhs.ptr_; }
            private:
                T* ptr_;
        };

        GTUIterator begin()
        {
            GTUIterator *x = new GTUIterator( sp.get());
            return *x;
        }

        GTUIterator end()
        {
            auto x = new GTUIterator( sp.get()+ size_ );
            return *x;

        }

        GTUIteratorConst begin() const
        {
            return GTUIteratorConst(sp.get());
        }

        GTUIteratorConst end() const
        {
            return GTUIteratorConst(sp.get() + size_);
        }
        std::shared_ptr<T> sp;
        T& operator[](int index);
        const T operator[](int index)const;     //Make work easy
    private:
        
                       //Make work easy this will be private
        int capacity = 1;
        int size_ = 0;
        
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


template<class T> 
GTUSet<T>::GTUIterator::GTUIterator(std::shared_ptr<T> ptr) : ptr_(ptr)
{
}

template<class T> 
void Deleter(T *ptr)
{
    ptr->deleteMe();
    // And make sure YOU ACTUALLY DELETE (or do whatever else you need to
    // do to release the resource)
    delete ptr;
}