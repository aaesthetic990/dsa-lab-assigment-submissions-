#include <iostream>
using namespace std;

#define SIZE 5

class Queue {
    int arr[SIZE];
    int front, rear;
public:
    Queue() {
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
    Queue q;
    int ch, val;
    do {
        cout << "1.Enqueue" << endl;
        cout << "2.Dequeue" << endl;
        cout << "3.Peek" << endl;
        cout << "4.Display" << endl;
        cout << "5.Exit" << endl;
        cout << "Enter your choice: ";
        cin >> ch;
        switch(ch) {
            case 1: 
                cout << "Enter value to enqueue: ";
                cin >> val; 
                q.enqueue(val); 
                break;
            case 2: 
                cout << "Performing Dequeue" << endl;
                q.dequeue(); 
                break;
            case 3: 
                cout << "Peeking front element" << endl;
                q.peek(); 
                break;
            case 4: 
                cout << "Displaying Queue" << endl;
                q.display(); 
                break;
        }
    } while(ch != 5);
    return 0;
}
