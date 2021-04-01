/*
	John May
	Personal Library
	Version 1.1
*/
#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <fstream>
#include <Windows.h>
#include <ctime>
#include <numeric>

using namespace std;

void swap(double& a, double& b)
{
	double temp = a;
	a = b;
	b = temp;
}

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void swap(string& a, string& b)
{
	string temp = a;
	a = b;
	b = temp;
}

int endFile() { // method signature (What's coming out, name, and whats coming in)

	// ****** End of program
	cout << "\n\n****************\n\nReprogrammed by may54721@mvctc.com\n\nPress any key to continue . . .";
	cin.ignore(100, '\n');
	cin.sync();
	cin.get();
	return 0;
}
int checkInt(string str) {
	cout << "\n\n" << str;
	int num = 0;

	while ((!(cin >> num)) || cin.fail()) {
		cout << "Error - Try Again";
		cin.clear();
		cin.sync();
		cin.ignore(100, '\n');
		cout << "\n" << str;
	}

	return num;
}

int checkInt(string str, int min, int max) {
	cout << "\n" << str;
	int num = 0;

	while ((!(cin >> num)) || cin.fail() || num < min || num > max) {
		cout << "Error - Try Again" << endl;
		cout << str << endl;
		cin.clear();
		cin.sync();
		cin.ignore(100, '\n');
		
	}

	return num;
}

/*
	Check Float
	returns the float number
*/

int checkFloat(string str, int min, int max) {
	cout << "\n\n" << str;
	float num = 0;

	while ((!(cin >> num)) || cin.fail() || num < min || num > max) {
		cout << "Error - Try Again";
		cin.clear();
		cin.sync();
		cin.ignore(100, '\n');
		cout << "\n\n" << str;
	}

	return num;
}
/*
	Check Double
	returns double number
*/
int checkDouble(string str, int min, int max) {
	cout << "\n\n" << str;
	double num = 0;

	while ((!(cin >> num)) || cin.fail() || num < min || num > max) {
		cout << "Error - Try Again";
		cin.clear();
		cin.sync();
		cin.ignore(100, '\n');
		cout << "\n\n" << str;
	}

	return num;
}

int displayMenu(string str, int min, int max) 
{
	int choice = 0;
	cout << str;
	while ((!(cin >> choice)) || cin.fail() || choice < min || choice > max) 
	{
		cout << str;
		cin.clear();
		cin.sync();
		cin.ignore(100, '\n');
	}
	return choice;
}

int linearSearch(string arr[], const int size, string value) 
{
	int index = 0; // used as a subscript to search the array
	int position = -1; // to record the position of the search value
	bool found = false; // flag to indicate if it was found
	while (index < size && !found)
	{
		if (arr[index] == value) // if the value is found
		{
			found = true; // set the flag
			position = index; // record subscript
		}
		index++;
	}
	return position;
}

int binarySearch(const int arr[], int numElems, int value)
{
	int first = 0,
		last = numElems - 1,
		middle,
		position = -1;
	bool found = false;

	while (!found && first <= last)
	{
		middle = (first + last) / 2; // calculate midpoint
		if (arr[middle] == value) // if value found at mid
		{
			found = true;
			position = middle;
		}
		else if (arr[middle] > value) // if value is in lower half
			last = middle - 1;
		else
			first = middle + 1; // if value is in upper half
	}
	return position;
}

void bubbleSort(int array[], int size)
{
	int maxElement;
	int index;

	for (maxElement = size - 1; maxElement > 0; maxElement--)
	{
		for (index = 0; index < maxElement; index++)
		{
			if (array[index] > array[index + 1]) 
			{
				swap(array[index], array[index + 1]);
			}
		}
	}
}

void selectionSort(int array[], int size)
{
	int minIndex, minValue;
	for (int start = 0; start < (size - 1); start++)
	{
		minIndex = start;
		minValue = array[start];
		for (int index = start + 1; index < size; index++)
		{
			if (array[index] < minValue)
			{
				minValue = array[index];
				minIndex = index;
			}
		}
		swap(array[minIndex], array[start]);
	}
}

void selectionSort(string array2[], float array[], int size)
{
	int minIndex, minValue;
	string minIndex2, minValue2;
	int minIndext =0, minValuet;
	for (int start = 0; start < (size - 1); start++)
	{
		minIndex = start;
		minIndex2 = start;
		minValue2 = array2[start];
		minValue = array[start];
		
		for (int index = start + 1; index < size; index++)
		{
			if (array[index] > minValue)
			{
				minValue2 = array2[index];
				minIndext = index;
				minValue = array[index];
				minIndex = index;
			}
		}
		swap(array[minIndex], array[start]);
		swap(array2[minIndext], array2[start]);
	}
}

void doubleSort(string id[], float sales[], int size)
{
	int start, maxIndex;
	string tempid;
	double maxValue;

	for (start = 0; start < (size - 1); start++)
	{
		maxIndex = start;
		maxValue = sales[start];
		tempid = id[start];
		for (int index = start + 1; index < size; start++) 
		{
			if (sales[index] > maxValue)
			{
				maxValue = sales[index];
				tempid = id[index];
				maxIndex = index;
			}
		}
		swap(sales[maxIndex], sales[start]);
		swap(id[maxIndex], id[start]);
	}
}



/*
int InputFileOpen(string str1, string str2) { \\ not working like i wanted.
	ofstream myOutputFile;
	ifstream myInputFile;

	string directoryName;
	string fileName;
	string firstval;
	string secondval;
	string thirdval;
	cout << "\n" << str1 << endl; // str1 is supposed to cout something pertaining to directory name such as "What directory is the file information stored in?"
	getline(cin, directoryName);
	cin.sync();

	cout << "\n" << str2 << endl; // str2 cout something pertaining to file name such as "What is the name of the file?"
	getline(cin, fileName);
	cin.sync();

	myInputFile.open(directoryName + "\\" + fileName + ".txt");

	if (myInputFile.is_open()) {
		cout << "File successfully opened!" << endl;
		while (myInputFile >> firstval) {
			getline(myInputFile, secondval, '\t');
			getline(myInputFile, thirdval);
			cout << firstval << "\t" << secondval << "\t" << thirdval << endl;
		}
	}
	else {
		cout << "Failed to open file." << endl;
	}
}*/

