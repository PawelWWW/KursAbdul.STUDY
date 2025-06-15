#ifndef ARRAYADT_H
#define ARRAYADT_H

#include <initializer_list>

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
    void display();
    void append(type ap);
    void insert(unsigned int index, type t);
    type& operator[](unsigned int index) const; // const na koncu musi byc nie modyfikujemy wartosci
    type erase(unsigned int index);
    inline type* begin();
    inline type* end();
    inline int getLength() const;

};
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
