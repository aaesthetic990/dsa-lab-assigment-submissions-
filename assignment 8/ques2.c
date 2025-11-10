#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left, *right;
};

struct node* create(int val){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

struct node* insert(struct node* root, int val){
    if(root == NULL)
        return create(val);
    if(val < root->data)
        root->left = insert(root->left, val);
    else if(val > root->data)
        root->right = insert(root->right, val);
    return root;
}

struct node* searchRec(struct node* root, int key){
    if(root == NULL || root->data == key)
        return root;
    if(key < root->data)
        return searchRec(root->left, key);
    else
        return searchRec(root->right, key);
}

struct node* searchNonRec(struct node* root, int key){
    while(root != NULL && root->data != key){
        if(key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return root;
}

struct node* findMin(struct node* root){
    while(root && root->left != NULL)
        root = root->left;
    return root;
}

struct node* findMax(struct node* root){
    while(root && root->right != NULL)
        root = root->right;
    return root;
}

struct node* inorderSuccessor(struct node* root, struct node* x){
    if(x->right != NULL)
        return findMin(x->right);
    struct node* succ = NULL;
    while(root != NULL){
        if(x->data < root->data){
            succ = root;
            root = root->left;
        }
        else if(x->data > root->data)
            root = root->right;
        else
            break;
    }
    return succ;
}

struct node* inorderPredecessor(struct node* root, struct node* x){
    if(x->left != NULL)
        return findMax(x->left);
    struct node* pred = NULL;
    while(root != NULL){
        if(x->data > root->data){
            pred = root;
            root = root->right;
        }
        else if(x->data < root->data)
            root = root->left;
        else
            break;
    }
    return pred;
}

void inorder(struct node* root){
    if(root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main(){
    struct node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    printf("Inorder: ");
    inorder(root);
    printf("\n");

    int key = 40;
    struct node* s1 = searchRec(root, key);
    if(s1) printf("Found %d (Recursive)\n", key);
    else printf("Not Found (Recursive)\n");

    struct node* s2 = searchNonRec(root, key);
    if(s2) printf("Found %d (Non-Recursive)\n", key);
    else printf("Not Found (Non-Recursive)\n");

    struct node* min = findMin(root);
    struct node* max = findMax(root);
    printf("Minimum: %d\n", min->data);
    printf("Maximum: %d\n", max->data);

    struct node* succ = inorderSuccessor(root, s1);
    if(succ) printf("Inorder Successor of %d: %d\n", s1->data, succ->data);
    else printf("No Inorder Successor\n");

    struct node* pred = inorderPredecessor(root, s1);
    if(pred) printf("Inorder Predecessor of %d: %d\n", s1->data, pred->data);
    else printf("No Inorder Predecessor\n");

    return 0;
}
