#ifndef STACK_H_
#define STACK_H_

namespace Array {
	template <typename T>
	class Stack {

	private:
		int maxLength;
		int top;
		T* arr;

	public:

		Stack(int maxLength);
		~Stack();
		bool isEmpty();
		bool isFull();

		void Show();
		void getTop(T& item);
		void push(T& item);
		void pop();


		T topValue();
	};

}


namespace Linked {

	template <typename T>
	struct Node {
		T data;
		Node<T>* nextNode;

	};

	template <typename T>
	class Stack {
	private:
		Node<T>* topPtr;


	public:
		Stack();
		~Stack();

		bool isEmpty();
		bool isFull();

		void getTop(T& item);
		void pop();
		void push(T item);

	};

}


#endif