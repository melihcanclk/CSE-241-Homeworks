#ifndef GTUITERATOR_H
#define GTUITERATOR_H
#include <string>
using namespace std;

namespace STLGTUContainer
{
template <class T>
class GTUIterator
{
public:
    GTUIterator(T *ptr) : ptr_(ptr) {}
    GTUIterator operator++()
    {
        GTUIterator i = *this;
        ptr_++;
        return i;
    }
    GTUIterator operator++(int junk)
    {
        ptr_++;
        return *this;
    }
    GTUIterator operator--()
    {
        GTUIterator i = *this;
        ptr_--;
        return i;
    }
    GTUIterator operator--(int junk)
    {
        ptr_--;
        return *this;
    }
    T &operator*() { return *ptr_; }
    T *operator->() { return ptr_; }
    bool operator==(const GTUIterator &rhs) { return ptr_ == rhs.ptr_; }
    bool operator!=(const GTUIterator &rhs) { return ptr_ != rhs.ptr_; }
    T *getPtr_() const noexcept
    {
        return ptr_;
    }

protected:
    T *ptr_;
};
template <class T>
class GTUIteratorConst
{
public:
    GTUIteratorConst(T *ptr) : ptr_(ptr) {}
    GTUIteratorConst operator++()
    {
        GTUIteratorConst i = *this;
        ptr_++;
        return i;
    }
    GTUIteratorConst operator++(int junk)
    {
        ptr_++;
        return *this;
    }
    GTUIteratorConst operator--()
    {
        GTUIteratorConst i = *this;
        ptr_--;
        return i;
    }
    GTUIteratorConst operator--(int junk)
    {
        ptr_--;
        return *this;
    }
    const T &operator*() { return *ptr_; }
    const T *operator->() { return ptr_; }
    bool operator==(const GTUIteratorConst &rhs) { return ptr_ == rhs.ptr_; }
    bool operator!=(const GTUIteratorConst &rhs) { return ptr_ != rhs.ptr_; }
    const T *getPtr_() const noexcept
    {
        return ptr_;
    }

private:
    T *ptr_;
};

} // namespace STLGTUIterator

#endif