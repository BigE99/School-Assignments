#pragma once
#include "Shape.h"
using namespace std;

class Rectangle : public Shape {
protected:
	int lenght, width;
	
public:
	//constructor and deconstructor
	Rectangle();
	~Rectangle();
	//multipling the dimension by a scaler
	void scale(int scaler);
	//adding two rectangles together
	Rectangle add_rec(bool oper, Rectangle rec_2);
	//getters
	int getWidth() {	return width;	}
	int getLenght() {	return lenght;	}
	//setters
	void setWidth(int setter) {	width = setter;	}
	void setLenght(int setter) {lenght = setter;}
	//get area
	int getArea() {	return (lenght * width); }

};
