

#include "Store.h"
#include "StoreProduct.h"
#include "DairyProducts.h"
#include "Agriculturist.h"
#include "Vegetable.h"
#include "Package.h"
#include "OtherDairy.h"
#include "Fruit.h"
#include "Cheese.h"



class UserInterface
{
	Store store;
	StoreProduct* newProduct;

public:
	UserInterface();
	~UserInterface();
	void runTest();
	StoreProduct* inputProduct();
};

