// healthProfile.h
#include <string>
#include <ctime>
#include <sstream>
#include <iostream>
#include <cctype>

using namespace std;

class DateofBirth
{
	private:
		int day = 0;
		int month = 0;
		int year = 0;
		string Month = "";
		
	public:
		// ---------------- Constructor: numeric  --------------------	
		DateofBirth(int d, int m, int y)
		{
			if(d >= 1 && d <= 31) { day = d; }
			if(m >= 1 && m <= 12) { month = m; }
			if(y >= 1900 && y <= 2026) { year = y; }
		}
		// ---------------- Constructor: string ---------------------
		DateofBirth(int d, string m, int y)
		{
			if(d >= 1 && d <= 31) { day = d; }
			if(y >= 1900 && y <= 2026) { year = y; }
			for(char &c : m) { c = tolower(c); }
			if(m == "jan" || m == "january") { Month = "Jan"; month = 1; }
			else if(m == "feb" || m == "february") { Month = "Feb"; month = 2; }
			else if(m == "mar" || m == "march") { Month = "Mar"; month = 3; }
			else if(m == "apr" || m == "april") { Month = "Apr"; month = 4; }
			else if(m == "may") { Month = "May"; month = 5; }
			else if(m == "jun" || m == "june") { Month = "Jun"; month = 6; }
			else if(m == "jul" || m == "july") { Month = "Jul"; month = 7; }
			else if(m == "aug" || m == "august") { Month = "Aug"; month = 8; }
			else if(m == "sep" || m == "september") { Month = "Sep"; month = 9; }
			else if(m == "oct" || m == "october") { Month = "Oct"; month = 10; }
			else if(m == "nov" || m == "november") { Month = "Nov"; month = 11; }
			else if(m == "dec" || m == "december") { Month = "Dec"; month = 12; }
			else { cout << "Invalid Month!" << endl; }
		}
		//------------------  Member Function  -----------------------
		int displayAge() const
		{
			time_t raw_time = time(nullptr);
    		tm* local_time = localtime(&raw_time);
    		int current_year = local_time->tm_year + 1900;
			return current_year - year;
		}
		void displayDOB() const
		{
			if(Month != "")
			{
				cout << "Date of Birth: " << day << "-" << Month << "-" << year << endl;	
			}
			else
			{
				cout << "Date of Birth: " << day << "-" << month << "-" << year << endl; 
			}
		}
		//------------------ Getter & Setter ------------------------
		void setDay(int d) 
		{
			if(d >= 1 && d <= 31) { day = d; }
			else { cout << "Invalid Date!" << endl; }
		}
		void setYear(int y) 
		{
			if(y >= 1900 && y <= 2026) { year = y; }
			else { cout << "Invalid Year!" << endl; }
		}
		void setMonth(int m)
		{
			if(m == 1) { Month = "Jan"; month = 1; }
			else if(m == 2) { Month = "Feb"; month = 2; }
			else if(m == 3) { Month = "Mar"; month = 3; }
			else if(m == 4) { Month = "Apr"; month = 4; }
			else if(m == 5) { Month = "May"; month = 5; }
			else if(m == 6) { Month = "Jun"; month = 6; }
			else if(m == 7) { Month = "Jul"; month = 7; }
			else if(m == 8) { Month = "Aug"; month = 8; }
			else if(m == 9) { Month = "Sep"; month = 9; }
			else if(m == 10) { Month = "Oct"; month = 10; }
			else if(m == 11) { Month = "Nov"; month = 11; }
			else if(m == 12) { Month = "Dec"; month = 12; }
			else { cout << "Invalid Month!" << endl; }
	    }
		int getDay() const { return day; }
		int getMonth() const { return month; }
		int getYear() const { return year; }
};

class healthProfile
{
	private:
		DateofBirth dob;
		string first_name = "";
		string last_name = "";
		string gender = "";
		float height = 0;
		float weight = 0;
		float bmi = 0;
		int maxHeart_Rate = 0;
		float targetMin = 0;
		float targetMax = 0;
		
		void Calculations()
		{
			bmi = weight / ((height / 100.0f) * (height / 100.0f));
			maxHeart_Rate = 220 - dob.displayAge(); 
			targetMax = maxHeart_Rate * 0.80;   
			targetMin = maxHeart_Rate * 0.50;   
		}
	
	public:
		// ----------------------------  Constructor for numeric ------------------------------------------	
		healthProfile(int d, int m, int y, string fn, string ln, string g, float h, float w) : dob(d, m, y)
		{
			first_name = fn;
			last_name = ln;
			gender = g;
			if(h >= 54.6 && h <= 272) { height = h; }
			if(w >= 15.5 && w <= 635) { weight = w; }
			Calculations();
		}	
		
		// ------------------------------------ Constructor for string ----------------------------
		healthProfile(int d, string m, int y, string fn, string ln, string g, float h, float w) : dob(d, m, y)
		{
			first_name = fn;
			last_name = ln;
			gender = g;
			if(h >= 54.6 && h <= 272) { height = h; }
			if(w >= 15.5 && w <= 635) { weight = w; }		
			Calculations();
		}
		
		// --------------------------------- Member Functions ----------------------------------------
		void displayProfile() const
		{
			cout << "----------------------------------------------------------------------------" << endl;		
			cout << "-------------------------  PATIENT PROFILE  --------------------------------" << endl;
			cout << "----------------------------------------------------------------------------" << endl;		
			cout << "\nFirst Name: " << first_name << endl;
			cout << "Last Name: " << last_name << endl;
			dob.displayDOB();
			cout << "Gender: " << gender << endl;
			cout << "Height: " << height << " cm           Weight: " << weight << " kg" << endl;
			cout << "Patient age is: " << dob.displayAge() << " years" << endl;
		}

		void displayHR() const
		{
			cout << "Max Heart Rate: " << maxHeart_Rate << " bpm" << endl;
			cout << "Target Heart Rate Range from: " << targetMin << "  -  " << targetMax << " bpm" << endl;		
		}	
		
		void displayBMI() const
		{
			cout << "Patient BMI (Body Mass Index) is: " << bmi << endl;
			cout << "\n--- BMI VALUES REFERENCE ---" << endl;
			cout << "Underweight: less than 18.5" << endl;
			cout << "Normal:      18.5 - 24.9" << endl;
			cout << "Overweight:  25 - 29.9" << endl;
			cout << "Obese:       30 or greater" << endl;
			cout << "----------------------------------------------------------------------------" << endl;
		}
		
		// ------------------------------- Setter & Getter ----------------------------------------
		string getFname() const { return first_name; }							
		string getLname() const { return last_name; }							
		string getGender() const { return gender; }							
		float getHeight() const { return height; }								
		float getWeight() const { return weight; }	
		void setFname(string fn) { first_name = fn; }
		void setLname(string ln) { last_name = ln; }
		void setGender(string gen) { gender = gen; }
		void setHeight(float h) { if(h >= 54.6 && h <= 272) { height = h; } Calculations(); }
		void setWeight(float w) { if(w >= 15.5 && w <= 635) { weight = w; } Calculations();}
};
