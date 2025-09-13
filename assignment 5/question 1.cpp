#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insertAtBeginning(int x) {
    Node* newNode = new Node();
    newNode->data = x;
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(int x) {
    Node* newNode = new Node();
    newNode->data = x;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
}

void insertBefore(int val, int x) {
    if (head == NULL) return;
    if (head->data == val) {
        insertAtBeginning(x);
        return;
    }
    Node* temp = head;
    while (temp->next != NULL && temp->next->data != val) temp = temp->next;
    if (temp->next != NULL) {
        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void insertAfter(int val, int x) {
    Node* temp = head;
    while (temp != NULL && temp->data != val) temp = temp->next;
    if (temp != NULL) {
        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void deleteFromBeginning() {
    if (head == NULL) return;
    Node* temp = head;
    head = head->next;
    delete temp;
}

void deleteFromEnd() {
    if (head == NULL) return;
    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }
    Node* temp = head;
    while (temp->next->next != NULL) temp = temp->next;
    delete temp->next;
    temp->next = NULL;
}

void deleteSpecific(int val) {
    if (head == NULL) return;
    if (head->data == val) {
        deleteFromBeginning();
        return;
    }
    Node* temp = head;
    while (temp->next != NULL && temp->next->data != val) temp = temp->next;
    if (temp->next != NULL) {
        Node* del = temp->next;
        temp->next = temp->next->next;
        delete del;
    }
}

void search(int val) {
    Node* temp = head;
    int pos = 1;
    while (temp != NULL) {
        if (temp->data == val) {
            cout << "Node found at position " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Node not found" << endl;
}

void display() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int choice, x, val;
    while (1) {
        cout << "1. Insert at beginning" << endl;
        cout << "2. Insert at end" << endl;
        cout << "3. Insert before a node" << endl;
        cout << "4. Insert after a node" << endl;
        cout << "5. Delete from beginning" << endl;
        cout << "6. Delete from end" << endl;
        cout << "7. Delete specific node" << endl;
        cout << "8. Search a node" << endl;
        cout << "9. Display list" << endl;
        cout << "10. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: cout << "Enter value: "; cin >> x; insertAtBeginning(x); break;
            case 2: cout << "Enter value: "; cin >> x; insertAtEnd(x); break;
            case 3: cout << "Enter node value to insert before: "; cin >> val; cout << "Enter new value: "; cin >> x; insertBefore(val, x); break;
            case 4: cout << "Enter node value to insert after: "; cin >> val; cout << "Enter new value: "; cin >> x; insertAfter(val, x); break;
            case 5: deleteFromBeginning(); break;
            case 6: deleteFromEnd(); break;
            case 7: cout << "Enter value to delete: "; cin >> val; deleteSpecific(val); break;
            case 8: cout << "Enter value to search: "; cin >> val; search(val); break;
            case 9: display(); break;
            case 10: return 0;
            default: cout << "Invalid choice" << endl;
        }
    }
}
