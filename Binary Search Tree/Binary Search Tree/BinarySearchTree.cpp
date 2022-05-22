#include <iostream>
#include "binarytree.h"
#include "BSTSource.cpp"


int main()
{
    BinarySearchTree<std::string> bst;

    bst.insert("Tahir");
    bst.insert("Akbas");
    bst.insert("Zart");
    bst.insert("Gum");
    bst.insert("Plack");
    bst.insert("Bar");

    bst.print(1);

}
