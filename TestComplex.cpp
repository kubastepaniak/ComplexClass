#include <iostream>
#include <cstdlib>
#include "Complex.h"
using namespace std;

int main()
{
	Complex a(5, 10);
	Complex b(3, -7);
	Complex c;

	cout << "a: " << a << endl;

	cout << "amplitude of a: " << a.Amp() << endl;

	cout << "phase of a: " << a.Phase() << " rad" << endl;

	c = a + b;
	cout << "addition: " << c << endl;

	c = a - b;
	cout << "subtraction: " << c << endl;

	c = a * b;
	cout << "multiplication: " << c << endl;

	c = a / b;
	cout << "division: " << c << endl;

	a += b;
	cout << "new a (a += b): " << a << endl;

	return 0;
}
