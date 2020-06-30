#include "queue/Queue.cpp"

using namespace std;

int main() {
    Queue<int> queue;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(30, 1);
    queue.enqueue(30, 2);
    queue.enqueue(30, 1);
}
