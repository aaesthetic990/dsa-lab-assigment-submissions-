#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
    struct node* prev;
};

struct node* head1 = NULL;
struct node* head2 = NULL;

void insertFirstCircular(int val){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    if(head1 == NULL){
        head1 = newnode;
        newnode->next = head1;
    } else {
        struct node* temp = head1;
        while(temp->next != head1)
            temp = temp->next;
        newnode->next = head1;
        temp->next = newnode;
        head1 = newnode;
    }
    printf("Inserted at first in circular\n");
}

void insertLastCircular(int val){
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
    printf("Inserted at last in circular\n");
}

void insertAfterCircular(int key,int val){
    if(head1==NULL){
        printf("List empty\n");
        return;
    }
    struct node* temp=head1;
    do{
        if(temp->data==key){
            struct node* newnode=(struct node*)malloc(sizeof(struct node));
            newnode->data=val;
            newnode->next=temp->next;
            temp->next=newnode;
            printf("Inserted after %d in circular\n",key);
            return;
        }
        temp=temp->next;
    }while(temp!=head1);
    printf("Key not found\n");
}

void insertBeforeCircular(int key,int val){
    if(head1==NULL){
        printf("List empty\n");
        return;
    }
    struct node* temp=head1;
    struct node* prev=NULL;
    do{
        if(temp->data==key){
            struct node* newnode=(struct node*)malloc(sizeof(struct node));
            newnode->data=val;
            if(temp==head1){
                while(temp->next!=head1)
                    temp=temp->next;
                newnode->next=head1;
                temp->next=newnode;
                head1=newnode;
            } else {
                newnode->next=temp;
                prev->next=newnode;
            }
            printf("Inserted before %d in circular\n",key);
            return;
        }
        prev=temp;
        temp=temp->next;
    }while(temp!=head1);
    printf("Key not found\n");
}

void deleteCircular(int key){
    if(head1==NULL){
        printf("List empty\n");
        return;
    }
    struct node* temp=head1;
    struct node* prev=NULL;
    do{
        if(temp->data==key){
            if(temp==head1 && temp->next==head1){
                head1=NULL;
            } else if(temp==head1){
                struct node* last=head1;
                while(last->next!=head1)
                    last=last->next;
                head1=head1->next;
                last->next=head1;
            } else {
                prev->next=temp->next;
            }
            free(temp);
            printf("Deleted %d from circular\n",key);
            return;
        }
        prev=temp;
        temp=temp->next;
    }while(temp!=head1);
    printf("Key not found\n");
}

void searchCircular(int key){
    if(head1==NULL){
        printf("List empty\n");
        return;
    }
    struct node* temp=head1;
    do{
        if(temp->data==key){
            printf("Found %d in circular\n",key);
            return;
        }
        temp=temp->next;
    }while(temp!=head1);
    printf("Not found\n");
}

void displayCircular(){
    if(head1==NULL){
        printf("List empty\n");
        return;
    }
    struct node* temp=head1;
    printf("Circular list: ");
    do{
        printf("%d ",temp->data);
        temp=temp->next;
    }while(temp!=head1);
    printf("\n");
}

void insertFirstDoubly(int val){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->prev=NULL;
    newnode->next=head2;
    if(head2!=NULL)
        head2->prev=newnode;
    head2=newnode;
    printf("Inserted at first in doubly\n");
}

void insertLastDoubly(int val){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->next=NULL;
    if(head2==NULL){
        newnode->prev=NULL;
        head2=newnode;
    } else {
        struct node* temp=head2;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=newnode;
        newnode->prev=temp;
    }
    printf("Inserted at last in doubly\n");
}

void insertAfterDoubly(int key,int val){
    struct node* temp=head2;
    while(temp!=NULL){
        if(temp->data==key){
            struct node* newnode=(struct node*)malloc(sizeof(struct node));
            newnode->data=val;
            newnode->next=temp->next;
            newnode->prev=temp;
            if(temp->next!=NULL)
                temp->next->prev=newnode;
            temp->next=newnode;
            printf("Inserted after %d in doubly\n",key);
            return;
        }
        temp=temp->next;
    }
    printf("Key not found\n");
}

void insertBeforeDoubly(int key,int val){
    struct node* temp=head2;
    while(temp!=NULL){
        if(temp->data==key){
            struct node* newnode=(struct node*)malloc(sizeof(struct node));
            newnode->data=val;
            newnode->next=temp;
            newnode->prev=temp->prev;
            if(temp->prev!=NULL)
                temp->prev->next=newnode;
            else
                head2=newnode;
            temp->prev=newnode;
            printf("Inserted before %d in doubly\n",key);
            return;
        }
        temp=temp->next;
    }
    printf("Key not found\n");
}

void deleteDoubly(int key){
    struct node* temp=head2;
    while(temp!=NULL){
        if(temp->data==key){
            if(temp->prev!=NULL)
                temp->prev->next=temp->next;
            else
                head2=temp->next;
            if(temp->next!=NULL)
                temp->next->prev=temp->prev;
            free(temp);
            printf("Deleted %d from doubly\n",key);
            return;
        }
        temp=temp->next;
    }
    printf("Key not found\n");
}

void searchDoubly(int key){
    struct node* temp=head2;
    while(temp!=NULL){
        if(temp->data==key){
            printf("Found %d in doubly\n",key);
            return;
        }
        temp=temp->next;
    }
    printf("Not found\n");
}

void displayDoubly(){
    if(head2==NULL){
        printf("List empty\n");
        return;
    }
    struct node* temp=head2;
    printf("Doubly list: ");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main(){
    int c,ch,val,key;
    while(1){
        printf("\n1.Circular Linked List\n2.Doubly Linked List\n3.Exit\n");
        scanf("%d",&c);
        if(c==1){
            while(1){
                printf("\n1.Insert First\n2.Insert Last\n3.Insert After\n4.Insert Before\n5.Delete Node\n6.Search\n7.Display\n8.Back\n");
                scanf("%d",&ch);
                if(ch==1){
                    scanf("%d",&val);
                    insertFirstCircular(val);
                } else if(ch==2){
                    scanf("%d",&val);
                    insertLastCircular(val);
                } else if(ch==3){
                    scanf("%d%d",&key,&val);
                    insertAfterCircular(key,val);
                } else if(ch==4){
                    scanf("%d%d",&key,&val);
                    insertBeforeCircular(key,val);
                } else if(ch==5){
                    scanf("%d",&key);
                    deleteCircular(key);
                } else if(ch==6){
                    scanf("%d",&key);
                    searchCircular(key);
                } else if(ch==7){
                    displayCircular();
                } else if(ch==8){
                    break;
                } else {
                    printf("Invalid\n");
                }
            }
        }
        else if(c==2){
            while(1){
                printf("\n1.Insert First\n2.Insert Last\n3.Insert After\n4.Insert Before\n5.Delete Node\n6.Search\n7.Display\n8.Back\n");
                scanf("%d",&ch);
                if(ch==1){
                    scanf("%d",&val);
                    insertFirstDoubly(val);
                } else if(ch==2){
                    scanf("%d",&val);
                    insertLastDoubly(val);
                } else if(ch==3){
                    scanf("%d%d",&key,&val);
                    insertAfterDoubly(key,val);
                } else if(ch==4){
                    scanf("%d%d",&key,&val);
                    insertBeforeDoubly(key,val);
                } else if(ch==5){
                    scanf("%d",&key);
                    deleteDoubly(key);
                } else if(ch==6){
                    scanf("%d",&key);
                    searchDoubly(key);
                } else if(ch==7){
                    displayDoubly();
                } else if(ch==8){
                    break;
                } else {
                    printf("Invalid\n");
                }
            }
        }
        else if(c==3){
            break;
        }
        else{
            printf("Invalid\n");
        }
    }
}
