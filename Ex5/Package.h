
#pragma once
#include <string>
#include <iostream>
#include "StoreProduct.h"
using namespace std;


class Package : virtual public StoreProduct
{
private:
	int _numOfProducts;
	string* _names;
	int _colors;

public:
	//constructor
	Package();
	//virtual destructor
	virtual ~Package();

	//set functions
	void setColors(int colors)
	{ 
		this->setPrice(this->getPrice() - _colors / 3); //sub the last colors
		_colors = colors; //update new colors
		this->setPrice(this->getPrice() + _colors / 3); //add the new colors
	}

	//get functions
	const int getColors() { return _colors; }
	const int getNumOfProducts() { return _numOfProducts; }

	/*************************************************************************
* function name: printProduct
* The Input:none
* The output:none
* The Function operation:print the values for a Package product
*************************************************************************/
	virtual void printProduct();

	/*************************************************************************
	* function name:setNewProduct
	* The Input:none
	* The output:none
	* The Function operation:sets the values of a Package product
	*************************************************************************/
	virtual void setNewProduct();
	

};

