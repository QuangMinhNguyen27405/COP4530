/*
MINH NGUYEN
COP 4530
MEM_MANAGER.CPP
A PROGRAM THAT SIMULATE A MEMORY
*/
#include<iostream>
#include<string>

#include "MyMemory.h"

using namespace std;
using namespace cop4530;

void print_menu() {
	cout << string(20, '=') << endl;
	cout << "d: memory dump" << endl;
	cout << "r: request memory" << endl;
	cout << "l: release memory" << endl;
	cout << "m: merge memory" << endl;
	cout << "x: quit program" << endl;
	cout << "Your choice: ";	
}

void request_memory(MyMemory& myMemory) {
	int len;

	cout << "Requested memory size (integer): ";
	cin >> len;

	myMemory.req_mem(len);
}

void release_memory(MyMemory& myMemory) {
	int len;
	int ind;
	
	cout << "Release memory index (integer): ";
	cin >> ind;
	cout << "Release memory size (integer): ";
	cin >> len;

	myMemory.release_mem(ind, len);
}

int main() {
	int len;
	int num;
	char choice;

	cout << "Memory configuration:\n"; 
	cout << "Number of memory blocks (integer): ";
	cin >> num;
	cout << "Memory block size (integer): ";
	cin >> len;

	MyMemory myMemory(num, len);
	
	do {

		print_menu();
		cin >> choice;

		switch(choice) {
			case 'd':
				myMemory.dump();
				break;
			case 'r':
				request_memory(myMemory);
				break;
			case 'l':
				release_memory(myMemory);
				break;
			case 'm':
				myMemory.merge_mem();
				break;
			case 'x':
				break;
			default:
				cout << "Invalid input, Please try again!\n";
		}

	} while(choice != 'x');
}


