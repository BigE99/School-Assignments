#include <iostream>
#include <string>
using namespace std;

struct ToDo {
	unsigned int priority;
	string task;
};

ToDo* newTodo();
ToDo* getFirstPriority(ToDo**, int);
void empty(ToDo**, int);


int main()
{

	ToDo** tasklist;
	unsigned int taskCount;
	cout << "How many Tasks will there be?\n";
	cin >> taskCount;
	cin.ignore();

	tasklist = new ToDo*[taskCount];

	for (int i = 0; i < taskCount; i++) {
		tasklist[i] = newTodo();
	}

	ToDo* first = getFirstPriority(tasklist, taskCount);
	cout << "\nYou should do \"" << first->task << "\" first.\n";

	empty(tasklist, taskCount);
	delete tasklist;
	tasklist = NULL;
	getchar();
	return 0;
}

ToDo* newTodo() {
	ToDo* t = new ToDo;
	cout << "What is the task?\n";
	getline(cin, (*t).task);
	cout << "What is the priority of this task?\n";
	cin >> t->priority;
	cin.ignore();
	return t;
}

ToDo* getFirstPriority(ToDo** tasklist, int num) {
	ToDo* highestPriority = *tasklist;
	for (int i = 1; i < num; i++) {
		if (tasklist[i]->priority < highestPriority->priority) {
			highestPriority = tasklist[i];
		}
	}
	return highestPriority;
}

void empty(ToDo** tasklist, int num) {
	for (int i = 0; i < num; i++) {
		delete tasklist[i];
		tasklist[i] = NULL;
	}
}