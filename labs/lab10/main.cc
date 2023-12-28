/*************************************************************************
	This is the main that drives lab 10. You will need to construct the
	four classes which are used in it:
	Shape, Circle, Rectangle, Trapezoid

	This lab provides the concepts that you will be using
	in Project 5, but there are important differences, such as the 
	use of the list class, and the need for output functions

	John Dolan			OU EECS				October 2013
	Patricia Lindner	Ohio University		October 2021
*************************************************************************/

#include "shapes.h"
#include <iostream>

using namespace std;

// Displays the menu to the user and returns the user's choice
int menu();

int main(){
    Shape* box[15];
    Shape* tmp;
    int used = 0;
    double total_cost = 0;

    int choice;
    choice = menu();

    while(choice != 4){
		if(choice == 1){
			tmp = new Circle;
		}
		else if(choice == 2){
			tmp = new Rectangle;
		}
		else if(choice == 3){
			tmp = new Trapezoid;
		}
		else if (choice == 4){
			break;
		}

		tmp -> input();
		box[used] = tmp;
		used++;
		choice = menu(); // read-at-the-bottom, sentinel loop
	}// end while loop

	for(int i = 0; i < used; ++i)
		total_cost += box[i] -> cost();

	cout.setf(ios::showpoint);
	cout.setf(ios::fixed);
	cout.precision(2);
	cout << "The total cost of this box of blocks is $" << total_cost << endl;

    return 0;
}

int menu(){
	int ans;

	cout << "Enter 1 to record a Circle.\n";
	cout << "Enter 2 to record a Rectangle.\n";
	cout << "Enter 3 to record a Trapezoid. \n";
	cout << "Enter 4 to quit and see total for the box.\n";
	cin >> ans;

	return ans;
}