
#pragma once
#include "DairyProducts.h"
#include <iostream>
#include <string>
using namespace std;

class OtherDairy : virtual public DairyProducts
{
private:
	int _numOfNonDairy;
	string* _names;
public:
	//constructor
	OtherDairy();
	//virtual destructor
	virtual ~OtherDairy();

	//get functions
	const int getNumOfNonDairy() { return _numOfNonDairy; }

	/*************************************************************************
* function name: printProduct
* The Input:none
* The output:none
* The Function operation:print the values for a OtherDairy product
*************************************************************************/
	virtual void printProduct();

	/*************************************************************************
* function name:setNewProduct
* The Input:none
* The output:none
* The Function operation:sets the values of a OtherDairy product
*************************************************************************/
	virtual void setNewProduct();
};

