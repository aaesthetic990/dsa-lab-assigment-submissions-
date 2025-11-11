#include<stdio.h>

int heap[50];
int size = 0;

void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

void insert(int val){
    heap[size] = val;
    int i = size;
    size++;
    while(i > 0 && heap[(i-1)/2] < heap[i]){
        swap(&heap[i], &heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

int deleteMax(){
    if(size == 0){
        printf("Priority Queue is empty\n");
        return -1;
    }
    int root = heap[0];
    heap[0] = heap[size-1];
    size--;
    int i = 0;
    while(1){
        int l = 2*i + 1;
        int r = 2*i + 2;
        int largest = i;
        if(l < size && heap[l] > heap[largest]) largest = l;
        if(r < size && heap[r] > heap[largest]) largest = r;
        if(largest == i) break;
        swap(&heap[i], &heap[largest]);
        i = largest;
    }
    return root;
}

void display(){
    if(size == 0){
        printf("Priority Queue is empty\n");
        return;
    }
    printf("Priority Queue: ");
    for(int i = 0; i < size; i++)
        printf("%d ", heap[i]);
    printf("\n");
}

int main(){
    int ch, val;
    while(1){
        printf("\n1. Insert\n2. Delete Max\n3. Display\n4. Exit\n");
        scanf("%d", &ch);
        if(ch == 1){
            printf("Enter value to insert: ");
            scanf("%d", &val);
            insert(val);
        }
        else if(ch == 2){
            int max = deleteMax();
            if(max != -1)
                printf("Deleted max element: %d\n", max);
        }
        else if(ch == 3)
            display();
        else
            break;
    }
    return 0;
}
