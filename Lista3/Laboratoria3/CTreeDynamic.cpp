#include <iostream>

#include "CTreeDynamic.h"

CTreeDynamic::CTreeDynamic() {
	pc_root = new CNodeDynamic(NULL);;
};

CTreeDynamic::~CTreeDynamic() {
	delete pc_root;
};

CTreeDynamic::CNodeDynamic* CTreeDynamic::pcGetRoot() {
	return(pc_root); 
}

void CTreeDynamic::vPrintTree() {
	pc_root->vPrintAllBelow();
};

bool CTreeDynamic::bMoveSubtree(CNodeDynamic* pcParentNode, CNodeDynamic* pcNewChildNode) {
	int offset = 0;
	CNodeDynamic* pcOldParent = pcNewChildNode->pcGetParent(&offset);

	if (offset > pcGetRoot()->iGetSize()) {
		return false;
	}
	else {
		pcOldParent->vDeletingChildAt(offset);

		pcNewChildNode->vSetNewParent(pcParentNode);
		pcParentNode->vAddNewChild(pcNewChildNode);
		return true;
	}
}


CTreeDynamic::CNodeDynamic::CNodeDynamic() {
	i_val = I_DEFAULT_VALUE;
	pc_parent_node = NULL;
};

CTreeDynamic::CNodeDynamic::CNodeDynamic(CNodeDynamic* parent) {
	i_val = I_DEFAULT_VALUE;
	pc_parent_node = parent;
};

CTreeDynamic::CNodeDynamic::~CNodeDynamic() {
	for (int i = 0; i < v_children.size(); i++) {
		delete v_children.at(i);
	}

	pc_parent_node = NULL;
	delete pc_parent_node;
};

void CTreeDynamic::CNodeDynamic::vSetValue(int iNewVal) {
	i_val = iNewVal;
}

int CTreeDynamic::CNodeDynamic::iGetChildrenNumber() {
	return v_children.size();
};

void CTreeDynamic::CNodeDynamic::vAddNewChild() {
	v_children.push_back(new CNodeDynamic(this));
};

CTreeDynamic::CNodeDynamic* CTreeDynamic::CNodeDynamic::pcGetChild(int iChildOffset) {
	if (iChildOffset > v_children.size() || iChildOffset < 0) return NULL;
	else return v_children.at(iChildOffset);
}

void CTreeDynamic::CNodeDynamic::vPrint() {
	std::cout << " " << i_val;
};

void CTreeDynamic::CNodeDynamic::vPrintAllBelow() {
	vPrint();
	for (int i = 0; i < v_children.size(); i++) {
		v_children.at(i)->vPrintAllBelow();
	}
};

void CTreeDynamic::CNodeDynamic::vDeletingChildAt(int iChildOffset) {
	std::vector<CNodeDynamic*>::const_iterator it = v_children.begin();
	it += iChildOffset;
	v_children.erase(it);
};

void CTreeDynamic::CNodeDynamic::vSetNewParent(CNodeDynamic* parent) {
	pc_parent_node = parent;
}

void CTreeDynamic::CNodeDynamic::vAddNewChild(CNodeDynamic* child){
	v_children.push_back(child);
};

CTreeDynamic::CNodeDynamic* CTreeDynamic::CNodeDynamic::pcGetParent()
{
	return pc_parent_node;
}

CTreeDynamic::CNodeDynamic* CTreeDynamic::CNodeDynamic::pcGetParent(int* childNumber)
{
	for (int i = 0; i < pc_parent_node->v_children.size(); i++){
		if (v_children.at(i) == this){
			*childNumber = i;
			return pc_parent_node;
		}
	}

	return pc_parent_node;
}

int CTreeDynamic::CNodeDynamic::iGetSize() {
	return v_children.size();
}