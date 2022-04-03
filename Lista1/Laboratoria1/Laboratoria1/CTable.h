class CTable {
public:
	CTable();
	CTable(std::string sName, int iTableLen);
	CTable(CTable& pcOther);
	~CTable();
	void getInfo();
	void vSetName(std::string sName);
	bool bSetNewSize(int iTableLen);
	CTable* pcClone();
	//////////////////////////
	void Merge(CTable* other);
private:
	std::string s_name;
	int* table;
	int tableSize;
};