#pragma once
#include "Complex.hpp"
using namespace std;


Complex::~Complex() {
}
Complex::Complex() :real(0.0), imag(0.0)
{
}
Complex::Complex(const Complex& C) :real(C.real), imag(C.imag)
{
}
Complex::Complex(double d) :real(d), imag(0.0)
{
}
Complex::Complex(double R, double Im) :real(R), imag(Im)
{
}
double& Complex::operator[](const char* input) {
	try {
		if (input == "real")
			return real;
		else if (input == "imag")
			return imag;
		else
			throw Complex::InputOutOfBoundsExeception("> Complex Class:Error Offset operator has invalid index, not real or imaginary, line 18-23", input);
	}
	catch (Complex::InputOutOfBoundsExeception& ee) {
		throw ee;
	}
}

const Complex operator*(const Complex& a, const Complex& c) {
	try {
		Complex temp;
		temp["real"] = a.real * c.real - a.imag * c.imag;
		temp["imag"] = a.real * c.imag + a.imag * c.real;;
		return temp;
	}
	catch (Complex::InputOutOfBoundsExeception& ee) {
		cout << ee.returnError() << " -- " << ee.returnOffendingIndex() << endl;
		return a.real;
	}
}
const Complex operator/(const Complex& a, const Complex& c) {
	try {
		double denominator = c.real * c.real + c.imag * c.imag;
		Complex temp;
		temp["real"] = (a.real * c.real + a.imag * c.imag) / denominator;
		temp["imag"] = (a.imag * c.real - a.real * c.imag) / denominator;
		return temp;
	}
	catch (Complex::InputOutOfBoundsExeception& ee) {
		cout << ee.returnError() << " -- " << ee.returnOffendingIndex() << endl;
		return a.real;
	}
}
const Complex operator+(const Complex& a, const Complex& c) {
	try {
		Complex temp;
		temp["real"] = (a.real + c.real);
		temp["imag"] = (a.imag + c.imag);
		return temp;
	}
	catch (Complex::InputOutOfBoundsExeception& ee) {
		cout << ee.returnError() << " -- " << ee.returnOffendingIndex() << endl;
		return a.real;
	}
}
const Complex operator-(const Complex& a, const Complex& c) {
	try {
		Complex temp;
		temp["real"] = (a.real - c.real);
		temp["imag"] = (a.imag - c.imag);
		return temp;
	}
	catch (Complex::InputOutOfBoundsExeception& ee) {
		cout << ee.returnError() << " -- " << ee.returnOffendingIndex() << endl;
		return a.real;
	}
}
Complex::InputOutOfBoundsExeception::InputOutOfBoundsExeception(const char* message, const char* index) :errorMessage(message), offendingIndex(index)
{
}
const char* Complex::InputOutOfBoundsExeception::returnError() {
	return errorMessage;
}
const char* Complex::InputOutOfBoundsExeception::returnOffendingIndex() {
	return offendingIndex;
}
double getMagnitude(const Complex& a) {
	return sqrt(a.real * a.real + a.imag * a.imag);
}