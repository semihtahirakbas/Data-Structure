#ifndef _AVLTREE_H
#define _AVLTREE_H
#include "node.h"

template <typename T>
class AVLTree {
public:
	Node<T>* rootPtr;
	AVLTree();

	void Insert(T item);

	bool isEmpty();

	int getHeight();

	void print();


private:
	
	
	int getHeight(Node<T>* rootPtr);
	int getBalanceFactor(Node<T>* node);

	void Insert(Node<T>*& nodePtr,T item);
	void inOrder(Node <T>* nodePtr);

	Node<T>* rightRotation(Node<T>*& y);
	Node<T>* leftRotation(Node<T>*& x);

	

};



#endif // !_AVLTREE_H

