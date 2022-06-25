#include <iostream>
#include "Heap.h"


template <typename T>
void HeapSort(MyBinaryHeap<T>& _heap) {
    
    unsigned int size = _heap.length();

    T* temp = new T[size + 1];

    //O(n*logn)
    for (int i = 0; i < size + 1; i++) {

        temp[i] = _heap[0];
        _heap.deleteMin();//logn
    }

    std::cout << "SORTED";

    for (int i = 0; i < size + 1; i++) {
        std::cout << temp[i] << " ";
    }
   
}

template <typename T>
void HeapSort(T temp[], unsigned int size) {
    //O()

    MyBinaryHeap<T> t_heap(size);
    
    //O(N)
    for (int i = 0; i < size; i++) {

        t_heap.insert(temp[i]);
    }

    //O(N*LOGN)
    for (int i = 0; i < size; i++) {

        temp[i] = t_heap[0];
        t_heap.deleteMin();
    }

}

template <typename T>
void print(T& arr, unsigned int size) {
    
    for (int i = 0; i < size; i++) {

        std::cout << arr[i] << " ";

    }
    std::cout << "\n";
}

int main()
{  
    srand(time(NULL));

    int* temp = new int[5];
    
    for (int i = 0; i < 5; i++) {
        
        temp[i] = rand() % 35 + 1;
    }
    std::cout << "BEFORE SORTING ARRAY" << std::endl;
    print(temp, 5);
    HeapSort(temp, 5);
    std::cout << "AFTER SORTING ARRAY" << std::endl;
    print(temp, 5);
}
