#pragma once
#include <iostream>
#define DEF_TAB_SIZE 10
class CTab
{
public:
	CTab() { pi_tab = new int[DEF_TAB_SIZE]; i_size = DEF_TAB_SIZE; }
	CTab(const CTab& cOther);
	CTab(CTab&& cOther);
	CTab operator=(const CTab& cOther);
	CTab operator=(CTab&& cOther);
	~CTab();
	int iGetSize() { return(i_size); }
private:
	void v_copy(const CTab& cOther);
	int* pi_tab;
	int i_size;
};

CTab::CTab(const CTab& cOther)
{
	v_copy(cOther);
}

CTab::CTab(CTab&& cOther)
{
	pi_tab = cOther.pi_tab;
	i_size = cOther.i_size;
	cOther.pi_tab = NULL;
}

CTab::~CTab()
{
	if (pi_tab != NULL) delete pi_tab;
}

CTab CTab::operator=(CTab&& cOther)
{
	if (pi_tab != NULL) delete[] pi_tab;

	pi_tab = cOther.pi_tab;
	pi_tab = std::move(cOther.pi_tab);
	cOther.pi_tab = nullptr;
	//i_size = cOther.i_size;
	
	return *this;
}

CTab CTab::operator=(const CTab& cOther)
{
	if (pi_tab != NULL) delete[] pi_tab;
	v_copy(cOther);
	return(*this);
}

void CTab::v_copy(const CTab& cOther)
{
	pi_tab = new int[cOther.i_size];
	i_size = cOther.i_size;
	for (int i = 0; i < cOther.i_size; i++)
		pi_tab[i] = cOther.pi_tab[i];
}



