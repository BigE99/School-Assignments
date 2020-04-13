#pragma once
#include "Shape.h"
using namespace std;

class Triangle : public Shape {
protected:
	int base, height;

public:
	//constructor and deconstructor
	Triangle();
	~Triangle();
	// multiply dimesion by a scaler
	void scale(int scaler);
	// adding two triangles together
	Triangle add_tri(bool oper, Triangle tri_2);
	//getters
	int getBase() { return height; }
	int getHeight() { return base; }
	//setters
	void setBase(int setter) { height = setter; }
	void setHeight(int setter) { base = setter; }
	//get area
	int getArea() { return (base * height / 2); }

};
