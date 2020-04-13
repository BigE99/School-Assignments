// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"
#include "string"
using namespace std;

int main()
{
	Rectangle test;
	Triangle test2;
	Circle test3;

	test3.set_hex("aaaaaa");
	test.set_hex("ffffff");
	unsigned int *rgb = test.get_rgb();
	unsigned int *hsv = test.get_hsv();
	cout << "Test rgb: " << rgb[0] << ", " << rgb[1] << ", " << rgb[2] << " hsv: " << hsv[0] << ", " << hsv[1] << ", " << hsv[2] << endl;

	test2.set_rgb(0, 0, 255);
	hsv = test2.get_hsv();
	cout << "Test2 Hex: " << test2.get_hex() << " hsv: " << hsv[0] << ", " << hsv[1] << ", " << hsv[2] << endl << endl;

	test.setX(10);
	test.setY(5);
	cout << "X cord is: " << test.getX() << " translated 5 is :";
	test.transX(5);
	cout << test.getX() << endl;
	cout << "Y cord is: " << test.getX() << " translated -3 is :";
	test.transY(-3);
	cout << test.getY() << endl << endl;


	test.setLenght(10);
	test.setWidth(2);
	cout << "Lenght: " << test.getLenght() << " Width: " << test.getWidth() << endl;
	test.scale(3);
	cout << "scaled by factor fo 3 Lenght: " << test.getLenght() << " Width: " << test.getWidth() << endl;
	test = test.add_rec(1, test);
	cout << "added a copy Lenght: " << test.getLenght() << " Width: " << test.getWidth() << endl;
	cout << "the area is: " << test.getArea() << endl << endl;

	test2.setBase(10);
	test2.setHeight(2);
	cout << "Base: " << test2.getBase() << " Height: " << test2.getHeight() << endl;
	test2.scale(3);
	cout << "scaled by factor fo 3 Base: " << test2.getBase() << " Height: " << test2.getHeight() << endl;
	test2 = test2.add_tri(1, test2);
	cout << "added a copy Base: " << test2.getBase() << " Height: " << test2.getHeight() << endl;
	cout << "the area is: " << test2.getArea() << endl << endl;

	test3.setRad(2);
	cout << "radius: " << test3.getRad() << endl;
	test3.scale(3);
	cout << "radius after sclaing by 3: " << test3.getRad() << endl;
	test3 = test3.add_cri(1, test3);
	cout << "added a copy Radius: " << test3.getRad() << endl;
	cout << "the area is: " << test3.getArea() << endl << endl;
}
