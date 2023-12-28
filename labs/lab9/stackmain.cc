/*************************************************************************
	Lab Assignment 9 - working with a stack

	It's sometimes tricky to set up the loop that reads the expression 
	from the keyboard, so I am giving that to you. You have to fill in 
	the rest of the main.

	John Dolan	Fall 2016	Ohio University		Home of the Bobcats
*************************************************************************/

#include <stack>
#include <iostream>
#include <cstdlib>
#include "calc_useful.h"

using namespace std;

int main(){

	char c;
	char tmp;
	int onenum, twonum, result;
	bool continu = true;
    stack <int> nums; // declare an STL stack called nums right here

	cout << "Please enter your expression:\n";

	while(continu == true){
		c = cin.get(); // priming read for the sentinel loop
		while(c != '\n'){
			if(isdigit(c)){
				cin.putback(c);
				cin >> onenum;
				nums.push(onenum); // stack operation here
			}
			else if(isop(c)){
				if(nums.size() >= 2){ // check to see if there's anything on the stack
					twonum = nums.top();
                    nums.pop();
                    onenum = nums.top();
                    nums.pop(); // pop two numbers from the stack
                    result = evaluate(onenum,twonum,c); // evaluate them using the evaluate from stack_useful
					nums.push(result); // push result onto the stack
				}
				else if(nums.size() == 1){
					cout << "Error: too few numbers" << endl;
					return 0;
				}
				else if(nums.empty()){ // user only entered an operand
					cout << "Error: empty stack" << endl; // what did this error tell us about the user's expression?
					return -1;
				}
			}
			c = cin.get(); // reading at the bottom of the sentinel loop
		} // bottom of the loop that reads a single expression from the keyboard

    // output the final result from the top of the stack...

        if(nums.size() > 1){
            cout << "Error: too few operands" << endl; //more than one number left on the stack
			return 0;
        }
		else cout << "Answer = " << nums.top() << endl;

	// ...but only after you check to make sure there's something on the stack

		cout << "Enter another equation?(y or n)";
		cin >> tmp;
		cin.ignore();
		if(tmp == 'y' || tmp == 'Y'){
			while(!nums.empty()){
				nums.pop(); // clear out the stack
			}
			continu = true;
		}
		else continu = false;
	}

	return 0;
}