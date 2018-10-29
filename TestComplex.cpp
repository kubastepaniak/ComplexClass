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
	cout << "a == b?" << endl << a << " == " << b << endl << l << endl << endl;

	a = Complex(2, 2);
	b = Complex(3, 3);
	c = Complex(4, 4);
	a += b += c;
	cout << "a += b += c :" << endl << "new a: " << a << endl << "new b: " << b << endl;

	a = Complex(2, 2);
	b = Complex(3, 3);
	c = Complex(4, 4);
	a *= b *= c;
	cout << "a *= b *= c :" << endl << "new a: " << a << endl << "new b: " << b << endl << endl;

	a = Complex(2, 2);
	b = Complex(3, 3);
	cout << "a: " << a << "\tb: " << b << endl;

	cout << "7 + a: " << 7 + a << endl;

	cout << "b * 5: " << b * 5 << endl;

	cout << "5 * b: " << 5 * b << endl;
	
	return 0;
}
