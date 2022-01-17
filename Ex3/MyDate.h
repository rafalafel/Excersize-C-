#pragma once



class MyDate
{ 

private: 
	
	int _day;
	int _month;
	int _year;
	char* _note;

public :

	//constructors
	MyDate();
	MyDate(const MyDate& date);
	MyDate(int day, int month, int year, const char* note);
	~MyDate();

	//getters
	int getDay() const { return _day; }
	int getMonth()const { return _month; }
	int getYear() const { return _year; }
	char* getNote() const{ return _note; }

	//setters
	void setDay(int newDay );
	void setMonth(int newMonth);
	void setYear(int newYear);
	void setNote(char* newNote);

	/*************************
	* function name:init
	* The Input:none
	* The output:none
	* The Function operation:initialize the field to the date of the submition
	*************************/
	void init();

	/*************************
	* function name:isBefore
	* The Input:MyDate, send by refernce
	* The output: bool
	* The Function operation:cheking if the input date is prior to other date and return 1 or 0 respectvely
	*************************/
	bool isBefore(const MyDate& existingDate)const;
	
	/*************************
	* function name:change comment
	* The Input:string
	* The output: none
	* The Function operation:change the note to the given string
	*************************/
	void changeComment(char* newNote);

	/*************************
	* function name:print
	* The Input:none
	* The output: none
	* The Function operation:print the Date
	*************************/
	void print()const;

	/*************************
	* function name:inc
	* The Input:none
	* The output: none
	* The Function operation:move the Date forward by 1
	*************************/
	void inc();

	


};

