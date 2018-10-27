#include <iostream>
#include <cstdlib>
#include "Complex.h"
using namespace std;

int main()
{
	Complex a(5, 10);
	Complex b(3, -7);
	Complex c;

	//create cout display function
	//cout << "a: " << 

	c = a + b;
	cout << "addition: " << c.getReal() << ", " << c.getImag() << endl;

	c = a - b;
	cout << "subtraction: " << c.getReal() << ", " << c.getImag() << endl;

	c = a * b;
	cout << "multiplication: " << c.getReal() << ", " << c.getImag() << endl;

	c = a / b;
	cout << "division: " << c.getReal() << ", " << c.getImag() << endl;

	return 0;
}
