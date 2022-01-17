#pragma once
#include "MyDate.h"

class Calander
{
private:
	MyDate *_arr[30];
	int _taken;

public:

	//constructors
	Calander();
	Calander(const Calander& cal);
	~Calander();

	void setDate(int num, const MyDate &newDate);

	/*************************
	* function name:isfree
	* The Input:Num
	* The output: bool
	* The Function operation:check if a cell in the array is full or not, respectvely to it index
	*************************/
	bool isfree(int Num) const;

	/*************************
	* function name:firstfree
	* The Input:none
	* The output: int ( index of a cell in the array)
	* The Function operation: return the index of the first cell in the array that empty
	*************************/
	int firstFree() const;
	/*************************
		* function name:Insert
		* The Input:bool
		* The output:MyDate
		* The Function operation: put DATE in the first empty cell, if the array is full return false
		*************************/
	bool Insert(const MyDate &DATE);
	/*************************
	* function name:dateNum
	* The Input:none
	* The output:int
	* The Function operation:count the days
	*************************/
	int	datesNum();
	/*************************
	* function name:Delete
	* The Input:int
	* The output:none
	* The Function operation: delete the apropriate cell
	*************************/
	void Delete(int num);
	/*************************
	* function name:deleteAll
	* The Input:none
	* The output:none
	* The Function operation: delete every member of the array
	*************************/
	void deleteAll();
	/*************************
	* function name:print
	* The Input:none
	* The output:none
	* The Function operation: print the members of the array
	*************************/
	void print();
	/*************************
	* function name:oldest
	* The Input:none
	* The output:int
	* The Function operation:return the number of the oldest date
	*************************/
	int oldest();
};

