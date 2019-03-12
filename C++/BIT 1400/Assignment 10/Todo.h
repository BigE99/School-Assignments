#pragma once
#include <iostream>
#include <string>
using namespace std;
class ToDo {
private:
	static ToDo* high;
public:
	ToDo();
	ToDo(int, string);
	string output(string);
	string getTask();
	void calchigh();
	static ToDo* highestPriority() { return high; }
	int getPriority();
	void increasePriority(int);
	string task;
	int priority;
};