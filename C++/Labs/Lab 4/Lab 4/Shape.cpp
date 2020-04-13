#include "stdafx.h"
#include "Shape.h"


Shape::Shape(Shape_type my_type, float h, float w, float d)
{
	Type = my_type;
	Dim.Base_h = h;
	Dim.Base_w = w;
	Dim.Base_d = d;
}
Shape::~Shape()
{
}
void Shape::Scale_h(float scaler) {
	Dim.Base_h = scaler;
	Set_vol();
	Set_sur();
}
void Shape::Scale_w(float scaler) {
	Dim.Base_w = scaler;
	Set_vol();
	Set_sur();
}
void Shape::Scale_d(float scaler) {
	Dim.Base_d = scaler;
	Set_vol();
	Set_sur();
}
void Shape::Scale(float scaler_h, float scaler_w, float scaler_d) {
	Dim.Base_h = scaler_h;
	Dim.Base_w = scaler_w;
	Dim.Base_d = scaler_d;
	Set_vol();
	Set_sur();
}
Shape::Dimension Shape::Sub_dim(Dimension Dim_1, Dimension Dim_2) {
	Dim_1.Base_h -= Dim_2.Base_h;
	Dim_1.Base_w -= Dim_2.Base_w;
	Dim_1.Base_d -= Dim_2.Base_d;
}
Shape::Dimension Shape::Add_dim(Dimension Dim_1, Dimension Dim_2) {
	Dim_1.Base_h += Dim_2.Base_h;
	Dim_1.Base_w += Dim_2.Base_w;
	Dim_1.Base_d += Dim_2.Base_d;
}
void Shape::Trans_x(int tran) {
	Loc.x += tran;
}
void Shape::Trans_y(int tran) {
	Loc.y += tran;
}
void Shape::Trans_z(int tran) {
	Loc.z += tran;
}