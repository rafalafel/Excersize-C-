#include "Calander.h"
#include "MyDate.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

Calander::~Calander()
{
	for (int i = 0; i < 30; i++)
	{
		if (_arr[i] != NULL)
			delete _arr[i];
	}
}
Calander::Calander() {

	_taken = 0;
		int i;
		for (int i = 0; i < 30; i++)
		{
			_arr[i] = NULL;

		}


}
Calander::Calander(const Calander& cal) {

	_taken = cal._taken;


	for (int i = 0; i < 30; i++)
	{
		if (cal._arr[i] == NULL)
		{
			_arr[i] = NULL;

		}
		else {
			_arr[i] = new MyDate(*cal._arr[i]); //copy all the data with copy constractor of "MyDate"
		}

	}


}

bool Calander::isfree(int Num) const 
{
	if (_arr[Num] != NULL)
		return false;
	return true; 
}

void Calander::setDate(int num, const MyDate &newDate)
{
	if (isfree(num) == false)
	{
		delete _arr[num];
	}
	
	_arr[num] = new MyDate(newDate); //copy all the data with copy constractor of "MyDate"


}

int Calander::firstFree() const{ 
	for (int i = 0; i < 30; i++)
	{
		if (isfree(i) == true)
			return i;
	}
	//if we are here the array is full
	return -1;
}

bool Calander::Insert(const MyDate &DATE) {
	int i = firstFree();
	if (i == -1)
		return false;
	else {
		_arr[i] = new MyDate(DATE);
		return true;
	}
}

int	Calander::datesNum() {
	int count=0;
	for (int i = 0; i < 30; i++)
	{
		if (isfree(i) == false)
			count++ ;

	}
	return count; 

}

void Calander::Delete(int num){
	if (isfree(num) == false)
	{
		delete _arr[num];
		_arr[num] = NULL;
	}


}

void Calander::deleteAll() {
	for (int i = 0; i < 30; i++)
	{
		Delete(i);
	}
}
	void Calander::print()
	{
	
		if (datesNum() == 0)
		{

			cout << "Empty Calander" << endl;
			return;

		}

		for (int i = 0; i < 30; i++)

		{
			if (isfree(i) == false)
			{
				cout << i << " ";
				_arr[i]->print();
			}

		}

	
	}

	int Calander::oldest()
	{
		int oldestCell = firstFree();
		for (int i = 1; i < 30; i++)
		{
			if(_arr[i] != NULL)
				if (_arr[i]->isBefore(*_arr[oldestCell-1]) == true)
					oldestCell = i;

		}
		return oldestCell;	
	}
	




