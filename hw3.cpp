//File: hw3
//Author: Christopher Fong
//Date: 2/3/2019

#include <iostream>

using namespace std;

//Global Variable
const int BIT_SIZE = 10;

//Methods
void createSet(int &set);
void printSet(int set);
void unionSet(int a, int b);
void intersection(int a, int b);
void sub(int a, int b);

int main()
{
	int setA = 0;
	int setB = 0;

	//Create Set A
	cout << "Enter values between 0-9 for set A. Enter -1 when finished: ";
	createSet(setA);

	//Create Set B
	cout << "Enter values between 0-9 for set B. Enter -1 when finished: ";
	createSet(setB);


	//Print set A
	cout << "A = { ";
	printSet(setA);
	cout << "}" << endl << endl;

	//Print set B
	cout << "B = { ";
	printSet(setB);
	cout << "}" << endl << endl;

	//Union sets A and B
	cout << "A U B = ";
	unionSet(setA, setB);
	

	//Intersect sets A and B
	cout << "A ^ B = ";
	intersection(setA, setB);
	

	//Subtract sets A from B
	cout << "A - B = ";
	sub(setA, setB);

	return 0;
}

//Creates a set
void createSet(int &set)
{
	int userInput = 0;
	
	while (userInput != -1)
	{
		cin >> userInput;
		if (userInput != -1)
			set |= (1 << userInput);
	}

	cout << endl;
}


//Prints a set as integers
void printSet(int set)
{
	for (int i = 0; i < BIT_SIZE; i++)
	{
		if ((((set >> i) % 2) ? '1' : '0') == '1')
			cout << i << " ";
	}
}

//a union b method
void unionSet(int a, int b)
{
	a |= b;

	cout << "{ ";
	printSet(a);
	cout << "}" << endl << endl;
}

//a intersection b method
void intersection(int a, int b)
{
	a &= b;

	cout << "{ ";
	printSet(a);
	cout << "}" << endl << endl;
}

//subtraction a - b method
void sub(int a, int b)
{
	int compliment = 0;

	for (int i = 0; i < 10; i++)
	{
		if ((((b >> i) % 2) ? '0' : '1') == '1')
			compliment |= (1 << i);
	}

	a &= compliment;

	cout << "{ ";
	printSet(a);
	cout << "}" << endl << endl;
}