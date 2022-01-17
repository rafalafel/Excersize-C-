/******************************************
* Yogev Yosef
* 312273410
* Ex 3
******************************************/
#include "UserInterface.h"


UserInterface::UserInterface()
{
	store;
	StoreProduct* newProduct;
	runTest();
}

UserInterface::~UserInterface()
{
	delete newProduct;
}

void UserInterface::runTest()
{
	int type;
	do {
		cout << endl << "-----MENU-----" << endl
			<< "Choose a function:" << endl <<
			"To add a product - press 1" << endl <<
			"To sum the prices of the products - press 2" << endl <<
			"To print the store info - press 3" << endl <<
			"To EXIT - press 0" << endl;
		cin >> type;
		switch (type)
		{

		case 1:
		{
				newProduct = inputProduct();
				if (newProduct != NULL)
				{
					cin >> *newProduct;

					if (store.checkSerialNo(newProduct->getSerialNo()) == true)
					{
						cout << "This serial number is already exist" << endl;
						delete newProduct;
						break;
					}

					store.addProduct(newProduct);
					newProduct->printProduct();
					newProduct = NULL;
				}
			break;
		}
		case 2:
		{
			cout << "Total price: " << store.totalPrice() << endl;
			break;
		}
		case 3:
		{
			cout << endl;
			store.printStore();
			break;
		}
		default:
			break;
		}
	} while (type != 0);
}

StoreProduct * UserInterface::inputProduct()
{
	int type;
	cout << "------CREATING AN OBJECT-------" << endl <<
		"which product would you like to add?" << endl <<
		"To add a regular DairyProducts product - press 1" << endl <<
		"To add a DairyProducts-Cheese product - press 2" << endl <<
		"To add a DairyProducts-OtherDairy product - press 3" << endl <<
		"To add an Agriculturist-Fruit product - press 4" << endl <<
		"To add an Agriculturist-Vegetable product - press 5" << endl <<
		"To add a Package product - press 6" << endl;
	cin >> type;
	switch (type)
	{ 
	case 1: return new DairyProducts;
	case 2: return new Cheese;
	case 3: return new OtherDairy;
	case 4: return new Fruit;
	case 5: return new Vegetable;
	case 6: return new Package;
	default: return NULL;
	}
}