// Char Counter.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>

int counter[58];
char letters[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', ',', '.', ';', '-', '!', ' ' };
using namespace std;

string textin()
{
	//input file loaded into textfile via input file stream
	ifstream textfile("input.txt");
	//reads successive chars from textfile
	string rawstring{ istreambuf_iterator<char>{textfile},
		istreambuf_iterator<char>{} };
	return rawstring;
}

void display()
{
	//run variable determines whether or not to rerun function
	char run = 'y';
	while (run == 'y')
	{
		//asks user for desired output
		cout << "Display single char or full array? s or f" << endl;
		char disp = 'f';
		cin >> disp;
		if (disp == 'f')
		{
			//displays each tracked char value with its number of appearances in the file
			for (int l = 0; l < 58; ++l)
			{
				cout << letters[l];
				cout << " ";
				cout << counter[l] << endl;
			}
			run = 'n';
		}
		if (disp == 's')
		{
			//asks user which char they want
			cout << "Which char do you want counted?" << endl;
			char choice = 'a';
			int d = 0;
			cin >> choice;
			int b = 0;
			//displays number of appearances of user's chosen char
			while (b == 0)
			{
				if (choice == letters[d])
				{
					cout << counter[d] << endl;
					b = 1;
				}
				d = d++;
			}
			int whileon = 1;
			while (whileon == 1)
			{
				cout << "Would you like to make another choice? y or n" << endl;
				char choose = ' ';
				cin >> choose;
				if (choose == 'y')
				{
					run = 'y';
					whileon = 0;
				}
				else if (choose == 'n')
				{
					run = 'n';
					whileon = 0;
				}
				//forces loop to continue until a proper input is entered
				else
				{
					cout << "Please enter a valid input" << endl;
				}
			}
		}
		if (run == 'n')
		{
			break;
		}
		else
		{
			cout << "Please enter a valid input" << endl;
		}
	}
}
int main()
{
	//runs textin() function to load input file
	string rawstring = textin();
	cout << "Input file accepted" << endl;
	int loops = rawstring.length();
	cout << "File length determined" << endl;
	//counts the number of appearances of each char
	for (int i = 0; i < loops; ++i)
	{
		int on = 1;
		int c = 0;
		while (on == 1 && c < 58)
		{
			if (rawstring.at(i) == letters[c])
			{
				counter[c] = counter[c] + 1;
				on = 0;
			}
			else
			{
				c = c++;

			}
		}
	}
	cout << "Finished combing" << endl;
	//runs display function
	display();
	return 0;
}



