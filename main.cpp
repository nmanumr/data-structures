#include <iostream>
#include "list/SingleLinkedList.cpp"

using namespace std;

int main() {
    SingleLinkedList<int> lst;
    lst.add(0);
    lst.add(1);
    lst.add(2);
    lst.add(1);
    lst.add(0);
}
