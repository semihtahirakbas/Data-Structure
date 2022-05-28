#ifndef _BINARY_TREE_H
#define _BINARY_TREE_H
#include "node.h"

template <typename T>
class BinarySearchTree
{
public:
	BinarySearchTree();
	~BinarySearchTree();

	bool isFull();
	bool isEmpty();

	int getLength() const;

	int getHeight();
	int getBalanceFactor();

	T getMin();
	T getMax();

	void retrieve(T& item, bool& found) const;
	void insert(T item);
	void remove(T remove);
	void print(int = 1) const;
	void removeAll(Node<T>*& nodePtr);

private:
	Node<T>* rootPtr;

	void remove(Node<T>*& tree, T item);
	void retrieve(Node<T>* nodePtr, T& item, bool& found) const;
	void insert(Node<T>*& nodePtr, T item);
	void removeNode(Node<T>*& tree);
	void getPredecessor(Node<T>* tree, T& item);

	int getLength(Node<T>* nodePtr) const;
	int getHeight(Node<T>* nodePtr);
	

	T getMin(Node<T>* nodePtr);
	T getMax(Node<T>* nodePtr);
	

};


#endif // !_BINARY_TREE_H
