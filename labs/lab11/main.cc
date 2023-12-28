/**
 *   @file: main.cc
 * @author: Hannah Culver
 *   @date: April 4, 2022
 *  @brief: lab 11 (recursion)
 */

#include <iostream>
using namespace std;

void counting(int n);

// helping function of see_stars to print stars
// should print n stars on the same line
// needs to be recursive
void print_stars(int n);

// calls print_stars in the body; also needs to be recursive
void see_stars(int count, int stop);

int main(){

    int x;
    for(int j = 0; j < 3; ++j){
        cout << "Enter a number: ";
        cin >> x;
        cout << "The even numbers counting up to there:" << endl;
        counting(x);
    }

    int n;
    cout << "Enter a number between 1 and 30 to see the stars: ";
    cin >> n;
    see_stars(1, n);

    return 0;
}

void counting(int n){
    if(n < 0){ //number is negative
        return;
    }
    else if(n % 2 == 1){ //number is odd
        cout << n - 1 << endl;
        n = n - 3;
        counting(n);
    }
    else{ //number is even
        cout << n << endl;
        n = n - 2;
        counting(n);
    }
}

void print_stars(int n){
    if(n <= 0){
        return;
    }
    cout << "*";
    print_stars(n - 1);
}

void see_stars(int count, int stop){
    if(count > stop){
        return;
    }
    print_stars(count);
    cout << endl;

    see_stars(count + 1, stop);
    
    print_stars(count);
    cout << endl;
}