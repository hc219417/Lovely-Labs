/**
 *   @file: main.cc
 * @author: Hannah Culver
 *   @date: April 11, 2022
 *  @brief: lab 12 (recursion 2)
 */

#include <iostream>
#include <string>
using namespace std;

void convert_to_base(int n, int base);
void reversing(string& s, int start, int end);

int main(){

    int num;
    cout << "Please input an int decimal number: ";
    cin >> num;

    cout << "This number in base 2 is: ";
    convert_to_base(num,2); //converts the number to base 2 (binary)
    cout << "\nThis number in base 3 is: ";
    convert_to_base(num,3); //converts the number to base 3 (ternary)
    cout << "\nThis number in base 7 is: ";
    convert_to_base(num,7); //converts the number to base 7 (septenary)

    cin.ignore();

    string s;
    int start, end;

    cout << "\nEnter a string: ";
    getline(cin,s);

    cout << "Enter two numbers that are within the bounds of the string: ";
    cin >> start >> end;

    cout << "This is how your string looks now: ";
    reversing(s, start, end);

    cout << s << endl;

    return 0;
}

void convert_to_base(int n, int base){
    if(n == 0){
        return;
    }
    convert_to_base(n/base,base);
    cout << n % base;
}

void reversing(string& s, int start, int end){
    char tmp;
    if(start == end){
        return;
    }
    tmp = s[start];
    s[start] = s[end];
    s[end] = tmp;
    reversing(s, start + 1, end - 1);
}