#include <iostream>
using namespace std;

#define SIZE 100

class Queue {
    char arr[SIZE];
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
    void enqueue(char x) {
        if (isFull()) return;
        arr[++rear] = x;
    }
    char dequeue() {
        if (isEmpty()) return '\0';
        return arr[front++];
    }
    char peek() {
        if (isEmpty()) return '\0';
        return arr[front];
    }
};

int main() {
    string s = "aabc";
    int freq[256] = {0};
    Queue q;

    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];
        freq[ch]++;
        q.enqueue(ch);

        while (!q.isEmpty() && freq[q.peek()] > 1) {
            q.dequeue();
        }

        if (q.isEmpty()) cout << -1 << " ";
        else cout << q.peek() << " ";
    }
    cout << endl;

    return 0;
}
