void displayCircular(){
    if(head1 == NULL){
        printf("List empty\n");
        return;
    }
    struct node* temp = head1;
    printf("Circular list: ");
    do{
        printf("%d ", temp->data);
        temp = temp->next;
    }while(temp != head1);
    printf("%d\n", head1->data);
}
