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

    /**
     * Add `item` to the queue based on the priority
     * @param item item to be added
     * @param priority priority of the item default is 0
     */
    void enqueue(T item, int priority = 0);

    /**
     * Remove first item from the queue and return it
     * @return first item of queue
     */
    T dequeue();

    /**
     * Returns first item of queue without removing it
     * @return first item of queue
     */
    T peek();

    /**
     * Checks if the queue is full
     *
     * if `max_size` is not set while construction
     * it will always return true
     */
    bool isFull();

    /**
     * Checks it queue is empty
     */
    bool isEmpty();

    /**
     * return the size of queue
     * @return size of queue
     */
    int size();
};


#endif //DSA_QUEUE_H
