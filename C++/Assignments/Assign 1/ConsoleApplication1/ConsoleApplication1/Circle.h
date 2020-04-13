#pragma once
#include "Shape.h"
#include <cmath>
using namespace std;

class Circle : public Shape {
protected:
	int radius;

public:
	//constructor / deconstrctor
	Circle();
	~Circle();
	//function to scale the dimesion by a scaler
	void scale(int scaler);
	//adds two circles
	Circle add_cri(bool oper,  Circle tri_2);
	//getters
	int getRad() { return radius; }
	//setters
	void setRad(int setter) { radius = setter; }
	//get area
	int getArea() { return (3.141 * pow(radius, 2)); }

};
