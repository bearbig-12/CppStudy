#include <iostream>
#include "BST.h"



int main()
{
	BST tree;
	tree.mpRoot = tree.Insert(nullptr, 8, "AN");
	tree.Insert(tree.mpRoot, 5, "Kang");
	tree.Insert(tree.mpRoot, 1, "Park");
	tree.Insert(tree.mpRoot, 6, "Jack");
	tree.Insert(tree.mpRoot, 10, "Kim");
	tree.Insert(tree.mpRoot, 15, "Ryu");
	tree.Insert(tree.mpRoot, 9, "Xin");

	tree.Delete(tree.mpRoot, 5);
	tree.InOrder(tree.mpRoot);

}