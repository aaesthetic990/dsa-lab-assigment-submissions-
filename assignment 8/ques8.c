#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left,*right;
};

struct node* create(int val){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->left=newnode->right=NULL;
    return newnode;
}

struct node* insert(struct node* root,int val){
    if(root==NULL)
        return create(val);
    if(val<root->data)
        root->left=insert(root->left,val);
    else if(val>root->data)
        root->right=insert(root->right,val);
    return root;
}

void inorderStore(struct node* root,struct node** head,struct node** prev){
    if(root==NULL)
        return;
    inorderStore(root->left,head,prev);
    if(*head==NULL)
        *head=root;
    else{
        (*prev)->right=root;
        root->left=*prev;
    }
    *prev=root;
    inorderStore(root->right,head,prev);
}

struct node* mergeDLL(struct node* h1,struct node* h2){
    struct node* head=NULL;
    struct node* tail=NULL;
    while(h1 && h2){
        struct node* temp;
        if(h1->data < h2->data){
            temp=h1;
            h1=h1->right;
        } else {
            temp=h2;
            h2=h2->right;
        }
        temp->left=tail;
        if(tail)
            tail->right=temp;
        else
            head=temp;
        tail=temp;
    }
    while(h1){
        h1->left=tail;
        if(tail)
            tail->right=h1;
        else
            head=h1;
        tail=h1;
        h1=h1->right;
    }
    while(h2){
        h2->left=tail;
        if(tail)
            tail->right=h2;
        else
            head=h2;
        tail=h2;
        h2=h2->right;
    }
    return head;
}

void printDLL(struct node* head){
    while(head){
        printf("%d ",head->data);
        head=head->right;
    }
}

int main(){
    struct node *root1=NULL,*root2=NULL;
    root1=insert(root1,30);
    root1=insert(root1,20);
    root1=insert(root1,40);
    root2=insert(root2,10);
    root2=insert(root2,25);
    root2=insert(root2,35);
    struct node *head1=NULL,*head2=NULL,*prev=NULL;
    inorderStore(root1,&head1,&prev);
    prev=NULL;
    inorderStore(root2,&head2,&prev);
    struct node* merged=mergeDLL(head1,head2);
    printf("Merged Doubly Linked List: ");
    printDLL(merged);
    printf("\n");
    return 0;
}
