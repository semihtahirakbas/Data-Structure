#include <iostream>
#include "binarytree.h"

template <typename T>
void preOrder(Node<T>* nodePtr) {
	if (nodePtr != NULL) {
		std::cout << nodePtr->data << " ";
		preOrder(nodePtr->left);
		preOrder(nodePtr->right);
	}

}

template <typename T>
void inOrder(Node<T>* nodePtr) {
	if (nodePtr != NULL) {
	
		inOrder(nodePtr->left);
		std::cout << nodePtr->data << " ";
		inOrder(nodePtr->right);
	}

}

template <typename T>
void postOrder(Node<T>* nodePtr) {

	if (nodePtr != NULL) {

		postOrder(nodePtr->left);
		postOrder(nodePtr->right);
		std::cout << nodePtr->data << " ";
	}

}


template <typename T>
BinarySearchTree<T>::BinarySearchTree() {

	rootPtr = NULL;
}

template <typename T>
BinarySearchTree<T>::~BinarySearchTree() {

	removeAll(rootPtr);
}


#pragma region Boolean Methods
template <typename T>
bool BinarySearchTree<T>::isFull() {
	Node<T>* location;
	try {
		location = new Node<T>;
		delete location;
		return false;
	}
	catch (std::bad_alloc exception) {
		return true;
	}

}

template <typename T>
bool BinarySearchTree<T>::isEmpty() {

	return (rootPtr == NULL);
}
#pragma endregion


template <typename T>
int BinarySearchTree<T>::getLength() const{

	return getLength(rootPtr);
}

template <typename T>
int BinarySearchTree<T>::getLength(Node<T>* nodePtr) const {

	if (nodePtr == NULL) {
		return 0;
	}
	
	else {
		return getLength(nodePtr->left) + getLength(nodePtr->right) + 1;
	}

}

template <typename T>
T BinarySearchTree<T>::getMax(Node<T>* nodePtr) {
	if (nodePtr->right == NULL) {
		return nodePtr->data;
	}
	return getMax(nodePtr->right);

}

template <typename T>
T BinarySearchTree<T>::getMax() {
	if (rootPtr == NULL)
		return -999; //rootPtr is NULL

	getMax(rootPtr);


}

template <typename T>
T BinarySearchTree<T>::getMin(Node<T>* nodePtr) {

	if (nodePtr->left == NULL) {
		return nodePtr->data;
	}

	return getMin(nodePtr->left);	
}

template <typename T>
T BinarySearchTree<T>::getMin() {
	if (rootPtr == NULL) return -999; //rootPtr is NULL.

	return getMin(rootPtr);
}

#pragma region Void Methods
template <typename T>
void BinarySearchTree<T>::removeAll(Node<T>*& nodePtr) {

	if (nodePtr != NULL) { //postorder traversal

		removeAll(nodePtr->left);
		removeAll(nodePtr->right);

		delete nodePtr;
	}

}

template <typename T>
void BinarySearchTree<T>::retrieve(T& item, bool& found) const {

	retrieve(rootPtr, item, found);
}

template <typename T>
void BinarySearchTree<T>::retrieve(Node<T>* nodePtr, T& item, bool& found) const {
	
	if (nodePtr == NULL)
		found = false;

	else if (item < nodePtr->data)
		retrieve(nodePtr->left, item, found);
	else if (item > nodePtr->data)
		retrieve(nodePtr->right, item, found);
	else {
		item = nodePtr->data;
		found = true;
	}

}

template <typename T>
void BinarySearchTree<T>::insert(T item) {

	insert(rootPtr, item);
}

template <typename T>
void BinarySearchTree<T>::insert(Node<T>*& nodePtr, T item) {

	if (nodePtr == NULL) { //insertion place found
		nodePtr = new Node<T>;
		nodePtr->right = NULL;
		nodePtr->left = NULL;
		nodePtr->data = item;
	}
	else if (item < nodePtr->data)
		insert(nodePtr->left, item);
	else if (item > nodePtr->data)
		insert(nodePtr->right, item);

}

template <typename T>
void BinarySearchTree<T>::remove(T item) {

	remove(rootPtr, item);
}

template <typename T>
void BinarySearchTree<T>::getPredecessor(Node<T>* tree, T& item) {

	while (tree->right != NULL) {
		tree = tree->right;
	}

	item = tree->data;

}

template <typename T>
void BinarySearchTree<T>::removeNode(Node<T>*& tree) {
	T item;
	Node<T>* tempPtr;

	tempPtr = tree;

	if (tree->left == NULL) {
		tree = tree->right;	
		delete tempPtr;
	}
	else if (tree->right == NULL) {
		tree = tree->left;
		delete tempPtr;
	}
	else {
		getPredecessor(tree->left, item);
		tree->data = item;
		remove(tree->left, item);//remove predecessor
	}
}
template <typename T>
void BinarySearchTree<T>::remove(Node<T>*& tree, T item) {

	if (tree == NULL) {
		return;
	}

	else if (item < tree->data)
		remove(tree->left, item);

	else if (item > tree->data)
		remove(tree->right, item);
	else
		removeNode(tree);

}

template <typename T>
void BinarySearchTree<T>::print(int order) const{
	if (order == 0) {
		std::cout << "Pre Order" << std::endl;
		preOrder(rootPtr);
	}
	else if (order == 1) {
		std::cout << "In Order" << std::endl;
		inOrder(rootPtr);
	}
	else if (order == 2) {
		std::cout << "Post Order" << std::endl;
		postOrder(rootPtr);
	}
	
	std::cout << "\n";

}


#pragma endregion

