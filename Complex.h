#pragma once

class Complex {
private:
	double re, im;
public:
	Complex();
	~Complex();
	Complex(double re, double im);
	Complex operator+(Complex & a, Complex & b);
	Complex operator-(Complex & a, Complex & b);
	Complex operator*(Complex & a, Complex & b);
	Complex operator/(Complex & a, Complex & b);
	Complex operator+=(Complex & a, Complex & b);
	Complex operator-=(Complex & a, Complex & b);
	Complex operator*=(Complex & a, Complex & b);
	Complex operator/=(Complex & a, Complex & b);
	bool operator==(Complex & a, Complex & b);
	double Re();
	double Im();
	double Amp();
	double Phase();
}
