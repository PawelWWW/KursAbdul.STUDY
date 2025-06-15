#ifndef ARRAYADT_HPP
#define ARRAYADT_HPP

#include <iostream>

template<typename type, int size>
arrayADT<type, size>::arrayADT(const arrayADT<type, size> &other) {
    length = other.length;
    data = new type[size];
    for (int i = 0; i < length; i++) {
        data[i] = other.data[i];
    }
}

template<typename type, int size>
type& arrayADT<type, size>::operator[](unsigned int index) const{
    return data[index];
}

template<typename type, int size>
type arrayADT<type, size>::erase(unsigned int index) {
    type x = data[index];
    if (index<length) { // unsigned int wiec zawsze wiekszy lub rowny 0
        for (unsigned int i = index ; i < length-1 ; i++) {
            data[i] = data[i+1];
        }
        length--;
        return x;
    }
    return x;
}
template<typename type, int size>
arrayADT<type, size>::arrayADT() {
    data = new type[size];
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
inline type *arrayADT<type, size>::begin() {
    return data;
}
template<typename type, int size>
inline type * arrayADT<type, size>::end() {
    return data + length;
}
template<typename type, int size>
arrayADT<type, size>::~arrayADT() {
    delete[] data;
}

template<typename type, int size>
void arrayADT<type, size>::display() {
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
void arrayADT<type, size>::insert(unsigned int index, type t) {
    if (index > length || length >= size) return;
    for (int i = length; i > index; i--) {
        data[i] = data[i - 1];
    }
    data[index] = t;
    length++;
}

template<typename type, int size>
inline int arrayADT<type, size>::getLength() const {
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

#endif // ARRAYADT_HPP
