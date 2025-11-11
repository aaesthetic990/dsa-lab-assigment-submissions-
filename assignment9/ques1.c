#include<stdio.h>

void heapify(int a[], int n, int i, int order){
    int extreme = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if(order == 1){ 
        if(l < n && a[l] > a[extreme]) extreme = l;
        if(r < n && a[r] > a[extreme]) extreme = r;
    } else { 
        if(l < n && a[l] < a[extreme]) extreme = l;
        if(r < n && a[r] < a[extreme]) extreme = r;
    }
    if(extreme != i){
        int t = a[i];
        a[i] = a[extreme];
        a[extreme] = t;
        heapify(a, n, extreme, order);
    }
}

void heapSort(int a[], int n, int order){
    for(int i = n/2 - 1; i >= 0; i--)
        heapify(a, n, i, order);
    for(int i = n - 1; i > 0; i--){
        int t = a[0];
        a[0] = a[i];
        a[i] = t;
        heapify(a, i, 0, order);
    }
}

int main(){
    int a[50], n, i, ch;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("1. Increasing Order\n2. Decreasing Order\nEnter choice: ");
    scanf("%d", &ch);
    if(ch == 1)
        heapSort(a, n, 1);
    else
        heapSort(a, n, 0);
    printf("Sorted array: ");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}
