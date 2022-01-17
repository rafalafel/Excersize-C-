/******************************************
* Yogev Yosef
* 312273410
* Ex 3
******************************************/
#pragma once
#include <string>
#include <iostream>
#include "StoreProduct.h"
using namespace std;


class Agriculturist : virtual public StoreProduct
{

private:

	string _productName;
	int _subType;
	int _seasons;
	int _suppliers;

protected:
	typedef enum {
		T_Vegetable = 1,
		T_Fruit = 2,
	}productType;

public:

	//constructor
	Agriculturist();
	//virtual destructor
	virtual ~Agriculturist();

	//set functions
	void setAgriculturistSubType(int subType) { _subType = subType; }
	void setProductName(string productName) { _productName = productName; }

	//get functions
	const int getAgriculturistSubType() { return _subType; }
	const int getSeasons() { return _seasons; }
	const int getSuppliers() { return _suppliers; }
	const string getProductName() { return _productName; }

	/*************************************************************************
	* function name: printProduct														
	* The Input:none																		
	* The output:none																		
	* The Function operation:print the values for a agriculturist product				
	*************************************************************************/
	virtual void printProduct();

	/*************************************************************************
	* function name:setNewProduct														
	* The Input:none																		
	* The output:none																		
	* The Function operation:sets the values of a agriculturist product					
	*************************************************************************/
	virtual void setNewProduct();
};

