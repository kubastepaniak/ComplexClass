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
	void operator+=(Complex & b);
	void operator-=(Complex & b);
	void operator*=(Complex & b);
	void operator/=(Complex & b);
//	bool operator==(Complex & a, Complex & b);
};

std::ostream& operator<<(std::ostream& out, Complex a);