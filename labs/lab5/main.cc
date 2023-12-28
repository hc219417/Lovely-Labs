/**
 *   @file: main.cc
 * @author: Hannah Culver
 *   @date: February 15, 2022
 *  @brief: lab 5 (linked lists)
 */

#include <iostream>
#include <string>
#include "list1.h"

using namespace std;

int main(){

    LiList L1, L2;
    string target;

    L1.add("Charlie");
    L1.add("Lisa");
    L1.add("Drew");
    L1.add("Derrick");
    L1.add("AJ");
    L1.add("Bojian");

    cout << "Now showing list one: " << endl;
    L1.show();

    cout << endl;

    cout << "Enter a name to search: ";
    cin >> target;

    if(L1.search(target) != NULL){
        cout << "That name is stored at address: " << L1.search(target) << endl;
    }
    
    else{
        cout << "That name is not in the list" << endl;
        L1.move_front_to_back();
        L1.move_front_to_back();
        L1.show();
    }
    
    return 0;
}