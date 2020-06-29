#include <iostream>
#include "queue/LinearQueue.cpp"

using namespace std;

int main() {
    LinearQueue<int> queue;
    queue.enqueue(10);
    queue.enqueue(20);
    cout << queue.size() << endl;
    cout << queue.dequeue() << endl;
    cout << queue.dequeue() << endl;
}
