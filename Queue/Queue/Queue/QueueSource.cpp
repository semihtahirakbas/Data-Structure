#include "Queue.h"
#include <iostream>

template <typename T>
Array::Queue<T>::Queue(unsigned int maxLength) {
	this->maxLength = maxLength + 1; //For front element.
	arr = new T[this->maxLength];
	this->front = this->maxLength - 1;
	this->rear = this->maxLength - 1;
	this->k = 1;
}

template <typename T>
Array::Queue<T>::~Queue() {

	delete[] arr;
}

template <typename T>
bool Array::Queue<T>::isEmpty() {

	return (rear == front);
}


template <typename T>
bool Array::Queue<T>::isFull(){

	return ((rear + 1) % maxLength == front);

}

template <typename T>
T Array::Queue<T>::dequeue() {

	if (isEmpty()) {
		std::cout << "The queue is already empty!!" << std::endl;
	}

	front = (front + 1) % maxLength;
	
	return arr[front];

}

template <typename T>
void Array::Queue<T>::enqueue(T item) {//To adding element.

	/*if (isFull()) {
		std::cout << "Queue is already full!" << std::endl;
		return;
	}*/


	rear = (rear + 1) % maxLength;
	
	//std::cout << item << "'s been added to queue!" << std::endl;

	//If rear equalt to maxLength - 1 
	if (rear == maxLength - 1) {
		k++;
		rear = ((k * maxLength - 1) + 1) % maxLength;
		arr[rear] = item;
		front = maxLength - 1;
		//std::cout << "Current location of rear : " << rear << " " << std::endl;;
	}
	else {
		arr[rear] = item;
	}
	
}


template <typename T>
T Array::Queue<T>::Back(){
	if (isEmpty()) {
		std::cout << "The queue is already empty!!" << std::endl;
		return 1;
	}

	return this->arr[rear];
}


template <typename T>
T Array::Queue<T>::Front(){

	return this->arr[front];
}
