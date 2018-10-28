#include <iostream>
#include <cmath>
#include "Complex.h"

Complex::Complex()
{
	re = 0;
	im = 0;
}

Complex::~Complex() {}

Complex::Complex(double re, double im)
{
	this->re = re;
	this->im = im;
}

double Complex::getReal() {	return re; }

double Complex::getImag() {	return im; }

double Complex::Amp()
{
	return sqrt(pow(re, 2) + pow(im, 2));
}

double Complex::Phase()
{
	return atan(im / re);
}

Complex Complex::operator+(Complex & b)
{
	return (Complex(re + b.getReal(), im + b.getImag()));
}

Complex Complex::operator-(Complex & b)
{
	return (Complex(re - b.getReal(), im - b.getImag()));
}

Complex Complex::operator*(Complex & b)
{
	return (Complex(re * b.getReal() + (-1)*(im)*(b.getImag()), 
					im * b.getReal() + re * b.getImag()));
}

Complex Complex::operator/(Complex & b)
{
	return (Complex((re * b.getReal() + im * b.getImag()) / 
					(pow(b.getReal(), 2) + pow(b.getImag(), 2)),
					(im * b.getReal() - re * b.getImag()) / 
					(pow(b.getReal(), 2) + pow(b.getImag(), 2))));
}

Complex& Complex::operator+=(Complex & b)
{
	re += b.getReal();
	im += b.getImag();
	return this;
}

Complex& Complex::operator-=(Complex & b)
{
	re -= b.getReal();
	im -= b.getImag();
	return this;
}

Complex& Complex::operator*=(Complex & b)
{
	double oldReal = re;
	double oldImag = im;
	re = oldReal * b.getReal() + (-1)*oldImag*(b.getImag());
	im = oldImag * b.getReal() + oldReal * b.getImag();
	return this;
}

Complex& Complex::operator/=(Complex & b)
{
	double oldReal = re;
	double oldImag = im;
	re = (oldReal * b.getReal() + oldImag * b.getImag()) / 
		  (pow(b.getReal(), 2) + pow(b.getImag(), 2));
	im = (oldImag * b.getReal() - oldReal * b.getImag()) / 
		  (pow(b.getReal(), 2) + pow(b.getImag(), 2));
	return this;
}

bool Complex::operator==(Complex & b)
{
	if(re == b.getReal() && im == b.getImag()) return true;
	return false;
}

std::ostream& operator<<(std::ostream& out, Complex a)
{
	out << "(" << a.getReal();
	if(a.getImag() > 0) out << " + " << a.getImag() << "i";
	else if(a.getImag() < 0) out << " - " << a.getImag() * (-1) << "i";
	out << ")";
	return out;
}

Complex operator+(int a, Complex & b)
{
	return (Complex(a + b.getReal(), b.getImag()));
}

Complex operator-(int a, Complex & b)
{
	return (Complex(a - b.getReal(), -b.getImag()));
}

Complex operator*(int a, Complex & b)
{
	return (Complex(a * b.getReal(), a * b.getImag()));
}

Complex operator/(int a, Complex & b)
{
	return (Complex(a * b.getReal() / (pow(b.getImag(), 2) + pow(b.getReal(), 2)),
					a * b.getImag() / (pow(b.getImag(), 2) + pow(b.getReal(), 2))));
}

Complex operator+(Complex & b, int a)
{
	return (Complex(b.getReal() + a, b.getImag()));
}

Complex operator-(Complex & b, int a)
{
	return (Complex(b.getReal() - a, b.getImag()));
}

Complex operator*(Complex & b, int a)
{
	return (Complex(b.getReal() * a, b.getImag() * a));
}

Complex operator/(Complex & b, int a)
{
	return (Complex(b.getReal() / a, b.getImag() / a));
}