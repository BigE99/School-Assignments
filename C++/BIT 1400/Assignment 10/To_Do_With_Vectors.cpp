#include <iostream>
#include <string>
#include <vector>
#include "ToDo.h"
using namespace std;
vector<ToDo> gettasks(vector<ToDo>);
vector<ToDo> sortTasks(vector<ToDo>);

int main()
{
	vector<ToDo> list;
	cout << "Welcome to my ToDo Prioritization Program:\n";
	list = gettasks(list);
	list = sortTasks(list);
	cout << "This is your tasklist, things you should do first are listed first:\n";
	for (int i = 1; i < list.size(); i++) {
		cout << list[i].output("\t\t") << endl;
	}
	system("PAUSE");
	return 0;
}

vector<ToDo> gettasks(vector<ToDo> list)
{ 
	ToDo temp;
	bool loop = true;
	while (loop) {
		cout << "What is the task that you would like to add?\n";
		getline(cin, temp.task);
		cout << "What is the priority of the task you would like to add? (Put a number less then 1 too stop)\n";
		cin >> temp.priority;
		list.push_back(temp);
		if (temp.priority < 1) {
			loop = false;
		}
		cin.ignore();
	}
	return list;
}

vector<ToDo> sortTasks(vector<ToDo> list) {

	for (int x = 0; x < list.size(); x++)
	{
		for (int y = 0; y < list.size() - 1; y++)
		{
			if (list[y].priority > list[y + 1].priority)
			{
				ToDo temp = list[y + 1];
				list[y + 1] = list[y];
				list[y] = temp;
			}
		}
	}
		return list;
}
