/**
 *   @file: list1.h
 * @author: Hannah Culver
 *   @date: February 15, 2022
 *  @brief: lab 5 (linked lists)
 */

#include <iostream>
#include <string>

struct Node{
    std::string data;
    Node *next;
};

class LiList{
    public:
        LiList(){head = NULL;}
        void add(std::string item);
        void show();

        Node* search(std::string target); //search function
        void move_front_to_back(); //move_front_to_back function

    private:
        Node *head;
};

void LiList::add(std::string item){
    Node *tmp;
    if(head == NULL){
        head = new Node;
        head -> data = item;
        head -> next = NULL;
    }
    else{
        for(tmp = head; tmp -> next != NULL; tmp = tmp -> next);
        tmp -> next = new Node;
        tmp = tmp -> next;
        tmp -> data = item;
        tmp -> next = NULL;
    }
}

void LiList::show(){
    for(Node *tmp = head; tmp != NULL; tmp = tmp -> next)
    std::cout << tmp -> data << " ";
}

Node* LiList::search(std::string target){
    Node* cursor;
    cursor = head;
    while(cursor -> next != NULL && cursor -> data != target){
        cursor = cursor -> next;
    }
    if(cursor -> data == target) return cursor;
    else return NULL;
}

void LiList::move_front_to_back(){
    Node* tmp = head;
    head = head -> next;
    Node* cursor = head;
    while(cursor -> next != NULL){
        cursor = cursor -> next;
    }
    cursor -> next = tmp;
    tmp -> next = NULL;
}