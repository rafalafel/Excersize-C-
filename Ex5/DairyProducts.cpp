/******************************************
* Yogev Yosef
* 312273410
* Ex 3
******************************************/

#include "DairyProducts.h"

void DairyProducts::setNewProduct()
{
	int type, colors;
	cout << endl << "-----OPTIONS-----" << endl
		<< "Choose a sub type:" << endl <<
		"A beverage - press 1" << endl <<
		"A yogurt - press 2" << endl <<
		"A cheese - press 3" << endl <<
		"A other dairy products - press 4" << endl;
	cin >> type;
	switch (type)
	{
	case 1:
	{
		_subType = T_Beverage;
		break;
	}
	case 2:
	{
		_subType = T_Yogurt;
		break;
	}
	case 3:
	{
		_subType = T_Cheese;
		break;
	}
	case 4:
	{
		_subType = T_OtherDairyProducts;
		break;
	}
	default:
		break;
	}
	StoreProduct::setNewProduct();
	string productName;
	StoreProduct::setProductType(T_DairyProducts);
	int fatPercentage;
	cout << "Enter name:" << endl;
	cin >> productName;
	_productName = productName;

	cout << "Enter fat percentage:" << endl;
	cin >> fatPercentage;
	if (fatPercentage < 0)
	{
		cout << "illegal data!" << endl;
		return;
	}
	_fatPercentage = fatPercentage;

	cout << "Enter num of colors:" << endl;
	cin >> colors;
	if (colors < 0)
	{
		cout << "illegal data!" << endl;
		return;
	}
	_colors = colors;
	this->setPrice(_subType*(this->getPrice() + _colors - _fatPercentage));
}

void DairyProducts::printProduct()
{
	StoreProduct::printProduct();
	cout << " " << _productName << " (" << _subType << "," << _colors << "," << _fatPercentage << ")";
}

DairyProducts::DairyProducts()
{
}

DairyProducts::~DairyProducts()
{
}
