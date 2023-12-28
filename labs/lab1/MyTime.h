// Add documentation for each function

#ifndef TIME_H
#define TIME_H
#include <iostream>
    
class MyTime
{   
  public:

    MyTime(int h = 0, int m = 0); //default constructor, initializes both h and m to 0 unless specified otherwise

    // Member functions
    void Reset(int h, int m); //resets both h and m to 0

    void input(std::istream& ins); //input function            

    void output(std::ostream& outs); //output function

    int get_hours() const{return hours;} //gets and returns hours

    int get_minutes() const{return minutes;} //gets and returns minutes

    // Friend functions
    MyTime operator + (const MyTime& t2); //adds time 1 and time 2
 
    MyTime operator - (const MyTime& t2); //subtracts time 2 from time 1
 
    MyTime operator * (int num); //multiplies time 1 by a scalar value

    MyTime operator / (int num); //divides time 1 by a scalar value

    std::istream& operator >> (MyTime& t1); //input function
    
    std::ostream& operator << (MyTime& t1); //output function

    bool operator == (const MyTime& t2); //returns true if time 1 and time 2 are equal, false otherwise

    bool operator < (const MyTime& t2); //returns true if time 1 is less than time 2, false otherwise

    bool operator <= (const MyTime& t2); //returns true if time 1 is less than or equal to time 2, false otherwise
   
  private:
      void simplify();
      int hours;        // hours can be > 24
      int minutes;      // 0 <= minutes <= 59
 };

  //std::istream& operator >> (istream& ins, MyTime& t1);
    
  //std::ostream& operator << (ostream& outs, MyTime& t1);

 #endif