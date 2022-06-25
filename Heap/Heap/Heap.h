#ifndef HEAP_H
#define HEAP_H


template <typename T>
class MyBinaryHeap {
private:
	T* arr;
	unsigned int arrayLength;
	unsigned int currentLength;

	void resize();
	void swap(T&, T&);
	void minHeapify(unsigned int i);

	int parent(unsigned int i);
	int left(unsigned int i);
	int right(unsigned int i);
	

public:
	MyBinaryHeap(unsigned int);
	~MyBinaryHeap();

	void insert(T item);
	void deleteMin();
	void print();

	int length();
	T operator[](unsigned int index);
};

template<typename T>
MyBinaryHeap<T>::MyBinaryHeap(unsigned int maxLength) {
	arrayLength = maxLength;
	arr = new T[maxLength];

	currentLength = 0;

}

template <typename T>
MyBinaryHeap<T>::~MyBinaryHeap() {

	delete[] arr;
}

template <typename T>
void MyBinaryHeap<T>::insert(T item) {

	if (currentLength == arrayLength) {
		//resize();
	}

	currentLength++;
	unsigned int i = currentLength - 1;
	arr[i] = item;


	//std::cout << "Parent: " << parent(i) << ". " << this->arr[parent(i)] << "      " << arr[i] << "\n";
	
	//Insertion for min heap. Minimum element will be carried to top of the array.
	while (i != 0 && arr[parent(i)] > arr[i]) {

		swap(arr[i], arr[parent(i)]);

		i = parent(i);

	}

}

template <typename T>
int MyBinaryHeap<T>::parent(unsigned int i) {

	return (i - 1) / 2;

}

template <typename T>
int MyBinaryHeap<T>::left(unsigned int i) {

	return 2 * i + 1;
}

template <typename T>
int MyBinaryHeap<T>::right(unsigned int i) {

	return 2 * i + 2;
}

template <typename T>
void MyBinaryHeap<T>::swap(T& higher, T& lower) {

	T temp = higher;

	//std::cout << higher << "'s swapped with " << lower << std::endl;

	higher = lower;
	lower = temp;

	//this->print();

}


template <typename T>
void MyBinaryHeap<T>::print() {

	for (int i = 0; i < currentLength; i++) {

		std::cout << arr[i] << " ";

	}

	std::cout << "\n";
}


template <typename T>
T MyBinaryHeap<T>::operator[](unsigned int index) {

	return arr[index];
}

template <typename T>
void MyBinaryHeap<T>::deleteMin() {

	if (currentLength == 0) {
		std::cout << "Heap's empty!" << std::endl;
		return;
	}
	if (currentLength == 1) {
		currentLength--;
		//std::cout << arr[currentLength] << "'s the smallest element!!" << std::endl;
	}

	arr[0] = arr[currentLength - 1];
	currentLength--;

	minHeapify(0);

}


template <typename T>
void MyBinaryHeap<T>::minHeapify(unsigned int i) {
	int l = left(i);
	int r = right(i);
	int smallest = i;


	if (l < currentLength && arr[l] < arr[i]) {
		smallest = l;
	}
	if (r < currentLength && arr[r] < arr[smallest]) {
		smallest = r;
	}
	if (smallest != i) {
		swap(arr[i], arr[smallest]);
		//std::cout << smallest << "\n";
		minHeapify(smallest);
	}

}

template <typename T>
int MyBinaryHeap<T>::length()
{
	return currentLength;
}

#endif
