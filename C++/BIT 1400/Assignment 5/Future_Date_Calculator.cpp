
#include <ctime>
#include <iostream>
#include <fstream>

using namespace std;

unsigned int getDayOfYear();
unsigned int getValidPositiveInteger();

const int MONTHS = 12;
const int ABBR_LENGTH = 4;

int main()
{
	ifstream fi;
	char months[MONTHS][ABBR_LENGTH];
	int monthDays[MONTHS];
	int days;

	fi.open("cal.txt");

	for (int i = 0; i < MONTHS; i++) {
		fi >> months[i];
	}
	for (int i = 0; i < MONTHS; i++) {
		fi >> monthDays[i];
	}
	fi.close();


	cout << "Incredible Edible Date Predictor!\n";
	cout << "*********************************\n";
	cout << "Enter the number of days in the future you want to predict the date for:";
	
	int x = getDayOfYear();
	days = (getValidPositiveInteger() + getDayOfYear()) % 365; // discard years

	int currMonth = -1;
	// get month and day
	while (days > monthDays[currMonth]) {
		days -= monthDays[++currMonth];
	} 
	currMonth++;
	cout << "The Date you have asked for is:\n" << months[currMonth] << " " << days << endl;

    return 0;
}


// returns the day of the year
unsigned int getDayOfYear() 
{
	time_t t;
	struct tm timeinfo; 

	time(&t);
#ifdef _WIN32
	localtime_s(&timeinfo, &t);
#else
	localtime_r(&t, &timeinfo)
#endif
	return timeinfo.tm_yday;
}

// Get a valid positive integer from the user
unsigned int getValidPositiveInteger() {
	int userInput;

	cin >> userInput;

	while (cin.fail() || userInput < 0) {
		cin.clear();
		cin.ignore();
		cout << "Please enter a positive integer only\n";
		cin >> userInput;
	}

	return (unsigned int)userInput;
}