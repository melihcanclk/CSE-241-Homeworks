#include <iostream>
#include <memory>
#include "GTUContainer.h"

using namespace STLGTUContainer;
using namespace STLGTUIterator;

namespace STLGTUVector
{
template <typename T>
class GTUVector : public GTUContainer<T>
{
public:
    GTUVector(int size);
    GTUVector() {}
    bool empty() override;
    void insert(GTUIterator<T> &iter, T inserted) override;
    int size() override;
    int max_size() override;
    GTUIterator<T> begin() override;
    GTUIterator<T> end() override;
    GTUIteratorConst<T> begin() const;
    GTUIteratorConst<T> end() const;
    void erase(GTUIterator<T> iter) override;
    void clear() override;
    T &operator[](int index);            //Make work easy this will be private
    const T operator[](int index) const; //Make work easy

private:
    std::shared_ptr<T> sp;
    int capacity = 1;
    int size_ = 0;
};
} // namespace STLGTUVector

template <typename T>
STLGTUVector::GTUVector<T>::GTUVector(int size)
{
    while (size > capacity)
    {
        capacity *= 2;
    }
    std::shared_ptr<T> spcopy(new T[capacity], std::default_delete<T[]>());
    sp = spcopy;
}
template <typename T>
const T STLGTUVector::GTUVector<T>::operator[](int index) const //for my own good
{
    throw(index < 0 || index >= size);
    return sp.get()[index];
}
template <typename T>
T &STLGTUVector::GTUVector<T>::operator[](int index) //for my own good
{
    return sp.get()[index];
}

template <typename T>
bool STLGTUVector::GTUVector<T>::empty()
{
    return size_ == 0;
}

template <class T>
int STLGTUVector::GTUVector<T>::size()
{
    return size_;
}
template <class T>
int STLGTUVector::GTUVector<T>::max_size()
{
    return capacity;
}

template <class T>
void STLGTUVector::GTUVector<T>::insert(GTUIterator<T> &iter, T inserted)
{

    int index = 0;
    if (size_ >= capacity)
    {
        capacity *= 2;
        std::shared_ptr<T> spcopy(new T[capacity], std::default_delete<T[]>());

        for (int i = 0; (i < size_ && &(*this)[i + 1] != (iter.getPtr_())); i++)
            index++;

        for (int i = 0; i < capacity / 2; i++)
        {
            spcopy.get()[i] = (*this)[i];
        }
        sp = nullptr; //to delete old shared pointer
        sp = spcopy;
        iter = begin();
        for (int i = 0; i <= index; i++)
            iter++;
    }
    int i;

    for (i = size() - 1; (i >= 0 && &(*this)[i + 1] != (iter.getPtr_())); i--)
        (*this)[i + 1] = (*this)[i];

    (*this)[i + 1] = inserted;
    this->size_++;
}

template <class T>
void STLGTUVector::GTUVector<T>::erase(GTUIterator<T> iter)
{
    bool isAlreadyInserted = false;
    for (auto iter_temp = this->begin(); iter_temp != this->end(); ++iter_temp)
    {
        if (*(iter_temp) == *iter)
        {
            for (auto iter2 = iter_temp; iter2 != this->end(); ++iter2)
            {
                *(iter2) = *(iter2.getPtr_() + 1);
                isAlreadyInserted = true;
            }
        }
    }
    if (isAlreadyInserted)
        this->size_--;
    if (this->size_ <= this->capacity / 2)
        this->capacity /= 2;
}

template <class T>
void STLGTUVector::GTUVector<T>::clear()
{
    this->sp = nullptr;
    *this = GTUVector(0);
}

template <class T>
GTUIterator<T> STLGTUVector::GTUVector<T>::begin()
{
    return GTUIterator<T>(sp.get());
}
template <class T>
GTUIterator<T> STLGTUVector::GTUVector<T>::end()
{
    return GTUIterator<T>(sp.get() + size_);
}
template <class T>
GTUIteratorConst<T> STLGTUVector::GTUVector<T>::begin() const
{
    return GTUIteratorConst<T>(sp.get());
}
template <class T>
GTUIteratorConst<T> STLGTUVector::GTUVector<T>::end() const
{
    return GTUIteratorConst<T>(sp.get() + size_);
}