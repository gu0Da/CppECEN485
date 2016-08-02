// Morse Translator While.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <string>

using std::string;

string input()
{
	std::cout << "Type letter or phrase to translate" << std::endl;
	string word = " ";
	std::cin >> word;
	return word;
}

int main()
{
	string morse[] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." };
	char eng[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
	string word = input();
	unsigned int len = word.length();
	for (unsigned int i = 0; i < len; ++i)
	{
		int eq = 0;
		//variable c must be outside while loop to prevent c from being reset to 0 in the while loop
		int c = 0;
		while (eq == 0)
		{
			if (word.at(i) == eng[c])
			{
				std::cout << morse[c] << " ";
				eq = 1;
				break;
			}
			else
			{
				c = c+1;
			}
		}
	}

	return 0;
}
