#include <iostream>
#include <queue>
using namespace std;

class StackTwoQueues {
    queue<int> q1, q2;
public:
    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }
    void pop() {
        if (!q1.empty()) q1.pop();
    }
    int top() {
        if (!q1.empty()) return q1.front();
        return -1;
    }
    bool empty() {
        return q1.empty();
    }
};

class StackOneQueue {
    queue<int> q;
public:
    void push(int x) {
        int size = q.size();
        q.push(x);
        for (int i = 0; i < size; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    void pop() {
        if (!q.empty()) q.pop();
    }
    int top() {
        if (!q.empty()) return q.front();
        return -1;
    }
    bool empty() {
        return q.empty();
    }
};

int main() {
    StackTwoQueues s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    cout << "Top using two queues: " << s1.top() << endl;
    s1.pop();
    cout << "Top after pop: " << s1.top() << endl;

    StackOneQueue s2;
    s2.push(100);
    s2.push(200);
    s2.push(300);
    cout << "Top using one queue: " << s2.top() << endl;
    s2.pop();
    cout << "Top after pop: " << s2.top() << endl;

    return 0;
}
