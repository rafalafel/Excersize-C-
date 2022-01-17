
#pragma once
#include "Agriculturist.h"
#include <iostream>
using namespace std;

class Vegetable : virtual public Agriculturist
{
private:
	int _vitamin;

public:
	//constructor
	Vegetable();
	//virtual destructor
	virtual ~Vegetable();

	//set functions
	void setVitamin(int vitamin) {
		this->setPrice(this->getPrice() - 2 * _vitamin); //sub the last vitamins
		_vitamin = vitamin; //update new vitamins
		this->setPrice(this->getPrice() + 2 * _vitamin); //add the new vitamins
	}
	//get functions
	const int getVitamin() { return _vitamin; }

	/*************************************************************************
* function name: printProduct
* The Input:none
* The output:none
* The Function operation:print the values for a Vegetable product
*************************************************************************/
	virtual void printProduct();

	/*************************************************************************
* function name:setNewProduct
* The Input:none
* The output:none
* The Function operation:sets the values of a Vegetable product
*************************************************************************/
	virtual void setNewProduct();
};

