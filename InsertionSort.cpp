#include <iostream>
#include <vector>
#include <cassert>
#include "BinaryInsertionSort.h"
#include "Node.h"
#include "fstream"
#include "myDataClass.h"

using namespace std;

int main() {

    ifstream inFile;
    string filename;
    //read the file name of your dataset
    filename = "CSC112_Project_6_NBA_Dataset_Frank_Jingwen.csv";
    inFile.open(filename);
    if (!inFile.is_open()) {
        cout << " Could not open NBA dataset" << endl;
        return 1; // something bad happened , return non‐zero
    }

    vector<myDataClass> v;
    // populate the vector with the data from your data set
    string tmp;
    string name;
    string position;
    string weight;
    string college;
    // get the first line of the data first since it is the title and we really don want it
    getline(inFile, tmp);
    // use .eof to iterate until the end of the dataset
    while (!inFile.eof()) {
        if (!inFile.fail()) { // check to make sure all data is read in successfully
            // use getline to get my string until the ',', which is the first column of my dataset
            getline(inFile, name, ',');  // store the first column as name
            getline(inFile, tmp, ',');   // 2nd column is useless
            getline(inFile, tmp, ',');   // 3rd column is useless
            getline(inFile, position, ',');   // store the forth column as position
            getline(inFile, weight, ',');   //  store the fifth column as weight
            getline(inFile, tmp, ',');   // 6th column is useless
            getline(inFile, college);   // store the 7th column as college
            myDataClass a(name, position, weight, college);
            v.push_back(a);
        }
    }

    // binary insertion sort
    insertionSort(v, v.size());

    // check if sorted
    for (int i = 1; i < v.size(); i++) {
        assert(v[i - 1] <= v[i]);
    }

    // print out sorted list
    for (int i = 0; i < v.size(); i++) {
        //you should ovrride << to YourClass
        cout << v[i] << endl;
    }

    // FINISH ME
    inFile.close();
    return 0;
}