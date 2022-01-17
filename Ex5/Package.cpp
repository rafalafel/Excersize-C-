#include "Package.h"


void Package::setNewProduct()
{
	int numOfProducts, colors;
	StoreProduct::setNewProduct();
	StoreProduct::setProductType(T_Package);

	cout << "Enter numeber of colors:" << endl;
	cin >> colors;
	if (colors < 0)//data checking
	{
		cout << "illigal data!" << endl;
		return;
	}
	_colors = colors;

	cout << "Enter numeber of products:" << endl;
	cin >> numOfProducts;
	if (numOfProducts < 0)//data checking
	{
		cout << "illigal data!" << endl;
		return;
	}
	_numOfProducts = numOfProducts;

	this->setPrice(this->getPrice()*2*_numOfProducts + _colors/3); //update new price

	_names = new string[_numOfProducts];

	for (int i = 0; i < _numOfProducts; i++)
	{
		cout << "Enter a product name:" << endl;
		cin >> _names[i];
	}
}
void Package::printProduct()
{
	StoreProduct::printProduct();

	//print all names without the last one
	for (int i = 0; i < _numOfProducts - 1; i++)
		cout << _names[i] << ",";

	cout << _names[_numOfProducts - 1] << "(" << _numOfProducts << "," << _colors << ")";
}

Package::Package()
{
}

Package::~Package()
{
	delete[] _names;
}