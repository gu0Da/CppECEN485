// OrbitSimulator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>

using namespace std;

int main()
{
	//Defining mass, initial position, initial momentum of earth
	double earth = 6e24;
	vector<double> eposition = { 15e10, 0 };
	vector<double> emomentum = { 0, (2e4*earth) };
	//Defining mass, initial position, initial momentum of sun
	double sun = 2e30;
	vector<double> sposition = { 0, 0 };
	vector<double> smomentum = { 0, 0 };
	//Defining gravitational constant
	double G = 6.673e-11;
	//Defining numerator of force equation
	double upper = G*earth*sun;
	//Defining time increment
	int dt = 8600;
	int t = 0;
	int p = 0;
	//Instantiate coordinate storage
	double xlocation[40000];
	double ylocation[40000];

	while (t < 320000000)
	{
		//Finding radius for force calculation
		double r = sqrt(pow(eposition[0], 2) + pow(eposition[1], 2));
		//Finding angle for force calculation
		vector<double> direction = { sposition[0] - eposition[0], sposition[1] - eposition[1] };
		//vector<double> direct = { direction[0] / r, direction[1] / r };
		double angle = atan2(direction[1], direction[0]);
		//Calculating gravitational force
		double force = upper / (r*r);
		//vector<double> df = force*direction;
		//double xforce = force*direct[0];
		//double yforce = force*direct[1];
		double xforce = force*cos(angle);
		double yforce = force*sin(angle);
		emomentum[0] = emomentum[0] + xforce*dt;
		emomentum[1] = emomentum[1] + yforce*dt;
		//Updating position
		eposition[0] = eposition[0] + (emomentum[0] / earth)*dt;
		eposition[1] = eposition[1] + (emomentum[1] / earth)*dt;
		//Storing position coordinates
		xlocation[p] = eposition[0];
		ylocation[p] = eposition[1];
		p = ++p;
		t = t + dt;
	}

	//Creating blank text file for coordinate storage
	ofstream file("coord.txt");
	int q = 0;
	file << "[ ";
	//Writing x coordinates to file
	for (int j = 0; j <= t-1; j = j + dt)
	{
		file << xlocation[q] << " ";
		q = ++q;
	}
	file << "];";
	file << endl;
	int w = 0;
	file << "[ ";
	//Writing y coordinates to file
	for (int k = 0; k <= t-1; k = k + dt)
	{
		file << ylocation[w] << " ";
		w = ++w;
	}
	file << "];";
	return 0;
}