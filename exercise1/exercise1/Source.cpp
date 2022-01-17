#include<iostream>
using namespace std;

void printNice(const char* str = "hello", int font=10,char color='y')
{
	cout << "str = " << str << endl;
	cout << "font = " << font << endl;
	cout << "color = " << color << endl;
}

void printReallyNice(int x) {
	cout << "x (int) = " << x << endl;
}

void printReallyNice(float x) {
	cout << "x (float) = " << x << endl;
}

void printReallyNice(double x) {
	cout << "x (double) = " << x << endl;
}
//
//void func(double x, int y = 3) {
//
//}
//void func(double x) {
//
//}

void function1(int x) {
	x = 1;
	cout << "The address of x : " << &x << endl;
}
void function2(int* xPtr) {
	*xPtr = 1;
}

void function3(int& y) { //	int& y = x;
	y = 2;
}
int & findByIndex(int arr[], int size,int index) {
	return arr[index];
}



void main() {
	//printNice("Hi", 20, 'b');
	//printNice("Hi", 20);
	//printNice("Hi");
	//printNice("hey", 'b');
	
	//printReallyNice(3);

	//func(3.4);

	int x = 0;
	cout << "x = " << x << endl;
	function1(x);
	cout << "x = " << x << endl;
	cout << "The address of x : " << &x << endl;
	function2(&x);
	cout << "x = " << x << endl;
	function3(x);
	cout << "x = " << x << endl;
	
	int num1 = 2;
	int& num2 = num1;
	int& num3 = num2;
	int& num4 = num1;
	num2 = 5;
	cout << num1 << " " << num2 << " " << num3 << " " << num4 << endl;

	int arr[] = { 3,5,7,6,4,3,2 };
	cout << findByIndex(arr, 7, 3) << endl;
	for (int i = 0; i < 7; i++)
		cout << arr[i] << " ";
	cout << endl;
	findByIndex(arr, 7, 3) = 90; //6 = 90;
	for (int i = 0; i < 7; i++)
		cout << arr[i] << " ";
	cout << endl;
	findByIndex(arr, 7, 2) = findByIndex(arr, 7, 3);
	for (int i = 0; i < 7; i++)
		cout << arr[i] << " ";
	cout << endl;

	/*const char* str1 = "hello";
	char str2[] = "hello";
	str2[3] = 'x';
	char * str3 = (char*)malloc(sizeof(char) * 6);
	strcpy_s(str3, strlen("hello"), "hello");
	str3[3] = 'x';
	*/
	

}