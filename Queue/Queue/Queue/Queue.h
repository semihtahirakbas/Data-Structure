#ifndef _QUEUE_H
#define _QUEUE_H


namespace Array {
	template <typename T>
	class Queue {
	private:
		unsigned int maxLength;
		unsigned int rear;
		unsigned int front;
		unsigned int k;
		T* arr;

	public:
		Queue(unsigned int maxLength = 10);
		~Queue();

		bool isEmpty();
		bool isFull();

		void enqueue(T);
		T dequeue();

		T Back();
		T Front();

	};
}




#endif 
