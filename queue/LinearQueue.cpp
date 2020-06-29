#include "LinearQueue.h"

template<typename T>
void LinearQueue<T>::enqueue(T item) {
    this->lst.add(item);
}

template<typename T>
T LinearQueue<T>::dequeue() {
    return this->lst.removeFirst();
}

template<typename T>
T LinearQueue<T>::peek() {
    return this->lst.getFirst();
}

template<typename T>
int LinearQueue<T>::size() {
    return this->lst.size();
}

template<typename T>
bool LinearQueue<T>::isEmpty() {
    return this->lst.size() == 0;
}

template<typename T>
bool LinearQueue<T>::isFull() {
    if (this->maxSize < 0) return false;
    return this->lst.size >= this->maxSize;
}
