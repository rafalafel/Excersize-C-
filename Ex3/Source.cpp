#include "MyDate.h"
#include "Calander.h"
#include <iostream>
using namespace std;

int main()
{

	MyDate date1;

	MyDate date2(date1);
	date1.print();

	cout<<date1.isBefore(date2)<<endl;

	date1.init();
	cout << date2.isBefore(date1) << endl;
	date1.print();
	char ch[19] = "programming in cpp";
	date1.changeComment(ch);
	date1.print();
	char ch1[13] = "happy Hanuka";
	MyDate date3(13, 2, 1999, ch1);
	date3.print();

	Calander cal1;

	cal1.Insert(date1);
	cal1.setDate(3, date2);
	cal1.print();

	cout << cal1.isfree(3)<<endl;
	cout << cal1.isfree(0)<<endl;
	cout << cal1.oldest() << endl;
	cal1.setDate(20, date3);
	cal1.print();

	cout << cal1.datesNum() << endl;
	cal1.deleteAll();
	cal1.print();

	return 0;
 }



