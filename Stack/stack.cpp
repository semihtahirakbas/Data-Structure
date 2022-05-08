#include "stack.h"
#include <iostream>

#pragma region Array Stack
template <typename T>
Array::Stack<T>::Stack(int maxLength) {

	//std::cout << "Stack's been created!!" << std::endl;
	this->maxLength = maxLength;
	arr = new T[maxLength];
	top = -1;
}

template <typename T>
Array::Stack<T>::~Stack() {

	delete[] arr;
}

template <typename T>
T Array::Stack<T>::topValue() {
	
	return arr[top];
}

template <typename T>
bool Array::Stack<T>::isEmpty() {

	return (top == -1);
}

template <typename T>
bool Array::Stack<T>::isFull() {

	return (top == maxLength - 1);
}

template <typename T>
void Array::Stack<T>::pop() {

	if (isEmpty()) {
		std::cout << "Stack is already empty" << std::endl;
		return;
	}

	top--;

}

template <typename T>
void Array::Stack<T>::Show() {

	if (isEmpty()) {
		std::cout << "Stack is currently empty!!" << std::endl;
		return;
	}


	for (int i = 0; i <= top; i++) {
		std::cout << arr[i] << " ";
	}

}


template <typename T>
void Array::Stack<T>::getTop(T& item) {

	if (isEmpty()) {
		std::cout << "Stack is already empty" << std::endl;
		return;
	}

	item = arr[top];

}

template <typename T>
void Array::Stack<T>::push(T& item) {

	if (isFull()) {
		std::cout << item << "'s not been pushed!!\n" << "Stack is currently full!!" << std::endl;
		return;
	}

	//std::cout << item << "'s been pushed!!" << std::endl;
	top++;
	arr[top] = item;
}
#pragma endregion

#pragma region Linked Stack

template <typename T>
Linked::Stack<T>::Stack() {

	this->topPtr = NULL;

}

template <typename T>
bool Linked::Stack<T>::isEmpty() {

	return (this->topPtr == NULL);

}

template <typename T>
bool Linked::Stack<T>::isFull() {
	Node<T>* tempPtr = NULL;

	try {
		tempPtr = new Node<T>;
		delete tempPtr;
		return false;
	}
	catch (std::bad_alloc exception) {
		return true;
	}
}

template <typename T>
Linked::Stack<T>::~Stack() {
	while (!isEmpty()) {
		pop();
	}

}

template <typename T>
void Linked::Stack<T>::getTop(T& item) {

	if (isEmpty()) {
		std::cout << "Linked stack is already empty!!" << std::endl;
	}

	item = this->topPtr->data;
}

template <typename T>
void Linked::Stack<T>::push(T item) {

	if (isFull()) {
		std::cout << "Linked stack is already full!!" << std::endl;
	}

	Node<T>* temp = new Node<T>;
	temp->data = item;
	temp->nextNode = this->topPtr;
	this->topPtr = temp;

}

template <typename T>
void Linked::Stack<T>::pop() {

	if (isEmpty()) {
		std::cout << "Linked stack is already empty!!" << std::endl;
	}

	Node<T>* tempPtr;

	tempPtr = this->topPtr;
	this->topPtr = this->topPtr->nextNode;

	delete tempPtr;
}

#pragma endregion