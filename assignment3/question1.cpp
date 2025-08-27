#include <iostream>
using namespace std;


int stack[5];
int top = -1;

void push(int x) {
    if (top == 4) {
        cout << "Stack is Full"<<endl;
    } else {
        top++;
        stack[top] = x;
        cout << x << " pushed"<<endl;
    }
}

void pop() {
    if (top == -1) {
        cout << "Stack is Empty"<<endl;
    } else {
        cout << stack[top] << " popped"<<endl;
        top--;
    }
}

void isEmpty() {
    if (top == -1) cout << "Stack is Empty"<<endl;
    else cout << "Stack is not Empty"<<endl;
}

void isFull() {
    if (top == 4 ) cout << "Stack is Full"<<endl;
    else cout << "Stack is not Full"<<endl;
}

void display() {
    if (top == -1) cout << "Stack is Empty"<<endl;
    else {
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--) cout << stack[i] << " ";
        cout << endl;
    }
}

void peek() {
    if (top == -1) cout << "Stack is Empty"<<endl;
    else cout << "Top element: " << stack[top] <<endl;
}

int main() {
    int choice, val;
    while (1) {
        cout << " 1.Push 2.Pop 3.isEmpty 4.isFull 5.Display 6.Peek 7.Exit"<<endl;
        cout << "Enter choice: "<<endl;
        cin >> choice;
        switch (choice) {
            case 1: cout << "Enter value: "; cin >> val; push(val); break;
            case 2: pop(); break;
            case 3: isEmpty(); break;
            case 4: isFull(); break;
            case 5: display(); break;
            case 6: peek(); break;
            case 7: return 0;
            default: cout << "Invalid choice"<<endl;
        }
    }
    return 0 ;
}
