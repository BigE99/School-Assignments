#include "Circle.h"


//construtor/deconstructor
Circle::Circle() :Shape() {
	radius = 0;
}
Circle::~Circle() {
}
//multiply by a scaler
void Circle::scale(int scaler) {
	int r = getRad();
	setRad(r * scaler);
}
// add two Circles
Circle Circle::add_cri(bool oper, Circle rec_2) {
	int r;
	if (oper == true) {
		r = this->radius + rec_2.radius;
	}
	else {
		r = this->radius - rec_2.radius;
	}
	Circle temp;
	temp.setRad(r);
	return temp;
}