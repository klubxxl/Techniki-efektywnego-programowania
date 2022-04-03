#pragma once
#include <vector>

class CNodeDynamic;

class CTreeDynamic
{
	class CNodeDynamic
	{
	public:
		CNodeDynamic();
		CNodeDynamic(CNodeDynamic* parent);
		~CNodeDynamic();

		int iGetChildrenNumber();
		int iGetSize();
		CNodeDynamic* pcGetChild(int iChildOffset);
		CNodeDynamic* pcGetParent();
		CNodeDynamic* pcGetParent(int* childNumber);
		
		void vDeletingChildAt(int iChildOffset);
		void vPrint();
		void vPrintAllBelow();
		void vAddNewChild();
		void vSetValue(int iNewVal);
		void vSetNewParent(CNodeDynamic* parent);
		void vAddNewChild(CNodeDynamic* child);
	private:
		std::vector<CNodeDynamic*> v_children;
		CNodeDynamic* pc_parent_node;
		int i_val;

		int I_DEFAULT_VALUE = 0;
	};
public:
	CTreeDynamic();
	~CTreeDynamic();

	bool bMoveSubtree(CNodeDynamic* pcParentNode, CNodeDynamic* pcNewChildNode);
	CNodeDynamic* pcGetRoot();
	
	void vPrintTree();
private:
	CNodeDynamic* pc_root;
};

