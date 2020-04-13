#pragma once
class Shape
{
public:
	struct Location {
		int x, y, z;
	};
	struct Dimension {
		float Base_h, Base_w, Base_d;
	};
	struct Shader{
		float Spec, Trans, Ref_ind;
	};
protected:
	enum Shape_type { Cly, Sph, Cub, Pyr };
	float Volume, Surf_area;
	char Color;

	Location Loc;
	Dimension Dim;
	Shader Sha;
	Shape_type Type;

	virtual void Set_vol() = 0;
	virtual void Set_sur() = 0;

	Dimension Sub_dim(Dimension, Dimension);
	Dimension Add_dim(Dimension, Dimension);

public:

	Shape(Shape_type, float, float, float);
	~Shape();

	void Scale_h(float);
	void Scale_w(float);
	void Scale_d(float);
	void Scale(float, float, float);

	void Trans_x(int);
	void Trans_y(int);
	void Trans_z(int);
};

