#include <iostream>
#include "Queue.h"
#include "QueueSource.cpp"
#include <queue>

void PrintQueue(Array::Queue<char>* _queue) {

    while (!_queue->isEmpty()) {
        std::cout << _queue->dequeue() << " ";
    }

}

int main()
{
    Array::Queue<char> queue(3);

    queue.enqueue('a');
    queue.enqueue('b');
    queue.enqueue('c');

    PrintQueue(&queue);
    //After printing the queue, elements in queue is turned garbage  
    queue.enqueue('e');
    queue.enqueue('e');
    queue.enqueue('e');

    PrintQueue(&queue);

}
