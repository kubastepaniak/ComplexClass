#pragma once

class Complex {
private:
	double re, im;
public:
	Complex(double re = 0, double im = 0);
	Complex(const Complex& a);
	~Complex();
	double getReal() const;
	double getImag() const;
	double Amp();
	double Phase();
	Complex operator+(const Complex& b);
	Complex operator-(const Complex& b);
	Complex operator*(const Complex& b);
	Complex operator/(const Complex& b);
	Complex& operator+=(const Complex & b);
	Complex& operator-=(const Complex & b);
	Complex& operator*=(const Complex & b);
	Complex& operator/=(const Complex & b);
	friend Complex operator+(double a, Complex & b);
	friend Complex operator-(double a, Complex & b);
	friend Complex operator*(double a, Complex & b);
	friend Complex operator/(double a, Complex & b);
	bool operator==(Complex & b);
	friend std::ostream& operator<<(std::ostream& out, Complex a);
};
