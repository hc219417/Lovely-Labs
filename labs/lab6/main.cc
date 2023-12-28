/*************************************************************************
    Lab Assignment 6: This is another lab assignment in working with 
    linked lists. We will be using a struct node, for its simplicity,
    and working with non-member functions here. The main point is to 
    work with the logic of a linked list. Do not be afraid to make 
    drawings on scrap paper.

    The prototypes for the functions that you are to implement are
    included. You should uncomment them when you are ready to write 
    the implementation.

    John Dolan              Spring 2014
    Patricia Lindner        Fall 2021
*************************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct node{
    int data;
    node* next;
};

// These are the three I have implemented for you.

void build_list(node*& head); // note that we are passing by reference
void show_list(const node* head);
int size(const node* head);

//These are the two that you are to write, as described in the instructions page.

void remove_repeats(node*& head);
void split_list(const node* original, node*& lesser, node*& greater, int split_value);

int main(){

    int start, stop;
    int split;
    node* head = NULL;
    node* lesser;
    node* greater;

    start = time(NULL);
    build_list(head);
    stop = time(NULL);
    cout << "Time to build list = " << stop - start << " seconds.\n";
    cout << "Size of the list = " << size(head) << endl;

    cout << endl;

    cout << "List of random numbers:" << endl;
    start = time(NULL);
    show_list(head);
    stop = time(NULL);
    cout << "Time to print list = " << stop - start << " seconds.\n";
    cout << "Size of the list = " << size(head) << endl;

    cout << endl;

    cout << "Cleaned-up list:" << endl;
    start = time(NULL);
    remove_repeats(head);
    stop = time(NULL);
    show_list(head);
    cout << "Time to remove duplicate items = " << stop - start << " seconds.\n";
    cout << "Size of the list = " << size(head) << endl;

    cout << endl;

    cout << "Please enter a split value: ";
    cin >> split;

    if(split < 1 || split > 500){
        cout << "Error: split value must be between 1 and 500" << endl;
        exit (0);
    }

    start = time(NULL);
    split_list(head,lesser,greater,split);
    stop = time(NULL);
    cout << "Time to split list = " << stop - start << " seconds.\n";

    cout << endl;

    cout << "List of numbers less than " << split << ":" << endl;
    start = time(NULL);
    show_list(lesser);
    stop = time(NULL);
    cout << "Time to print list = " << stop - start << " seconds.\n";
    cout << "Size of the list = " << size(lesser) << endl;

    cout << endl;

    cout << "List of numbers greater than " << split << ":" << endl;
    start = time(NULL);
    show_list(greater);
    stop = time(NULL);
    cout << "Time to print list = " << stop - start << " seconds.\n";
    cout << "Size of the list = " << size(greater) << endl;

    cout << endl;

    if(size(lesser) + size(greater) < size(head)){
        cout << split << " was in the original list" << endl;
    }
    else cout << split << " was NOT in the original list" << endl;

    return 0;
}

// builds a linked list of 2000 random integers, all in the range 1 - 500
void build_list(node*& head){
    node* cursor;

    head = new node;
    head -> data = rand()%500 + 1;

    cursor = head;
    for(int i = 0; i < 2000; ++i){
	    cursor -> next = new node;
        cursor = cursor -> next;
        cursor -> data = rand()%500 + 1;
    }
    cursor -> next = NULL;
}

// outputs the contents of a linked list to the screen
void show_list(const node* head){
    const node* cursor = head;

    while(cursor !=  NULL){
        cout << cursor -> data << "  ";
        cursor = cursor -> next;
    }
    cout << endl;
}

// returns the number of nodes in a linked list
int size(const node* head){
	const node* cursor = head;
	int count = 0;
	while(cursor != NULL){
  	    count++;
	    cursor = cursor -> next;
	}
	return count;
}

// removes all duplicate items
void remove_repeats(node*& head){
    node* duplicate, *cursor, *previous;
    duplicate = head;
    while(duplicate != NULL && duplicate -> next != NULL){
        cursor = duplicate;
        while(cursor -> next != NULL){
            if(duplicate -> data == cursor -> next -> data){
                previous = cursor -> next;
                cursor -> next = cursor -> next -> next;
                delete previous;
            }
            else cursor = cursor -> next;
        }
        duplicate = duplicate -> next;
    }
}

// creates two new lists
void split_list(const node* original, node*& lesser, node*& greater, int split_value){

    const node* src;
    src = original;

    lesser = NULL;
    greater = NULL;

    node* dest1;
    node* dest2;

    while(src != NULL){
        if(src -> data < split_value){
            if(lesser == NULL){
                lesser = new node;
                lesser -> data = src -> data;
                lesser -> next = NULL;
                dest1 = lesser;
            }
            else{
                while(dest1 -> next != NULL){
                    dest1 = dest1 -> next;
                }
                dest1 -> next = new node;
                dest1 -> next -> data = src -> data;
                dest1 -> next -> next = NULL;
            }
        }
        else if(src -> data > split_value){
            if(greater == NULL){
                greater = new node;
                greater -> data = src -> data;
                greater -> next = NULL;
                dest2 = greater;
            }
            else{
                while(dest2 -> next != NULL){
                    dest2 = dest2 -> next;
                }
                dest2 -> next = new node;
                dest2 -> next -> data = src -> data;
                dest2 -> next -> next = NULL;
            }
        }
        src = src -> next;
    }
}