#include <iostream>
#include <complex>
#include <cmath>
#include "Header.h"
using namespace std;

void main()
{
	setlocale(LC_ALL, "");
	double re, im;
	cout << "Введите реальную и мнимую часть комплексного числа" << endl;
	cin >> re >> im;

	Complex z(im, re);
	complex<double> z1(im, re);

	cout << userf(z) << endl << inbuildf(z1) << endl;
	//cout <<"////"<<imag(inbuildf(z1)) << endl;
	table();
	cout << "Введите реальную и мнимую часть комплексного числа для проверки работы" << endl;
	cin >> re >> im;
	sravn(re, im);

}