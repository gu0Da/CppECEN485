// Morse Translator.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <string>

using std::string;

string input()
{
	std::cout << "Type letter or phrase to translate" << std::endl;
	//Asks user to input word to be translated
	string word = " ";
	std::cin >> word;
	return word;
}

int main()
{
	string morse[] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." };
	//Holds all letters in Morse
	char eng[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
	//Holds every single letter
	string word = input();
	unsigned int l = word.length();
	//Determines length of inputted word
	for (unsigned int i = 0; i < l; ++i)
	//Goes through every letter of inputted word
	{
		unsigned int e = sizeof(eng);
		//Left unspecified in case more translations are added later
		for (unsigned int c = 0; c < e; ++c)
		//Combs across eng[] array
		{
			if (word.at(i) == eng[c])
			//Checks if char in word matches letter in eng array
			{
				std::cout << morse[c] << " ";
				//Outputs morse code for specified letter
			}
		}
	}

	return 0;
}
