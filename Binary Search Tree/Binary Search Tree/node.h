#ifndef _NODE_H
#define _NODE_H

template <typename T>
struct Node
{
	T data;
	Node<T>* right;
	Node<T>* left;
};

#endif // !_NODE_H
