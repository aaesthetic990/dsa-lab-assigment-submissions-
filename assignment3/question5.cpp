#include <iostream>
#include <string>
using namespace std;

int top = -1;

void push(int stack[], int n, int x) {
    if (top < n - 1) {
        stack[++top] = x;
    }
}

int pop(int stack[]) {
    if (top != -1) {
        return stack[top--];
    }
    return 0;
}

int power(int base, int exp) {
    int result = 1;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

int main() {
    string postfix;
    cout << "Enter postfix expression: ";
    getline(cin, postfix);

    int n = postfix.length();
    int stack[1000];

    for (int i = 0; i < n; i++) {
        char c = postfix[i];

        if (c >= '0' && c <= '9') {
            push(stack, n, c - '0');
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
            int val2 = pop(stack);
            int val1 = pop(stack);
            int res = 0;

            switch (c) {
                case '+': res = val1 + val2; break;
                case '-': res = val1 - val2; break;
                case '*': res = val1 * val2; break;
                case '/': res = val1 / val2; break;
                case '^': res = power(val1, val2); break;
            }
            push(stack, n, res);
        }
    }

    cout << "Result = " << pop(stack) << endl;
    return 0;
}
