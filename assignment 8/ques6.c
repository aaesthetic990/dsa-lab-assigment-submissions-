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

int search(int inorder[],int start,int end,int val){
    for(int i=start;i<=end;i++){
        if(inorder[i]==val)
            return i;
    }
    return -1;
}

struct node* buildTree(int inorder[],int preorder[],int start,int end,int *preIndex){
    if(start>end)
        return NULL;
    struct node* node=create(preorder[*preIndex]);
    (*preIndex)++;
    if(start==end)
        return node;
    int inIndex=search(inorder,start,end,node->data);
    node->left=buildTree(inorder,preorder,start,inIndex-1,preIndex);
    node->right=buildTree(inorder,preorder,inIndex+1,end,preIndex);
    return node;
}

void inorderPrint(struct node* root){
    if(root==NULL) return;
    inorderPrint(root->left);
    printf("%d ",root->data);
    inorderPrint(root->right);
}

int main(){
    int inorder[]={4,2,5,1,6,3,7};
    int preorder[]={1,2,4,5,3,6,7};
    int n=7;
    int preIndex=0;
    struct node* root=buildTree(inorder,preorder,0,n-1,&preIndex);
    printf("Inorder Traversal of constructed tree: ");
    inorderPrint(root);
    printf("\n");
    return 0;
}
