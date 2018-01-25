#include <iostream>
#include <string>
#include "Source.h"
#include "Error.h"
#include <cfloat>
#include <cctype>
using namespace std;
int main()
{
	string s;
	system("color F0");
	cout << "Lipska Vlada, step C, class:Vaector, operations: +,-,*,-,*a, ==,+=,-=,*=" << endl;
	Vector v1(0, 0, 0), v2(0, 0, 0);
	for (int i = 0; i < 6; ) {
		try {
			cout << "Put in value" << endl;
			cin >> s;
			for each (char c in s.substr(1,s.length()-1))	if (!(isdigit(c) || c == '.')) throw StrangeSymbols();
			if (!(isdigit(s[0]) || s[0] == '-')) throw StrangeSymbols();
			if (s.find_first_of('.') != s.find_last_of('.')) throw Points();
			switch (i) {
			case 0: v1.SetX(stof(s)); break;
			case 1: v1.SetY(stof(s)); break;
			case 2: v1.SetZ(stof(s)); break;
			case 3: v2.SetX(stof(s)); break;
			case 4: v2.SetY(stof(s)); break;
			default: v2.SetZ(stof(s)); break;
			} i++;
		}
		catch (StrangeSymbols &e) { e.ErrorPrint(); i = 6; }
		catch (Points &e) { e.ErrorPrint(); i = 6; }
		catch (out_of_range) { cout << "Overflow!"; i = 6; }
	}

	cout << "v1: "; v1.GetC();
	cout << "v2: "; v2.GetC();

	cout << "c=v1+v2" << endl;
	Vector c = v1 + v2;
	cout << "v1+=v2" << endl;
	v1 += v2;
	cout << "v1: ";
	v1.GetC();
	cout << "f=v1-v2" << endl;
	Vector f = v1 - v2;
	cout << "v1-=v2" << endl;
	v1 -= v2;
	cout << "v1: ";
	v1.GetC();
	cout << "g=v1*v2" << endl;
	Vector g = v1 * v2;
	cout << "v1*=v2" << endl;
	v1 *= v2;
	v1.GetC();
	cout << "k=v1*6" << endl;
	Vector k = v1 * 6;
	cout << "v1*=6" << endl;
	v1 *= 6;
	v1.GetC();
	system("pause");
}