/******************************************
* Yogev Yosef
* 312273410
* Ex 3
******************************************/
#include "Store.h"
#include "Package.h"
#include "Agriculturist.h"
#include "DairyProducts.h"
#include "Vegetable.h"
#include "Fruit.h"
#include "OtherDairy.h"
#include "Cheese.h"


bool const Store::checkSerialNo(int serialNo) const
{
	for (int i = 0; i < _numOfProducts; i++)
		if (_products[i]->getSerialNo() == serialNo)
			return true;
	//if we are here it means that the product isnt exist in the store
	return false;
}

float Store::totalPrice()const
{
	float totalPrice = 0;

	for (int i = 0; i < _numOfProducts; i++)
		totalPrice += _products[i]->getPrice();
	return totalPrice;
}

void Store::printStore()const
{
	int i;
	cout << "Name: " << _storeName << endl << "Number of products: " << _numOfProducts << endl;
	cout << "Publicity: " << _publicity << endl;
	for (i = 0; i < _numOfProducts; i++)
	{
		_products[i]->printProduct();
		cout << endl;
	}
}

void Store::setPublicity(int publicity)
{
	int type;
	_publicity = publicity;

	//update all the prices
	for (int i = 0; i < _numOfProducts; i++)
		updatePrice(_products[i]);
}

void Store::updatePrice(StoreProduct * newProduct)
{
	int type;
	newProduct->setPrice(newProduct->getQuantity()*newProduct->getArea()*_publicity); //base price
	type = newProduct->getProductType();

		//T_Agriculturist
	if(type == 1)
	{
		Agriculturist * temp = dynamic_cast<Agriculturist*>(newProduct);
		newProduct->setPrice((newProduct->getPrice() * 3 * (5 - temp->getSeasons())) + temp->getAgriculturistSubType() + (5 * temp->getSuppliers()));
		//case its a T_Vegetable
		if (temp->getAgriculturistSubType() == 1)
		{
			Vegetable * temp2 = dynamic_cast<Vegetable*>(temp);
			newProduct->setPrice(newProduct->getPrice() + (2 * temp2->getVitamin()));
		}
		//case its a T_Fruit
		else
		{
			Fruit * temp2 = dynamic_cast<Fruit*>(temp);
			newProduct->setPrice(newProduct->getPrice() + (temp2->getSugar() / 2));
		}
	}
		//T_DairyProducts
	else if(type == 2)
	{
		DairyProducts * temp = dynamic_cast<DairyProducts*>(newProduct);
		newProduct->setPrice(temp->getDairyProductSubType() * (newProduct->getPrice() + temp->getColors() - temp->getFatPercentage()));
		//case its a T_Cheese
		if (temp->getDairyProductSubType() == 3)
		{
			Cheese * temp2 = dynamic_cast<Cheese*>(temp);
			newProduct->setPrice(newProduct->getPrice() + temp2->getAdditions());
		}
		//case its a T_OtherDairyProducts
		if (temp->getDairyProductSubType() == 4)
		{
			OtherDairy * temp2 = dynamic_cast<OtherDairy*>(temp);
			newProduct->setPrice(newProduct->getPrice() + (5 * temp2->getNumOfNonDairy()));
		}
	}
	//T_Package
	else
	{
		Package * temp = dynamic_cast<Package*>(newProduct);
		newProduct->setPrice((newProduct->getPrice() * 2 * temp->getNumOfProducts()) + temp->getColors() / 3);
	}

}

void Store::addProduct(StoreProduct * newProduct)
{
	if (_numOfProducts > 0)//case its not the first product
	{
		StoreProduct** temp_products;
		temp_products = new StoreProduct*[_numOfProducts];
		for (int i = 0; i < _numOfProducts; i++)
			temp_products[i] = _products[i];
		delete[] _products;
		_numOfProducts++;
		_products = new StoreProduct*[_numOfProducts];
		for (int i = 0; i < _numOfProducts; i++)
			_products[i] = temp_products[i];
		delete[] temp_products;
	}
	else //case its the first product of the store
	{
		_numOfProducts++;
		_products = new StoreProduct*[_numOfProducts];
	}
	_products[_numOfProducts - 1] = newProduct;
	updatePrice(newProduct); //fix the price

}

Store::Store()
{
	_storeName = "SuperShop";
	_numOfProducts = 0;
	_publicity = 2;
	_products = NULL;
}

Store::~Store()
{
	for (int i = 0; i < _numOfProducts; i++)
		delete _products[i];
	delete[] _products;
}