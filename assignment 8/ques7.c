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

struct node* buildTree(int inorder[],int postorder[],int start,int end,int *postIndex){
    if(start>end)
        return NULL;
    struct node* node=create(postorder[*postIndex]);
    (*postIndex)--;
    if(start==end)
        return node;
    int inIndex=search(inorder,start,end,node->data);
    node->right=buildTree(inorder,postorder,inIndex+1,end,postIndex);
    node->left=buildTree(inorder,postorder,start,inIndex-1,postIndex);
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
    int postorder[]={4,5,2,6,7,3,1};
    int n=7;
    int postIndex=n-1;
    struct node* root=buildTree(inorder,postorder,0,n-1,&postIndex);
    printf("Inorder Traversal of constructed tree: ");
    inorderPrint(root);
    printf("\n");
    return 0;
}
