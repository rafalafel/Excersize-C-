#include "OtherDairy.h"


void OtherDairy::setNewProduct()
{
	int nonDairy;
	DairyProducts::setNewProduct();
	cout << "Enter numeber of non dairy:" << endl;
	cin >> nonDairy;
	if (nonDairy < 0)//data checking
	{
		cout << "illigal data!" << endl;
		return;
	}
	_numOfNonDairy = nonDairy;
	this->setPrice(this->getPrice() + (5 * _numOfNonDairy)); //update new price

	_names = new string[_numOfNonDairy];

	for (int i = 0; i < _numOfNonDairy; i++)
	{
		cout << "Enter a non dairy name:" << endl;
		cin >> _names[i];
	}
}

void OtherDairy::printProduct()
{
	DairyProducts::printProduct();
	//print all names without the last one
	for (int i = 0; i < _numOfNonDairy - 1; i++)
		cout << _names[i] << ",";

	cout << _names[_numOfNonDairy - 1] << "(" << _numOfNonDairy << ")";
	
}

OtherDairy::OtherDairy()
{
}

OtherDairy::~OtherDairy()
{
	delete[] _names;
}