#ifndef GTUCONTAINER_H
#define GTUCONTAINER_H
#include "GTUIterator.h"
#include <memory>


template <class T>
class GTUContainer { 
    public: 
        virtual bool empty() = 0;
        virtual int size() = 0;
        virtual int max_size() = 0;
        virtual void insert(T inserted) = 0;
        virtual void erase(GTUIterator<T> iter) = 0;
        virtual void clear() = 0;
        virtual GTUIterator<T> begin() = 0;
        virtual GTUIterator<T> end() = 0;
       
}; 

#endif