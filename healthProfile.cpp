// healthProfile.cpp
#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <conio.h>
#include "healthProfile.h"

using namespace std;

int main()
{
	string fn, ln, gen;
	string dob;
	float h, w;
	
	cout << "Enter first Name: ";
	cin >> fn;
	cout << "Enter last Name: ";
	cin >> ln;
	cout << "Enter gender (Male or Female): ";
	cin >> gen;
	cout << "Enter height (cm): ";
	cin >> h;
	cout << "Enter weight (kg): ";
	cin >> w;
	cout << "Enter Date of Birth (e.g., 23-Sep-1953 or 25-12-1949): ";
	cin >> dob;
	
	// Replace hyphens with spaces so stringstream extracts tokens cleanly
	for(char &c : dob) {
		if(c == '-') {
			c = ' ';
		}
	}
	
	stringstream ss(dob);
	int day, year;
	string Month;
	
	ss >> day >> Month >> year;
	
	if (isdigit(Month[0]))
	{
		int month = stoi(Month);
		healthProfile p(day, month, year, fn, ln, gen, h, w);
		p.displayProfile();
		p.displayHR();
		p.displayBMI();
	}
	else
	{
		healthProfile p(day, Month, year, fn, ln, gen, h, w);
		p.displayProfile();
		p.displayHR();
		p.displayBMI();
	}
	
	getch();
	return 0;
}
	
	//healthProfile p1(25,12,1949,"Nawaz","Sharif","Male",173,82);
	//healthProfile p2(23,"Sep",1953,"Shahbaz","Sharif","Male",170,76);
	//healthProfile p3(28,"Oct",1973,"Maryam","Nawaz","Female",165,65);
