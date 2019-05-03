#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>
#include "generate.cpp"
#include <time.h>
#include <cmath>
#include <math.h>
using namespace std;

int Odnorodniy_Binary_search(int Array[], int size, int search)
{
	int index, delta= size / 2;
	index = delta;
	while (true)
	{
		delta= delta/2;
		if (Array[index] == search)
		{
			break;
		}
		if (Array[index] > search)
		{
			index = index - delta;
		}
		if (Array[index] < search)
		{
			index = index + delta;
		}
		if (delta == 0)
		{
			break;
		}
	}
	return index;
}


int Binary_search(int arr[],int left, int right, int key)
{
	int midd = 0;
	while (1)
	{
		midd = (left + right) / 2;

		if (key < arr[midd])       
			right = midd - 1;      
		else if (key > arr[midd])  
			left = midd + 1;    
		else                       
			return midd;           

		if (left > right)          
			return -1;
	}
}


int Sharr_search(int Array[], int n, int K)
{
	int k = log2(n);
	int index = pow(2, k);
	int comparison = 1;
	if (K == Array[index]) cout << "Element is founded, index:" << index << endl;
	if (K < Array[index])
	{
		for (int i = 1; i <= k; i++)
		{
			comparison++;
			int del = pow(2, k - i);
			if (K == Array[index])
			{
				cout << "Element is founded, index:" << index << endl;
				break;
			}
			if (K < Array[index]){
				index = index - del;
			}
			else{
				index = index + del;
			}
			if (K == Array[index])
			{
				cout << "Element is founded, index:" << index << endl;
				break;
			}
			if (i == k)
			{
				cout << "Element is not in array." << endl;
			}
		}
	}
	if (K > Array[index])
	{
		int l = log2(n - pow(2, k)) + 1;
		index = n + 1 - pow(2, l);
		if (K > Array[index])
		{
			for (int j = 1; j <= l; j++)
			{
				comparison++;
				int del = pow(2, l - j);
				if (K == Array[index])
				{
					cout << "Element is founded, index:" << index << endl;
					break;
				}
				if (K < Array[index]){
					index = index - del;
				}
				else{
					index = index + del;
				}
				if (K == Array[index])
				{
					cout << "Element is founded, index:" << index << endl;
					break;
				}
				if (j == l)
				{
					cout << "Element is not in array." << endl;
				}
			}
		}
	}
	return index;
}

int select_search(int *A, int size){
	cout << "Enter element, that you want to search in the array: ";
	int key;
	cin >> key;
	cout << "Chose the method, which you want to search element: " << endl;
	cout << "1) Odnorodniy binary search" << endl;
	cout << "2) Binary search" << endl;
	cout << "3) Sharr search" << endl;
	cout << "Select: ";
	int sel;
	cin >> sel;
	int res;
	switch(sel){
		case 1:
			res = Odnorodniy_Binary_search(A, size, key);
			break;
		case 2:
			res = Binary_search(A, 0, size, key);
			break;
		case 3:
			res = Sharr_search(A, size, key);
			break;
		default:
			cout << "Default select." << endl;
			select_search(A, size);
			break;
	}
	if (res && res>=0)
	{
		cout << "Result: " << res << endl;
		return res;
	}
	else{
		cout << "Error 404: Not founded." << endl;
	}
	return 0;
}

int main()
{
	int SIZE = input_size();
	int *A = new int [SIZE];
	A = select(A, SIZE);
	select_search(A, SIZE);
	return 0;
}