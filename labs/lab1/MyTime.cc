// The implementation file for the MyTime class

#include "MyTime.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

// Default constructor
MyTime::MyTime(int h, int m){
	hours = h;
	minutes = m;
}

// Member and friend functions
void MyTime::Reset(int h, int m){
	hours = h;
	minutes = m;
}

void MyTime::simplify(){
    hours += minutes/60;
	minutes = minutes%60;
}

MyTime MyTime::operator + (const MyTime& t2){
	MyTime tmp;
    tmp.hours = hours + t2.hours;
	tmp.minutes = minutes + t2.minutes;
	tmp.simplify();
	return tmp;
}

MyTime MyTime::operator - (const MyTime& t2){
	MyTime tmp;
	tmp.minutes = abs((hours*60+minutes) - (t2.hours*60+t2.minutes));
	tmp.simplify();
	return tmp;
}

MyTime MyTime::operator / (int num){
	MyTime tmp;
	tmp.minutes = hours*60 + minutes;
	tmp.minutes /= num;
	tmp.simplify();
	return tmp;
}

MyTime MyTime::operator * (int num){
	MyTime tmp;
	tmp.minutes = hours*60 + minutes;
	tmp.minutes *= num;
	tmp.simplify();
	return tmp;
}

bool MyTime::operator == (const MyTime& t2){
	return hours == t2.hours && minutes == t2.minutes;
}

bool MyTime::operator < (const MyTime& t2){
	return (hours*60 + minutes) < (t2.hours*60 + t2.minutes);
}

bool MyTime::operator <=(const MyTime& t2){
	return (hours*60 + minutes) <= (t2.hours*60 + t2.minutes);
}

void MyTime::input(istream& ins){
	char junk;
	ins >> hours;
  	ins.get(junk);
	ins >> minutes;
	simplify();
}

void MyTime::output(ostream& outs){
	outs << hours << ':' << setw(2) << setfill('0') << minutes;
}

ostream& operator << (ostream& outs, MyTime& t1){
	t1.output(outs);
    return outs;
}

istream& operator >> (istream& ins, MyTime& t1){
	t1.input(ins);
	return ins;
}