#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

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

int isBSTUtil(struct node* root,int min,int max){
    if(root==NULL) return 1;
    if(root->data<min || root->data>max) return 0;
    return isBSTUtil(root->left,min,root->data-1) && isBSTUtil(root->right,root->data+1,max);
}

int isBST(struct node* root){
    return isBSTUtil(root,INT_MIN,INT_MAX);
}

int main(){
    struct node* root=create(50);
    root->left=create(30);
    root->right=create(70);
    root->left->left=create(20);
    root->left->right=create(40);
    root->right->left=create(60);
    root->right->right=create(80);

    if(isBST(root))
        printf("The tree is a BST\n");
    else
        printf("The tree is not a BST\n");

    return 0;
}
