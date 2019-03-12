#include <iostream>
#include <string>
#include <ctime>
#include <stdexcept>
#include "ToDo.h"
using namespace std;

int getRand(int min, int range) {
	return (rand() % range) + min;     
}


const unsigned int NUM_VERB = 4;
const unsigned int NUM_ACTIVITY = 7;

const string VERB[] = { "Play", "Work on", "Practice","Eat", };
const string TARGET[] = { "homework", "dishes", "games", "guitar","vacuuming","aardvarking","coding" };

int main()
{
	srand(static_cast<unsigned int>(time(NULL))); // seed random number generator
	int numTask = getRand(3, 3); // number of tasks is 3->3+3
	ToDo** tasks = new ToDo*[numTask]; // create array of ToDo pointers, sized with numTask

	// creates new ToDo objects and keeps the pointers in tasks array
	for (int i = 0; i < numTask; i++) {
		tasks[i] = new ToDo(getRand(1, 9), VERB[rand() % NUM_VERB] + " " + TARGET[rand() % 7]);
	}

	cout << "The tasks are:\n" << "Priority\tTask\n";
	// lists the ToDo objects using the output() member
	for (int i = 0; i < numTask; i++) {
		cout << tasks[i]->output("\t\t") << endl;
	}
	cout << "\nYou should work on:\n";
	cout << ":==> " << ToDo::highestPriority()->getTask() << endl << endl;

	unsigned int increaseBy = rand() % 7 + 1;
	cout << "But if i increase the priority of: " << tasks[numTask -1]->getTask() << " by " << increaseBy << endl;

	tasks[numTask - 1]->increasePriority(increaseBy);
	
	cout << "\nYou should work on:\n";
	cout << ":==> " << ToDo::highestPriority()->output(": ") << endl;

	// make sure all priorities are greator than 0
	for (int i = 0; i < numTask; i++) {
		if (tasks[i]->getPriority() < 1) {
			throw invalid_argument("Invalid Priority Found!");
		}
	}

	// de-allocate memory, pointer null-ing not important as end of progran
	for (int i = 0; i < numTask; i++) {
		delete tasks[i];
	}
	delete tasks;


	getchar();
	
	return 0;

}



