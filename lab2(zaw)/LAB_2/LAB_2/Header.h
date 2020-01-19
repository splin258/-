#pragma once
#include <iostream>
#include <complex>
#include <cmath>

using namespace std;
complex <double> inbuildf(complex <double>);
class Complex
{
public: float re, im;
public:
	Complex() { re = im = 0; }
	Complex(float a) { re = a, im = 0; }
	Complex(float a, float b) { re = a, im = b; }

	/*float real() { return this->re; }
	float imag() { return this->im; }*/

	friend Complex operator+(Complex z1, Complex z2);
	friend Complex operator-(Complex z1, Complex z2);
	friend Complex operator*(Complex z1, double z2);
	friend Complex operator/(Complex z1, Complex z2);
	friend Complex sin(Complex z);
	friend ostream& operator<<(ostream& s, Complex d);
	friend istream& operator>>(istream& s, Complex d);
	friend bool operator== (const Complex z1, const complex <float> z3);
	friend bool operator!= (const Complex z1, const complex <float> z3);
};

ostream& operator<<(ostream& s, Complex d)
{
	s << "(" << d.re << "," << d.im << ")";
	return s;
}

istream& operator>>(istream& s, Complex d)
{
	s >> d.re >> d.im;
	return s;
}

Complex operator+(Complex z1, Complex z2)
{
	return Complex(z1.re + z2.re, z1.im + z2.im);
}
Complex operator-(Complex z1, Complex z2)
{
	return Complex(z1.re - z2.re, z1.im - z2.im);
}
Complex operator/(Complex z1, Complex z2)
{
	return Complex((z1.re * z2.re + z1.im * z2.im) / (z2.re * z2.re + z2.im * z2.im), (z1.im * z2.re - z1.re * z2.im) / (z2.re * z2.re + z2.im * z2.im));
}

Complex operator*(Complex z1, double z2)
{
	return Complex(z1.re * z2, z1.im * z2);
}
bool operator== (const Complex z1, const complex <float>  z3)
{
	float k = round((z3.real() * 1000)) / 1000;
	float m = round((z3.imag() * 1000)) / 1000;
	float a = round((z1.re * 1000)) / 1000;
	float b = round((z1.im * 1000)) / 1000;
	return (a == k &&
		b == m);
}

bool operator!= (const Complex z1, const complex <float> z3)
{
	return !(z1 == z3);
}

Complex sin(Complex z)
{
	return Complex(sin(z.re) * cosh(z.im), cos(z.re) * sinh(z.im));
}

Complex userf(Complex z)
{
	Complex Z(0, 1);
	return z * 2. + sin(z - Z);
}

complex <double> inbuildf(complex <double> z)
{
	complex <double> Z(0, 1);
	return  2.*z  + sin(z - Z);
}

void table()
{
	double a, b;
	for (double i = -1; i <= 1; i = i + 0.5)
	{
		for (double j = -1; j <= 1; j = j + 0.5)
		{
			a = i;
			b = j;
			Complex z(a, b);
			complex <double> z1(a, b);

			cout << a << "\t" << b << "\t" << userf(z) << "\t" << inbuildf(z1) << endl;
		}
	}
}
void sravn(double re, double im)
{
	Complex z1(im, re);
	complex<double> z2(im, re);
	complex<double> z3 = inbuildf(z2);

	if (userf(z1) == z3)
	{
		cout << userf(z1) << "==" << inbuildf(z2) << endl;
	} else {
		cout << userf(z1) << "!=" << inbuildf(z2) << endl;
	}
}