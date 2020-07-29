#include "DoubleLinkedList.h"

template<typename T>
DoubleLinkedList<T>::DoubleLinkedList() {
    this->head = nullptr;
    this->tail = nullptr;
};

template<typename T>
void DoubleLinkedList<T>::add(T item) {
    auto node = new DoubleLinkedListNode<T>();
    node->data = item;
    node->prev = this->tail;
    node->next = nullptr;

    if (this->head == nullptr) {
        this->head = node;
    } else if (this->tail != nullptr) {
        this->tail->next = node;
    }
    this->tail = node;
}

template<typename T>
void DoubleLinkedList<T>::addFirst(T item) {
    auto node = new DoubleLinkedListNode<T>();
    node->data = item;
    node->prev = nullptr;
    this->head->prev = node;
    node->next = this->head;
    this->head = node;

    if (this->tail == nullptr) {
        this->tail = node;
    }
}

template<typename T>
void DoubleLinkedList<T>::add(int index, T item) {
    if (index <= 0) {
        this->addFirst(item);
        return;
    }

    int i = 0;
    DoubleLinkedListNode<T> *node = this->head;
    while (node != nullptr && i < index) {
        if (i == index - 1) {
            auto itemNode = new DoubleLinkedListNode<T>();
            itemNode->data = item;
            itemNode->next = node->next;
            itemNode->prev = node;

            if (node == this->tail) {
                this->tail = itemNode;
            }
            node->next->prev = itemNode;
            node->next = itemNode;
            return;
        }
        i++;
        node = node->next;
    }
    this->add(item);
}

template<typename T>
void DoubleLinkedList<T>::addWhere(T item, std::function<bool(T, T)> predicate) {
    DoubleLinkedListNode<T> *node = this->head;
    DoubleLinkedListNode<T> *lastNode = nullptr;

    if (this->head == nullptr) {
        this->addFirst(item);
        return;
    }

    while (node != nullptr) {
        if (predicate(node->data, item)) {
            auto *itemNode = new DoubleLinkedListNode<T>();
            itemNode->data = item;
            itemNode->next = node;
            itemNode->prev = node->prev;

            if (node->prev == nullptr) {
                this->addFirst(item);
            } else if (node->next == nullptr) {
                this->add(item);
            } else {
                node->prev->next = itemNode;
                node->prev = itemNode;
            }
            return;
        }

        node = node->next;
    }

    this->add(item);
}

template<typename T>
int DoubleLinkedList<T>::indexOf(T item) {
    DoubleLinkedListNode<T> *node = this->head;
    int i = 0;
    while (node != nullptr) {
        if (node->data == item) { return i; }
        node = node->next;
        i++;
    }
    return -1;
}

template<typename T>
int DoubleLinkedList<T>::lastIndexOf(T item) {
    int index = -1;
    DoubleLinkedListNode<T> *node = this->head;
    int i = 0;
    while (node != nullptr) {
        if (node->data == item) { index = i; }
        node = node->next;
        i++;
    }
    return index;
}

template<typename T>
T DoubleLinkedList<T>::get(int index) {
    int i = 0;
    DoubleLinkedListNode<T> *node = this->head;
    while (node != nullptr) {
        if (i == index) { return node->data; }
        i++;
        node = node->next;
    }
    return 0;
}

template<typename T>
T DoubleLinkedList<T>::getFirst() {
    return this->head->data;
}

template<typename T>
T DoubleLinkedList<T>::getLast() {
    return this->tail->data;
}

template<typename T>
int DoubleLinkedList<T>::size() {
    int size = 0;
    DoubleLinkedListNode<T> *node = this->head;
    while (node != nullptr) {
        size++;
        node = node->next;
    }
    return size;
}

template<typename T>
void DoubleLinkedList<T>::clear() {
    DoubleLinkedListNode<T> *node = this->head;
    while (node != nullptr) {
        DoubleLinkedListNode<T> *tmp = node;
        node = node->next;
        delete tmp;
    }
    this->head = nullptr;
    this->tail = nullptr;
}

template<typename T>
T DoubleLinkedList<T>::remove() {
    T tmp = this->tail->data;

    if (this->head != this->tail) {
        DoubleLinkedListNode<T> *prev = this->tail->prev;
        delete this->tail;
        this->tail = prev;
        this->tail->next = nullptr;
    } else {
        delete this->tail;
        this->head = nullptr;
        this->tail = nullptr;
    }

    return tmp;
}

template<typename T>
T DoubleLinkedList<T>::removeFirst() {
    T tmp = this->head->data;
    if (this->head == this->tail) {
        delete this->head;
        this->head = nullptr;
        this->tail = nullptr;
    } else {
        DoubleLinkedListNode<T> *node = this->head->next;
        delete this->head;
        this->head = node;
        this->head->prev = nullptr;
    }
    return tmp;
}

template<typename T>
T DoubleLinkedList<T>::removeByIndex(int index) {
    int i = 0;
    DoubleLinkedListNode<T> *node = this->head;
    while (node != nullptr && i <= index) {
        if (i == index) {
            if (node->prev == nullptr) {
                return this->removeFirst();
            } else if (node->next == nullptr) {
                return this->remove();
            } else {
                node->prev->next = node->next;
                node->next->prev = node->prev;
                T tmp = node->data;
                delete node;
                return tmp;
            }
        }
        i++;
        node = node->next;
    }
}

template<typename T>
int DoubleLinkedList<T>::remove(T item) {
    int i = 0;
    DoubleLinkedListNode<T> *node = this->head;

    while (node != nullptr) {
        if (node->data == item) {
            if (node == this->head) {
                node->next->prev = nullptr;
                this->head = node->next;
            } else if(node == this->tail) {
                node->prev->next = nullptr;
                this->tail = node->prev;
            } else {
                node->prev->next = node->next;
                node->next->prev = node->prev;
            }
            delete node;
            return i;
        }
        i++;
        node = node->next;
    }
    return -1;
}

template<typename T>
int DoubleLinkedList<T>::removeRight(T item) {
    int i = 0;
    DoubleLinkedList<T> *node = this->tail;
    while (node != nullptr) {
        if (node->data == item) {
            node->prev->next = node->next;
            delete node;
            return i;
        }
        i++;
        node = node->prev;
    }

    return -1;
}
