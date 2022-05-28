#include <iostream>
#include "AVLTree.h"

template <typename T>
AVLTree<T>::AVLTree() {

	rootPtr = NULL;
}

template <typename T>
bool AVLTree<T>::isEmpty() {

	if (rootPtr == NULL) {
		return true;
	}
	else {
		return false;
	}

}


template <typename T>
int AVLTree<T>::getHeight(Node<T>* nodePtr) {
	if (nodePtr == NULL)
		return -1;

	else {
		int lheight = getHeight(nodePtr->left);
		int rheight = getHeight(nodePtr->right);


		if (lheight > rheight) {
			return lheight + 1;
		}
		else {
			return rheight + 1;
		}

	}
}

template <typename T>
Node<T>* AVLTree<T>::rightRotation(Node<T>*& y) {
	std::cout << "Perform right rotate" << std::endl;
	Node<T>* x = y->left;
	Node<T>* T2 = x->right;

	//Perform rotation
	x->right = y;
	y->left = T2;

	return x;
}

template <typename T>
Node<T>* AVLTree<T>::leftRotation(Node<T>*& x) {
	std::cout << "Perform left rotate" << std::endl;
	Node<T>* y = x->right;
	Node<T>* T2 = y->left;	

	//Perform rotation
	y->left = x;
	x->right = T2;

	return y;
}

template <typename T>
void AVLTree<T>::inOrder(Node<T>* nodePtr) {

	if (nodePtr != NULL) {
	
		inOrder(nodePtr->left);
		std::cout << nodePtr->data << " ";
		inOrder(nodePtr->right);
	}

}

template <typename T>
void AVLTree<T>::print() {

	inOrder(rootPtr);

}

template <typename T>
void AVLTree<T>::Insert(Node<T>*& nodePtr, T item) {

	if (nodePtr == NULL) {
		std::cout << item << "'s inserted successfully!" << std::endl;
		nodePtr = new Node<T>;
		nodePtr->right = NULL;
		nodePtr->left = NULL;
		nodePtr->data = item;

	}

	else if (item < nodePtr->data) {
		Insert(nodePtr->left, item);
	}
	else if (item > nodePtr->data) {
		Insert(nodePtr->right, item);
	}

	int bf = getBalanceFactor(nodePtr);
	std::cout << bf << std::endl;

	//We've to change rootPtr for every rotation. If we don't change we can't insert an item to AVLTree.
	//LEFT LEFT
	if (bf > 1 && item > nodePtr->left->data) {
		rootPtr = rightRotation(nodePtr);
		return;
	}

	//RIGHT RIGHT
	if (bf < -1 && item > nodePtr->right->data) {
		rootPtr = leftRotation(nodePtr);
		return;
	}

	//LEFT RIGHT
	else if (bf > 1 && item > nodePtr->left->data) {
		leftRotation(nodePtr->left);
		rootPtr = rightRotation(nodePtr);
		return;
	}

	//RIGHT LEFT
	else if (bf < -1 && item > nodePtr->right->data) {
		rightRotation(nodePtr->right);
		rootPtr = leftRotation(nodePtr);
		return;
	}
	
}


template <typename T>
void AVLTree<T>::Insert(T item)
{
	Insert(rootPtr, item);
}



template <typename T>
int AVLTree<T>::getHeight() {

	return getHeight(rootPtr);
}

template <typename T>
int AVLTree<T>::getBalanceFactor(Node<T>* node) {

	if (node == NULL) {
		return -999;
	}

	return getHeight(node->left) - getHeight(node->right);
}