#include "Pixel.hpp"
#include <iostream>
using namespace std;

Pixel::~Pixel() {

}
const unsigned int& Pixel::operator[](const char* input) const {
	try {
		if (input == "red")
			return this->red;
		else if (input == "green")
			return this->green;
		else if (input == "blue")
			return this->blue;
		else
		{
			throw InputOutOfBoundsExeception("Error Pixel class overloaded offset operator - lines 7-18 calling ", input);
		}
	}
	catch (InputOutOfBoundsExeception& e) {
		throw e;
	}

}

ofstream& operator<<(ofstream& out, const Pixel& p1) {
	try {
		out << p1["red"] << " " << p1["green"] << " " << p1["blue"];
		return out;
	}
	catch (Pixel::InputOutOfBoundsExeception e) {
		throw e;
	}
}

Pixel::Pixel() :red(0), green(0), blue(0)
{
}
Pixel::Pixel(const Pixel& p1) :red(p1.red), green(p1.green), blue(p1.blue)
{
}
Pixel::Pixel(unsigned int red, unsigned int green, unsigned int blue)
	:red(red), green(green), blue(blue)
{
}
Pixel::InputOutOfBoundsExeception::InputOutOfBoundsExeception(const char* message, const char* index)
	:errorMessage(message), offendingIndex(index)
{

}
const char* Pixel::InputOutOfBoundsExeception::returnError() {
	return this->errorMessage;
}
const char* Pixel::InputOutOfBoundsExeception::returnOffendingIndex() {
	return this->offendingIndex;
}