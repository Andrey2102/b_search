#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>
#include "generate.cpp"
#include <time.h>
#include <cmath>
#include <math.h>

using namespace std;
int Odnorodniy_Binary_seach(int Array[], int size, int seach)
{
	int index, delta= size / 2;
	index = delta;
	while (true)
	{
		delta= delta/2
		if (Array[index] == seach)
		{
			
			break;
		}
		if (Array[index] > seach)
		{
			index = index - delta;
		}
		if (Array[index] < seach)
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
int Binary_seach(int Array[],int left, int right, int key)
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
})


int Sharr_seach(int Array[], int K)
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
			if (K < Array[index]) index = index - del;
			else index = index + del;
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
				if (K < Array[index]) index = index - del;
				else index = index + del;
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
int main()
{
	int SIZE = input_size();
	int *A = new int [SIZE];
	A = select(A, SIZE);
	return 0;
}