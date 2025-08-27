#include <iostream>
#include <string>
using namespace std;

int top = -1;

void push(char stack[], int n, char x) {
    if (top < n - 1) {
        stack[++top] = x;
    }
}

char pop(char stack[]) {
    if (top != -1) {
        return stack[top--];
    }
    cout<<" stack overflow ";
}

char peek(char stack[]) {
    if (top != -1) return stack[top];
    return  '\0';
}

int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}

int main() {
    string infix, postfix = "";
    cout << "Enter infix expression: ";
    getline(cin, infix);

    int n = infix.length();
    char stack[1000];

    for (int i = 0; i < n; i++) {
        char c = infix[i];

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            postfix += c;
        }
        else if (c == '(') {
            push(stack, n, c);
        }
        else if (c == ')') {
            while (top != -1 && peek(stack) != '(') {
                postfix += pop(stack);
            }
            if (top != -1 && peek(stack) == '(') pop(stack);
        }
        else {
            while (top != -1 && precedence(peek(stack)) >= precedence(c)) {
                postfix += pop(stack);
            }
            push(stack, n, c);
        }
    }

    while (top != -1) {
        postfix += pop(stack);
    }

    cout << "Postfix expression: " << postfix << endl;
    return 0;
}
