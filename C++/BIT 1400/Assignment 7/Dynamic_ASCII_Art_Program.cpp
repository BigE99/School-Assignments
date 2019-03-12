#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

char getValidChar();
unsigned int getValidPositiveInteger();
void drawImg(char**, int, int, ostream&);
void fillImg(char**, int, int, char);
void deleteImage(char **, int, int);
void clearScreen();

int main()
{

	char** image;
	int w, h, x, y;
	bool quit = false;
	char brush = '*', menuSelection;


	cout << "  ASCII Art Master 2000 SE  \n"
		 << "----------------------------\n";

	cout << "How many characters wide would you like your art to be?\n";
	w = getValidPositiveInteger();

	cout << "How many characters tall would you like your art to be?\n";
	h = getValidPositiveInteger();

	// create an array of char pointers
	image = new char*[w];
	// for each element, create a new array of char pointers
	for (int i = 0; i < w; i++) {
		image[i] = new char[h];
	}

	fillImg(image, w, h, ' ');

	do {

		cout << "Image is " << w << "x" << h << endl;
		cout << "Please Select an Action:\n\n";
		cout << "\tD: Draw\n" << "\tB: Set Brush\n" << "\tF: Fill\n" << "\tP: Set Point\n" << "\tS: Save Art\n" << "\tQ: Quit\n\t:";

		menuSelection = toupper(getValidChar());

		switch (menuSelection)
		{
		case 'D':
			drawImg(image, w, h, cout);
			break;
		case 'B':
			cout << "Please Enter the Character You Would Like to Use as a Brush:";
			brush = getValidChar();
			break;
		case 'F':
			fillImg(image, w, h, brush);
			break;
		case 'P':
			cout << "What Point would you like to draw to? (x y):";
				x = getValidPositiveInteger()-1;
				y = getValidPositiveInteger()-1;
				if (x < w || y < h) {
					image[x][y] = brush;
				}

			break;
		case 'S': 
		{
			ofstream fout;
			char filename[] = "output.txt";
			fout.open(filename);
			drawImg(image, w, h, fout);
			fout.close();
			cout << "Your masterpiece saved to " << filename << endl;
			break; 
		}
		case 'Q':
			quit = true;
			break;
		default:
			clearScreen();
			drawImg(image, w, h, cout);
		}	

 	} while (!quit);

	deleteImage(image, w, h);

	return 0;
}



void drawImg(char** img, int width, int height, ostream& out) {

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			out << img[j][i];
		}
		out << endl;
	}
}

void fillImg(char** img, int width, int height, char brush) {
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

void deleteImage(char ** image, int w, int h) {
	for (int i = 0; i < h; i++) {
		delete image[i];
	}
	delete image;
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


