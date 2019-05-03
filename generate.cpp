#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>
using namespace std;

int input_size(){
	cout << "Enter size of the array: ";
	int SIZE;
	cin >> SIZE;
	return SIZE;
}


void output(int *A, int SIZE){
	for (int i = 0; i < SIZE; i++)
	{
		cout << setw(4) << A[i];
	}
	cout << endl;
}

int* input(int* A, int SIZE){
	cout << "Enter elements of thr array: ";
	for (int i = 0; i < SIZE; ++i)
	{
		cin >> A[i];
	}
	cout << endl << endl << "Array: ";
	output(A, SIZE);
	return A;
}


int* generate(int* A, int SIZE){
	for (int i = 0; i < SIZE; ++i)
	{
		A[i] = i;
	}
	cout << endl << endl << "Generated array: ";
	output(A, SIZE);
	return A;
	}
	
	int* select(int* A, int SIZE){
	cout << "If you want to enter numbers yourself - press (1)." << endl << "Press (2) to generate array." << endl << "Select:";
	int sel = 0;
	cin >> sel;
	switch(sel){
		case 1:
			A = input(A, SIZE);
			break;
		case 2:
			A = generate(A, SIZE);
			break;
		default:
			cout << "Default select." << endl;
			select(A, SIZE);
	}
	return A;
}