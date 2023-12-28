/**
 *   @file: queuemain.cc
 * @author: Hannah Culver
 *   @date: March 20, 2022
 *  @brief: lab 9 (stacks and queues)
 */

#include <iostream>
#include <cstdlib>
#include "chore.h"
using namespace std;

int main(){

	queue <Chore> chores; //STL queue
	Chore temp1;

	for(int i = 0; i < 5; i++){
		temp1.input(cin);
		chores.push(temp1);
	}

	for(int i = 0; i < 5; i++){
		chores.front().output(cout);
		chores.pop();
	}

	priority_queue <Chore> prq; //priority queue
	Chore temp2;

	for(int i = 0; i < 5; i++){
		temp2.input(cin);
		prq.push(temp2);
	}

	for(int i = 0; i < 5; i++){
		prq.top().output(cout);
		prq.pop();
	}

	return 0;
}