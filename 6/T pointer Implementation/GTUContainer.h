#ifndef GTUCONTAINER_H
#define GTUCONTAINER_H
#include "GTUIterator.h"

namespace STLGTUContainer
{
template <class T>
class GTUContainer
{
public:
    virtual bool empty() = 0;
    virtual int size() = 0;
    virtual int max_size() = 0;
    virtual void insert(GTUIterator<T> &iter, T inserted) = 0;
    virtual void erase(GTUIterator<T> iter) = 0;
    virtual void clear() = 0;
    virtual GTUIterator<T> begin() = 0;
    virtual GTUIterator<T> end() = 0;
};

} // namespace STLGTUContainer

#endif