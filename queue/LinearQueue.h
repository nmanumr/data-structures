#ifndef DSA_LINEARQUEUE_H
#define DSA_LINEARQUEUE_H

#include "../linkedlist/SingleLinkedList.cpp"


template<typename T>
class LinearQueue {
private:
    SingleLinkedList<T> lst;
    int maxSize{};

public:
    explicit LinearQueue(int size = -1) {
        this->maxSize = size;
    }

    void enqueue(T item);

    T dequeue();

    T peek();

    bool isFull();

    bool isEmpty();

    int size();
};


#endif
