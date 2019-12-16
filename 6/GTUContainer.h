#ifndef GTUCONTAINER_H
#define GTUCONTAINER_H
#include <memory>

template <class T>
class GTUContainer { 
    public: 
        virtual bool empty() = 0;
        virtual int size() = 0;
        /*virtual int max_size() = 0;*/
        virtual void insert(T inserted) = 0;
       /* virtual void erase() = 0;
        virtual void clear() = 0;
        virtual void begin() = 0;*/
}; 

#endif