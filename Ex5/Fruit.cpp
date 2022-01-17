#include "Fruit.h"


void Fruit::setNewProduct()
{
	int sugar;
	Agriculturist::setNewProduct();
	cout << "Enter numeber of sugar:" << endl;
	cin >> sugar;
	if (sugar < 0)//data checking
	{
		cout << "illigal data!" << endl;
		return;
	}
	_sugar = sugar;
	this->setPrice(this->getPrice() + _sugar/2); //update new price
}

void Fruit::printProduct()
{
	Agriculturist::printProduct();
	cout << "(" << _sugar << ")";
}

Fruit::Fruit()
{
}

Fruit::~Fruit()
{
}
