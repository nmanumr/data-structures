#ifndef DSA_STACK_H
#define DSA_STACK_H

#include "../list/SingleLinkedList.cpp"

template<typename T>
class Stack {
private:
    SingleLinkedList<T> lst;

public:
    /**
     * Push item to top of the stack
     * @param item item to be pushed
     */
    void push(T item);

    /**
     * Pop last item from stack and return it
     * @return last item in stack
     */
    T pop();

    /**
     * get last item without removing it
     * @return last item in stack
     */
    T peek();

    /**
     * search the first occurrence given item
     * @param item item to be searched
     * @return left most index of the item otherwise '-1'
     */
    int search(T item);

    /**
     * search the last occurrence given item
     * @param item item to be searched
     * @return right most index of the item otherwise '-1'
     */
    int searchRight(T item);

    /**
     * return the size of stack
     * @return size of stack
     */
    int size();
};


#endif //DSA_STACK_H
