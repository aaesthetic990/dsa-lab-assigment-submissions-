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

struct node* findMinNode(struct node* root){
    while(root && root->left!=NULL)
        root=root->left;
    return root;
}

struct node* deleteNode(struct node* root,int key){
    if(root==NULL)
        return root;
    if(key<root->data)
        root->left=deleteNode(root->left,key);
    else if(key>root->data)
        root->right=deleteNode(root->right,key);
    else{
        if(root->left==NULL){
            struct node* temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            struct node* temp=root->left;
            free(root);
            return temp;
        }
        struct node* temp=findMinNode(root->right);
        root->data=temp->data;
        root->right=deleteNode(root->right,temp->data);
    }
    return root;
}

int maxDepth(struct node* root){
    if(root==NULL) return 0;
    int l=maxDepth(root->left);
    int r=maxDepth(root->right);
    return (l>r?l:r)+1;
}

int minDepth(struct node* root){
    if(root==NULL) return 0;
    int l=minDepth(root->left);
    int r=minDepth(root->right);
    if(l==0 || r==0) return (l>r?l:r)+1;
    return (l<r?l:r)+1;
}

void inorder(struct node* root){
    if(root==NULL) return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

int main(){
    struct node* root=NULL;
    int ch,val;
    while(1){
        printf("\n1.Insert\n2.Delete\n3.Inorder\n4.Max Depth\n5.Min Depth\n6.Exit\n");
        scanf("%d",&ch);
        if(ch==1){
            printf("Enter value to insert: ");
            scanf("%d",&val);
            root=insert(root,val);
        }
        else if(ch==2){
            printf("Enter value to delete: ");
            scanf("%d",&val);
            root=deleteNode(root,val);
        }
        else if(ch==3){
            printf("Inorder: ");
            inorder(root);
            printf("\n");
        }
        else if(ch==4)
            printf("Maximum Depth: %d\n",maxDepth(root));
        else if(ch==5)
            printf("Minimum Depth: %d\n",minDepth(root));
        else
            break;
    }
    return 0;
}
