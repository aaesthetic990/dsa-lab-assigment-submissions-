#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node* create(){
    struct node *head=NULL,*temp,*newnode;
    int val;
    printf("Enter data (-1 to stop): ");
    while(1){
        scanf("%d",&val);
        if(val==-1)
            break;
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=val;
        newnode->next=NULL;
        if(head==NULL)
            head=temp=newnode;
        else{
            temp->next=newnode;
            temp=newnode;
        }
    }
    return head;
}

int isCircular(struct node* head){
    if(head==NULL)
        return 0;
    struct node *temp=head->next;
    while(temp!=NULL && temp!=head)
        temp=temp->next;
    if(temp==head)
        return 1;
    return 0;
}

int main(){
    struct node *head=create();
    int ch;
    printf("Make it circular? (1 for yes, 0 for no): ");
    scanf("%d",&ch);
    if(ch==1){
        struct node *temp=head;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=head;
    }
    if(isCircular(head))
        printf("Circular Linked List\n");
    else
        printf("Not Circular Linked List\n");
    return 0;
}
