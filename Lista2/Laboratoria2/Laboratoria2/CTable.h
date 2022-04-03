class CTable {
public:
	int tableSize;
	CTable();
	CTable(std::string sName, int iTableLen);
	CTable(std::string sName, int iTableLen, bool view);
	CTable(CTable& pcOther);
	//~CTable();
	void getInfo();
	void vSetName(std::string sName);
	bool bSetNewSize(int iTableLen);
	CTable* pcClone();
	void operator=(const CTable& pcOther);
	CTable operator+(CTable& pcOther);
	void vSetValueAt(int iOffset, int iNewVal);
	void vPrint();
	int vGetValue(int iOffset);
private:
	std::string s_name;
	int* table;
};