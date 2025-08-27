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
    cout<< " stack underflow ";
}

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    int n = str.length();
    char stack[1000];  

    for (int i = 0; i < n; i++) {
        push(stack, n, str[i]);
    }

    cout << "Reversed string: ";
    while (top != -1) {
        cout << pop(stack);
    }
    cout <<endl ;

    return 0;
}
