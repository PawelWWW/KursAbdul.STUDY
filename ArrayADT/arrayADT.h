#ifndef ARRAYADT_H
#define ARRAYADT_H

#include <functional>
#include <initializer_list>
using size_t = unsigned long long;
template<typename type, int size>
class arrayADT {
private:
    int length{};
    type *data;
public:
    arrayADT();
    arrayADT(std::initializer_list<type> init);
    ~arrayADT();
    arrayADT(const arrayADT<type, size> &other);

    arrayADT<type, size> &operator=(const arrayADT<type, size> &other);
    void display() const ;
    void append(type ap);
    void insert(size_t index, type t);
    type& operator[](size_t index) const; // const na koncu musi byc nie modyfikujemy wartosci
    type erase(size_t index);
    type* begin() const ;
    type* end() const ;
    int getLength() const;
    type* max();
    type* min();
    template<typename Func>
    const type accumulate(type* begin, type* end, Func func) const;
    const type accumulate(type* begin, type* end) const ;
    const type accumulate() const ;

    void reverse();
    void leftShift(unsigned int shift);
    void rotateLeft(unsigned int rotate);

    bool isSorted() const;

};

template<typename type, int size>
double average(const arrayADT<type, size> &A) {
    return static_cast<double>(  A.accumulate( A.begin(), A.end() )  ) / A.getLength();
}

template<typename type, int size>
int binarySearch(const arrayADT<type, size> &A, type key) {
    int low = 0;
    int high = A.getLength()-1;
    while (low <= high) {
        int mid = (low+high)/2;
        if (key == A[mid])
            return mid;
        else if (key < A[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}
// nie da sie inaczej i guess
#include "arrayADT.hpp"

#endif // ARRAYADT_H
