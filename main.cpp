#include <iostream>
#include "list/DoubleLinkedList.cpp"

using namespace std;

int main() {
    DoubleLinkedList<int> lst(3, 0, 2, 3);
    // now `lst` contains [0, 2, 3]

    //////////////
    // Add methods

    // add at end
    lst.add(1);
    // now `lst` contains [0, 2, 3, 1]

    // add at start
    lst.addFirst(1);
    // now `lst` contains [1, 0, 2, 3, 1]

    // add at index 1
    lst.add(1, 5);
    // now `lst` contains [1, 5, 0, 2, 3, 1]

    // add where predicate matches (ie where num)
    lst.addWhere(4, [](int e, int num) { return e > num;});
    // now `lst` contains [1, 4, 5, 0, 2, 3, 1]


    //////////////
    // get methods

    // get size of list
    cout << "size of list: " << lst.size() << endl;

    // get nth element
    cout << "3rd element of list: " << lst.get(3) << endl;

    // get index of element
    cout << "index of first most occurrence of 1 is: " << lst.indexOf(1) << endl;

    // get last index of element
    cout << "index of last most occurrence of 1 is: " << lst.lastIndexOf(1) << endl;

    // get first element from array
    cout << "first element of array: " << lst.getFirst() << endl;

    // get last element from array
    cout << "last element of array: " << lst.getLast() << endl;

    /////////////////
    // remove methods

    // remove last element
    cout << "removed element: " << lst.remove() << endl;
    // now `lst` contains [1, 4, 5, 0, 2, 3]

    // remove first element
    cout << "removed element: " << lst.removeFirst() << endl;
    // now `lst` contains [4, 5, 0, 2, 3]

    // remove by specific element
    cout << "index of removed element: " << lst.remove(0) << endl;
    // now `lst` contains [4, 5, 2, 3]

    // remove by specific index
    cout << "removed element: " << lst.removeByIndex(2) << endl;
    // now `lst` contains [4, 5, 3]

    // removes all element
    lst.clear();
    // now `lst` contains []
}
