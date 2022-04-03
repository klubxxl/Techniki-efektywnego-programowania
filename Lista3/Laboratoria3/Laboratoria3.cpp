#include <iostream>

#include "CStaticTree.h"
#include "CTreeDynamic.h"

void v_tree_test()
{
    CTreeStatic tree_static;
    tree_static.pcGetRoot()->vAddNewChild();
    tree_static.pcGetRoot()->vAddNewChild();
    tree_static.pcGetRoot()->pcGetChild(0)->vSetValue(1);
    tree_static.pcGetRoot()->pcGetChild(1)->vSetValue(2);
    tree_static.pcGetRoot()->pcGetChild(0)->vAddNewChild();
    tree_static.pcGetRoot()->pcGetChild(0)->vAddNewChild();
    tree_static.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(11);
    tree_static.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(12);
    tree_static.pcGetRoot()->pcGetChild(1)->vAddNewChild();
    tree_static.pcGetRoot()->pcGetChild(1)->vAddNewChild();
    tree_static.pcGetRoot()->pcGetChild(1)->pcGetChild(0)->vSetValue(21);
    tree_static.pcGetRoot()->pcGetChild(1)->pcGetChild(1)->vSetValue(22);

    tree_static.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vPrintUp();

    std::cout << std::endl;
    
    tree_static.vPrintTree();

    std::cout << std::endl << std::endl;

	CTreeDynamic* c_tree = new CTreeDynamic();

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

	CTreeDynamic* c_tree_helper = new CTreeDynamic();

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
}

int main()
{
    v_tree_test();
}

