//
//  main.cpp
//  Ordered List
//
//  Created by Allen Moody on 10/24/14.
//  Copyright (c) 2014 FAMU. All rights reserved.
//
#include <fstream>
#include <iostream>
#include <iomanip>
#include "OrderedList.h"

using std::cout;
using std::endl;


int main() {
    const char* filename = "/Users/AJ/Documents/COP3530/Ordered List/Ordered List/test.txt";
    std::ifstream inFile(filename);
    
    // Make sure the file stream is good
    if(!inFile) {
        cout << endl << "Failed to open file " << filename;
        return 1;
    }
    
    OrderedList<long> oList;
    
    long n = 0;
    while(!inFile.eof()) {
        inFile >> n;
        cout << std::setw(5) << n;
        oList.insertItem(n);
    }
    cout << endl;
    inFile.close();
    
    cout << "the sorted list is : " << endl;
    oList.start();
    while (oList.hasNext()) {
        cout << oList.next() << ',' ;
    }
    cout << endl;
    
    return 0;
}