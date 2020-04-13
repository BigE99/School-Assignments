#include "shape.h"
#include <string>
#include <sstream>
#include <iostream>
#include <cmath>

//constructor/deconstructor
Shape::Shape() {
	hex = '\0';
	*rgb = {};
	*hsv = {};
	x = 0;
	y = 0;
}
Shape::~Shape() {
}
//Translates in shape in x and y direction
void Shape::transX(int trans) {
	int x = getX();
	setX(x + trans);
}
void Shape::transY(int trans) {
	int y = getY();
	setY(y + trans);
}
//sets the hsv value the converts to rgb and hex this code is working properly so I will assume the inputed color will not be hsv
/*
void Shape::set_hsv(int h, int s, int v) {
	//sets hsv values
	hsv[0] = h;
	hsv[1] = s;
	hsv[2] = v;
	//defines varibles for the equaiton for refrence on what the varibles are go to https://www.rapidtables.com/convert/color/hsv-to-rgb.html
	float c, x, m, r_p, g_p, b_p, _s, _v;
	_s = float(s) / 100;
	_v = float(v) / 100;
	c = _v * _s;
	x = c * (1 - abs(fmod((h / 60), 2) - 1));
	m = _v - c;
	//the condidtions from the equation in the link
	if (h < 60) {
		r_p = c;
		g_p = x;
		b_p = 0;
	}
	else if (60 <= h < 120) {
		r_p = x;
		g_p = c;
		b_p = 0;
	}
	else if (120 <= h < 180) {
		r_p = 0;
		g_p = c;
		b_p = x;
	}
	else if (180 <= h < 240) {
		r_p = 0;
		g_p = x;
		b_p = c;
	}
	else if (240 <= h < 300) {
		r_p = x;
		g_p = 0;
		b_p = c;
	}
	else if (300 <= h <= 360) {
		r_p = c;
		g_p = 0;
		b_p = x;
	}
	rgb[0] = (r_p + m) * 255;
	rgb[1] = (g_p + m) * 255;
	rgb[2] = (b_p + m) * 255;
	//calling the function that will set the hex
	rgbtohex(rgb[0], rgb[1], rgb[2]);
}*/
// sets the hex color then calls the set rgb funstion that will set rgb and hsv
void Shape::set_hex(string color_in) {
	hex = color_in;
	int size = color_in.size();
	stringstream ss;
	string str;
	for (int i = 0; i < 3; i++) {
		//making sur ethat the hex is 5 digits
		if (size != 6) { break; }
		// will grab to numbers per loop
		else if (size == 6) { str = hex.substr(i * 2, 2); }
		//hex conversion
		ss << std::hex << str;
		//setting the rgb
		ss >> rgb[i];
		//clean up stringstream
		ss.clear();
	}
	//used to converting rgb to hex
	set_rgb(rgb[0], rgb[1], rgb[2]);
	
}
//setting rgb and converting to hsv
void Shape::set_rgb(int r, int g, int b) {
	//setting the rgb values
	rgb[0] = r;
	rgb[1] = g;
	rgb[2] = b; 
	//setting the hex value
	rgbtohex(r,g,b);
	//hsv conversions
	float r_p = float(r) / 255, g_p = float(g) / 255, b_p = float(b) / 255, cmax, cmin, delta;
	int iden;
	if (r_p >= g_p && r_p >= b_p){
		cmax = r_p;
		iden = 1;
	}
	else if (g_p >= r_p && g_p >= b_p){
		cmax = g_p;
		iden = 2;
	}
	else if (b_p >= r_p && b_p >= g_p) {
		cmax = b_p;
		iden = 3;
	}
	if (r_p <= g_p && r_p <= b_p) {
		cmin = r_p;
	}
	else if (g_p <= r_p && g_p <= b_p) {
		cmin = g_p;
	}
	else if (b_p <= r_p && b_p <= g_p) {
		cmin = b_p;
	}
	delta = cmax - cmin;
	//getting and setting hue
	if (delta == 0) {
		hsv[0] = 0;
	}
	else if (iden == 1) {
		float temp2 = (g_p - b_p) / delta;
		temp2 = fmod(temp2, 6);
		hsv[0] = temp2 * 60 + 1;
	}
	else if (iden == 2) {
		hsv[0] = 60 * (((b_p - r_p) / delta) + 2);
	}
	else if (iden == 3) {
		hsv[0] = 60 * (((r_p - g_p) / delta) + 4);
	}
	//getting and setting sat
	if (cmax == 0) {
		hsv[1] = 0;
	}
	else {
		hsv[1] = delta / cmax * 100;
	}
	//gettign and setting value
	hsv[2] = cmax * 100;
}
//converting rgb to hex
void Shape::rgbtohex(int r, int g, int b) {
	string temp;
	char red[255];
	sprintf_s(red, "%.2X", r);
	temp.append(red);
	char green[255];
	sprintf_s(green, "%.2X", g);
	temp.append(green);
	char blue[255];
	sprintf_s(blue, "%.2X", b);
	temp.append(blue);
	hex = temp;
}
//todo make add shapes function
