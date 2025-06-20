#ifndef ARRAYADT_HPP
#define ARRAYADT_HPP

#include <iostream>
#include "arrayADT.h"

template<typename type, int size>
arrayADT<type, size>::arrayADT(const arrayADT<type, size> &other) {
    length = other.length;
    data = new type[size];
    for (int i = 0; i < length; i++) {
        data[i] = other.data[i];
    }
}

template<typename type, int size>
type& arrayADT<type, size>::operator[](size_t index) const{
    if (index < length) return data[index]; // index >= 0 nie jest potrzebne, unsigned
    else throw std::out_of_range("index out of range");
}

template<typename type, int size>
type arrayADT<type, size>::erase(size_t index) {
    type x = data[index];
    if (index<length) { // unsigned int wiec zawsze wiekszy lub rowny 0
        for (unsigned int i = index ; i < length-1 ; i++) {
            data[i] = data[i+1];
        }
        length--;
        return x;
    }
    throw std::out_of_range("Array index out of range");
}
template<typename type, int size>
arrayADT<type, size>::arrayADT() {
    data = new type[size];
    length = 0;
}

template<typename type, int size>
arrayADT<type, size>::arrayADT(std::initializer_list<type> init) {
    data = new type[size];
    int i = 0;
    for (auto val : init) {
        if (i >= size) break;
        data[i++] = val;
    }
    length = i;
}
template<typename type, int size>
type *arrayADT<type, size>::begin() const {
    return data;
}
template<typename type, int size>
type * arrayADT<type, size>::end() const {
    return data + length;
}
template<typename type, int size>
arrayADT<type, size>::~arrayADT() {
    delete[] data;
}

template<typename type, int size>
void arrayADT<type, size>::display() const {
    std::cout << "Displaying array elements: ";
    for (int i = 0; i < length; i++) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}

template<typename type, int size>
void arrayADT<type, size>::append(type ap) {
    if (length < size) {
        data[length++] = ap;
    }
}

template<typename type, int size>
void arrayADT<type, size>::insert(size_t index, type t) {
    if (index > length || length >= size) return;
    for (int i = length; i > index; i--) {
        data[i] = data[i - 1];
    }
    data[index] = t;
    length++;
}

template<typename type, int size>
int arrayADT<type, size>::getLength() const {
    return length;
}

template<typename type, int size>
arrayADT<type, size> &arrayADT<type, size>::operator=(const arrayADT<type, size> &other) {
    if (this != &other) {
        delete[] data;
        data = new type[size];
        length = other.length;
        for (int i = 0; i < length; ++i) data[i] = other.data[i];
    }
    return *this;
}
template<typename type, int size>
type* arrayADT<type, size>::max() {
    if (length <= 0) return nullptr;
    type* value = data;
    for (int i = 1 ; i < length ; i++) {
        if (*(data + i) > *value)
            value = data + i;
    }
    return value;
}
template<typename type, int size>
type* arrayADT<type, size>::min() {
    if (length <= 0) return nullptr;
    type* value = data;
    for (int i = 1 ; i < length ; i++) {
        if (*(data + i) < *value)
            value = data + i;
    }
    return value;
}

template<typename type, int size>
template<typename Func>
const type arrayADT<type, size>::accumulate(type* begin, type* end, Func func) const {
    type ret{};
    if (end - begin <= 0) {
        throw std::out_of_range("Invalid iterator range: end must be after begin");
    }

    for (type* start = begin ; start != end ; start++) {
        ret = func(ret, *start);
    }
    // for (int i = 0 ; i < end - begin ; i++ ) {
    //     ret = func(ret, *(begin + i));
    // }
    return ret;
}

template<typename type, int size>
const type arrayADT<type, size>::accumulate(type* begin, type* end) const {
    return accumulate(begin, end, [](type a, type b){ return a + b; } );
}

template<typename type, int size>
const type arrayADT<type, size>::accumulate() const {
    return accumulate(begin(), end(), [](type a, type b){ return a + b; } );
}

template<typename type, int size>
void arrayADT<type, size>::reverse() {
    for (int i = 0, j = length-1; i < j ; i++, j--) {
        std::swap(data[i], data[j]);
    }
}

template<typename type, int size>
void arrayADT<type, size>::leftShift(unsigned int shift) {
    for (int i = 0 ; i < length ; i++) {
        if (i + shift < length ) {
            data[i] = data[i + shift];
        }
        else {
            data[i] = type{};
        }
    }
}

template<typename type, int size>
void arrayADT<type, size>::rotateLeft(unsigned int rotate) {
    if (length == 0 || rotate == 0) return;

    rotate = rotate % length; // jesli jest na przyklad length 5 i rotate 7 to wystarczy przeciez rotate(2)
    type* temp = new type[rotate];
    for (unsigned int i = 0 ; i < rotate ; i ++)
        temp[i] = data[i];

    this->leftShift(rotate);

    for (unsigned int i = length-rotate, j = 0 ; i < length ; i++, j++)
        this->data[i] = temp[j];
    delete[] temp;
}

template<typename type, int size>
bool arrayADT<type, size>::isSorted() const {
    for (int i = 0 ; i < length-1 ; i++) {
        if (data[i] > data[i+1])
            return false;
    }
    return true;
}


#endif // ARRAYADT_HPP
