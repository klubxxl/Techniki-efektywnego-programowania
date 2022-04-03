#include <iostream>

#include "CTreeDynamic.h"

void v_tree_test()
{
	CTreeDynamic<int>* c_tree = new CTreeDynamic<int>();

	c_tree->pcGetRoot()->vAddNewChild();
	c_tree->pcGetRoot()->vAddNewChild();

	c_tree->pcGetRoot()->pcGetChild(0)->vSetValue(1);
	c_tree->pcGetRoot()->pcGetChild(1)->vSetValue(2);

	c_tree->pcGetRoot()->pcGetChild(0)->vAddNewChild();
	c_tree->pcGetRoot()->pcGetChild(0)->vAddNewChild();

	c_tree->pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(11);
	c_tree->pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(12);

	c_tree->pcGetRoot()->pcGetChild(1)->vAddNewChild();
	c_tree->pcGetRoot()->pcGetChild(1)->vAddNewChild();

	c_tree->pcGetRoot()->pcGetChild(1)->pcGetChild(0)->vSetValue(21);
	c_tree->pcGetRoot()->pcGetChild(1)->pcGetChild(1)->vSetValue(22);

	c_tree->vPrintTree();
	std::cout << std::endl;

	CTreeDynamic<int>* c_tree_helper = new CTreeDynamic<int>();

	c_tree_helper->pcGetRoot()->vAddNewChild();
	c_tree_helper->pcGetRoot()->pcGetChild(0)->vSetValue(1);

	c_tree_helper->pcGetRoot()->pcGetChild(0)->vAddNewChild();
	c_tree_helper->pcGetRoot()->pcGetChild(0)->vAddNewChild();


	c_tree_helper->pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(2);
	c_tree_helper->pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(2);

	c_tree_helper->pcGetRoot()->vPrintAllBelow();
	std::cout << std::endl;

	c_tree_helper->bMoveSubtree(c_tree_helper->pcGetRoot()->pcGetChild(0)->pcGetChild(1), c_tree->pcGetRoot()->pcGetChild(0));

	c_tree->pcGetRoot()->vPrintAllBelow();
	std::cout << std::endl;

	c_tree_helper->pcGetRoot()->vPrintAllBelow();
	std::cout << std::endl;

	CTreeDynamic<std::string>* c_tree_string = new CTreeDynamic<std::string>();

	c_tree_string->pcGetRoot()->vAddNewChild();
	c_tree_string->pcGetRoot()->pcGetChild(0)->vSetValue("a");

	c_tree_string->pcGetRoot()->pcGetChild(0)->vAddNewChild();
	c_tree_string->pcGetRoot()->pcGetChild(0)->vAddNewChild();


	c_tree_string->pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue("b");
	c_tree_string->pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue("b");

	c_tree_string->pcGetRoot()->vPrintAllBelow();
}

int main()
{
	v_tree_test();
}

