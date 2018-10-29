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

double Complex::getReal() const {	return re; }

double Complex::getImag() const {	return im; }

double Complex::Amp()
{
	return sqrt(pow(re, 2) + pow(im, 2));
}

double Complex::Phase()
{
	return atan(im / re);
}

Complex Complex::operator+(const Complex& b)
{
	return (Complex(re + b.re, im + b.im));
}

Complex Complex::operator-(const Complex & b)
{
	return (Complex(re - b.re, im - b.im));
}

Complex Complex::operator*(const Complex & b)
{
	return (Complex(re * b.re + (-1)*(im)*(b.im), 
					im * b.re + re * b.im));
}

Complex Complex::operator/(const Complex & b)
{
	return (Complex((re * b.re + im * b.im) / 
					(pow(b.re, 2) + pow(b.im, 2)),
					(im * b.re - re * b.im) / 
					(pow(b.re, 2) + pow(b.im, 2))));
}

Complex& Complex::operator+=(const Complex & b)
{
	re += b.re;
	im += b.im;
	return *this;
}

Complex& Complex::operator-=(const Complex & b)
{
	re -= b.re;
	im -= b.im;
	return *this;
}

Complex& Complex::operator*=(const Complex & b)
{
	double oldReal = re;
	double oldImag = im;
	re = oldReal * b.re + (-1)*oldImag*(b.im);
	im = oldImag * b.re + oldReal * b.im;
	return *this;
}

Complex& Complex::operator/=(const Complex & b)
{
	double oldReal = re;
	double oldImag = im;
	re = (oldReal * b.re + oldImag * b.im) / 
		  (pow(b.re, 2) + pow(b.im, 2));
	im = (oldImag * b.re - oldReal * b.im) / 
		  (pow(b.re, 2) + pow(b.im, 2));
	return *this;
}

bool Complex::operator==(Complex & b)
{
	if(re == b.re && im == b.im) return true;
	return false;
}

Complex operator+(double a, Complex & b)
{
	return Complex(a + b.getReal(), b.getImag());
}

Complex operator-(double a, Complex & b)
{
	return Complex(a - b.getReal(), -b.getImag());
}

Complex operator*(double a, Complex & b)
{
	return Complex(a * b.getReal(), a * b.getImag());
}

Complex operator/(double a, Complex & b)
{
	return Complex(a * b.getReal() / (pow(b.getReal(), 2) + pow(b.getImag(), 2)),
				   a * b.getImag() / (pow(b.getReal(), 2) + pow(b.getImag(), 2)));
}

std::ostream& operator<<(std::ostream& out, Complex a)
{
	out << a.re;
	if(a.im > 0) out << " + " << a.im << "i";
	else if(a.im < 0) out << " - " << a.im * (-1) << "i";
	return out;
}