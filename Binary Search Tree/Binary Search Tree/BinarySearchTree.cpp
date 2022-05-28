#include <iostream>
#include "binarytree.h"
#include "AVLTree.h"
#include "BSTSource.cpp"
#include "AVLSource.cpp"


int main()
{
    AVLTree<int> tree;
   
    
    tree.Insert(3);
    tree.Insert(5);
    tree.Insert(7);
    tree.Insert(9);
    tree.Insert(8);

    tree.print();
}

