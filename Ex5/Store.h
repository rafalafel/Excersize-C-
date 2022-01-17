/******************************************
* Yogev Yosef
* 312273410
* Ex 3
******************************************/
#include "StoreProduct.h"
#include <string>
#include <iostream>
using namespace std;

class Store
{
private:
	string _storeName;
	int _numOfProducts;
	StoreProduct** _products;
	int _publicity;

public:
	//constructor
	Store();
	//virtual destructor
	~Store();

	//get functions
	const int getNumOfProducts() const { return _numOfProducts; }
	const int getPublicity() const { return _publicity; }

	/*************************************************************************
* function name:checkSerialNo
* The Input:int seraialNo
* The output:bool
* The Function operation:checks if the serial number exist
*************************************************************************/
	bool const checkSerialNo(int seraialNo)const;

	/*************************************************************************
	* function name:totalPrice															
	* The Input:none																		
	* The output:none																		
	* The Function operation:print the price of the whole store							
	*************************************************************************/
	float totalPrice() const;

	/*************************************************************************
	* function name:setPublicity
	* The Input:publicity
	* The output:none
	* The Function operation: the function update the new publicity and all the prices
	*************************************************************************/
	void setPublicity(int publicity);

	/*************************************************************************
	* function name:printStore															
	* The Input:none																	
	* The output:none																	
	* The Function operation:print the products of the store							
	*************************************************************************/
	void printStore()const;

	void updatePrice(StoreProduct * newProduct);
	/*************************************************************************
	* function name:addProduct															
	* The Input:new product																
	* The output:none																		
	* The Function operation:add new product to the array								
	*************************************************************************/
	void addProduct(StoreProduct* new_product);
};
