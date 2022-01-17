#pragma once
using namespace std;
class Complex
{
private: 
	int _a, _b; 
	

public: 

	//get functions//
	int get_a()const;
	
	int get_b()const;
	/*************************
	Function name:getAbs()
	Input:none
	Output:double
	The function operation: get the absolute value
	************************/
	double getAbs()const;
	/*************************
	Function name:getPhase()
	Input:none
	Output:double
	The function operation: get the Phase value
	************************/
	double getPhase()const;

	//set functions//
	void set(int new_a,int new_b);
	/*************************
	Function name:print
	Input:none
	Output:none
	The function operation: the function print the complex number
	************************/
	void print()const;
	/*************************
		Function name : add
		Input : complex
		Output : complex
		The function operation : adding two varible from complex type
	************************/
	Complex add(const Complex& comp)const;
	/*************************
	Function name:Complex
	Input:complex
	Output:complex
	The function operation: defult constructor with the values 0,0
	************************/
	Complex(int new_a = 0, int new_b = 0);

	/*************************
	Function name:sub
	Input: const Complex
	Output:Complex
	The function operation: sub two varible from complex type
	************************/
	Complex sub(const Complex& comp)const;

};

