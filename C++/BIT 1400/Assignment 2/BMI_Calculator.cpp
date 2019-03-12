#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
	double currWeight, targetWeightChange, targetWeight;
	int weeks, ft, inches, height;
	const int BMI_RATIO_IMP = 703;

	time_t timeval;
	time(&timeval);

	int year = gmtime(&timeval)->tm_year + 1900;
	cout << year << endl;


	cout << "BMI Calculator\n" << "--------------\n";
	cout << "What is your current weight in pounds (lb)?\n";
	cin >> currWeight;
	
	cout << "What is your height? (in ft, inches), with a space between (e.g. 5 11)\n";
	cin >> ft >> inches;

	height = static_cast<int>(pow(ft * 12 + inches,2));

	//cout << "Your current BMI is:\n" << fixed << setprecision(2) << (currWeight*BMI_RATIO_IMP)/height << endl;
	
	cout << "What is your goal weight change per week? (lb)?\n";
	cin >> targetWeightChange;

	cout << "How many weeks do you plan to continue this trend?\n";
	cin >> weeks;


	targetWeight = (currWeight + targetWeightChange*weeks);

	cout << "If you complete follow your plan:\n";
	cout << "          Weight(lb)     BMI\n"
		<< "----------------------------\n";

	cout << "Start  " << setw(13) << currWeight << setw(8) << fixed << setprecision(2) << (currWeight*BMI_RATIO_IMP) / height << endl;
	cout << "End    " << setw(13) << setprecision(0) << targetWeight << setw(8) << fixed << setprecision(2) << (targetWeight*BMI_RATIO_IMP) / height << endl;

    return 0;
}