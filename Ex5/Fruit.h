
#pragma once
#include "Agriculturist.h"
#include <iostream>
using namespace std;

class Fruit : virtual public Agriculturist
{
private:
	int _sugar;
public:
	//constructor
	Fruit();
	//virtual destructor
	virtual ~Fruit();

	//set functions
	void setSugar(int sugar) {
		this->setPrice(this->getPrice() - _sugar/2); //sub the last sugar
		_sugar = sugar; //update new sugar
		this->setPrice(this->getPrice() + _sugar / 2); //add the new sugar
	}

	//get functions
	const int getSugar() { return _sugar; }

	/*************************************************************************
* function name: printProduct
* The Input:none
* The output:none
* The Function operation:print the values for a Fruit product
*************************************************************************/
	virtual void printProduct();

	/*************************************************************************
* function name:setNewProduct
* The Input:none
* The output:none
* The Function operation:sets the values of a Fruit product
*************************************************************************/
	virtual void setNewProduct();

};

