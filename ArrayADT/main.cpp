#include "arrayADT.h"
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    arrayADT<int, 5> arr = {1, 2, 3};
    arr.display();
    arr.append(4);
    arr.insert(1, 10);
    arr.display();
    arr.erase(2);
    arr.display();

    arrayADT<string, 3> str ({"pawel", "mis", "jedrzej"});
    str.display();
    str.erase(2);
    str.append("masywny");
    str.display();
    cout << str[0] << endl;
    str[0] = "fajny";
    cout << str[0] << endl;
    str.display();

    arr.display();
    sort(arr.begin(), arr.end());
    arr.display();
    cout << binarySearch(arr, 3) << endl; // samo wykrywa ze <int, 5>


    arrayADT<int, 60> arrBig = {4, 8, 10, 12, 14, 15, 17, 20, 22, 23, 34, 40, 43, 44, 45, 49, 50, 51, 52, 54, 56, 57, 58, 70, 79, 80, 86, 89, 92, 93, 94, 95, 99, 100, 101, 102, 103, 104, 105, 107};
    cout << binarySearch(arrBig, 12) << endl;

    arrayADT<int, 3> first = {1, 2, 3};
    arrayADT<int, 3> second = {4, 5, 6};
    second.display();
    second = first;
    second.display();

    cout << "MAX_OF_SECOND: " << *second.max() << endl;
    *second.max() = 4;
    cout << "MAX_OF_SECOND: " << *second.max() << endl;

    cout << "MIN_OF_SECOND: " << *second.min() << endl;
    *second.min() = 10;
    cout << "MIN_OF_SECOND: " << *second.min() << endl;
    second.display();
    cout << "SUM OF ELEMENTS: " << second.accumulate() << endl; // accumulate(second.begin(), second.end(), [](type a, type b){ return a + b; } );

    cout << average(second)<< endl;
    second.reverse();
    second.display();

    arrayADT<int, 5>  newArray_m = {10,9,8,7,12};
    newArray_m.display();
    newArray_m.leftShift(1);
    newArray_m.display();
    newArray_m.leftShift(1);
    newArray_m.display();
    newArray_m.leftShift(2);
    newArray_m.display();

    arrayADT<int , 5> rotationTest = {10,9,8,7,12};
    rotationTest.display();
    rotationTest.rotateLeft(7);
    rotationTest.display();

    cout << arrBig.isSorted() << endl;


    return 0;
}
