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

	T getMin();
	T getMax();

	void retrieve(T& item, bool& found) const;
	void insert(T item);
	void remove(T remove);
	void print(int = 1) const;
	void removeAll(Node<T>*& nodePtr);

protected:

private:
	Node<T>* rootPtr;

	void remove(Node<T>*& tree, T item);
	void retrieve(Node<T>* nodePtr, T& item, bool& found) const;
	void insert(Node<T>*& nodePtr, T item);
	void removeNode(Node<T>*& tree);
	void getPredecessor(Node<T>* tree, T& item);

	int getLength(Node<T>* nodePtr) const;

	T getMin(Node<T>* nodePtr);
	T getMax(Node<T>* nodePtr);
	




};


#endif // !_BINARY_TREE_H
