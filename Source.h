#ifndef Source_h
#define Source_h
class Vector {
	float x = 0,
		y = 0,
		z = 0;
public:
	Vector(float, float, float);
	Vector operator+(Vector t);
	Vector operator+=(Vector t);
	Vector operator-(Vector t);
	Vector operator-=(Vector t);
	Vector operator-();
	Vector operator*(Vector t);
	Vector operator*=(Vector t);
	Vector operator*(float t);
	Vector operator*=(float t);
	Vector operator=(Vector t);
	bool operator==(Vector t);
	bool operator!=(Vector t);
	void GetC();
	void SetX(float x1);
	void SetY(float y1);
	void SetZ(float z1);
};
#endif
