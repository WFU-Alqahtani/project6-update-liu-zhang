//
// Created by Frankky Boy on 4/5/2020.
//

#ifndef BINARYINSERTIONSORT_MYDATACLASS_H
#define BINARYINSERTIONSORT_MYDATACLASS_H

#include <iostream>
#include <string>

using namespace std;


class myDataClass {
public:
    // default constructor
    myDataClass();

    // constructor
    myDataClass(string name, string position, string weight, string college);

    bool operator<(const myDataClass &rhs);

    bool operator>(const myDataClass &rhs);

    bool operator==(const myDataClass &rhs);

    // this is defined for the assert test on InsertionSort.cpp
    bool operator<=(const myDataClass &rhs);

    friend ostream &operator<<(ostream &out, const myDataClass &obj);

private:
    string name;
    string position;
    string weight;
    string college;
};


#endif //BINARYINSERTIONSORT_MYDATACLASS_H
