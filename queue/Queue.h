#ifndef DSA_QUEUE_H
#define DSA_QUEUE_H

#include "../linkedlist/SingleLinkedList.cpp"

template<typename T>
struct QueueItem {
    int priority;
    T data;
};

/**
 * SingleLinkedList based Queue implementation
 * can also handle tasks priorities
 */
template<typename T>
class Queue {
private:
    SingleLinkedList<QueueItem<T>> lst;
    int maxSize{};

public:
    explicit Queue(int size = -1) {
        this->maxSize = size;
    }

    void enqueue(T item, int priority=0);

    T dequeue();

    T peek();

    bool isFull();

    bool isEmpty();

    int size();
};


#endif //DSA_QUEUE_H
