#include <iostream>
#include <iomanip>
using namespace std;

class generate{
	int SIZE;
	int* A;
	public:
		generate(): SIZE(200), A(new int [SIZE]) {}
		void input_size();
		void output();
		int *input();
		int *generate_ar();		
		int *generate_revert();
		void select();
};

void generate::output(){
	for (int i = 0; i < SIZE; i++)
	{
		cout << setw(4) << A[i];
	}
	cout << endl;
}

int* generate::input(){
	cout << "Enter elements of thr array: ";
	for (int i = 0; i < SIZE; ++i)
	{
		cin >> A[i];
	}
	cout << endl << endl << "Array: ";
	output();
}

int* generate::generate_ar(){
	srand(time(NULL));
	cout << "Enter limit of the number that will generated: ";
	int lim;
	cin >> lim;
	for (int i = 0; i < SIZE; ++i)
	{
		A[i] = rand()%(lim + 1);
	}
	cout << endl << endl << "Generated array: ";
	output();
}

int* generate::generate_revert(){
	srand(time(NULL));
	for (int i = 0; i < SIZE; ++i)
	{
		A[i] = SIZE - i;
	}
	cout << endl << endl << "Generated array: ";
	output();
	}
	
void generate::select(){
	cout << "If you want to enter numbers yourself - press (1)." << endl << "Press (2) to generate random numbers." << endl << "(Press (3) to generate an array sorted in the opposite direction): ";
	int sel = 0;
	cin >> sel;
	switch(sel){
		case 1:
			A = input();
			break;
		case 2:
			A = generate_ar();
			break;
		case 3:
			A = generate_revert();
			break;
		default:
			cout << "Default select." << endl;
			select();
	}
}