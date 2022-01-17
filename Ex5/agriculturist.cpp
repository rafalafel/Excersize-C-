/******************************************
* Yogev Yosef
* 312273410
* Ex 3
******************************************/
#include "Agriculturist.h"


void Agriculturist::setNewProduct()
{
	int type, seasons, suppliers;
	cout << endl << "-----OPTIONS-----" << endl
		<< "Choose a sub type:" << endl <<
		"A vegetable - press 1" << endl <<
		"A fruit - press 2" << endl;
	cin >> type;
	switch (type)
	{
	case 1:
	{
		_subType = T_Vegetable;
		break;
	}
	case 2:
	{
		_subType = T_Fruit;
		break;
	}
	default:
		break;
	}
	StoreProduct::setNewProduct();
	StoreProduct::setProductType(T_Agriculturist);
	string productName;
	cout << "Enter name:" << endl;
	cin >> productName;
	_productName = productName;
	
	cout << "Enter numeber of seasons:" << endl;
	cin >> seasons;
	if (!(seasons > 0 && seasons < 5))//data checking
	{
		cout << "illigal data!" << endl;
		return;
	}
	_seasons = seasons;

	cout << "Enter numeber of suppliers:" << endl;
	cin >> suppliers;
	if (suppliers < 0)//data checking
	{
		cout << "illigal data!" << endl;
		return;
	}
	_suppliers = suppliers;

	this->setPrice(_subType + (5 * _suppliers) + ((5 - _seasons)* 3 * this->getPrice()));

}
void Agriculturist::printProduct()
{
	StoreProduct::printProduct();
	cout << " " << _productName << " (" << _subType << "," << _seasons << "," << _suppliers << ")";
}

Agriculturist::Agriculturist()
{
}

Agriculturist::~Agriculturist()
{
}
