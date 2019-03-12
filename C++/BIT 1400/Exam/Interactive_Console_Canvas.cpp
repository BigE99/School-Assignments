//#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <vector>
#include "Canvas.h"
#include "Instruction.h"

using namespace std;

string getFile(std::ifstream&);
ACTION getDirection();

int main()
{
	bool quit = true;
	vector<Instruction*> temp;
	Canvas Can;
	ACTION test = NONE;
	Pen pen;

	ifstream Reader("File1.txt");             //Open file
	string Art = getFile(Reader);       //Get file
	cout << Art << std::endl;               //Print it to the screen
	Reader.close();                           //Close file
	cout << endl << "Pen Position: " << &Canvas::getPenX << ", " << &Canvas::getPenY << "       Image Size: " << &Canvas::getWidth << ", " << &Canvas::getHeight << endl;

	ofstream outputFile;
	outputFile.open("Instruction.txt");
	while (quit) {
		test = getDirection();
		if (test == STOP) {
			quit = false;
		}
		Can.doCommand(test);
		cout << Can.getPenX();
		system("CLS");
		ifstream Reader("File1.txt");             //Open file
		string Art = getFile(Reader);       //Get file
		cout << Art << endl;               //Print it to the screen
		Reader.close();                           //Close file
		if (pen._show) {
			Can.draw(cout, true);
		}
		else
		{
			Can.draw(cout, false);
		}
		unsigned int test1 = 0;
		Instruction *test2;
		temp = Can.getInstructions();

		for (unsigned int i = 0; i < test1; i++) {
			test1 = temp.size();
			test2 = temp.at(i);
			outputFile << test2;
		}

	}


	outputFile.close();
	return 0;
}

string getFile(std::ifstream& File)
{
	string Lines = "";        //All lines

	if (File)
	{
		while (File.good())
		{
			string TempLine;                  //Temp line
			getline(File, TempLine);        //Get temp line
			TempLine += "\n";                      //Add newline character

			Lines += TempLine;                     //Add newline
		}
		return Lines;
	}
	else                           //Return error
	{
		return "ERROR File does not exist.";
	}
}

ACTION getDirection() {
	char d = tolower(_getch());
	switch (d) {
	case 'a':
		return LEFT;
	case 'd':
		return RIGHT;
	case 'w':
		return UP;
	case 's':
		return DOWN;
	case 'q':
		return STOP;
	case 'e':
		return PEN_TOGGLE;
	case 'f':
		return PEN_POSITION;
	}
	return STOP;
}