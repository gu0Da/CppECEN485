// Cpp practice 1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

string translate()
{
	string letter("a");
	string disp("error");
	cout << "Enter a letter from a to f" << endl;
	cin >> letter;
	if (letter.compare("a") == 0)
	{
		disp = ".-";
	}
	else if (letter.compare("b") == 0)
	{
		disp = "-...";
	}
	else if (letter.compare("c") == 0)
	{
		disp = "-.-.";
	}
	else if (letter.compare("d") == 0)
	{
		disp = "-..";
	}
	else if (letter.compare("e") == 0)
	{
		disp = ".";
	}
	else if (letter.compare("f") == 0)
	{
		disp = "..-.";
	}
	else
	{
		cout << "Input only one lower case letter from a to f" << endl;
	}
	return disp;
}

int main()
{
	int x(1);
	while (x == 1)
	{
		cout << translate() << endl;
		string br("y");
		cout << "Break? y or n" << endl;
		cin >> br;
		if (br.compare("y") == 0)
		{
			x = 0;
		}
	}
	return 0;
}
