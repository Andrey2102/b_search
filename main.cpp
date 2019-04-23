#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>
#include "generate.cpp"
using namespace std;

int main()
{
	int SIZE = input_size();
	int *A = new int [SIZE];
	A = select(A, SIZE);
	return 0;
}