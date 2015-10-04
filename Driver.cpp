/*	Author:			Ben Hiler
	Date Created:	10.01.15
	Last Modified:	10.03.15
	Lab Number:		CST 211 (Assignment 1)
	Filename:		Driver.cpp / Array.h / Array.inc

	Overview:
		Driver test program for the dynamic array class outlined in assignment 1.
		Could not find enough documentation or help on the exception class, so
		that aspect of the assignment is not present. However, the driver will
		test the ability to change the size of the array, the starting index, and
		the contents of the array, including the loss of data when shrinking the
		array. Exceptions will be thrown for invalid array lengths, bounds, and 
		if the memory allocation for the array fails.

	Input:
		No input is required for the test driver, except to continue the driver
		when exceptions are thrown.

	Output:
		Output is broken into each section of the test, displaying the length,
		starting index, and contents of the array. Each time the array is changed,
		a message is shown to what end the changes are.
*/

#include "Array.h"
#include <iostream>

int main()
{
	cout << "Array test A" << endl;
	cout << "Will demonstrate retrieving and changing array contents," << endl; cout << "length, and starting index" << endl;
	try
	{
		Array<int> ArrayTestA(10, 10);
		cout << "Array length        : " << ArrayTestA.getLength() << endl;
		cout << "Array starting index: " << ArrayTestA.getStartIndex() << endl;
		cout << "Array contents..." << endl;
		for (int idx = 0; idx < ArrayTestA.getLength(); idx++)
		{
			cout << "Index " << (idx + ArrayTestA.getStartIndex()) << ':' << ArrayTestA[idx] << endl;
		}

		ArrayTestA.setLength(5); cout << endl << "Changed array length to 5" << endl;
		ArrayTestA.setStartIndex(-10); cout << "Changed starting index to -10" << endl;

		cout << "Array length        : " << ArrayTestA.getLength() << endl;
		cout << "Array starting index: " << ArrayTestA.getStartIndex() << endl;
		cout << "Array contents..." << endl;
		for (int idx = 0; idx < ArrayTestA.getLength(); idx++)
		{
			cout << "Index " << (idx + ArrayTestA.getStartIndex()) << ':' << ArrayTestA[idx] << endl;
		}

		ArrayTestA[0] = 3505;
		ArrayTestA[1] = 3505;
		ArrayTestA[2] = 3505;
		ArrayTestA[3] = 3505;
		ArrayTestA[4] = 3505;
		cout << endl << "Filled array with '3505.'" << endl;

		ArrayTestA.setLength(15); cout << "Changed array length to 15" << endl;

		cout << "Array length        : " << ArrayTestA.getLength() << endl;
		cout << "Array starting index: " << ArrayTestA.getStartIndex() << endl;
		cout << "Array contents..." << endl;
		
		for (int idx = 0; idx < ArrayTestA.getLength(); idx++)
		{
			cout << "Index " << (idx + ArrayTestA.getStartIndex()) << ':' << ArrayTestA[idx] << endl;
		}
	}
	catch (int ERROR)
	{
		switch (ERROR)
		{
		case 1: cout << "Invalid array length." << endl; system("pause"); break;
		case 2: cout << "Memory allocation failue." << endl; system("pause"); break;
		case 3: cout << "Out of bounds." << endl; system("pause"); break;
		}
	}
	
	cout << endl << endl << "Array test B" << endl;
	cout << "Invalid array length test" << endl;
	try
	{
		Array<char> ArrayTestB(-20, -10);
	}
	catch (int ERROR)
	{
		switch (ERROR)
		{
		case 1: cout << "Invalid array length." << endl; system("pause"); break;
		case 2: cout << "Memory allocation failue." << endl; system("pause"); break;
		case 3: cout << "Out of bounds." << endl; system("pause"); break;
		}
	}

	cout << endl << endl << "Array test C" << endl;
	cout << "Invalid bounds test" << endl;
	try
	{
		Array<char> ArrayTestC(1, 0);
		ArrayTestC[2] = 0;
	}
	catch (int ERROR)
	{
		switch (ERROR)
		{
		case 1: cout << "Invalid array length." << endl; system("pause"); break;
		case 2: cout << "Memory allocation failue." << endl; system("pause"); break;
		case 3: cout << "Out of bounds." << endl; system("pause"); break;
		}
	}

	cout << endl << endl << "Array test D" << endl;
	cout << "Assignment test" << endl;
	try
	{
		Array<int> ArrayTestD1(1, 0);
		ArrayTestD1[0] = 01;

		Array<int> ArrayTestD2(1, 0);
		ArrayTestD2[0] = 10;

		cout << "Contents of arrays D1 and D2..." << endl;
		cout << "D1: " << ArrayTestD1[0] << endl;
		cout << "D2: " << ArrayTestD2[0] << endl;

		cout << "Assigning D1 to D2..." << endl;
		ArrayTestD2 = ArrayTestD1;

		cout << "Contents of arrays D1 and D2..." << endl;
		cout << "D1: " << ArrayTestD1[0] << endl;
		cout << "D2: " << ArrayTestD2[0] << endl;
	}
	catch (int ERROR)
	{
		switch (ERROR)
		{
		case 1: cout << "Invalid array length." << endl; system("pause"); break;
		case 2: cout << "Memory allocation failue." << endl; system("pause"); break;
		case 3: cout << "Out of bounds." << endl; system("pause"); break;
		}
	}
	return 0;
};