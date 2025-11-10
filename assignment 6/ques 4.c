#include<stdio.h>
#include<stdlib.h>

struct node{
    char data;
    struct node *prev;
    struct node *next;
};

struct node* create(){
    struct node *head=NULL,*temp,*newnode;
    char ch;
    printf("Enter characters (use . to stop): ");
    while(1){
        scanf(" %c",&ch);
        if(ch=='.')
            break;
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=ch;
        newnode->next=NULL;
        newnode->prev=NULL;
        if(head==NULL)
            head=temp=newnode;
        else{
            temp->next=newnode;
            newnode->prev=temp;
            temp=newnode;
        }
    }
    return head;
}

int isPalindrome(struct node* head){
    struct node *left=head,*right=head;
    if(head==NULL)
        return 1;
    while(right->next!=NULL)
        right=right->next;
    while(left!=right && right->next!=left){
        if(left->data!=right->data)
            return 0;
        left=left->next;
        right=right->prev;
    }
    return 1;
}

int main(){
    struct node *head=create();
    if(isPalindrome(head))
        printf("Palindrome\n");
    else
        printf("Not Palindrome\n");
    return 0;
}
