/**
 *   @file: part2.cc
 * @author: Hannah Culver
 *   @date: February 1, 2022
 *  @brief: lab 3 (dynamic variables)
 */

#include <iostream>
#include <cstdlib>
using namespace std;

int main(){

    int* ptr; //declare a pointer capable of pointing at an int
    // ptr = new int; //make the pointer point at a new integer
    // cout << ptr << endl; //print out the address of the new integer
    // cout << &ptr << endl; //print out the address of that pointer

    // *ptr = 2401; //using the * operator, set the value of your integer to 2401

    // for (int i = 0; i < 10; i++)
    // {
    //     ++(*ptr);
    //     cout << *ptr << " is stored at " << ptr << endl;
    // }

    //remove the * in front of ptr

    // for (int i = 0; i < 10; i++)
    // {
    //     ++(ptr);
    //     cout << *ptr << " is stored at " << ptr << endl;
    // }

    //the difference here is that you were moving the pointer instead of changing the value being pointed at

    size_t capacity = 5, used = 0;
    int* tmpptr;

    ptr = new int[capacity];
    for (size_t i = 0; i < 25; i++)
    {
        ptr[used] = rand();
        // cout << ptr[used] << endl;
        used++;

        if (used == capacity)
        {
            tmpptr = new int[capacity + 5];
            for (size_t j = 0; j < capacity; j++)
            {
                tmpptr[j] = ptr[j]; //copy the data from the original array to the new one
            }
            delete []ptr; //delete the original array
            ptr = tmpptr; //assign ptr to tmpptr, so these pointers will both point at the newer array
            capacity += 5; //adjust the capacity variable so it accurately reflects the size of the new array
            cout << "RESIZED" << endl;
        }
    }

    tmpptr[2] = 0;
    for (size_t i = 0; i < 25; i++)
    {
        cout << ptr[i] << endl; //output all the numbers in the ptr array
    }

    delete ptr;
    delete tmpptr;    
    return 0;
}