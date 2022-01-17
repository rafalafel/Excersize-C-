
#pragma once
#include "DairyProducts.h"
#include <iostream>
using namespace std;

class Cheese : virtual public DairyProducts
{
private:
	int _additions;
public:
	//constructor
	Cheese();
	//virtual destructor
	virtual ~Cheese();

	//set functions
	void setVitamin(int additions) {
		this->setPrice(this->getPrice() - _additions); //sub the last additions
		_additions = additions; //update new additions
		this->setPrice(this->getPrice() + _additions); //add the new additions
	}
	//get functions
	const int getAdditions() { return _additions; }

	/*************************************************************************
* function name: printProduct
* The Input:none
* The output:none
* The Function operation:print the values for a Cheese product
*************************************************************************/
	virtual void printProduct();

	/*************************************************************************
* function name:setNewProduct
* The Input:none
* The output:none
* The Function operation:sets the values of a Cheese product
*************************************************************************/
	virtual void setNewProduct();

};

