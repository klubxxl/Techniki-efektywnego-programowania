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
CTable::CTable(CTable& pcOther) {
	s_name = pcOther.s_name + "_copy";
	table = pcOther.table;
	tableSize = pcOther.tableSize;
	std::cout << "kopiuj: " << s_name << std::endl;
}

CTable::~CTable() {
	std::cout << "usuwam: " << s_name << std::endl;
	delete[] table;
}

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
		delete[] CTable::table;
		CTable::table = new int[iTableLen];
		CTable::tableSize = iTableLen;

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

void CTable::Merge(CTable* other) {
	int newSize = other->tableSize + this->tableSize;
	int* newTable = new int[newSize];
	for (int i = 0; i < newSize; i++) {
		if (i < other->tableSize) newTable[i] = other->table[i];
		else newTable[i] = this->table[i - other->tableSize];
	}

	delete[] this->table;
	this->table = newTable;
}
