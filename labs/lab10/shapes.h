/**
 *   @file: shapes.h
 * @author: Hannah Culver
 *   @date: March 27, 2022
 *  @brief: lab 10 (inheritance and virtual functions)
 */

#include <iostream>
#include <cmath>

class Shape{
    public:
        Shape() {thickness = 0, cost_per_cubic_unit = 0;}
        virtual void input();
        double cost() {return thickness * cost_per_cubic_unit * area();}
        virtual double area() {return 0;}
    private:
        double thickness;
        double cost_per_cubic_unit;
};

class Circle:public Shape{
    public:
        Circle() {radius = 0;}
        void input();
        double area() {return M_PI * radius * radius;}
    private:
        double radius;
};

class Rectangle:public Shape{
    public:
        Rectangle() {length = 0, width = 0;}
        void input();
        double area() {return length * width;}
    private:
        double length;
        double width;
};

class Trapezoid:public Shape{
    public:
        Trapezoid() {base1 = 0, base2 = 0, height = 0;}
        void input();
        double area() {return height * (base1 + base2) / 2.0;}
    private:
        double base1;
        double base2;
        double height;
};