#pragma once
#include <iostream>
#include <string>
using namespace std;
class ToDo {
private:
	string task;
	int priority;
	static ToDo* high;
public:
	ToDo();
	ToDo(int, string);
	string output(string);
	string getTask();
	void gethigh();
	// did the enitire function in here instead of in cpp
	static ToDo* highestPriority() { return high; }
	int getPriority();
	void increasePriority(int);
};