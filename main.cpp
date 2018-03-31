/*
 * Binary Search Tree
 * c++
 * This program will create a binary search tree that will read in a series of numbers between 1 and 1000
 *
 * Created by Alex Young
 */
 
#include <iostream>
#include <fstream>
#include <cstring>
#include "node.h"

using namespace std;

int main() {
	// intro to user
	cout << "This program will create a binary search tree that will read in a series of numbers between 1 and 1000" << endl
		 << "Enter in numbers by inputing numbers between spaces" << endl
		 << "Type [Q] to stop inputting numbers" << endl;
	
	int entry = 0;
	cout << "Enter in numbers between 1 and 1000 to be sorted." << endl;
	Node* root = NULL;
	
	// enter in numbers and add them to the tree and first value will be NULL
	while (true) {
		
		if (!(cin >> entry)) {
			break;
		}
		
		// cout << entry << endl;
		
		if (root == NULL) {
			root = new Node(entry);
		} else {
			root->insert(entry);
		}
	}
	
	// have to clear the entries for the rest of the cin to work
	cin.clear();
	cin.get();
	
	// while not quitting, ask if they want to print delete or quit
	while (true) {
		char input[10] =  "xxxxxxxxx" ;
		
		cout << "You can print [P] or delete [D] or quit [Q]" << endl;
		cin >> input;
		
		//cout << "input is [" << input << "]";
		// if print...
		if (strcmp(input, "p") == 0 || strcmp(input, "P") == 0 || strcmp(input, "print") == 0 || strcmp(input, "Print") == 0) {
			
			// check if there is a tree then print out
			if (root != NULL) {
				cout << "[Infix] ";
				root->print();
				cout << endl;
				root->visual();
			}
		}
		
		// if deleting...
		else if (strcmp(input, "d") == 0 || strcmp(input, "D") == 0 || strcmp(input, "delete") == 0 || strcmp(input, "Delete") == 0){
			// read in a number to remove
			int n = 0;
			cout << "Enter a number to remove: ";
			cin >> n;
			cout << endl;
			// check if tree and then remove!
			if (root != NULL) {
				//cout << "removing " << n << endl;
				root = root->remove(n);
			}
			
		} else {
			break;
		}
	}
	return 0;
}
