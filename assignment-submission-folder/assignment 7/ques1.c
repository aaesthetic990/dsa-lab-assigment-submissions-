#include<stdio.h>

void selection(int a[],int n){
    int i,j,min,t;
    for(i=0;i<n-1;i++){
        min=i;
        for(j=i+1;j<n;j++){
            if(a[j]<a[min])
                min=j;
        }
        t=a[i];
        a[i]=a[min];
        a[min]=t;
    }
}

void insertion(int a[],int n){
    int i,j,key;
    for(i=1;i<n;i++){
        key=a[i];
        j=i-1;
        while(j>=0 && a[j]>key){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}

void bubble(int a[],int n){
    int i,j,t;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
}

void merge(int a[],int l,int m,int r){
    int n1=m-l+1,n2=r-m,i,j,k;
    int L[50],R[50];
    for(i=0;i<n1;i++)
        L[i]=a[l+i];
    for(j=0;j<n2;j++)
        R[j]=a[m+1+j];
    i=j=0;
    k=l;
    while(i<n1 && j<n2){
        if(L[i]<=R[j])
            a[k++]=L[i++];
        else
            a[k++]=R[j++];
    }
    while(i<n1)
        a[k++]=L[i++];
    while(j<n2)
        a[k++]=R[j++];
}

void mergesort(int a[],int l,int r){
    if(l<r){
        int m=(l+r)/2;
        mergesort(a,l,m);
        mergesort(a,m+1,r);
        merge(a,l,m,r);
    }
}

int partition(int a[],int low,int high){
    int pivot=a[high];
    int i=low-1,t,j;
    for(j=low;j<high;j++){
        if(a[j]<=pivot){
            i++;
            t=a[i];
            a[i]=a[j];
            a[j]=t;
        }
    }
    t=a[i+1];
    a[i+1]=a[high];
    a[high]=t;
    return i+1;
}

void quicksort(int a[],int low,int high){
    if(low<high){
        int p=partition(a,low,high);
        quicksort(a,low,p-1);
        quicksort(a,p+1,high);
    }
}

void display(int a[],int n){
    int i;
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
}

int main(){
    int a[50],n,ch,i;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    printf("Enter elements: ");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    while(1){
        printf("\n1.Selection Sort\n2.Insertion Sort\n3.Bubble Sort\n4.Merge Sort\n5.Quick Sort\n6.Exit\n");
        scanf("%d",&ch);
        if(ch==1){
            selection(a,n);
            display(a,n);
        }
        else if(ch==2){
            insertion(a,n);
            display(a,n);
        }
        else if(ch==3){
            bubble(a,n);
            display(a,n);
        }
        else if(ch==4){
            mergesort(a,0,n-1);
            display(a,n);
        }
        else if(ch==5){
            quicksort(a,0,n-1);
            display(a,n);
        }
        else
            break;
    }
    return 0;
}
