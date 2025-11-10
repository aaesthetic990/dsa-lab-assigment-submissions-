#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
    struct node* prev;
};

struct node* head1 = NULL;
struct node* head2 = NULL;

void insertCircular(int val){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    if(head1 == NULL){
        head1 = newnode;
        newnode->next = head1;
    } else {
        struct node* temp = head1;
        while(temp->next != head1)
            temp = temp->next;
        temp->next = newnode;
        newnode->next = head1;
    }
    printf("Inserted in circular\n");
}

void insertDoubly(int val){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = NULL;
    if(head2 == NULL){
        newnode->prev = NULL;
        head2 = newnode;
    } else {
        struct node* temp = head2;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
        newnode->prev = temp;
    }
    printf("Inserted in doubly\n");
}

void sizeCircular(){
    if(head1 == NULL){
        printf("Circular list size = 0\n");
        return;
    }
    struct node* temp = head1;
    int count = 0;
    do{
        count++;
        temp = temp->next;
    }while(temp != head1);
    printf("Circular list size = %d\n", count);
}

void sizeDoubly(){
    int count = 0;
    struct node* temp = head2;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    printf("Doubly list size = %d\n", count);
}

void displayCircular(){
    if(head1 == NULL){
        printf("Circular list empty\n");
        return;
    }
    struct node* temp = head1;
    do{
        printf("%d ", temp->data);
        temp = temp->next;
    }while(temp != head1);
    printf("%d\n", head1->data);
}

void displayDoubly(){
    if(head2 == NULL){
        printf("Doubly list empty\n");
        return;
    }
    struct node* temp = head2;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    int ch, val;
    while(1){
        printf("\n1.Insert in Circular\n2.Display Circular\n3.Size of Circular\n4.Insert in Doubly\n5.Display Doubly\n6.Size of Doubly\n7.Exit\n");
        scanf("%d", &ch);
        if(ch == 1){
            scanf("%d", &val);
            insertCircular(val);
        }
        else if(ch == 2){
            displayCircular();
        }
        else if(ch == 3){
            sizeCircular();
        }
        else if(ch == 4){
            scanf("%d", &val);
            insertDoubly(val);
        }
        else if(ch == 5){
            displayDoubly();
        }
        else if(ch == 6){
            sizeDoubly();
        }
        else if(ch == 7){
            break;
        }
        else{
            printf("Invalid\n");
        }
    }
}
