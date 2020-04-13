#include "Rectangle.h"


//construtor and deconstructor
Rectangle::Rectangle() :Shape() {
	width = 0;
	lenght = 0;
}
Rectangle::~Rectangle() {
}
//multiply by a scaler
void Rectangle::scale(int scaler) {
	int w = getWidth();
	int l = getLenght();
	setWidth(width * scaler);
	setLenght(lenght * scaler);
}
// add two rectangles
Rectangle Rectangle::add_rec(bool oper, Rectangle rec_2) {
	int l, w;
	if (oper == true) {
		w = this->width + rec_2.width;
		l = this->lenght + rec_2.lenght;
	}
	else {
		w = this->width - rec_2.width;
		l = this->lenght - rec_2.lenght;
	}
	Rectangle temp;
	temp.setLenght(l);
	temp.setWidth(w);
	return temp;
}