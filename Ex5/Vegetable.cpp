#include "Vegetable.h"

void Vegetable::setNewProduct()
{
	int vitamins;
	Agriculturist::setNewProduct();
	cout << "Enter numeber of vitamins:" << endl;
	cin >> vitamins;
	if (vitamins < 0)//data checking
	{
		cout << "illigal data!" << endl;
		return;
	}
	_vitamin = vitamins;
	this->setPrice(this->getPrice() + 2 * _vitamin); //update new price
}

void Vegetable::printProduct()
{
	Agriculturist::printProduct();
	cout << "(" << _vitamin << ")";
}

Vegetable::Vegetable()
{
}

Vegetable::~Vegetable()
{
}
