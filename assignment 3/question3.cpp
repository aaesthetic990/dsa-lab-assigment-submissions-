#include <iostream>
using namespace std;

#define SIZE 20

class Queue {
    int arr[SIZE];
    int front, rear;
public:
    Queue() {
        front = 0;
        rear = -1;
    }
    bool isEmpty() {
        return front > rear;
    }
    bool isFull() {
        return rear == SIZE - 1;
    }
    void enqueue(int x) {
        if (isFull()) return;
        arr[++rear] = x;
    }
    int dequeue() {
        if (isEmpty()) return -1;
        return arr[front++];
    }
    int peek() {
        if (isEmpty()) return -1;
        return arr[front];
    }
    int size() {
        return rear - front + 1;
    }
    void display() {
        for (int i = front; i <= rear; i++) cout << arr[i] << " ";
        cout << endl;
    }
};

void interleave(Queue &q) {
    int n = q.size();
    if (n % 2 != 0) {
        cout << "Queue has odd number of elements" << endl;
        return;
    }

    Queue firstHalf;
    int half = n / 2;

    for (int i = 0; i < half; i++) {
        firstHalf.enqueue(q.dequeue());
    }

    while (!firstHalf.isEmpty()) {
        q.enqueue(firstHalf.dequeue());
        q.enqueue(q.dequeue());
    }
}

int main() {
    Queue q;
    int arr[] = {4, 7, 11, 20, 5, 9};
    int n = sizeof(arr)/sizeof(arr[0]);

    for (int i = 0; i < n; i++) q.enqueue(arr[i]);

    cout << "Original Queue: ";
    q.display();

    interleave(q);

    cout << "Interleaved Queue: ";
    q.display();

    return 0;
}
