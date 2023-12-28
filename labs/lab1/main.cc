/**
 *   @file: main.cc
 * @author: Hannah Culver
 *   @date: January 18, 2022
 *  @brief: lab 1 (operator overloading)
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <cctype>
#include <fstream>
#include "MyTime.h"
#include "MyTime.cc"

using namespace std;

int main(int argc, char const *argv[]) {

    MyTime tmp1;
    MyTime tmp2;
    int scalar;
    
    cout << "Enter first time: ";
    cin >> tmp1;
    cout << "The time you entered is ";
    tmp1.output(cout);
    cout << endl;

    cout << "Enter second time: ";
    cin >> tmp2;
    cout << "The time you entered is ";
    tmp2.output(cout);
    cout << endl;

    cout << "Enter scalar value: ";
    cin >> scalar;

    MyTime tmp_add = tmp1 + tmp2;
    MyTime tmp_sub = tmp1 - tmp2;
    MyTime tmp_mul = tmp1 * scalar;
    MyTime tmp_div = tmp1 / scalar;

    cout << "Addition: " << tmp_add.get_hours() << " hour(s), " << tmp_add.get_minutes() << " minute(s)" << endl;
    cout << "Subtraction: " << tmp_sub.get_hours() << " hour(s), " << tmp_sub.get_minutes() << " minute(s)" << endl;
    cout << "Multiplication: " << tmp_mul.get_hours() << " hour(s), " << tmp_mul.get_minutes() << " minute(s)" << endl;
    cout << "Division: " << tmp_div.get_hours() << " hour(s), " << tmp_div.get_minutes() << " minute(s)" << endl;

    if (tmp1 == tmp2)
    {
        cout << tmp1 << " and " << tmp2 << " are equal" << endl;
    }
    else
    {
        cout << tmp1 << " and " << tmp2 << " are NOT equal" << endl;
    }

    return 0;
}// main