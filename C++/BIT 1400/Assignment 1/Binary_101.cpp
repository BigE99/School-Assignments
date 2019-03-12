// binary101.cpp : Defines the entry point for the console application.
//
#include <iostream>
using namespace std;


int main()
{
	int year_born, year_now, period_alive;
	cout << "What year is it right now?\n";
	cin >> year_now;
	cout << "What year were you born?\n";
	cin >> year_born;
	period_alive = (year_now - year_born) / 5;
	cout << "You have been alive for " << period_alive << " periods in 101b.\n";
	system("pause");

    return 0;
}

