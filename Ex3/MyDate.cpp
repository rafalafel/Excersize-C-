#include "MyDate.h"
#include <string>
#include <stdio.h>
#include <iostream>
using namespace std;



MyDate::MyDate(const MyDate& date)
{
	
	_day = date._day;
	_month = date._month;
	_year = date._year;
	if (date._note != NULL)
	{
		_note = new char[strlen(date._note) + 1];

		strcpy(_note, date._note);
	}
	//case we dont have any new note
	else
		_note = NULL;

}

MyDate::MyDate()
{

	_day = 1;
	_month = 1;
	_year = 2020;
	_note = NULL;


}

MyDate::MyDate(int day, int month, int year, const char* note)
{
	if (day < 0 || day>31 || year < 0 || month < 0 || month>12)
	{
		MyDate();
		return;
	}
	if (note != NULL)
	{
		_note = new char[strlen(note) + 1];
		strcpy(_note, note);
	}
	//case we dont have any new note
	else
		_note = NULL;
	_month = month;
	_year = year;
	if (month == 2 && day < 29)
	{
		_day = day;
		return;
	}
	if ((month == 4|| month == 6|| month == 9 || month == 11) && day < 31)
	{
		_day = day;
		return;
	}
	_day = day;

}
MyDate::~MyDate()
{
	if (_note != NULL)
		delete []_note;
}



 void MyDate:: setDay(int newDay)
{

	 if (_month == 2 && newDay < 29)
	 {
		 _day = newDay;
		 return;
	 }
	
	 
	 if ((_month == 4 || _month == 6 || _month == 9 || _month == 11) && newDay< 31)
	 {
		 _day = newDay;
		 return;
	 }
	
	 
	 if ((_month == 1 || _month == 3 || _month == 5 || _month == 7 || _month == 8 || _month == 10 || _month == 12 ) && newDay < 32)
	 {
		 _day = newDay;
		 return;
	 }
}
void MyDate::setMonth(int newMonth)

{
	
	if(0 < newMonth && newMonth < 13)
		_month = newMonth;

}
 void MyDate::setYear(int newYear)
{
	 if (0 < newYear )
		 _year = newYear;

}
 
 void MyDate::setNote(char* newNote)
{
	 if (newNote != NULL)
	 {
		 _note = new char[strlen(newNote) + 1];
		 strcpy(_note, newNote);
	 }
}

 void MyDate::init()

 {
	 _day = 13;
	 _month = 12;
	 _year = 2020;
	 if (_note != NULL)
	 {
		 delete[] _note;
		 _note = NULL;
	 }

 }

 bool MyDate::isBefore(const MyDate& existingDate) const
 {
	 if (existingDate._year > _year)
		 return true;
	 if (existingDate._year == _year)
	 {

		 if (existingDate._month > _month)
			 return true;
		
		 if (existingDate._month == _month)
			 if (existingDate._day > _day)
				 return true;
	 }
	
	 return false;
 }

 void MyDate::changeComment(char* newNote)
 {
	 if (newNote != NULL)
	 {
		 if (_note != NULL)
			 delete[] _note;//delete doesnt insert into _note a NULL
		 _note= new char[strlen(newNote) + 1];
		 strcpy(_note, newNote);	
	 }
 }


 void MyDate::print() const

 {
	 if(_note != NULL)
		 cout << _day << "/" << _month << "/" << _year << " " << _note << endl;
	 else
		 cout << _day << "/" << _month << "/" << _year << endl;
 }

 void MyDate::inc()

 {

	 if (_day < 28)
	 {
		 _day++;
		 return;
	 }


	 if (_month == 2)
	 {
		 _day = 1;
			 _month = 3;
		 return;
	 }


	 if ((_month == 4 || _month == 6 || _month == 9 || _month == 11))
	 {
		 if (_day == 30)
		 {
			 _day = 1;
			 _month ++;	 
		 }
		  else
			 _day++;
		 return;
	 }

	 if (_month == 1 || _month == 3 || _month == 5 || _month == 7 || _month == 8 || _month == 10 )
	 {

		 if (_day == 31)
		 {
			 _day = 1;
			 _month++;
		 }
		 else
			 _day++;
		 return;
	 }
	 //if are here we are in month =12
	
	 if (_day == 31)
	 {
		 _day = 1;
		 _month = 1;
		 _year++;
	 }

	 else
		 _day++;



	

 }










 