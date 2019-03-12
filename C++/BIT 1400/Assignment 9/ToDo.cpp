#pragma once
#include <iostream>
#include <string>
#include "ToDo.h"
using namespace std;
// makes a ToDo that will store highest priority 
ToDo* ToDo::high = new ToDo();
// constructor when no parameters given 
ToDo::ToDo() {
	task = "";
	priority = 10;
}

//constructor when given two paraneters
ToDo::ToDo(int priority, string task) {
	this->task = task;
	this->priority = priority;
	gethigh();
}
// Outputing the priority and task
string ToDo::output(string table) {
	return to_string(priority) + table + task;
}


string ToDo::getTask() {
	return task;
}

//Gets highest priority ToDo and stores in high
void ToDo::gethigh() {
	if (priority < high->priority) {
		high->task = task;
		high->priority = priority;
	}
}

int ToDo::getPriority() {
	return priority;
}

//Increase the priority by amount but does not let priority go below 1
void ToDo::increasePriority(int amount) {
	if (priority - amount < 1) {
		priority = 1;
	}
	else {
		priority -= amount;
	}
	gethigh();
}