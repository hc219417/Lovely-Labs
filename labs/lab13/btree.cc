/**
 *   @file: btree.cc
 * @author: Hannah Culver
 *   @date: April 18, 2022
 *  @brief: lab 13 (binary trees)
 */

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Bnode{
	string data;
	Bnode* left;
	Bnode* right;
};

void inorder(Bnode* root){
	if(root != NULL){
		inorder(root -> left);
		cout << root -> data << endl;
		inorder(root -> right);
	}
}

void add(Bnode*& root, string item){
	if(root == NULL){
		root = new Bnode;
		root -> data = item;
		root -> left = root -> right = NULL;
	}
	else if(item <= root -> data){
		add(root -> left, item);
	}
	else{
		add(root -> right, item);
	}
}

int size(Bnode* root){
	if(root == NULL) return 0;
	else return size(root -> left) + size(root -> right) + 1;
}

int search(Bnode* root, const string& target){
	int many = 0;
	Bnode* cursor = root;
	while(cursor != NULL){
		if(target < cursor -> data){
			cursor = cursor -> left;
		}
		else if(target > cursor -> data){
			cursor = cursor -> right;
		}
		else if(target == cursor -> data){
			many++;
			cursor = cursor -> left;
		}
	}
	return many;
}

int greater_than(Bnode* root, const string& target){
	if(root == NULL){
		return 0;
	}
	else{
		if(root -> data > target){
			return greater_than(root -> left, target) + size(root -> right) + 1;
		}
		else{
			return greater_than(root -> right, target);
		}
	}
}

int main(){

	Bnode* btree = new Bnode;
	string name;

	ifstream fin;
	fin.open("names.txt");

	if(!fin.fail()){
		while(!fin.eof()){
			fin >> name;
			add(btree,name);
		}
	}
	fin.close();

	string search_name;
	cout << "Please enter a name: ";
	cin >> search_name;

	int count1 = search(btree, search_name);
	int count2 = greater_than(btree, search_name);

	cout << "Your search name appears " << count1 << " times." << endl;
	cout << "There are " << count2 << " non-unique names following your search name." << endl;

	return 0;
}