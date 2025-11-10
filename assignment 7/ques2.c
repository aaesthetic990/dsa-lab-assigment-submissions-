#include<stdio.h>

void improvedSelection(int a[],int n){
    int i,min,max,t;
    for(i=0;i<n/2;i++){
        min=i;
        max=n-i-1;
        int j;
        for(j=i;j<n-i;j++){
            if(a[j]<a[min])
                min=j;
            if(a[j]>a[max])
                max=j;
        }
        t=a[i];
        a[i]=a[min];
        a[min]=t;
        if(max==i)
            max=min;
        t=a[n-i-1];
        a[n-i-1]=a[max];
        a[max]=t;
    }
}

int main(){
    int a[50],n,i;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    printf("Enter elements: ");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    improvedSelection(a,n);
    printf("Sorted array: ");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
    return 0;
}
