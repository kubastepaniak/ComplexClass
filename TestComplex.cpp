#include <iostream>
#include <cstdlib>
#include "Complex.h"
using namespace std;

int main()
{
	Complex a(5, 10);
	Complex b(3, -7);
	Complex c;

	cout << "a: " << a << endl << endl;

	cout << "amplitude of a: " << a.Amp() << endl << endl;

	cout << "phase of a: " << a.Phase() << " rad" << endl << endl;

	c = a + b;
	cout << "addition: " << c << endl << endl;

	c = a - b;
	cout << "subtraction: " << c << endl << endl;

	c = a * b;
	cout << "multiplication: " << c << endl << endl;

	c = a / b;
	cout << "division: " << c << endl << endl;

	a += b;
	cout << "new a (a += b): " << a << endl << endl;

	bool l = a == b;
	cout << "a == b?" << endl << a << " == " << b << endl << l << endl;

	cout << 7 + a;
	/*
	a += b += c
	a *= b *= c
	7 + a
	b * 5
	5 * b
	*/
	return 0;
}
