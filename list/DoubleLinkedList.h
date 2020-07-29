#ifndef DSA_DOUBLELINKEDLIST_H
#define DSA_DOUBLELINKEDLIST_H

#include <functional>
#include <cstdarg>

template<typename T>
struct DoubleLinkedListNode {
    T data;
    DoubleLinkedListNode *next;
    DoubleLinkedListNode *prev;
};

template<typename T>
class DoubleLinkedList {
private:
    DoubleLinkedListNode<T> *head;
    DoubleLinkedListNode<T> *tail;

public:
    DoubleLinkedList();

    explicit DoubleLinkedList(T size, ...) {
        this->head = nullptr;
        this->tail = nullptr;

        va_list arguments;

        va_start (arguments, size);
        for (int x = 0; x < size; x++) {
            this->add(va_arg (arguments, T));
        }
        va_end (arguments);
    };

    /**
     * Adds an item at the end
     *
     * Time complexity: O(1)
     *
     * @param item item to be inserted
     */
    void add(T item);

    /**
     * Adds an item at specified `index`
     *
     * Time complexity: O(n)
     *
     * @param index position of item to be inserted
     * @param item item to be inserted
     * @return return true if `index` is a valid index
     */
    void add(int index, T item);

    /**
     * Adds an element where predicate is true otherwise at the end of lst
     *
     * Time complexity: O(n)
     *
     * @param item item to be inserted
     */
    void addWhere(T item, std::function<bool(T, T)>);

    /**
     * Add an item at head of list
     *
     * Time complexity: O(1)
     *
     * @param item item to be inserted
     */
    void addFirst(T item);

    /**
     * clears the whole list
     *
     * Time complexity: O(n)
     */
    void clear();

    /**
     * get element at `index`
     *
     * Time complexity: O(n)
     *
     * @param index index of item starts from 0
     * @return returns element at `index`
     */
    T get(int index);

    /**
     * returns first element of list
     *
     * Time complexity: O(1)
     *
     * @return returns first element of list
     */
    T getFirst();

    /**
     * returns last element of list
     *
     * Time complexity: O(1)
     *
     * @return returns last element of list
     */
    T getLast();

    /**
     * return index of first occurrence of `item`
     *
     * Time complexity: O(n)
     *
     * @param item item to search
     * @return index of `item` of found else -1
     */
    int indexOf(T item);

    /**
     * return index of last occurrence of `item`
     *
     * Time complexity: O(n)
     *
     * @param item item to search
     * @return index of `item` of found else -1
     */
    int lastIndexOf(T item);

    /**
     * removes last item
     *
     * Time complexity: O(1)
     *
     * @return return removed item
     */
    T remove();

    /**
     * removes
     *
     * Time complexity: O(n)
     *
     * @param index
     * @return return removed item
     */
    T removeByIndex(int index);

    /**
     * Remove the given element
     *
     * Time complexity: O(n)
     *
     * @param item element to search for
     * @return index of element deleted from
     */
    int remove(T item);

    /**
     * Remove the given element and start search from right
     *
     * Time complexity: O(n)
     *
     * @param item element to search for
     * @return index of element deleted from
     */
    int removeRight(T item);

    /**
     * remove first element from list
     *
     * Time complexity: O(1)
     *
     * @return removed element
     */
    T removeFirst();

    /**
     * find size of linked list
     *
     * Time complexity: O(n)
     *
     * @return size of the linked list
     */
    int size();


};


#endif //DSA_DOUBLELINKEDLIST_H
