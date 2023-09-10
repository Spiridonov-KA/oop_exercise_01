#include <iostream>
#include <cmath>

class Complex {
private:
	double re = 0, im = 0;
public:
	Complex();
	Complex(double);
	Complex(double, double);

	void print();
	void setRealPart(double);
	void setImaginaryPart(double);

	void add(Complex&);
	void sub(Complex&);
	void mul(Complex&);
	void div(Complex&);
	bool equ(Complex&);
	void conj();
	double getModule();
	bool isLess(Complex&);
	double getRealPart();
	double getImaginaryPart();

	~Complex();
};

Complex::Complex() {
	std::cout << "By default\n";
}

// initilazier list
Complex::Complex(double re) : re(re) {}

// initilazier list
Complex::Complex(double re, double im) : re(re), im(im) {}

void Complex::print() {
	std::cout << "real part: " << re << std::endl;
	std::cout << "imaginary part: " << im << "i" << std::endl;
}

void Complex::setRealPart(double re) {
	this->re = re;
}

void Complex::setImaginaryPart(double im) {
	this->im = im;
}

void Complex::add(Complex &a) {
	re += a.re;
	im += a.im;
}

void Complex::sub(Complex &a) {
	re -= a.re;
	im -= a.im;
}


void Complex::mul(Complex &a) {
	re = re * a.re - im * a.im;
	im = re * a.im + im * a.re;
}

void Complex::div(Complex &a) {
	if (a.re * a.re + a.im * a.im < 1e-6) {
		std::cout << "Division by zero is undefined" << std::endl;
		return;
	}
	re = (re * a.re + im * a.im) / (a.re * a.re + a.im * a.im);
	im = (re * a.re - im * a.im) / (a.re * a.re + a.im * a.im);
}

bool Complex::equ(Complex &a) {
	return (re == a.re and im == a.im);
}

void Complex::conj() {
	im = -im;
}

double Complex::getModule() {
	return sqrt(re * re + im * im);
}

bool Complex::isLess(Complex &a) {
	return this->getModule() < a.getModule();
}

double Complex::getRealPart() {
	return re;
}

double Complex::getImaginaryPart() {
	return im;
}

Complex::~Complex() {
	std::cout << "I'm deleted\n";
}

int main() {

	std::string command;
	Complex *complexNumber = new Complex;
	Complex *tmpComplexNumber = new Complex;
	double realNumber;
	while (std::cin >> command) {
		// assert ?

		if (command == "conj") {
			complexNumber->conj();
			continue;
		}
		std::cout << "Input real part: ";
		std::cin >> realNumber;
		std::cout << std::endl;
		tmpComplexNumber->setRealPart(realNumber);

		std::cout << "Input imaginary part: ";
		std::cin >> realNumber;
		std::cout << std::endl;
		tmpComplexNumber->setImaginaryPart(realNumber);

		if (command == "add")
			complexNumber->add(*tmpComplexNumber);
		else if (command == "sub")
			complexNumber->sub(*tmpComplexNumber);
		else if (command == "mul")
			complexNumber->mul(*tmpComplexNumber);
		else if (command == "div") 
			complexNumber->div(*tmpComplexNumber);
		else if (command == "equ") {
			if (complexNumber->equ(*tmpComplexNumber))
				std::cout << "Numbers are equal" << std::endl;
			else
				std::cout << "Numbers are not equal" << std::endl;
			continue;
		}
		else if (command == "less") {
			if (complexNumber->isLess(*tmpComplexNumber))
				std::cout << "Module of complex number with real part = " << 
					complexNumber->getRealPart() << " and imaginary part = " << 
					complexNumber->getImaginaryPart() << " is less than complex number with real part = " <<
					tmpComplexNumber->getRealPart() << " and imaginary part = " <<
					tmpComplexNumber->getImaginaryPart() << std::endl;
			else
				std::cout << "Module of complex number with real part = " << 
					complexNumber->getRealPart() << " and imaginary part = " << 
					complexNumber->getImaginaryPart() << " is more or equal than complex number with real part = " <<
					tmpComplexNumber->getRealPart() << " and imaginary part = " <<
					tmpComplexNumber->getImaginaryPart() << std::endl;
		}
		else {
			std::cout << "Command " << command << " is unknown" << std::endl;
		}

		complexNumber->print();
	}
}
