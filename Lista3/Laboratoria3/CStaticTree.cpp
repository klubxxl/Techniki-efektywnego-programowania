#include <iostream>

#include "CStaticTree.h"

CTreeStatic::CTreeStatic() {
};

CTreeStatic::~CTreeStatic() {
};

CTreeStatic::CNodeStatic* CTreeStatic::pcGetRoot()
{
	return &c_root;
}

void CTreeStatic::vPrintTree() {
	c_root.vPrintAllBelow();
};

CTreeStatic::CNodeStatic::CNodeStatic()
{
	i_val = I_DEFAULT_VALUE;
	pc_parent_node = NULL;
}

CTreeStatic::CNodeStatic::CNodeStatic(CNodeStatic* parent)
{
	i_val = I_DEFAULT_VALUE;
	pc_parent_node = parent;
}

// CNodeStatic::CNodeStatic(const CNodeStatic& pcOther)
// {
// 	i_val = pcOther.i_val;
// 	pc_parent_node = pcOther.pc_parent_node;
// 	v_children = pcOther.v_children;
// }

CTreeStatic::CNodeStatic::~CNodeStatic()
{
	v_children.clear();
	pc_parent_node = NULL;
	delete pc_parent_node;
}

void CTreeStatic::CNodeStatic::vSetValue(int iNewVal) {
	i_val = iNewVal;
}

int CTreeStatic::CNodeStatic::iGetChildrenNumber() {
	return(v_children.size());
}

void CTreeStatic::CNodeStatic::vAddNewChild() {
	CNodeStatic::v_children.push_back(CNodeStatic(this));
}

CTreeStatic::CNodeStatic* CTreeStatic::CNodeStatic::pcGetChild(int iChildOffset) {
	if (iChildOffset > v_children.size() || iChildOffset < 0) return NULL;
	else return &v_children.at(iChildOffset);
}

void CTreeStatic::CNodeStatic::vPrint() {
	std::cout << i_val << " ";
}

void CTreeStatic::CNodeStatic::vPrintAllBelow() {
	vPrint();
	for (int i = 0; i < v_children.size(); i++) {
		v_children.at(i).vPrintAllBelow();
	}
}

void CTreeStatic::CNodeStatic::vPrintUp() {
	vPrint();
	if (pc_parent_node != NULL) pc_parent_node->vPrintUp();
}

void CTreeStatic::CNodeStatic::helper() {
	std::cout << &pc_parent_node << " ";
};

