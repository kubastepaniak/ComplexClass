#include <iostream>
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
					(b.getReal() * b.getReal() + b.getImag() * b.getImag()),
					(im * b.getReal() - re * b.getImag()) / 
					(b.getReal() * b.getReal() + b.getImag() * b.getImag())));
}

//double Amp();
//double Phase();
//Complex operator+=(Complex & a, Complex & b);
//Complex operator-=(Complex & a, Complex & b);
//Complex operator*=(Complex & a, Complex & b);
//Complex operator/=(Complex & a, Complex & b);
//bool operator==(Complex & a, Complex & b);
