/******************************************
* Yogev Yosef
* 312273410
* Ex 3
******************************************/
#include "StoreProduct.h"
#include "Store.h"


void StoreProduct::setNewProduct()
{
	int serialNo, quantity, area, shelf;
	char row;

	cout << "Enter serial number:" << endl;
	cin >> serialNo;
	if (serialNo < 0)//data checking
	{
		cout << "illigal data!" << endl;
		return;
	}
	_serialNo = serialNo;

	cout << "Enter quantity (Kg):" << endl;
	cin >> quantity;
	if (quantity < 0)//data checking
	{
		cout << "illigal data!" << endl;
		return;
	}
	_quantity = quantity;

	cout << "Enter Row:" << endl;
	cin >> row;
	if (!(isalpha(row)))
	{
		cout << "illigal data!" << endl;
		return;
	}
	_row = toupper(row);

	cout << "Enter Shelf:" << endl;
	cin >> shelf;
	if (!(shelf > 0 && shelf < 6))
	{
		cout << "illigal data!" << endl;
		return;
	}
	_shelf = shelf;

	cout << "Enter Area:" << endl;
	cin >> area;
	if (!(area > 0 && area < 4))
	{
		cout << "illigal data!" << endl;
		return;
	}
	_area = area;

	_price = _area*_quantity;
}

void StoreProduct::printProduct()
{
	cout << _serialNo << " "<< _row << " " << _shelf << "(" << _quantity << "," << _type << "," << _area << ")";
}

StoreProduct::StoreProduct()
{
}

StoreProduct::~StoreProduct()
{
}

void StoreProduct::operator >> (istream & is)
{
	this->setNewProduct();
}

istream & operator >> (istream & is, StoreProduct & new_product)
{
	new_product.setNewProduct();
	return is;
}
