#pragma once
#include <iostream>
#include <vector>

class CNodeStatic;

class CTreeStatic
{
	class CNodeStatic
	{
	public:
		CNodeStatic();
		CNodeStatic(CNodeStatic* parent);
		~CNodeStatic();

		int iGetChildrenNumber();
		void vAddNewChild();
		CNodeStatic* pcGetChild(int iChildOffset);

		void vSetValue(int iNewVal);
		void vPrint();
		void vPrintAllBelow();
		void vPrintUp();
		void helper();

	private:
		std::vector<CNodeStatic> v_children;

		CNodeStatic* pc_parent_node;
		int i_val;

		int I_DEFAULT_VALUE = 0;
	};

public:
	CTreeStatic();
	~CTreeStatic();

	CNodeStatic* pcGetRoot();

	void vPrintTree();
private:
	CNodeStatic c_root;
};

