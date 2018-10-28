#pragma once

class Complex {
private:
	double re, im;
public:
	Complex();
	~Complex();
	Complex(double re, double im);
	double getReal();
	double getImag();
	double Amp();
	double Phase();
	Complex operator+(Complex & b);
	Complex operator-(Complex & b);
	Complex operator*(Complex & b);
	Complex operator/(Complex & b);
	Complex& operator+=(Complex & b);
	Complex& operator-=(Complex & b);
	Complex& operator*=(Complex & b);
	Complex& operator/=(Complex & b);
	bool operator==(Complex & b);
};

std::ostream& operator<<(std::ostream& out, Complex a);
Complex operator+(int a, Complex & b);
Complex operator-(int a, Complex & b);
Complex operator*(int a, Complex & b);
Complex operator/(int a, Complex & b);
Complex operator+(Complex & b, int a);
Complex operator-(Complex & b, int a);
Complex operator*(Complex & b, int a);
Complex operator/(Complex & b, int a);