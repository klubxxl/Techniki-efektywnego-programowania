#pragma once
#include <vector>

template<typename T>
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
		void vSetValue(T iNewVal);
		void vSetNewParent(CNodeDynamic* parent);
		void vAddNewChild(CNodeDynamic* child);
	private:
		std::vector<CNodeDynamic*> v_children;
		CNodeDynamic* pc_parent_node;
		T i_val;

		int I_DEFAULT_VALUE_INT = 0;
		std::string I_DEFAULT_VALUE_STRING = "null";
		bool I_DEFAULT_VALUE_BOOL = false;
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

// FUNKCJE

template<typename T>
CTreeDynamic<T>::CTreeDynamic() {
	pc_root = new CNodeDynamic(NULL);;
};

template<typename T>
CTreeDynamic<T>::~CTreeDynamic() {
	delete pc_root;
};

template<typename T>
typename CTreeDynamic<T>::CNodeDynamic* CTreeDynamic<T>::pcGetRoot() {
	return(pc_root);
}

template<typename T>
void CTreeDynamic<T>::vPrintTree() {
	pc_root->vPrintAllBelow();
};

template<typename T>
bool CTreeDynamic<T>::bMoveSubtree(CNodeDynamic* pcParentNode, CNodeDynamic* pcNewChildNode) {
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

template<typename T>
CTreeDynamic<T>::CNodeDynamic::CNodeDynamic() {
	i_val = NULL;
	pc_parent_node = NULL;
};
template <>
CTreeDynamic<int>::CNodeDynamic::CNodeDynamic()
{
	i_val = I_DEFAULT_VALUE_INT;
	pc_parent_node = NULL;
}
template <>
CTreeDynamic<bool>::CNodeDynamic::CNodeDynamic()
{
	i_val = I_DEFAULT_VALUE_BOOL;
	pc_parent_node = NULL;
}
template <>
CTreeDynamic<std::string>::CNodeDynamic::CNodeDynamic()
{
	i_val = I_DEFAULT_VALUE_STRING;
	pc_parent_node = NULL;
}

template<typename T>
CTreeDynamic<T>::CNodeDynamic::CNodeDynamic(CNodeDynamic* parent) {
	i_val = NULL;
	pc_parent_node = parent;
};
template <>
CTreeDynamic<int>::CNodeDynamic::CNodeDynamic(CNodeDynamic* parent) {
	i_val = I_DEFAULT_VALUE_INT;
	pc_parent_node = parent;
};
template <>
CTreeDynamic<std::string>::CNodeDynamic::CNodeDynamic(CNodeDynamic* parent) {
	i_val = I_DEFAULT_VALUE_STRING;
	pc_parent_node = parent;
};
template <>
CTreeDynamic<bool>::CNodeDynamic::CNodeDynamic(CNodeDynamic* parent) {
	i_val = I_DEFAULT_VALUE_BOOL;
	pc_parent_node = parent;
};

template<typename T>
CTreeDynamic<T>::CNodeDynamic::~CNodeDynamic() {
	for (int i = 0; i < v_children.size(); i++) {
		delete v_children.at(i);
	}

	pc_parent_node = NULL;
	delete pc_parent_node;
};

template<typename T>
void CTreeDynamic<T>::CNodeDynamic::vSetValue(T iNewVal) {
	i_val = iNewVal;
}

template<typename T>
int CTreeDynamic<T>::CNodeDynamic::iGetChildrenNumber() {
	return v_children.size();
};

template<typename T>
void CTreeDynamic<T>::CNodeDynamic::vAddNewChild() {
	v_children.push_back(new CNodeDynamic(this));
};

template<typename T>
typename CTreeDynamic<T>::CNodeDynamic* CTreeDynamic<T>::CNodeDynamic::pcGetChild(int iChildOffset) {
	if (iChildOffset > v_children.size() || iChildOffset < 0) return NULL;
	else return v_children.at(iChildOffset);
}

template<typename T>
void CTreeDynamic<T>::CNodeDynamic::vPrint() {
	std::cout << " " << i_val;
};

template<typename T>
void CTreeDynamic<T>::CNodeDynamic::vPrintAllBelow() {
	vPrint();
	for (int i = 0; i < v_children.size(); i++) {
		v_children.at(i)->vPrintAllBelow();
	}
};

template<typename T>
void CTreeDynamic<T>::CNodeDynamic::vDeletingChildAt(int iChildOffset) {
	typename std::vector<CNodeDynamic*>::const_iterator it = v_children.begin();
	it += iChildOffset;
	v_children.erase(it);
};

template<typename T>
void CTreeDynamic<T>::CNodeDynamic::vSetNewParent(CNodeDynamic* parent) {
	pc_parent_node = parent;
}

template<typename T>
void CTreeDynamic<T>::CNodeDynamic::vAddNewChild(CNodeDynamic* child) {
	v_children.push_back(child);
};

template<typename T>
typename CTreeDynamic<T>::CNodeDynamic* CTreeDynamic<T>::CNodeDynamic::pcGetParent()
{
	return pc_parent_node;
}

template<typename T>
typename CTreeDynamic<T>::CNodeDynamic* CTreeDynamic<T>::CNodeDynamic::pcGetParent(int* childNumber)
{
	for (int i = 0; i < pc_parent_node->v_children.size(); i++) {
		if (v_children.at(i) == this) {
			*childNumber = i;
			return pc_parent_node;
		}
	}

	return pc_parent_node;
}

template<typename T>
int CTreeDynamic<T>::CNodeDynamic::iGetSize() {
	return v_children.size();
}
