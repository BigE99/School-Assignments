#include <iostream>
#include <cmath>

using namespace std;


void sum1(double&, unsigned int);
double sum2(unsigned int);
unsigned int getValidPositiveInteger();

int main()
{
	double s1, s2;
	cout << "Number of interations to complete (n, for trial 1) \n";
	unsigned int n = getValidPositiveInteger(),m;
	cout << "Number of interations to complete (n, for trial 2) \n";
	m = getValidPositiveInteger();
	cout << "Calculating...";
	sum1(s1, n);
	s2 = sum2(m);
	cout << "Done\n"
		<< "Using pass by reference, the partial sum using " << n << " terms is:\n" << s1 << endl
		<< "Using pass by value, the partial sum using " << m << " terms is:\n" << s2 << endl
		<< "\nThe two functions did " << (s1 == s2 ? "":"not ") << "result in the exact same value\n";
	
	return 0;
}

void sum1(double& sum, unsigned int n)
{
	sum = sum2(n);
}

double sum2(unsigned int n)
{
	double thesum = 0;
	for (unsigned int i = 2; i <= n; i++) {
		thesum += 1.0/((i*i)-1);
	}
	return thesum;
}

// Get a valid integer from the user
unsigned int getValidPositiveInteger() {
	unsigned int userInput;

	cin >> userInput;

	while (cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << "Please enter a positive integer only\n";
		cin >> userInput;
	}

	return userInput;
}