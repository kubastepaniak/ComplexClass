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

void Complex::operator+=(Complex & b)
{
	re += b.getReal();
	im += b.getImag();
}

void Complex::operator-=(Complex & b)
{
	re -= b.getReal();
	im -= b.getImag();
}

void Complex::operator*=(Complex & b)
{
	double oldReal = re;
	double oldImag = im;
	re = oldReal * b.getReal() + (-1)*oldImag*(b.getImag());
	im = oldImag * b.getReal() + oldReal * b.getImag();
}

void Complex::operator/=(Complex & b)
{
	double oldReal = re;
	double oldImag = im;
	re = (oldReal * b.getReal() + oldImag * b.getImag()) / 
		  (pow(b.getReal(), 2) + pow(b.getImag(), 2));
	im = (oldImag * b.getReal() - oldReal * b.getImag()) / 
		  (pow(b.getReal(), 2) + pow(b.getImag(), 2));

}
//bool operator==(Complex & a, Complex & b);

std::ostream& operator<<(std::ostream& out, Complex a)
{
	out << "(" << a.getReal();
	if(a.getImag() > 0) out << " + " << a.getImag() << "i";
	else if(a.getImag() < 0) out << " - " << a.getImag() * (-1) << "i";
	out << ")";
	return out;
}