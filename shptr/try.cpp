// Sample custom iterator.
// By perfectly.insane (http://www.dreamincode.net/forums/index.php?showuser=76558)
// From: http://www.dreamincode.net/forums/index.php?showtopic=58468

#include <iostream>
#include <memory>
#include <cassert>

template <typename T>
class fixed_array
{
    public:

        class iterator
        {
            public:

                iterator(std::shared_ptr<T> ptr) : ptr_(ptr) { }
                iterator operator++() { iterator i = *this; ptr_++; return i; }
                iterator operator++(int junk) { ptr_++; return *this; }
                std::shared_ptr<T>& operator*() { return ptr_; }
                std::shared_ptr<T> operator->() { return ptr_; }
                bool operator==(const iterator& rhs) { return ptr_ == rhs.ptr_; }
                bool operator!=(const iterator& rhs) { return ptr_ != rhs.ptr_; }
            private:
                std::shared_ptr<T> ptr_;
        };

        class const_iterator
        {
            public:

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


        fixed_array(int size) : size_(size) {
            while(size > capacity){
                capacity *= 2;
            } 
            std::shared_ptr< T > spcopy(new T[capacity], std::default_delete<T[]>());
            data_ = spcopy;
            std::cout << "constructor called" << std::endl;
        }

        int size() const { return size_; }

        T& operator[](int index)
        {
            assert(index < size_);
            return data_.get()[index];
        }

        const T& operator[](int index) const
        {
            assert(index < size_);
            return data_[index];
        }

        iterator begin()
        {
            return iterator(data_);
        }

        iterator end()
        {
            T * x = data_.get();
            std::shared_ptr<T> cpy(x + size_);
            return iterator(cpy);
        }

        const_iterator begin() const
        {
            return const_iterator(data_);
        }

        const_iterator end() const
        {
            return const_iterator(data_ + size_);
        }

    private:
        std::shared_ptr<T> data_;
        int size_;
        int capacity = 1;
};


int main()
{
    fixed_array<double> point3d(3);
    point3d[0] = 3.2;
    point3d[1] = 2.3;
    point3d[2] = 4.2;

    for(fixed_array<double>::iterator i = point3d.begin(); i != point3d.end(); i++)
    {
        std::cout << *i << " ";
    }

    std::cout << std::endl;
    return 0;
}