
#pragma once
#include <iostream>
#include <ctype.h>
using namespace std;

class StoreProduct
{
private:

	int _serialNo;
	int _quantity;
	int _type;
	float _price;
	char _row;
	int _shelf;
	int _area;

public:

	typedef enum
	{
		T_Agriculturist = 1,
		T_DairyProducts = 2,
		T_Package = 3,
	}productType;


	//constructor
	StoreProduct();
	//virtual destructor
	virtual ~StoreProduct();

	//set functions
	void setSerialNo(int serialNo) { _serialNo = serialNo; }
	void setRow(char row) { _row = row; }
	void setShelf(int Shelf) { _shelf = Shelf; }
	void setArea(int area) { _area = area; _price = _area * _quantity;}
	void setQuantity(int quantity) { _quantity = quantity; _price = _area * _quantity; }
	void setProductType(int type) { _type = type; }
	void setPrice(float price) { _price = price; }
	
	//get functions
	const float getPrice() const { return _price; }
	const int getSerialNo() const { return _serialNo; }
	const int getQuantity() const { return _quantity; }
	const int getShelf() const { return _shelf; }
	const int getArea() const { return _area; }
	const char getRow() const { return _row; }
	const int getProductType() const { return _type; }
	virtual const string getProductName() { return ""; }

	/*************************************************************************
	* function name:setNewProduct														
	* The Input:none																
	* The output:none																	
	* The Function operation:sets the values of the product								
	*************************************************************************/
	virtual void setNewProduct();

	/*************************************************************************
	* function name:printProduct														
	* The Input:none																		
	* The output:none																		
	* The Function operation:print the values of the product								
	*************************************************************************/
	virtual void printProduct();

	/*************************************************************************
	* function name:operator>>															
	* The Input:none																		
	* The output:none																		
	* The Function operation:sets the values of the product								
	*************************************************************************/
	virtual void operator>>  (istream &is);

	/*************************************************************************
	* function name:operator>>
	* The Input:a StoreProduct object
	* The output:none
	* The Function operation:sets the values of the product
	*************************************************************************/
	friend istream& operator >> (istream &is, StoreProduct& new_product);
};


