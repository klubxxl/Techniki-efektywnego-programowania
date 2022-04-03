#include <iostream>
#include "CTable.h"


CTable::CTable() {
	s_name = "defaultName";
	std::cout << "bezp: " << s_name << std::endl;
	table = new int[10];
	tableSize = 10;
}
CTable::CTable(std::string sName, int iTableLen) {
	s_name = sName;
	std::cout << "parametr: " << s_name << std::endl;
	table = new int[iTableLen];
	tableSize = iTableLen;
}
CTable::CTable(std::string sName, int iTableLen, bool view) {
	s_name = sName;
	if(view == true) std::cout << "parametr: " << s_name << std::endl;
	table = new int[iTableLen];
	tableSize = iTableLen;
}
CTable::CTable(CTable& pcOther) { 
	s_name = pcOther.s_name + "_copy";
	tableSize = pcOther.tableSize;
	for (int i = 0; i < tableSize; i++)
		table[i] = pcOther.table[i];
}

//CTable::~CTable() {
//	std::cout << "usuwam: " << s_name << std::endl;
//	delete[] table;
//}

void CTable::getInfo()
{
	std::cout << "Name: " << s_name << std::endl;
	std::cout << "Table length: " << tableSize << std::endl;
}

void CTable::vSetName(std::string sName)
{
	s_name = sName;
}

bool CTable::bSetNewSize(int iTableLen) {
	if (iTableLen < 0) {
		return false;
	}
	else {
		delete[] table;
		table = new int[iTableLen];
		tableSize = iTableLen;

		return true;
	}
}

CTable* CTable::pcClone() {
	CTable* pomCTable = new CTable();

	pomCTable->s_name = this->s_name;
	pomCTable->table = new int[tableSize];
	for (int i = 0; i < tableSize; i++)
		pomCTable->table[i] = this->table[i];

	return pomCTable;
}

void CTable::vSetValueAt(int iOffset, int iNewVal)
{
	if(iOffset < tableSize) table[iOffset] = iNewVal;
}

void CTable::vPrint()
{
	for (int i = 0; i < tableSize; i++) std::cout << table[i] << " ";;
	std::cout << std::endl;
}

int CTable::vGetValue(int iOffset) {
	if (iOffset < tableSize) return table[iOffset];
	else return 0;
}

void CTable::operator=(const CTable& pcOther)
{
	table = pcOther.table;
	tableSize = pcOther.tableSize;
}

CTable CTable::operator+(CTable& pcOther)
{
	int newSize = pcOther.tableSize + tableSize;
	int* newTable = new int[newSize];

	for (int i = 0; i < newSize; i++) {
		if (i < tableSize) newTable[i] = table[i];
		else newTable[i] = pcOther.vGetValue(i - tableSize);
	}

	CTable cTable("temporary", newSize, false);
	for (int i = 0; i < newSize; i++) cTable.vSetValueAt(i, newTable[i]);

	delete[] newTable;

	return &cTable;
}
