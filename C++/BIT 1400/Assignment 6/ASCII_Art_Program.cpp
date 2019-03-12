#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

const unsigned int WIDTH = 16, HEIGHT = 9;
char getValidChar();
unsigned int getValidPositiveInteger();
void clearScreen();

void drawImg(char[][HEIGHT], int, int, ostream&);
void fillImg(char[][HEIGHT], int, int, char);

int main()
{

	char image[WIDTH][HEIGHT];
	int x, y;
	bool quit = false;
	char brush = ' ', menuSelection;


	cout << "  ASCII Art Master 2000  \n"
		 << "-------------------------\n";



	fillImg(image, WIDTH, HEIGHT, brush);
	brush = '*';

	do {

		cout << "Please Select an Action:\n\n";
		cout << "\tD: Draw\n" << "\tB: Set Brush\n" << "\tF: Fill\n" << "\tP: Set Point\n" << "\tS: Save Art\n" << "\tQ: Quit\n\t:";

		menuSelection = toupper(getValidChar());

		switch (menuSelection)
		{
		case 'D':
			drawImg(image, WIDTH, HEIGHT, cout);
			break;
		case 'B':
			cout << "Please Enter the Character You Would Like to Use as a Brush:";
			brush = getValidChar();
			break;
		case 'F':
			fillImg(image, WIDTH, HEIGHT, brush);
			break;
		case 'P':
			cout << "What Point would you like to draw to? (x y):";
				x = getValidPositiveInteger()-1;
				y = getValidPositiveInteger()-1;
				if (x < WIDTH || y < HEIGHT) {
					image[x][y] = brush;
				}

			break;
		case 'S': 
		{
			ofstream fout;
			char filename[] = "output.txt";
			fout.open(filename);
			drawImg(image, WIDTH, HEIGHT, fout);
			fout.close();
			cout << "Your masterpiece saved to " << filename << endl;
			break; 
		}
		case 'Q':
			quit = true;
			break;
		default:
			clearScreen();
			drawImg(image, WIDTH, HEIGHT, cout);
		}	

 	} while (!quit);


	return 0;
}



void drawImg(char img[][HEIGHT], int width, int height, ostream& out) {

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			out << img[j][i];
		}
		out << endl;
	}
}

void fillImg(char img[][HEIGHT], int width, int height, char brush) {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			img[j][i] = brush;
		}
	}
}

char getValidChar() {
	char userInput;

	cin >> userInput;

	while (cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << "Please enter a character only\n";
		cin >> userInput;
	}

	return (userInput);
}

void clearScreen()
{
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}

unsigned int getValidPositiveInteger() {
	int userInput;

	cin >> userInput;

	while (cin.fail() || userInput <= 0) {
		cin.clear();
		cin.ignore();
		cout << "Please enter a positive integer only\n";
		cin >> userInput;
	}

	return (unsigned int)userInput;
}


