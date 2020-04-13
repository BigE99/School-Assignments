#include "Triangle.h"


//construtor/ deconstructor
Triangle::Triangle() :Shape() {
	base = 0;
	height = 0;
}
Triangle::~Triangle(){
}
//multiply by a scaler
void Triangle::scale(int scaler) {
	int w = getBase();
	int l = getHeight();
	setBase(w * scaler);
	setHeight(l * scaler);
}
// add two Triangles
Triangle Triangle::add_tri(bool oper, Triangle rec_2) {
	int l, w;
	if (oper == true) {
		w = this->base + rec_2.base;
		l = this->height + rec_2.height;
	}
	else {
		w = this->base - rec_2.base;
		l = this->height - rec_2.height;
	}
	Triangle temp;
	temp.setHeight(l);
	temp.setBase(w);
	return temp;
}