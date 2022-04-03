#pragma once
#include <iostream>
class CTable
{
	int tableSize;
	CTable();
	CTable(std::string sName, int iTableLen);
	CTable(std::string sName, int iTableLen, bool view);
	CTable(CTable& pcOther);
	CTable(CTable&& pcOther);
	~CTable();
	void getInfo();
	void vSetName(std::string sName);
	bool bSetNewSize(int iTableLen);
	CTable* pcClone();
	CTable& operator=(CTable& pcOther);
	CTable& operator=(CTable&& pcOther);
	CTable operator+(CTable& pcOther);
	void vSetValueAt(int iOffset, int iNewVal);
	void vPrint();
	int vGetValue(int iOffset);
private:
	std::string s_name;
	int* table;
};

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
	if (view == true) std::cout << "parametr: " << s_name << std::endl;
	table = new int[iTableLen];
	tableSize = iTableLen;
}
CTable::CTable(CTable& pcOther) {
	s_name = pcOther.s_name + "_copy";
	table = pcOther.table;
	tableSize = pcOther.tableSize;
	//std::cout << "kopiuj: " << s_name << std::endl;
}
CTable::CTable(CTable&& pcOther)
{
	s_name = std::move(pcOther.s_name);
	table = std::move(pcOther.table);
	tableSize = std::move(pcOther.tableSize);
	std::cout << "Move: " << s_name << '\n';
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
	if (iOffset < tableSize) table[iOffset] = iNewVal;
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

CTable CTable::operator+(CTable& pcOther)
{
	int newSize = pcOther.tableSize + tableSize;
	int* newTable = new int[newSize];

	for (int i = 0; i < newSize; i++) {
		if (i < tableSize) newTable[i] = table[i];
		else newTable[i] = pcOther.vGetValue(i - tableSize);
	}

	CTable cTable(s_name + " " + pcOther.s_name, newSize, false);
	for (int i = 0; i < newSize; i++) cTable.vSetValueAt(i, newTable[i]);

	delete[] newTable;

	return cTable;
}

CTable& CTable::operator=(CTable& pcOther)
{
	delete table;

	s_name = pcOther.s_name;
	tableSize = pcOther.tableSize;
	table = new int[tableSize];

	if (table != NULL)
	{
		for (int i = 0; i < tableSize; i++)
		{
			table[i] = pcOther.table[i];
		}
	}

	return *this;
}

CTable& CTable::operator=(CTable&& pcOther)
{

	delete table;

	s_name = pcOther.s_name;
	tableSize = pcOther.tableSize;
	table = std::move(pcOther.table);
	pcOther.table = NULL;

	return *this;
}

