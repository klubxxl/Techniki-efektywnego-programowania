#include <iostream>
#include "CTable.h"

int main()
{
	
	//			ZADANIE 1			\\

	/*
	CTable c_tab_0, c_tab_1;
	c_tab_0.bSetNewSize(6);
	c_tab_1.bSetNewSize(4);
	c_tab_0 = c_tab_1;

	Zgłoszono wyjątek: Element Laboratoria2.exe wyzwolił punkt przerwania.
	*/
	

	//			ZADANIE 2			\\

	/*
	CTable c_tab_0, c_tab_1;
	c_tab_0.bSetNewSize(6);
	c_tab_1.bSetNewSize(4);
	c_tab_0 = c_tab_1;

	Po usunięciu destruktora program zadziałał bez wyrzucania wyjątku.
	*/

	//			ZADANIE 3			\\

	CTable c_tab_0, c_tab_1;
	c_tab_0.bSetNewSize(6);
	c_tab_1.bSetNewSize(4);
	
	std::cout << std::endl;

	int addVal1 = 1, addVal2 = 50;
	for (int i = 0; i < c_tab_0.tableSize; i++) c_tab_0.vSetValueAt(i, i + addVal1);
	for (int i = 0; i < c_tab_1.tableSize; i++) c_tab_1.vSetValueAt(i, i + addVal2);

	c_tab_0.vPrint();
	c_tab_1.vPrint();
	c_tab_0 = c_tab_1; 
	std::cout << std::endl;
	c_tab_1.vSetValueAt(2, 123);
	c_tab_0.vPrint();
	c_tab_1.vPrint();
	
	/* WYNIK:
	51 52 123 54
	51 52 123 54
	*/

	//			ZADANIE 4			\\

	std::cout << std::endl;

	CTable c_tab_2, c_tab_3, c_tab_4;
	c_tab_2.bSetNewSize(2);
	c_tab_3.bSetNewSize(3);
	int add1 = 20, add2 = 30;
	for (int i = 0; i < c_tab_2.tableSize; i++) c_tab_2.vSetValueAt(i, i + add1);
	for (int i = 0; i < c_tab_3.tableSize; i++) c_tab_3.vSetValueAt(i, i + add2);

	std::cout << std::endl;

	c_tab_2.vPrint();
	c_tab_3.vPrint();
	c_tab_4 = c_tab_2 + c_tab_3;
	c_tab_4.vPrint(); 
}