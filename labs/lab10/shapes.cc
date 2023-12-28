/**
 *   @file: shapes.cc
 * @author: Hannah Culver
 *   @date: March 27, 2022
 *  @brief: lab 10 (inheritance and virtual functions)
 */

#include "shapes.h"
using namespace std;

void Shape::input(){
    cout << "Please enter the thickness: ";
    cin >> thickness;
    cout << "Please enter the cost per cubic unit: ";
    cin >> cost_per_cubic_unit;
}

void Circle::input(){
    Shape::input();
    cout << "Please enter the radius: ";
    cin >> radius;
}

void Rectangle::input(){
    Shape::input();
    cout << "Please enter the length: ";
    cin >> length;
    cout << "Please enter the width: ";
    cin >> width;
}

void Trapezoid::input(){
    Shape::input();
    cout << "Please enter the length of base 1: ";
    cin >> base1;
    cout << "Please enter the length of base 2: ";
    cin >> base2;
    cout << "Please enter the height: ";
    cin >> height;
}