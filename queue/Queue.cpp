#include "Queue.h"

template<typename T>
void Queue<T>::enqueue(T item, int priority) {
    auto *queueItem = (QueueItem<T>*) malloc(sizeof(QueueItem<T>));
    queueItem->data = item;
    queueItem->priority = priority;

    auto predicate = [priority](QueueItem<T> el, QueueItem<T> _) { return el.priority < priority; };
    this->lst.addWhere(*queueItem, predicate);
}

template<typename T>
T Queue<T>::dequeue() {
    return this->lst.removeFirst();
}

template<typename T>
T Queue<T>::peek() {
    return this->lst.getFirst();
}

template<typename T>
int Queue<T>::size() {
    return this->lst.size();
}

template<typename T>
bool Queue<T>::isEmpty() {
    return this->lst.size() == 0;
}

template<typename T>
bool Queue<T>::isFull() {
    if (this->maxSize < 0) return false;
    return this->lst.size >= this->maxSize;
}
