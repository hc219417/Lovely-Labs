//*******************************************
//	Implementation file for the Numlist class, which 
//	allows programmers to store a list of numbers that they
//	choose to have sorted if they like.
//	January 2013		John Dolan
//	Ohio University		EECS
//**********************************************/
#include "numlist.h"
using namespace std;

// Constructor
NumList::NumList(){
	used = 0;
}

void NumList::insert(int num){
	if(used <CAPACITY){
		data[used] = num;
		used++;
	}
	else{
		cout<<"Error. List capacity has been reached.\n";
	}
}

void NumList::load_from_file(istream& ins){

	ifstream instream;
    string input_file;

    cout << "Please enter the name of the file you would like to load from: ";
    cin >> input_file;

    instream.open(input_file); //open the input file given by the user
    if (instream.fail()) //check for failure
    {
        cout << "Error: file not found" << endl;
        exit(0);
    }

	int count = 0; //counter (initialized to 0)
	string number;
	string numbers[CAPACITY]; //array of strings

	while (!instream.eof()) //while NOT end of file
	{
		getline(instream,number); //getline function
		count++; //basically count how many lines there are in the file
	}

	instream.close(); //close the stream to reset

	instream.open(input_file); //reopen the file
    if (instream.fail()) //check again (just to be safe)
    {
        cout << "Error: file not found" << endl;
        exit(0);
    }

	for (int i = 0; i < count - 1; i++)
	{
		instream >> numbers[i]; //load up the array
		data[i] = stoi(numbers[i]); //convert to integers
		used++; //increment the used counter
	}

	instream.close(); //always close your streams
}

void NumList::save_to_file(ostream& outs){

	ofstream outstream;
    string output_file;

    cout << "Please enter the name of the file you would like to save to: ";
    cin >> output_file; //should be the same as the input file name

	int location = output_file.find("."); //find the period index
	string sorted_output_file = output_file.insert(location,"sorted"); //insert the string "sorted"

    outstream.open(sorted_output_file); //open file with the new title
    if (outstream.fail()) //check for failure
    {
        cout << "Error: failed to create file" << endl;
        exit(0);
    }

	for (size_t i = 0; i < used; i++)
	{
		outstream << data[i] << endl; //output the (now sorted) array to the output file
	}

	outstream.close(); //seriously, don't forget to close your streams!!
}

void NumList::see_all()const{
	if(used == 0){
	    cout<<"Empty list.\n";
	}
	else{
	    for(size_t i = 0; i<used; ++i)
		cout<<data[i]<<endl;
	}
} //used for testing, no longer in the main

int NumList::get_item(size_t index)const{
	if(index < used){
		return data[index];
	}
	else{
		return -1;
	}
}
	
void NumList::b_sort(){
    bool done = false;
    int j;
    int tmp;
    while(!done){
		done = true; //remove the ! before true
		for(j=used-1; j>= 0; --j){
			if(data[j] < data[j-1]){
			done = false;
			tmp = data[j];
			data[j] = data[j-1];
			data[j-1] = tmp;
			}
		}
    }
}