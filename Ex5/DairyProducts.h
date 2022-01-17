/******************************************
* Yogev Yosef
* 312273410
* Ex 3
******************************************/

#pragma once

#include "StoreProduct.h"
#include <iostream>
#include <string>
using namespace std;

class DairyProducts : virtual public StoreProduct
{
private:

	string _productName;
	double _fatPercentage;
	int _subType;
	int _colors;
	
protected:
	typedef enum {
		T_Beverage = 1,
		T_Yogurt = 2,
		T_Cheese = 3,
		T_OtherDairyProducts = 4
	}productType;

public:

	//constructor
	DairyProducts();
	//virtual destructor
	virtual ~DairyProducts();

	//set functions
	void setDairyProductSubType(int subType) { _subType = subType; }
	void setProductName(string productName) { _productName = productName; }
	void setFatPercentage(double fatPercentage) { _fatPercentage = fatPercentage; }

	//get functions
	const int getDairyProductSubType() const { return _subType; }
	const int getColors() const { return _colors; }
	const string getProductName() const { return _productName; }
	const double getFatPercentage() const { return _fatPercentage; }

	/*************************************************************************
	* function name: printProduct														
	* The Input:none		 																
	* The output:none																		
	* The Function operation:print the values for a dairy product						
	*************************************************************************/
	virtual void printProduct();

	/*************************************************************************
	* function name:setNewProduct														
	* The Input:none																		
	* The output:none																		
	* The Function operation:sets the values of a dairy product							
	*************************************************************************/
	virtual void setNewProduct();
};

