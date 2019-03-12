#pragma once
#include <iostream>
#include <string>
#include "ToDo.h"
using namespace std;

ToDo* ToDo::high = new ToDo();

ToDo::ToDo() {
	task = "";
	priority = 10;
}


ToDo::ToDo(int priority, string task) {
	this->task = task;
	this->priority = priority;
	calchigh();
}

string ToDo::output(string table) {
	return to_string(priority) + table + task;
}

string ToDo::getTask() {
	return task;
}

void ToDo::calchigh() {
	if (priority < high->priority) {
		high->task = task;
		high->priority = priority;
	}
}

int ToDo::getPriority() {
	return priority;
}

void ToDo::increasePriority(int amount) {
	if (priority - amount < 1) {
		priority = 1;
	}
	else {
		priority -= amount;
	}
	calchigh();
}