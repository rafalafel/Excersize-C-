#include "Complex.h"

int main()
{
	int x;
	Complex comp2;
	comp2.getAbs();
	//comp2.set(1, -1);
	const Complex comp1(6,6);
	comp1.print();
	comp2.print();
	Complex comp3;
	comp3 = comp1.add(comp2);
	comp3.print(); 
	comp3 = comp1.sub(comp2);
	comp3.print();
	const Complex comp5(5, 5);
	const Complex comp4(4, 4);
	comp5.print();
	comp4.print();
	comp3 = comp5.add(comp4);
	comp3.print();
	comp3 = comp5.sub(comp4);
	comp3.print();
}
