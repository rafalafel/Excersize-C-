#include "complex.h"
#include "math.h"
#include <iostream>
Complex Complex::add(const Complex& comp)const 
{
	Complex comp1;
	comp1.set(_a + comp._a,_b + comp._b);
	return comp1;
 }
Complex Complex::sub(const Complex& comp)const
{
	Complex comp1;
	comp1.set(_a - comp._a, _b - comp._b);
	return comp1;
}

Complex::Complex(int new_a, int new_b)
{
	_a = new_a;
	_b = new_b;

}
int Complex::get_a()const
{
	return _a;
}

int Complex::get_b()const
{
	return _b;
}

double Complex::getAbs()const
{
	double x = sqrt(_a*_a + _b * _b);

		return x;

}

double Complex::getPhase()const

{ 
	double x = atan2(_b, _a);

	return x;

}

void Complex::set(int new_a, int new_b)
{
	_a = new_a;
	_b = new_b;


}

void Complex::print()const
{
	cout << _a << " + " << _b << "i(" << getAbs() << "," << getPhase() << ")" << endl;
}
Complex:: Complex(const Complex& comp)
{
	set(comp._a, comp._b);
}