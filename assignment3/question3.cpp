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
    cout<<" stack overflow " ;
}

bool isMatching(char open, char close) {
    if (open == '(' && close == ')') return true;
    if (open == '[' && close == ']') return true;
    if (open == '{' && close == '}') return true;
    return false;
}

int main() {
    string expr;
    cout << "Enter expression: ";
    getline(cin, expr);

    int n = expr.length();
    char stack[1000];

    for (int i = 0; i < n; i++) {
        if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{') {
            push(stack, n, expr[i]);
        } else if (expr[i] == ')' || expr[i] == ']' || expr[i] == '}') {
            if (top == -1) {
                cout << "Not Balanced" << endl;
                return 0;
            }
            char open = pop(stack);
            if (!isMatching(open, expr[i])) {
                cout << "Not Balanced" << endl;
                return 0;
            }
        }
    }

    if (top == -1) cout << "Balanced" << endl;
    else cout << "Not Balanced" << endl;

    return 0;
}
