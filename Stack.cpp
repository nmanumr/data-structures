#include "Stack.h"

template <typename T>
void Stack<T>::push(T item) {
    this->lst.add(item);
}

template <typename T>
T Stack<T>::pop() {
    return this->lst.remove();
}

template <typename T>
T Stack<T>::peek() {
    return this->lst.getLast();
}

template <typename T>
int Stack<T>::search(T item) {
    return this->lst.indexOf(item);
}

template <typename T>
int Stack<T>::searchRight(T item) {
    return this->lst.lastIndexOf(item);
}

template <typename T>
int Stack<T>::size() {
    return this->lst.size();
}