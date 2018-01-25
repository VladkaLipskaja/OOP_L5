#include "Source.h"
#include "Error.h"
#include <iostream>
#include <float.h>
using namespace std;
Vector::Vector(float x1 = 0, float y1 = 0, float z1 = 0) : x(x1), y(y1), z(z1) { };
void Vector::SetX(float x1) { x = x1; }
void Vector::SetY(float y1) { y = y1; }
void Vector::SetZ(float z1) { z = z1; }
Vector Vector::operator+(Vector t) { 
	Vector temp;
	try {
		if (abs(t.x) >= 0 && abs(x) >= 0) if (FLT_MAX - abs(t.x) < abs(x)) throw OverFlow();
		temp.x = x + t.x;
		if (abs(t.y) >= 0 && abs(y) >= 0) if (FLT_MAX - abs(t.y) < abs(y)) throw OverFlow();
		temp.y = y + t.y;
		if (abs(t.z) >= 0 && abs(z) >= 0) if (FLT_MAX - abs(t.z) < abs(z)) throw OverFlow();
		temp.z = z + t.z;
		temp.GetC();
		return temp;
	} catch (OverFlow &e) { e.ErrorPrint(); return t; }
}

Vector Vector::operator+=(Vector t) {
	try {
		if (abs(t.x) >= 0 && abs(x) >= 0) if (FLT_MAX - abs(t.x) < abs(x)) throw OverFlow();
	 	x = x + t.x;
		if (abs(t.y) >= 0 && abs(y) >= 0) if (FLT_MAX - abs(t.y) < abs(y)) throw OverFlow();
		y = y + t.y;
		if (abs(t.z) >= 0 && abs(z) >= 0) if (FLT_MAX - abs(t.z) < abs(z)) throw OverFlow();
		z = z + t.z;
		return *this;
	} catch (OverFlow &e) { e.ErrorPrint(); return t; }
}

Vector Vector::operator-(Vector t) {
	Vector temp;
	try {
		if (t.x >= 0 && x <= 0)	if (FLT_MAX - t.x < abs(x)) throw OverFlow();
		else if (t.x <= 0 && x >= 0) if (FLT_MAX - x < abs(t.x)) throw OverFlow();
		temp.x = x - t.x;

		if (t.y >= 0 && y <= 0)	if (FLT_MAX - t.y < abs(y)) throw OverFlow();
		else if (t.y <= 0 && y >= 0) if (FLT_MAX - y < abs(t.y)) throw OverFlow();
		temp.y = y - t.y;

		if (t.z >= 0 && z <= 0)	if (FLT_MAX - t.z < abs(z)) throw OverFlow();
		else if (t.z <= 0 && z >= 0) if (FLT_MAX - z < abs(t.z)) throw OverFlow();
		temp.z = z - t.z;
		temp.GetC();
		return temp;
	} catch (OverFlow &e) { e.ErrorPrint(); return t; }
}
Vector Vector::operator-=(Vector t) {
	try {
		if (t.x >= 0 && x <= 0)	if (FLT_MAX - t.x < abs(x)) throw OverFlow();
		else if (t.x <= 0 && x >= 0) if (FLT_MAX - x < abs(t.x)) throw OverFlow();
		x = x - t.x;

		if (t.y >= 0 && y <= 0) if (FLT_MAX - t.y < abs(y)) throw OverFlow();
		else if (t.y <= 0 && y >= 0) if (FLT_MAX - y < abs(t.y)) throw OverFlow();
		y = y - t.y;

		if (t.z >= 0 && z <= 0)	if (FLT_MAX - t.z < abs(z)) throw OverFlow();
		else if (t.z <= 0 && z >= 0) if (FLT_MAX - z < abs(t.z)) throw OverFlow();
		z = z - t.z;
		return *this;
	} catch (OverFlow &e) { e.ErrorPrint(); return t; }
}
Vector Vector::operator*=(Vector t) {
	try {
		if (t.x == 0 || x == 0)	x = 0;
		else if (abs(FLT_MAX / t.x) < abs(x)) throw OverFlow();
		else x = x * t.x;

		if (t.y == 0 || y == 0)	y = 0;
		else if (abs(FLT_MAX / t.y) < abs(y)) throw OverFlow();
		else y = y * t.y;

		if (t.z == 0 || z == 0)	z = 0;
		else if (abs(FLT_MAX / t.z) < abs(z)) throw OverFlow();
		else z = z * t.z;
		return *this;
	} catch (OverFlow &e) { e.ErrorPrint(); return t; }
}
Vector Vector::operator*=(float t) {
	try {
		if (t == 0) { x = 0; y = 0; z = 0;  return *this; }
		if (abs(FLT_MAX / t) < abs(x)) throw OverFlow();
		else x = x * t;

		if (abs(FLT_MAX / t) < abs(y)) throw OverFlow();
		else y = y * t;

		if (abs(FLT_MAX / t) < abs(z)) throw OverFlow();
		else z = z * t;
		return *this;
	} catch (OverFlow &e) { e.ErrorPrint(); }
}

Vector Vector::operator-() {
	Vector temp;
	temp.x = -x;
	temp.y = -y;
	temp.z = -z;
	return temp;
}
bool Vector::operator==(Vector t) { if (t.x == x&&t.y == y&&t.z == z) return true;	else return false; }
bool Vector::operator!=(Vector t) { if (y*t.x / x == t.y&&z*t.x / x == t.z) return true;	else return false; }
Vector Vector::operator*(Vector t) {
	Vector temp;
	try {
		if (t.x == 0 || x == 0)	temp.x = 0;
		else if (abs(FLT_MAX/t.x) < abs(x)) throw OverFlow();
		else temp.x = x * t.x;

		if (t.y == 0 || y == 0)	temp.y = 0;
		else if (abs(FLT_MAX / t.y) < abs(y)) throw OverFlow();
		else temp.y = y * t.y;

		if (t.z == 0 || z == 0)	temp.z = 0;
		else if (abs(FLT_MAX / t.z) < abs(z)) throw OverFlow();
		else temp.z = z * t.z;

		temp.GetC();
		return temp;
	} catch (OverFlow &e) { e.ErrorPrint(); return t; }

}
Vector Vector::operator*(float t) {
	Vector temp;
	try {
		if (t == 0) { temp.GetC();  return temp; }
		if (x == 0)	temp.x = 0;
		else if (abs(FLT_MAX / t) < abs(x)) throw OverFlow();
		else temp.x = x * t;

		if (y == 0)	temp.y = 0;
		else if (abs(FLT_MAX / t) < abs(y)) throw OverFlow();
		else temp.y = y * t;

		if ( z == 0) temp.z = 0;
		else if (abs(FLT_MAX / t) < abs(z)) throw OverFlow();
		else temp.z = z * t;

		temp.GetC();
		return temp;
	} catch (OverFlow &e) { e.ErrorPrint(); return t; }
}
Vector Vector::operator=(Vector t) {
	x = t.x;
	y = t.y;
	z = t.z;
	return *this;
}
void Vector::GetC() { cout << x << ", " << y << ", " << z << endl; }
