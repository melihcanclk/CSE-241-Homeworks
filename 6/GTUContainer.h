#ifndef GTUCONTAINER_H
#define GTUCONTAINER_H
#include <iostream>
#include <memory> 
#include <iterator>

class GTUContainer { 
    public: 
        virtual bool empty() = 0;
        virtual int size() = 0;
        virtual int max_size() = 0;
        virtual void insert() = 0;
        virtual void erase() = 0;
        virtual void clear() = 0;
        virtual void begin() = 0;
}; 

#endif