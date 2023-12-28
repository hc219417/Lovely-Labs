/**
 *   @file: main.cc
 * @author: Hannah Culver
 *   @date: January 25, 2022
 *  @brief: lab 2 (sorting and gdb)
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <fstream>
#include "numlist.h"
#include "numlist.cc"

using namespace std;

int main(int argc, char const *argv[]) {

    NumList tmp; //create NumList object

    tmp.load_from_file(cin); //load_from_file function

    int n1; //create not 1 ...
    int n2; //... not 2 ...
    int n3; //... but 3 integers

    cout << "Please enter three numbers: "; //prompt user for input
    cin >> n1 >> n2 >> n3; //take in 3 integers

    tmp.insert(n1); //then insert them
    tmp.insert(n2); //into our object
    tmp.insert(n3); //using the insert function

    tmp.b_sort(); //bubble sort function

    tmp.save_to_file(cout); //save_to_file function

    return 0;
}// main