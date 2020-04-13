#pragma once
#include <string>
#include <iostream>
using namespace std;
class Shape
{
protected:
	//color varibles
	string hex = "";
	unsigned int rgb[3], hsv[3];
	//x and y position
	int x, y;
	//rgb to hex conversion
	void rgbtohex(int r, int g, int b);
public:
	//tranlsate in x and y direction
	void transX(int trans);
	void transY(int trans);
	//constructor/deconstructor
	Shape();
	~Shape();
	//Getters
	unsigned int * get_rgb() { return rgb; }
	unsigned int * get_hsv() { return hsv; }
	string get_hex() { return hex; }
	int getX() {	return x;	}
	int getY() {	return y;	}
	//Setters
	void set_rgb(int r, int g, int b);
	//void set_hsv(int h, int s, int v);
	void set_hex(string hex);
	void setX(int m) {	x = m;	}
	void setY(int n) {	y = n;	}
};
