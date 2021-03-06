// CS60 HW2.cpp : Defines the entry point for the console application.
//

//
//  main.cpp
//  Ex3-Complex
//

// In this example we will create a complex number class. The purpose of this
// example is to become familiar with operator overloading, and should not be
// used in practice as C++ already has a complex number class.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class Complex
{
public:
	Complex(double real, double imag);

	Complex();

	//Assignment operators
	void operator +=(Complex rhs);
	void operator -=(Complex rhs);
	void operator *=(Complex rhs);
	void operator /=(Complex rhs);

	//Unary operators
	void operator +();
	void operator -();

	//Getter Declarations
	double get_real();
	double get_imag();

private:
	double real_;
	double imag_;
};

//Operator Overloads
ostream& operator <<(ostream& os, Complex z);  
Complex operator +(Complex lhs, Complex rhs);  
Complex operator *(Complex lhs, Complex rhs);  
Complex operator -(Complex lhs, Complex rhs);
Complex operator /(Complex lhs, Complex rhs);
bool operator ==(Complex lhs, Complex rhs);
bool operator !=(Complex lhs, Complex rhs);

											 
Complex::Complex(double real, double imag) {
	real_ = real;
	imag_ = imag;
}

Complex::Complex() {
	real_ = 0;
	imag_ = 0;
}

//Getter Functions
double Complex::get_real() { 
	return real_; 
}
double Complex::get_imag() { 
	return imag_; 
}

ostream& operator<<(ostream& os, Complex z) {
	os << z.get_real() << " + " << z.get_imag() << "i";
	return os;
}

Complex operator +(Complex lhs, Complex rhs) {
	return Complex(lhs.get_real() + rhs.get_real(),
		lhs.get_imag() + rhs.get_imag());
}

Complex operator *(Complex lhs, Complex rhs) {
	return Complex(
		lhs.get_real() * rhs.get_real() - lhs.get_imag() * rhs.get_imag(),
		lhs.get_imag() * rhs.get_real() + lhs.get_real() * rhs.get_imag());
}

Complex operator -(Complex lhs, Complex rhs) {
	return Complex( lhs.get_real() - rhs.get_real(), lhs.get_imag() - rhs.get_imag() );
}

Complex operator /(Complex lhs, Complex rhs) {
	return Complex( ( (lhs.get_real() * rhs.get_real() )+(lhs.get_imag() * rhs.get_imag()) ) / ((rhs.get_real() *rhs.get_real()) +  (rhs.get_imag() * rhs.get_imag())),
		((lhs.get_imag() * rhs.get_real()) - (lhs.get_real() * rhs.get_imag())) / ((rhs.get_real() *rhs.get_real()) + (rhs.get_imag() * rhs.get_imag())));
}

bool operator ==(Complex lhs, Complex rhs) {
	return(lhs.get_real() == rhs.get_real() && lhs.get_imag() == rhs.get_imag());
}

bool operator !=(Complex lhs, Complex rhs) {
	return(lhs.get_real() != rhs.get_real() || lhs.get_imag() != rhs.get_imag());
}

void Complex::operator +=(Complex rhs) {
	real_ += rhs.get_real();
	imag_ += rhs.get_imag();
}
void Complex::operator -=(Complex rhs) {
	real_ -= rhs.get_real();
	imag_ -= rhs.get_imag();
}
void Complex::operator *=(Complex rhs) {
	real_ = real_ * rhs.get_real() - imag_ * rhs.get_imag();
	imag_ = imag_ * rhs.get_real() + real_ * rhs.get_imag();
}
void Complex::operator /=(Complex rhs) {
	real_ = (((real_ * rhs.get_real()) + (imag_ * rhs.get_imag())) / ((rhs.get_real() *rhs.get_real()) + (rhs.get_imag() * rhs.get_imag())));
	imag_ = ((imag_ * rhs.get_real()) - (real_ * rhs.get_imag())) / ((rhs.get_real() *rhs.get_real()) + (rhs.get_imag() * rhs.get_imag()));
}

void Complex::operator +() {
	imag_ = imag_;
	real_ = real_;
}

void Complex::operator -() {
	imag_ = 0 - imag_;
	real_ = 0 - real_;
}

int main() {
	Complex z(3, 2);
	/*z. operator -();*/
	Complex w(2, 2);
	cout << "z = " << z << endl
		<< "w = " << w << endl
		<< "z + w = " << z + w << endl
		<< "z * w = " << z * w << endl
		<< "z - w = " << z - w << endl
		<< "z / w = " << z / w << endl
		<< "z == w = " << (z == w) << endl
		<< "z != w = " << (z != w) << endl
		<< "z + w == w + z " << (z + w == w + z) << endl
		<< "z + w != w + z " << (z + w != w + z) << endl;

	Complex i(0, 1);
	cout << "i = " << i << endl << "i^2 = " << i * i << endl;

	system("pause");
	return 0;
}