#include "Cheese.h"

void Cheese::setNewProduct()
{
	int additions;
	DairyProducts::setNewProduct();
	cout << "Enter numeber of additions:" << endl;
	cin >> additions;
	if (additions < 0)//data checking
	{
		cout << "illigal data!" << endl;
		return;
	}
	_additions = additions;
	this->setPrice(this->getPrice() + additions); //update new price
}

void Cheese::printProduct()
{
	DairyProducts::printProduct();
	cout << "(" << _additions << ")";
}

Cheese::Cheese()
{
}

Cheese::~Cheese()
{
}