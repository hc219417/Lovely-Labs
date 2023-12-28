/**
 *   @file: part1.cc
 * @author: Hannah Culver
 *   @date: February 1, 2022
 *  @brief: lab 3 (static and automatic variables)
 */

#include <iostream>
using namespace std;

void pretty( ){ 
	static int x = 0;
    x++; 

    for(int i = 0; i < x; ++i){ 
        cout << "*"; 
    } 

    cout << endl;
} 

int main(){
    for(int i = 0; i < 6; i++){
        pretty();
    }
    return 0;
}