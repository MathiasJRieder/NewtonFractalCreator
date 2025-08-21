#pragma once
#include <iostream>
#include "Pixel.hpp"
#include "Complex.hpp"
using namespace std;
class Fractal {
private:
	unsigned int cols;
	Pixel** grid; //Needs pixel class
	unsigned int maxIter;
	unsigned int rows;
	//Private data members

	Pixel determinePixelColor(Complex); //Needs pixel and complex classes
	void makeNewtonFractal();
	//Private member functions
	public
	Fractal();
	Fractal(unsigned int, unsigned int);
	//Constructors

	~Fractal();
	//Destructor

	Fractal(const Fractal&);
	Fractal(Fractal&&);
	//Copy and move constructors

	const Fractal& operator=(const Fractal&);
	Fractal& operator=(Fractal&&);
	//Copy and move assignment overloaded operators

	friend void saveToPPM(const Fractal&, const char*);
	
};