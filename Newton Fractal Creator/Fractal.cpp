#include <iostream>
#include <fstream>
#include "Pixel.hpp"
#include "Complex.hpp"
#include "Fractal.hpp"
using namespace std;

Pixel Fractal::determinePixelColor(Complex) {

} 
void Fractal::makeNewtonFractal() {
	cout << "> Now creating the Newton Fractal..." << endl;

}

Fractal::Fractal(): rows(0), cols(0), maxIter(30) {
	cout << "> Default constructor called..." << endl;
	for (int i = 0; i < rows; i++) {
		this->grid[i] = new Pixel[this->cols];
	}
}
Fractal::Fractal(unsigned int r, unsigned int c): rows(r), cols(c), maxIter(30) {
	cout << "> Two-arg constructor called..." << endl;
	for (int i = 0; i < rows; i++) {
		this->grid[i] = new Pixel[this->cols];
	}
}
//Constructors

Fractal::~Fractal() {
	cout << "> Destructor called ..." << endl;
	for (int i = 0; i < rows; i++){
		delete[] grid[i];
	}
	delete[] grid;
}
//Destructor

Fractal::Fractal(const Fractal& f) {
	cout << "> Copy constructor called..." << endl;
	this->cols = f.cols;
	this->rows = f.rows;

	this->maxIter = f.maxIter;
	grid = new Pixel* [rows];

	for (int i = 0; i < rows; i++){
		this->grid[i] = new Pixel[this->cols];
	}
	//Allocate the memory for two-dimensional array

	for (int row = 0; row < rows; ++row){
		for (int col = 0; col < cols; ++col) {
			this->grid[row][col] = f.grid[row][col];

		}

	}
	//Insert the pixel details
}
Fractal::Fractal(Fractal&& f) {
	cout << "> Move constructor called..." << endl;
	this->rows = f.rows;
	this->cols = f.cols;
	this->maxIter = f.maxIter;
	this->grid = f.grid;
	//Move data
	f.rows = 0;
	f.cols = 0;
	f.maxIter = 0;
	f.grid = nullptr;
	//Unassign data
}
//Copy and move constructors

const Fractal& Fractal::operator=(const Fractal& f) {
	cout << "> Copy assignment operator called..." << endl;

	if (this != &f) {
		if (this->grid != nullptr) {
			for (int i = 0; i < rows; i++) {
				delete[] grid[i];
			}
			delete[] grid;
		}
		this->rows = f.rows;
		this->cols = f.cols;
		this->maxIter = f.maxIter;
		this->grid = f.grid;
		for (int row = 0; row < rows; ++row){
			for (int col = 0; col < cols; ++col) {
				this->grid[row][col] = f.grid[row][col];
			}
		}

	}

	return *this;
}
Fractal& Fractal::operator=(Fractal&& f) {
	cout << "> Move assignment operator called..." << endl;
	if (this != &f) {
		swap(this->cols, f.cols);
		swap(this->grid, f.grid);
		swap(this->maxIter, f.maxIter);
		swap(this->rows, f.rows);
	}
}
//Copy and move assignment overloaded operators

void saveToPPM(const Fractal& f, const char* fn) {
	cout << "> Saving Fractal object to PPM file..." << endl;
}
//Friend function