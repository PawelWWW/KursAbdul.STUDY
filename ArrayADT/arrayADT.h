#ifndef ARRAYADT_H
#define ARRAYADT_H
#include <vector>
#include <initializer_list>
#include <stdexcept>
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

    [[nodiscard]] bool isSorted() const;

    type back() const { return data[length-1]; }
    type front() const { return data[0]; }

};

namespace ADT {
    //SET OPERATIONS
    //Union - A u B

    template<typename type, int size1, int size2>
    arrayADT<type, size1 + size2> merge(const arrayADT<type, size1> &a, const arrayADT<type, size2> &b) {
        if (!a.isSorted() || !b.isSorted())
            throw std::invalid_argument("merge() requires sorted arrays.");

        arrayADT<type, size1 + size2> result;
        int i = 0, j = 0;

        // scalaj, aż jedna tablica się wyczerpie
        while (i < a.getLength() && j < b.getLength()) {
            if (a[i] < b[j]) {
                result.append(a[i++]);
            } else {
                result.append(b[j++]);
            }
        }

        // dodaj pozostałe
        while (i < a.getLength()) {
            result.append(a[i++]);
        }
        while (j < b.getLength()) {
            result.append(b[j++]);
        }

        return result;
    }

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
}
// nie da sie inaczej i guess
#include "arrayADT.hpp"

#endif // ARRAYADT_H
