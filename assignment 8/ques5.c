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

void inorderNonRecursive(struct node* root){
    struct node* stack[100];
    int top=-1;
    struct node* curr=root;
    while(curr!=NULL || top!=-1){
        while(curr!=NULL){
            stack[++top]=curr;
            curr=curr->left;
        }
        curr=stack[top--];
        printf("%d ",curr->data);
        curr=curr->right;
    }
}

int main(){
    struct node* root=NULL;
    root=insert(root,50);
    root=insert(root,30);
    root=insert(root,70);
    root=insert(root,20);
    root=insert(root,40);
    root=insert(root,60);
    root=insert(root,80);

    printf("Inorder Traversal (Non-Recursive): ");
    inorderNonRecursive(root);
    printf("\n");
    return 0;
}
