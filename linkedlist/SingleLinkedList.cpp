#include <malloc.h>
#include "SingleLinkedList.h"


template<typename T>
SingleLinkedList<T>::SingleLinkedList() {
    this->head = nullptr;
    this->tail = nullptr;
}

template<typename T>
void SingleLinkedList<T>::add(T item) {
    auto *node = (SingleLinkedListNode<T>*) malloc(sizeof(SingleLinkedListNode<T>));
    node->data = item;
    node->next = nullptr;

    if (this->head == nullptr) {
        this->head = node;
    } else if (this->tail != nullptr) {
        this->tail->next = node;
    }
    this->tail = node;
}

template<typename T>
void SingleLinkedList<T>::addFirst(T item) {
    auto *node = (SingleLinkedListNode<T>*) malloc(sizeof(SingleLinkedListNode<T>));
    node->data = item;
    node->next = this->head;
    this->head = node;
}

template<typename T>
bool SingleLinkedList<T>::add(int index, T item) {
    if (index == 0) {
        this->addFirst(item);
    }

    int i = 0;
    SingleLinkedListNode<T> *node = this->head;
    while (node != nullptr && i < index) {
        if (i == index - 1) {
            SingleLinkedListNode<T> *itemNode = {item, node->next};
            if (node->next == this->tail) {
                this->tail = itemNode;
            }
            node->next = itemNode;
            return true;
        }
        i++;
        node = node->next;
    }
    return false;
}

template<typename T>
int SingleLinkedList<T>::indexOf(T item) {
    SingleLinkedListNode<T> *node = this->head;
    int i = 0;
    while (node != nullptr) {
        if (node->data == item) { return i; }
        node = node->next;
        i++;
    }
    return -1;
}

template<typename T>
int SingleLinkedList<T>::lastIndexOf(T item) {
    int index = -1;
    SingleLinkedListNode<T> *node = this->head;
    int i = 0;
    while (node != nullptr) {
        if (node->data == item) { index = i; }
        node = node->next;
        i++;
    }
    return index;
}

template<typename T>
T SingleLinkedList<T>::get(int index) {
    for (
            SingleLinkedListNode<T> *node = this->head, i = 0;
            node != nullptr;
            node = node->next, i++
            ) {
        if (i == index) { return node->data; }
    }
    return nullptr;
}

template<typename T>
T SingleLinkedList<T>::getFirst() {
    return this->head->data;
}

template<typename T>
T SingleLinkedList<T>::getLast() {
    return this->tail->data;
}

template<typename T>
int SingleLinkedList<T>::size() {
    int size = 0;
    SingleLinkedListNode<T> *node = this->head;
    while (node != nullptr) {
        size++;
        node = node->next;
    }
    return size;
}

template<typename T>
void SingleLinkedList<T>::clear() {
    SingleLinkedListNode<T> *node = this->head;
    while (node != nullptr) {
        SingleLinkedListNode<T> *tmp = node;
        node = node->next;
        delete tmp;
    }
    this->head = nullptr;
    this->tail = nullptr;
}

template<typename T>
T SingleLinkedList<T>::remove() {
    T tmp = this->tail->data;

    SingleLinkedListNode<T> *node = this->head;
    while (node->next != this->tail) {
        node = node->next;
    }
    node->next = nullptr;

    delete this->tail;
    this->tail = node;

    return tmp;
}

template<typename T>
T SingleLinkedList<T>::removeFirst() {
    T tmp = this->head->data;
    if (this->head == this->tail) {
        delete this->head;
        this->head = nullptr;
        this->tail = nullptr;
    } else {
        SingleLinkedListNode<T> *node = this->head->next;
        delete this->head;
        this->head = node;
    }
    return tmp;
}
