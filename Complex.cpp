#include <iostream>
#include <cmath>
#include "Complex.h"

Complex::Complex(double re, double im)
{
	this->re = re;
	this->im = im;
}

Complex::Complex(const Complex& a)
{
	re = a.getReal();
	im = a.getImag();
}

Complex::~Complex() {}

double Complex::getReal() const { return re; }

double Complex::getImag() const { return im; }

double Complex::Amp()
{
	return sqrt(pow(re, 2) + pow(im, 2));
}

double Complex::Phase()
{
	return atan(im / re);
}

Complex& Complex::operator+=(const Complex& b)
{
	*this = *this + b;
	return *this;
}

Complex& Complex::operator-=(const Complex& b)
{
	*this = *this - b;
	return *this;
}

Complex& Complex::operator*=(const Complex& b)
{
	*this = *this * b;
	return *this;
}

Complex& Complex::operator/=(const Complex& b)
{
	*this = *this / b;
	return *this;
}

bool Complex::operator==(const Complex& b)
{
	if(re == b.re && im == b.im) return true;
	return false;
}

Complex operator+(const Complex& a, const Complex& b)
{
	return Complex(a.re + b.re, a.im + b.im);
}

Complex operator-(const Complex& a, const Complex& b)
{
	return Complex(a.re - b.re, a.im - b.im);
}

Complex operator*(const Complex& a, const Complex& b)
{
	return Complex(a.re * b.re + (-1) * a.im * b.im, 
				   a.im * b.re + a.re * b.im);
}

Complex operator/(const Complex& a, const Complex& b)
{
	return Complex((a.re * b.re + a.im * b.im) / 
				   (pow(b.re, 2) + pow(b.im, 2)),
				   (a.im * b.re - a.re * b.im) / 
				   (pow(b.re, 2) + pow(b.im, 2)));
}

std::ostream& operator<<(std::ostream& out, const Complex& a)
{
	out << a.re;
	if(a.im > 0) out << " + " << a.im << "i";
	else if(a.im < 0) out << " - " << a.im * (-1) << "i";
	return out;
}