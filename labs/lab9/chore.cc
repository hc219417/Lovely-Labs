/**
 *   @file: chore.cc
 * @author: Hannah Culver
 *   @date: March 20, 2022
 *  @brief: lab 9 (stacks and queues)
 */

#include "chore.h"
using namespace std;

void Chore::input(std::istream& ins){
    cout << "Please enter the name or a brief description of the chore: ";
    while(ins.peek() == '\n' || ins.peek() == '\r'){
        ins.ignore();
    }
    getline(ins,chore);
    cout << "On a scale of 1-10 (1 being the least urgent, 10 being the most urgent), how urgent is this chore? ";
    ins >> prnum;
}

void Chore::output(std::ostream& outs)const{
    outs << "*************************" << endl;
    outs << "chore: " << chore << endl;
    outs << "priority level: " << prnum << endl;
    outs << "*************************" << endl;
}

bool operator < (const Chore& a, const Chore& b){
    return a.prnum < b.prnum;
}

ostream& operator << (ostream& outs, const Chore& c){
    c.output(outs);
    return outs;
}

istream& operator >> (istream& ins, Chore& c){
    c.input(ins);
    return ins;
}