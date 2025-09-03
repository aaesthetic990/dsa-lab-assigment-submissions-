#include <iostream>
using namespace std;

#define SIZE 5

class CircularQueue {
    int arr[SIZE];
    int front, rear;
public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }
    bool isEmpty() {
        return front == -1;
    }
    bool isFull() {
        return (rear + 1) % SIZE == front;
    }
    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue is Full" << endl;
            return;
        }
        if (front == -1) front = 0;
        rear = (rear + 1) % SIZE;
        arr[rear] = x;
        cout << x << " enqueued" << endl;
    }
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty" << endl;
            return;
        }
        cout << arr[front] << " dequeued" << endl;
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
    }
    void peek() {
        if (isEmpty()) {
            cout << "Queue is Empty" << endl;
        } else {
            cout << "Front: " << arr[front] << endl;
        }
    }
    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty" << endl;
            return;
        }
        cout << "Queue: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue q;
    int ch, val;
    do {
        cout << "1.Enqueue" << endl;
        cout << "2.Dequeue" << endl;
        cout << "3.Peek" << endl;
        cout << "4.Display" << endl;
        cout << "5.Check Empty" << endl;
        cout << "6.Check Full" << endl;
        cout << "7.Exit" << endl;
        cout << "Enter your choice: ";
        cin >> ch;
        switch(ch) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> val;
                q.enqueue(val);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.peek();
                break;
            case 4:
                q.display();
                break;
            case 5:
                if(q.isEmpty()) cout << "Queue is Empty" << endl;
                else cout << "Queue is not Empty" << endl;
                break;
            case 6:
                if(q.isFull()) cout << "Queue is Full" << endl;
                else cout << "Queue is not Full" << endl;
                break;
        }
    } while(ch != 7);
    return 0;
}
